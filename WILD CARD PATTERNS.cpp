#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, p;

    getline(cin, s);
    getline(cin, p);

    // Remove possible carriage return / spaces from input lines
    while (!s.empty() && (s.back() == '\r' || s.back() == ' '))
        s.pop_back();

    while (!p.empty() && (p.back() == '\r' || p.back() == ' '))
        p.pop_back();

    int n = s.size();
    int m = p.size();

    int i = 0, j = 0;

    int star = -1;
    int starMatch = -1;

    while (i < n) {

        // Exact character or ? wildcard
        if (j < m && (p[j] == '?' || p[j] == s[i])) {
            i++;
            j++;
        }

        // *
        else if (j < m && p[j] == '*') {
            star = j;
            starMatch = i;
            j++;
        }

        // Try making * match one more character
        else if (star != -1) {
            j = star + 1;
            starMatch++;
            i = starMatch;
        }

        else {
            cout << 0;
            return 0;
        }
    }

    // Remaining pattern must contain only *
    while (j < m && p[j] == '*')
        j++;

    cout << (j == m ? 1 : 0);

    return 0;
}
