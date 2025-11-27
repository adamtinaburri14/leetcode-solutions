#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high_index = nums.size() - 1;
        int middle_index = 0;
        int low_index = 0;
        while (low_index <= high_index){
            middle_index = low_index + (high_index-low_index)/2;
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
                low_index = middle_index+1;
            }
            else if (target < nums[middle_index]) {
                high_index = middle_index-1;
            }       
        }
        return -1;
    }
};

int main() {
    Solution solution;

    // vector<int> nums = {-1,0,3,5,9,12,15,18,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150};
    // vector<int> nums = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51};
    vector<int> nums = {5};
    cout << nums.size()+5 << endl;
    
    for (int i = -5; i <= static_cast<int>(nums.size())+5; i++) {
        int target = i;
        int binary_search_index = solution.search(nums, target);
        
        cout << "Index of " << target << ": " << binary_search_index << endl;
    }
    return 0;
}