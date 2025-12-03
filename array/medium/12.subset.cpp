#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, int index,
                   vector<int>& current, vector<vector<int>>& result) {
        // Add the current subset (snapshot) to the result
        result.push_back(current);

        // Try to include each element starting from 'index'
        for (int i = index; i < (int)nums.size(); ++i) {
            // Choose nums[i]
            current.push_back(nums[i]);

            // Recurse with next starting index
            backtrack(nums, i + 1, current, result);

            // Backtrack (remove last choice)
            current.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = sol.subsets(nums);

    cout << "All subsets:\n";
    for (auto &subset : ans) {
        cout << "[ ";
        for (int x : subset) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
