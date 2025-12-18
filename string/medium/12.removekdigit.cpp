#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    string st; // acts as stack

    for (char c : num) {
        // Remove larger digits to make number smaller
        while (!st.empty() && k > 0 && st.back() > c) {
            st.pop_back();
            k--;
        }
        st.push_back(c);
    }

    // If k still remains, remove from end
    while (k > 0 && !st.empty()) {
        st.pop_back();
        k--;
    }

    // Remove leading zeros
    int idx = 0;
    while (idx < st.size() && st[idx] == '0') {
        idx++;
    }

    string result = st.substr(idx);

    return result.empty() ? "0" : result;
}

int main() {
    string num = "1432219";
    int k = 3;

    cout << "Input Number: " << num << endl;
    cout << "Digits to Remove: " << k << endl;

    string ans = removeKdigits(num, k);

    cout << "Smallest Number: " << ans << endl;

    return 0;
}
