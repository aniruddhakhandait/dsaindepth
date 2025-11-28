#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    
    // Step 1: Sort by start time
    sort(intervals.begin(), intervals.end());
    
    // Step 2: Iterate and merge
    for (auto& interval : intervals) {
        // If result empty OR no overlap → add interval
        if (result.empty() || result.back()[1] < interval[0]) {
            result.push_back(interval);
        }
        else {
            // Overlapping → merge by extending the end
            result.back()[1] = max(result.back()[1], interval[1]);
        }
    }
    
    return result;
}

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = merge(intervals);
    
    for (auto& v : ans) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
}
