#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int seen = 0;
    int duplicate = 0;

    // Find duplicate characters using bit manipulation
    for (char c : s) {
        int bit = c - 'a';

        if (seen & (1 << bit)) {
            duplicate = duplicate | (1 << bit);
        }
        else {
            seen = seen | (1 << bit);
        }
    }

    // Print duplicates in order of first occurrence
    int printed = 0;
    bool found = false;

    for (char c : s) {
        int bit = c - 'a';

        if ((duplicate & (1 << bit)) &&
            !(printed & (1 << bit))) {

            cout << c << " ";
            printed = printed | (1 << bit);
            found = true;
        }
    }

    if (!found) {
        cout << "No duplicates";
    }

    return 0;
}
