#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    ListNode* remove_node(ListNode* prev, ListNode* victim) {

        // probably need a current, next, and prev node to do proper removal
        ListNode* next = victim->next;

        // might have to check if previous or next is null

        // indicates a lone node  
        if (!next && !prev) {
            return NULL;
        }
        
        // prev is null, head node
        if (!prev) {
            delete victim;
            return next;    
        }

    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> banned_numbers;

        for (const auto num : nums) {
            banned_numbers.insert(num);
        }

        // can handle case where head nodes need to be removed right away

        while (head && banned_numbers.count(head->val) > 0) {
            ListNode * temp = head;
            head = head->next;
            delete temp;
        }


        if (head == nullptr) {
            return nullptr;
        }

        ListNode* curr_node = head; 

        while (curr_node->next != nullptr) {
            if (banned_numbers.count(curr_node->next->val)) {
                // prev node will stay the same
                
                ListNode* temp = curr_node->next;
                // skip next node
                curr_node->next = curr_node->next->next;
                
                delete temp;
            }
            else {
                curr_node = curr_node->next;
            }
        }
        return head;
    }
};

ListNode* build_tree(vector<int>& vals) {



}

int main() {
    Solution sol;

    auto test1 = {1,2,3};



    // sol.modifiedList();

    return 0;
}