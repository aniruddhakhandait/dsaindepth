#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int num : s) {
            // Only start counting if this is the beginning of a sequence
            if (s.find(num - 1) == s.end()) {
                int currentNum = num;
                int streak = 1;

                // Count the streak
                while (s.find(currentNum + 1) != s.end()) {
                    currentNum++;
                    streak++;
                }

                longest = max(longest, streak);
            }
        }

        return longest;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    cout << sol.longestConsecutive(nums) << endl;  // Output: 4

    return 0;
}
