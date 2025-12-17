#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.size() < ransomNote.size()) {
            return false;
        }
        while (ransomNote.size() > 0) {
            size_t magazine_position = magazine.find(ransomNote[0]);
            cout << "Ransom Note: " << ransomNote << endl;
            cout << "Magazine   : " << magazine << endl;
            if (magazine_position != string::npos) {
                ransomNote.erase(0,1);
                magazine.erase(magazine_position,1);
            }
            else { // current first letter of ransom note is not in magazine, can't make the letter
                return false;
            }
        }
        return true;
    }
};

int main() {
    string ransomNote = "abcdefghijklmnopqrstuvwxyz";
    string magazine = "zyxwvutsrqponmlkjihgfedcba";
    Solution solution;
    // ransomNote.erase(0,1);
    // cout << "Ransom Note: " << ransomNote << endl;
    // cout << "Magazine   : " << magazine << endl;
    bool isPossible = solution.canConstruct(ransomNote, magazine);
    cout << "Construction is possible: " << isPossible << endl;


    return 0;
}