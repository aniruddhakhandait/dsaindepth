#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>&nums){
    int n = nums.size();
     
    // find pivot : the first decressing element from right
    int i = n-2;
    while (i >=0 && nums[i] >= nums[i+i]){
         i--;
    }
    // if the pivot exits ,replace with the first element bigger than this and swap
    if (i >=0){
        int j = n-1;
        while (nums[j] <= nums[i]){
            j--;
        }
        swap (nums[i],nums[j]);
    }
     
    // reverse everything after pivot
     reverse(nums.begin() +i + 1,nums.end());

}

int main (){
     vector<int> nums={1,2,3};
     
     cout << "Original:";
     for (int x :nums) cout << x << " ";
     cout << endl;

     nextPermutation(nums);

     cout << "Next permutation:";

     for(int x : nums) cout << x << " ";
     cout << endl;
     
     return 0;


}