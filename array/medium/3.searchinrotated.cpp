
#include <bits/stdc++.h>
using namespace std;


int searchInRotated(vector<int>& nums,int target){
    // This is base case 
    int left = 0 , right = nums.size()-1;
       
    while (left <= right){
         int mid = left + (right-left)/2;

         if (nums[mid] == target)
         return mid;

         // check the left half is sorted 
        if (nums[left] <= nums[mid]){

            if (nums[left] <= target && target <nums[mid])
            right = mid -1 ;
            else left = mid + 1;
        }
        
        // otherwise right half is sorted
        else{
            if (nums[mid] < target && target <= nums[right])
            left = mid + 1 ;
            else right = mid -1;
        
        }

    }
     right -1;
    }

    int main (){
           vector <int > nums = {4,5,6,7,0,1,2};
           int target = 0;

           int index = searchInRotated (nums,target);
           cout << "Target found at index: " << index << endl;

           return 0;
    }