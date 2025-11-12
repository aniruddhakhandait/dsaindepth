#include <iostream>
#include <vector>
using namespace std;


int removeduplicates(vector<int>& nums){
        if(nums.empty()) return 0;

        // start track for unique number
        int i = 0;
        for (int j=1; j<nums.size(); j++){
            
            if(nums[j] != nums[i]){ 
             // found unique number
                i++;
                nums [i]=nums[j];
            }
        }

         return i + 1;
}

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int length = removeduplicates(nums);

    cout << "Unique count: " << length << endl;
    cout << "Modified array: ";
    for (int i = 0; i < length; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}