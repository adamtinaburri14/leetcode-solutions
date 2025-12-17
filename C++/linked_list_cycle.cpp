#include <iostream>
#include <array>
#include <set>

using namespace std;



 // Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *current_node = head;
        set<ListNode*> next_nodes;
        while (current_node != nullptr) {
            if (next_nodes.count(current_node)){
                return true;
            }
            else {
                next_nodes.insert(current_node);
            }
            current_node = current_node->next;
        }
        return false;
    }
};

int main() {
    array<int, 5> arr = {1, 2, 3, 4, 5};
    ListNode dummy(0);
    ListNode* head = &dummy;
    ListNode* current_node = head;
    for (int x : arr) {
        current_node->next = new ListNode(x);
        current_node = current_node->next;
    }
    head = head->next;
    current_node = head;
    while (current_node != nullptr) {
        cout << current_node->val << endl;
        current_node = current_node->next;
    }
    Solution solution;
    cout << "Head has a Cycle: " << solution.hasCycle(head) << endl;
    return 0;
}