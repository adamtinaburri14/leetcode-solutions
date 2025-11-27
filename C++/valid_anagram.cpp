#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};


int main() {
    string s = "rat";
    string t = "car";

    Solution solution;
    cout << "Is Anagram? " << solution.isAnagram(s, t) << endl;
}