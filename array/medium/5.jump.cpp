#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int jumps = 0;
    int farthest = 0;
    int current_end = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);

        // When we reach the end of the current jump range
        if (i == current_end) {
            jumps++;
            current_end = farthest;
        }
    }

    return jumps;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << jump(nums) << endl;  // Output: 2
}
