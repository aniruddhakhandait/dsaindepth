#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();

    vector<bool> dp(n + 1, false);
    dp[0] = true; // empty string

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && dict.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    cout << "String: " << s << endl;
    cout << "Dictionary: ";
    for (auto& w : wordDict) cout << w << " ";
    cout << endl;

    bool result = wordBreak(s, wordDict);

    cout << "Can be segmented? ";
    cout << (result ? "true" : "false") << endl;

    return 0;
}
