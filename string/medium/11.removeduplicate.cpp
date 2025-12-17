#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s) {
    vector<int> freq(26, 0);
    vector<bool> used(26, false);

    // Count frequency of each character
    for (char c : s) {
        freq[c - 'a']++;
    }

    string result; // acts like a stack

    for (char c : s) {
        int idx = c - 'a';
        freq[idx]--;

        // If already used, skip
        if (used[idx]) continue;

        // Remove larger characters if they appear later again
        while (!result.empty() &&
               result.back() > c &&
               freq[result.back() - 'a'] > 0) {

            used[result.back() - 'a'] = false;
            result.pop_back();
        }

        result.push_back(c);
        used[idx] = true;
    }

    return result;
}

int main() {
    string s = "cbacdcbc";

    cout << "Input: " << s << endl;

    string ans = removeDuplicateLetters(s);

    cout << "Output: " << ans << endl;

    return 0;
}
