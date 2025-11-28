#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> to_check = {{sr,sc}};
        int original_color = image[sr][sc];
        while (to_check.size() > 0) {

            if (image[to_check.front()[0]][to_check.front()[1]] == original_color){
                cout << "success" << endl;
                to_check.pop_front();
            }
        }
        return image;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1;
    int sc = 1;
    int color = 2;
    solution.floodFill(image, sr, sc, color);

    return 0;
}