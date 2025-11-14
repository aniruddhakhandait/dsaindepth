#include <bits/stdc++.h>
using namespace std ;

vector<vector<int>>threesum(vector<int>&nums){
    vector<vector<int>> result;
    
    sort (nums.begin(),nums.end());
    int n = nums.size();

    // 3 loop (i,j,k)
    for(int i = 0; i<n;i++){
        // skip duplicate fixed number 
        if (i > 0 && nums[i] == nums[i-1])
        continue;
        
        int left = i+1;
        int right = n-1;

         
        while (left < right){
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0){
                result.push_back({ nums[i],nums[left],nums[right]});
                left ++ ;
                right --;
               
               //skip duplicate left values
               while (left < right && nums[left] == nums[left -1])
                left ++ ;

                //skip duplicate right values
                
                while (left < right && nums[right] == nums[right +1])
                right -- ;
            }
            else if (sum < 0)
            left ++ ;
            else 
            right --;
        }
    }


   return result ;
}
int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threesum
    
    (nums);

    for (auto& triplet : ans) {
        for (int num : triplet) 
            cout << num << " ";
        cout << endl;
    }
}