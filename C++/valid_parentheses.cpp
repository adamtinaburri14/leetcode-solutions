#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void printStack(stack<char> s){ // remove
    cout << "stack: ";
    while (!s.empty()){
        cout << s.top() << ", ";
        s.pop();
    }
    cout << endl;
}

class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses_stack;
        vector<char> open_lookup_table = {'(', '[', '{'};
        vector<char> close_lookup_table = {')', ']', '}'};

        for (int i=0; i < s.length(); i++){
            parentheses_stack.push(s[i]);
            if (find(open_lookup_table.begin(), open_lookup_table.end(), parentheses_stack.top()) != open_lookup_table.end()) { // open bracket check
                continue;
            } 
            else if (find(close_lookup_table.begin(), close_lookup_table.end(), parentheses_stack.top()) != close_lookup_table.end()) { // close bracket check
                char close_parenthesis = parentheses_stack.top();
                parentheses_stack.pop();
                if (parentheses_stack.empty()) { // edge case for closed bracket coming before open bracket or an extra closed bracket
                    return false;
                }
                else if (((int)close_parenthesis-(int)parentheses_stack.top()) < 3 && ((int)close_parenthesis-(int)parentheses_stack.top()) > 0){ // check ascii values within range
                    parentheses_stack.pop();
                }                
                else { // ascii out of range (means out of order closing bracket)
                    return false;
                }
            }
        }
        return parentheses_stack.empty(); // catches extra open brackets 
    }
};

int main(){
    string s = "()(){}[]({[]})([{}])}";
    Solution solution;
    bool input_valid = solution.isValid(s);
    cout << "Is "<< s << " valid? --> " << input_valid << endl;
    return 0;
}