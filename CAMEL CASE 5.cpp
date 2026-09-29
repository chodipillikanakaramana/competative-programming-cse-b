#include <bits/stdc++.h>
using namespace std;

string getAbbreviation(string s) {
    string abbr;

    for (char c : s) {
        if (isupper(c)) {
            abbr += c;
        }
    }

    return abbr;
}

bool matches(string abbr, string pattern) {
    int i = 0, j = 0;

    while (i < abbr.size() && j < pattern.size()) {
        if (abbr[i] == pattern[j]) {
            j++;
        }
        i++;
    }

    return j == pattern.size();
}

int main() {
    int n;
    cin >> n;

    cin.ignore();

    string line;
    getline(cin, line);

    string pattern;
    getline(cin, pattern);

    vector<string> words;

    stringstream ss(line);
    string word;

    while (getline(ss, word, ',')) {
        words.push_back(word);
    }

    vector<pair<string, string>> ans;

    for (string s : words) {
        string abbr = getAbbreviation(s);

        if (matches(abbr, pattern)) {
            ans.push_back({abbr, s});
        }
    }

    sort(ans.begin(), ans.end());

    if (ans.empty()) {
        cout << "No match found";
    }
    else {
        for (auto p : ans) {
            cout << p.second << endl;
        }
    }

    return 0;
}
