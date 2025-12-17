#include <iostream>
#include <map>
#include <vector>
#include <utility>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> count;
        for(int x : nums) {
            count[x] += 1; // potential problem if key x doesn't exists yet
            if (count[x] >= float(nums.size())/2) {
                return x;
            }
        }
    }
};

int main() {
    vector<int> nums = {2,2,2,2,2,5,5,5,5,5,5};
    Solution solution;
    int majority_element = solution.majorityElement(nums);
    cout << "Majority Element: " << majority_element << endl;
    return 0;
}