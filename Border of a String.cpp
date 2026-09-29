#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    vector<int> lps(n, 0);

    int len = 0;
    int i = 1;

    while (i < n) {

        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    int borderLength = lps[n - 1];

    if (borderLength == 0) {
        cout << "No border";
    }
    else {
        cout << s.substr(0, borderLength);
    }

    return 0;
}
