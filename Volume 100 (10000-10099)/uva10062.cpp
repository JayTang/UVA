#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class frequency {
  public:
    char letter;
    int count;
    frequency(char c, int i = 0): letter(c), count(i) {}
    
    // sorting rule 
    bool operator < (const frequency& other) const {
        if (count != other.count) return count < other.count;
        else return letter > other.letter;
    }
};

int main() {
    string input;
    
    for (int i = 0; getline(cin, input); i++) {
        if (i != 0) cout << endl; // print empty line between cases
        
        // class init
        vector<frequency> list;
        for (int i = 32; i <= 127; i++)
            list.push_back(frequency(i));

        // count letter
        for (char c: input) list[c - 32].count++;

        // sort frequency
        sort(list.begin(), list.end());

        // print result
        for (frequency f: list)
            if (f.count > 0) cout << (int)f.letter << " " << f.count << endl;
    }
    
    return 0;
}
