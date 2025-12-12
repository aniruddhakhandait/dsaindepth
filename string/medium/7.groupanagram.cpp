#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end()); // sorted string becomes key
        mp[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto& p : mp) {
        result.push_back(p.second);
    }

    return result;
}

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> ans = groupAnagrams(strs);

    cout << "Grouped Anagrams:\n";
    for (auto& group : ans) {
        cout << "[ ";
        for (auto& s : group) {
            cout << s << " ";
        }
        cout << "]\n";
    }

    return 0;
}
