#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    int prev2 = 0; // dp[i-2]
    int prev1 = 0; // dp[i-1]

    for (int money : nums) {
        int curr = max(prev1, prev2 + money);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    vector<int> houses = {2, 7, 9, 3, 1};

    cout << "Money in houses: ";
    for (int x : houses) cout << x << " ";
    cout << endl;

    cout << "Maximum money robbed: " << rob(houses) << endl;

    return 0;
}
