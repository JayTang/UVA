#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define MAX_SIZE 52 // 50 + 2 (0 and length)

int find_minimun_cost(int dp[][MAX_SIZE], vector<int> &cuts, int cut_start, int cut_end) {
	if (dp[cut_start][cut_end] != INT_MAX) return dp[cut_start][cut_end];
	if (cut_end - cut_start == 1) return dp[cut_start][cut_end] = 0;

	// dp[x][y] = min(dp[x][cut_index] + dp[cut_index][y] + cut_cost) for all cut index from x+1 to y-1
	for(int i = cut_start + 1; i < cut_end; i++)
		dp[cut_start][cut_end] = min(dp[cut_start][cut_end], find_minimun_cost(dp, cuts, cut_start, i) + find_minimun_cost(dp, cuts, i, cut_end) + cuts[cut_end] - cuts[cut_start]);

	return dp[cut_start][cut_end];
}

int main() {
    // dp[x][y] = the minimum cost between cut index x and y
    int length, ncut, tmp, min_cost, dp[MAX_SIZE][MAX_SIZE]; 

    while (cin >> length && length) {
		vector<int> cuts;

		// cuts init
		cin >> ncut;
		cuts.push_back(0);
		for (int i = 0; i < ncut && cin >>tmp; i++) cuts.push_back(tmp);
		cuts.push_back(length);

		// dp array init
		fill(&dp[0][0], &dp[0][0] + MAX_SIZE * MAX_SIZE, INT_MAX);

		// find minimun cost by dynamic programming
		min_cost = find_minimun_cost(dp, cuts, 0, cuts.size() - 1);

		// print result
		cout << "The minimum cutting is " << min_cost << "." << endl;
    }
    
    return 0;
}
