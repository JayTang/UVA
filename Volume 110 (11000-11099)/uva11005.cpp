#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int ncase, nquery, num, costs[36];
    cin >> ncase;
 
    for (int i = 1; i <= ncase; i++) {
        if (i > 1) cout << endl; // print empty line between cases
        cout << "Case " << i << ":" << endl;

        // costs init
        for (int j = 0; j < 36; j++) cin >> costs[j];

        cin >> nquery;
        while (nquery--) {
            vector<int> result; // list of cheapest base
            int opt_cost = INT_MAX;

            cin >> num;
            for (int base = 2; base <= 36; base++) {
                // convert num to base n and sum the cost
                int tmp = num, total_cost = 0;
                do {
                    total_cost += costs[tmp % base];
                    tmp /= base;
                } while (tmp);

                // update optimal cost
                if (total_cost < opt_cost) {
                    result.clear();
                    result.push_back(base);
                    opt_cost = total_cost;
                }
                else if (total_cost == opt_cost)
                    result.push_back(base);

            }

            // print result
            cout << "Cheapest base(s) for number " << num << ":";
            for (int base: result)  cout << " " << base;
            cout << endl;
        }
    }
    return 0;
}
