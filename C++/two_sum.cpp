#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;
        for (int i=0; i < nums.size(); i++) {
            if (num_map.count(nums[i])) {
                return {num_map[nums[i]], i};
            }
            num_map[target - nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2,71,11,7};
    int target = 82;
    vector<int> result = solution.twoSum(nums, target);
    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}