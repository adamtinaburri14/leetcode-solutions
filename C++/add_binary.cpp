#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int idx_a = a.size() - 1;
        int idx_b = b.size() - 1;
        char carry = '0';
        string result = "";
        while (idx_a >= 0 && idx_b >= 0) {
            if (carry == '0') {
                if (a[idx_a] == '0' && b[idx_b] == '0') {
                    result = '0' + result;
                }
                else if ((a[idx_a] == '1' && b[idx_b] == '0') || (a[idx_a] == '0' && b[idx_b] == '1')) {
                    result = '1' + result;
                }
                else if (a[idx_a] == '1' && b[idx_b] == '1') {
                    result = '0' + result;
                    carry = '1';
                }
            }
            else if (carry == '1') {
                if (a[idx_a] == '0' && b[idx_b] == '0') {
                    result = '1' + result;
                    carry = '0';
                }
                else if ((a[idx_a] == '1' && b[idx_b] == '0') || (a[idx_a] == '0' && b[idx_b] == '1')) {
                    result = '0' + result;
                }
                else if (a[idx_a] == '1' && b[idx_b] == '1') {
                    result = '1' + result;
                }
            }
            idx_a--;
            idx_b--;
        }
        while (idx_a >= 0) {
            if (a[idx_a] == '0' && carry == '0') {
                result = '0' + result;
            }
            else if ((a[idx_a] == '1' && carry == '0') || (a[idx_a] == '0' && carry == '1')) {
                result = '1' + result;
                carry = '0';
            }
            else if (a[idx_a] == '1' && carry == '1') {
                result = '0' + result;
                carry = '1';
            }
            idx_a--;
        }
        while (idx_b >= 0) {
            if (b[idx_b] == '0' && carry == '0') {
                result = '0' + result;
            }
            else if ((b[idx_b] == '1' && carry == '0') || (b[idx_b] == '0' && carry == '1')) {
                result = '1' + result;
                carry = '0';
            }
            else if (b[idx_b] == '1' && carry == '1') {
                result = '0' + result;
                carry = '1';
            }
            idx_b--;
        }
        if (carry == '1') {
            result = carry + result;
        }
        return result;
    }
};

int main() {
    string a = "11";
    string b = "1";
    Solution solution;
    string result = solution.addBinary(a,b);
    cout << a << " + " << b << " = " << result << endl;
    return 0;
}