#include <iostream>
#include <vector>
#include <climits>
#include <numeric>

using namespace std;

int main() {
	int ncase, nquery, num, cost[36];
	cin >> ncase;

	for (int i = 1; i <= ncase; i++) {
		if (i > 1) cout << endl;

		for (int i = 0; i < 36; i++) cin >> cost[i];
		cin >> nquery;

		cout << "Case " << i << ":" << endl;

		while (nquery--) {
			vector<int> result;
			int opt_cost = INT_MAX;

			cin >> num;
			for (int base = 2; base <= 36; base++) {
				// convert to base n and push cost into vector
				vector<int> costs;
				int tmp = num;
				do {
					costs.push_back(cost[tmp % base]);
					tmp /= base;
				} while (tmp);

				// sum all the cost
				int sum = accumulate(costs.begin(), costs.end(), 0);

				// update optimal cost
				if (sum < opt_cost) {
					result.clear();
					result.push_back(base);
					opt_cost = sum;
				}
				else if (sum == opt_cost)
					result.push_back(base);

			}

			// print result
			cout << "Cheapest base(s) for number " << num << ":";
			for (int base: result)	cout << " " << base;
			cout << endl;
		}
	}
	return 0;
}
