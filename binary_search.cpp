#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high_index = nums.size() / 2 - 1;
        int middle_index = 0;
        int low_index = 0;
        while (low_index < high_index){
            middle_index = low_index + (high_index-low_index)/2;

            cout << "High Index: " << high_index << endl;
            cout << "Middle Index: " << middle_index << endl;
            cout << "Low Index: " << low_index << endl;
            cout << "Value at High Index: " << nums[high_index] << endl;
            cout << "Middle Index: " << middle_index << endl;
            cout << "Value at Low Index: " << nums[low_index] << endl;

            if (target == nums[high_index]) {
                return high_index;
            }
            else if (target == nums[middle_index]) {
                return middle_index;
            }
            else if (target == nums[low_index]) {
                return low_index;
            }
            else if (target > nums[middle_index]) {
                low_index = middle_index;
            }
            else if (target < nums[middle_index]) {
                high_index = middle_index;
            }
            if (high_index > nums.size() - 1) {
                high_index = nums.size() - 1;
            }
            else if (low_index < 0) {
                low_index = 0;
            }
            
        }
        return -1;
    }
};

int main() {
    Solution solution;

    // vector<int> nums = {-1,0,3,5,9,12,15,18,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150};
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    cout << nums.size() << endl;
    int target = 12;
    int binary_search_index = solution.search(nums, target);

    cout << "Index of " << target << ": " << binary_search_index << endl;
    // cout << target/2 << endl;
}