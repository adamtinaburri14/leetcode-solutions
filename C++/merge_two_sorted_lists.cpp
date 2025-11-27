#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLinkedList (ListNode *head){
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *list1_current_node = list1;
        ListNode *list2_current_node = list2;
        ListNode *mergedList_head = new ListNode();
        ListNode *mergedList_current_node = mergedList_head;

        // Edge cases
        if (list1_current_node == nullptr && list2_current_node == nullptr) { // 1
            return nullptr;
        }
        else if (list1_current_node == nullptr && list2_current_node != nullptr) { // 2 
            return list2;
        }
        else if (list1_current_node != nullptr && list2_current_node == nullptr) { // 3
            return list1;
        }   

        // Initial
        if (list1_current_node->val <= list2_current_node->val) {
            mergedList_current_node->val = list1_current_node->val;
            printLinkedList(mergedList_head);
            cout << "Adding from list 1: " << list1_current_node->val << endl;
            list1_current_node = list1_current_node->next;
        }
        else {
            mergedList_current_node->val = list2_current_node->val;
            printLinkedList(mergedList_head);
            cout << "Adding from list 2: " << list2_current_node->val << endl;
            list2_current_node = list2_current_node->next;
        }
        while (list1_current_node != nullptr && list2_current_node != nullptr) {
            if (list1_current_node->val <= list2_current_node->val) {
                mergedList_current_node->next = new ListNode(list1_current_node->val);
                printLinkedList(mergedList_head);
                cout << "Adding from list 1: " << list1_current_node->val << endl;
                list1_current_node = list1_current_node->next;
            }
            else {
                mergedList_current_node->next = new ListNode(list2_current_node->val);
                printLinkedList(mergedList_head);
                cout << "Adding from list 2: " << list2_current_node->val << endl;
                list2_current_node = list2_current_node->next;
            }
            mergedList_current_node = mergedList_current_node->next;
        }

        while (list1_current_node != nullptr || list2_current_node != nullptr) {
            if (list1_current_node != nullptr) {
                mergedList_current_node->next = new ListNode(list1_current_node->val);
                list1_current_node = list1_current_node->next;
            }
            else {
                mergedList_current_node->next = new ListNode(list2_current_node->val);
                list2_current_node = list2_current_node->next;
            }
            mergedList_current_node = mergedList_current_node->next;
        }

        return mergedList_head;
    }
};

int main() {
    // ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    // ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    ListNode *list1 = nullptr;
    ListNode *list2 = new ListNode(0);
    
    // ListNode *list1 = new ListNode(1);
    // ListNode *list2 = nullptr;

    // ListNode *list1 = nullptr;
    // ListNode *list2 = nullptr;



    Solution solution;
    ListNode *mergedList = solution.mergeTwoLists(list1, list2);

    cout << "final list: ";
    printLinkedList(mergedList);
    
}