#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<vector<int>> to_check;
        int original_color = image[sr][sc];
        if (color != original_color) {
                to_check.push({sr,sc});
            }
        while (!to_check.empty()) {
            int cr = to_check.front()[0];
            int cc = to_check.front()[1];
            if (image[cr][cc] == original_color){
                image[cr][cc] = color;
                // check up
                if (cr > 0) {
                    if (image[cr-1][cc] == original_color) {
                        to_check.push({cr-1, cc});
                    }
                }
                // check down
                if (cr < image.size()-1) {
                    if (image[cr+1][cc] == original_color) {
                        to_check.push({cr+1, cc});
                    }
                }
                // check left
                if (cc > 0) {
                    if (image[cr][cc-1] == original_color) {
                        to_check.push({cr, cc-1});
                    }
                }
                // check right
                if (cc < image[0].size()-1){
                    if (image[cr][cc+1] == original_color) {
                        to_check.push({cr, cc+1});
                    }
                }
            }
            to_check.pop();
        }
        return image;
    }
};

int main() {
    Solution solution;
    // vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>> image = {{0,0,0},{0,0,0}};
    int sr = 0;
    int sc = 0;
    int color = 0;
    solution.floodFill(image, sr, sc, color);
    for (const vector<int>& x : image) {
        for (int val : x) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}