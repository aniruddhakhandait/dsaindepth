#include <bits/stdc++.h>
using namespace std;

void backtrack(int index, vector<int>& candidates, int target,
               vector<int>& path, vector<vector<int>>& result) {

    if (target == 0) {
        result.push_back(path);
        return;
    }

    if (index == candidates.size() || target < 0)
        return;

    // Option 1: pick current number
    path.push_back(candidates[index]);
    backtrack(index, candidates, target - candidates[index], path, result);
    path.pop_back();

    // Option 2: skip current number
    backtrack(index + 1, candidates, target, path, result);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> path;
    backtrack(0, candidates, target, path, result);
    return result;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = combinationSum(candidates, target);

    for (auto& comb : ans) {
        for (int num : comb) cout << num << " ";
        cout << endl;
    }
}
