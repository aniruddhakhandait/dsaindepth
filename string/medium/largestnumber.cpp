#include <bits/stdc++.h>
using namespace std;

// Custom comparator
bool compare(string a, string b) {
    return a + b > b + a;
}

string largestNumber(vector<int>& nums) {
    vector<string> arr;

    // Convert integers to strings
    for (int num : nums) {
        arr.push_back(to_string(num));
    }

    // Sort using custom comparator
    sort(arr.begin(), arr.end(), compare);

    // Edge case: if largest is "0", result is "0"
    if (arr[0] == "0") return "0";

    // Build result
    string result;
    for (string& s : arr) {
        result += s;
    }

    return result;
}

int main() {
    vector<int> nums = {3, 30, 34, 5, 9};

    cout << "Input: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    string ans = largestNumber(nums);

    cout << "Largest Number = " << ans << endl;

    return 0;
}
