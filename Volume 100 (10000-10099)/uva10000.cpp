#include <iostream>
#include <vector>

using namespace std;

// return pair<point n, longest distance from start to point n>
pair<int, int> travel(pair<vector<int>, int> *path, int from, int distance) {
    // pruning sub path, to avoid time limit exceeded
    if (path[from].second > distance) return pair<int, int>(from, path[from].second);

    path[from].second = distance;

    pair<int, int> longest(from, path[from].second), current;
    for (int i: path[from].first) {
        current = travel(path, i, distance + 1);
        if (current.second > longest.second) longest = current;
        else if (current.second == longest.second && current.first < longest.first) longest.first = current.first;
    }

    return longest;
}

int main() {
    int npoint, spoint, from, to, ncase = 1;

    while (cin >> npoint && npoint) {
        cin >> spoint;

        // setup path, path[n] = information of point n, first = list of path to other point, second = longest distance from start to this point
        pair<vector<int>, int> path[101];
        while (cin >> from >> to && from && to) {
            path[from].first.push_back(to);
            path[from].second = 0;
        }

        // depth first search
        pair<int, int> longest_path = travel(path, spoint, 0);
        
        // print result
        cout << "Case " << ncase++ << ": The longest path from " << spoint << " has length " << longest_path.second << ", finishing at " << longest_path.first << "." << endl << endl;
    }

    return 0;
}
