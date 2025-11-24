#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& nums, vector<int>& path,
               vector<bool>& used, vector<vector<int>>& result) {

    if (path.size() == nums.size()) {
        result.push_back(path);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;

        used[i] = true;
        path.push_back(nums[i]);

        backtrack(nums, path, used, result);

        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used(nums.size(), false);

    backtrack(nums, path, used, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permute(nums);

    for (auto& perm : ans) {
        for (int num : perm)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}
