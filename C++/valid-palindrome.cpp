#include <iostream>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        s = lowercase(s);
        s = remove_non_alphanumeric(s);
        string s_reverse = reverse_string(s);
        // cout << s;
        
        if (s == s_reverse) {
            return true;
        }
        else {
            return false;
        }

        return true;
    }

private:
    string lowercase(string s) {
        for (char& c : s) {
            c = tolower(static_cast<unsigned char>(c));
        }
        cout << "lowercase result: " << s << endl;
        return s;
    }
    string remove_non_alphanumeric(string s) {
        string result = "";
        for (char c : s) {
            if (isalnum(c)) {
                result += (char)c;
            }
        }
        cout << "remove result: " << result << endl;
        return result;
    }
    string reverse_string(string s) {
        string result = "";
        for (int i = s.length()-1; i >= 0; i--) {
            result += s[i];
        }
        cout << "reverse result: " << result << endl;
        return result;
    }
};

int main(){
    string s = "RaCe (*&(*^&^(*^&^*(&**&**(&^%^*(&^&*(CaR";

    Solution solution;

    bool palindrome = solution.isPalindrome(s);
    cout << "Is " << s << " a palindrome? " << (bool)palindrome << endl;

    return 0;
}