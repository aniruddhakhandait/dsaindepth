#include <bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";

    int n1 = num1.size(), n2 = num2.size();
    vector<int> result(n1 + n2, 0);

    // Make multiplication like manual method
    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {

            int mul = (num1[i] - '0') * (num2[j] - '0');

            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;        // current digit
            result[i + j] += sum / 10;           // carry to next place
        }
    }

    // Convert result vector to string
    string ans = "";
    for (int num : result) {
        if (!(ans.empty() && num == 0)) {
            ans.push_back(num + '0');
        }
    }

    return ans.empty() ? "0" : ans;
}

int main() {
    string num1 = "123";
    string num2 = "45";

    cout << "Num1 = " << num1 << endl;
    cout << "Num2 = " << num2 << endl;

    string product = multiply(num1, num2);

    cout << "Product = " << product << endl;

    return 0;
}
