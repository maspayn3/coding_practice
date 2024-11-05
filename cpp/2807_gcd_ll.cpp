#include <iostream>
#include <vector>




struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head->next) {
            return head;
        }

        ListNode* curr_node = head;
        ListNode* prev = nullptr;
        ListNode* next = curr_node->next;

        // a is val of left node, b is val of right node
        while(next != nullptr) {
            int a = curr_node->val;
            int b = next->val;

            ListNode * to_be_inserted = new ListNode(gcd(a, b));

            // now need to perform the swap

            // set new nodes next to the curr_nodes next
            to_be_inserted->next = curr_node->next;

            // set curr_nodes next to be the new node
            curr_node->next = to_be_inserted;

            // set curr_node to be one after new node
            // should be guaranteed to not be null
            curr_node = to_be_inserted->next;
            next = curr_node->next;
        }
        return head;
    }
};


int main() {
    return 0;
}