#include <iostream>
#include <vector>
using namespace std;

int removeelement(vector<int>&nums,int val){ 
    int i = 0; 
     for (int j=0; j<nums.size(); j++){
            if(nums[j] != val){
                 nums[i] = nums[j];
                 i++;
            }
     }
     return i;
}

int main (){
    // passing the value and array
    vector<int> nums = {3,2,2,3,4,5,3};
    int val = 3;
    int length = removeelement(nums,val);
 
     // return the new array after removal
    cout << "Element after removal:  ";
    for(int i=0;i<length;i++){
         cout << nums[i] << " ";
    }
    cout << endl;
    // return the length of an array
    cout << "New length "<< length << endl;

    return 0;
}