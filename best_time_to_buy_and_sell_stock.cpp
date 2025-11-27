#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = prices[0];

        for (int i=1; i < prices.size(); i++) {
            if (prices[i] > buy) {
                profit = max(profit, prices[i]-buy);
            }
            else {
                buy = prices[i];
            }
        }
        return profit;
    }
};

int main() {
    vector<int> prices = {7,6,6,6,6,4};

    Solution solution;

    int maximum_profit = solution.maxProfit(prices);

    cout << "Maximum Profit: " << maximum_profit << endl;
    return 0;
}