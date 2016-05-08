#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class freq {
  public:
    char letter;
    int count;
    freq(char c, int i = 0): letter(c), count(i) {}

    bool operator < (const freq& other) const {
        if (count > other.count) return false;
        else if (count < other.count) return true;
        else return (letter > other.letter);
    }
};

int main() {
    string input;
    
    for (int i = 0; getline(cin, input); i++) {
        // print empty line between cases
        if (i != 0) cout << endl;
        
        // class init
        vector<freq> list;
        for (int i = 0; i <= 127; i++)
            list.push_back(freq(i));

        // count
        for (char c: input)
            list[c].count++;

        // sort
        sort(list.begin(), list.end());

        // print answer
        for (freq f: list)
            if (f.count > 0)
                cout << (int)f.letter << " " << f.count << endl;
    }
    
    return 0;
}
