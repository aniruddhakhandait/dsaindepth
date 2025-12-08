#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> result;

    void backtrack(string current, int open, int close, int n) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (open < n)
            backtrack(current + "(", open + 1, close, n);

        if (close < open)
            backtrack(current + ")", open, close + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return result;
    }
};

int main() {
    Solution sol;
    int n = 3;

    vector<string> ans = sol.generateParenthesis(n);

    for (string s : ans)
        cout << s << endl;

    return 0;
}
