#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
//    Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//    Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:

    bool solution_search(ListNode* head, TreeNode* root) {

        // we know head will equal root so check the left and right first
        // ListNode* tmp = head->next;

        // EDIT: might want to get rid of above assumption for generalizability
        // and new queue method
        ListNode* tmp = head;
        TreeNode* tree_tracker = root;
        bool found_flag = false;

        // need to reset list head if we run into deadend
        // EDIT: this ended up not working out, we also need a way
        // to reach the list pointer associated with the tree node


        stack<pair<TreeNode*, ListNode *>> to_be_searched;
        to_be_searched.push({root, head});

 
        while (!to_be_searched.empty()) {
            auto curr_node = to_be_searched.top().first;
            auto curr_list = to_be_searched.top().second;
            to_be_searched.pop();

            while (curr_list && curr_node) {
                if (curr_node->val != curr_list->val) {
                    break;
                }
                curr_list = curr_list->next;

                if (curr_list) {
                    if (curr_node->left) {
                        to_be_searched.push({curr_node->left, curr_list});
                    }
                    if (curr_node->right) {
                        to_be_searched.push({curr_node->right, curr_list});
                    }
                    break;
                }
            }
            if (!curr_list) {
                return true;
            }

            // // check if right matches next in list
            // if (tree_tracker->right && tmp->next && tmp->next->val == tree_tracker->right->val) {
            //     to_be_searched.push({tree_tracker->right, curr_list});
            //     found_flag = true;
            // }
            // // check if left matches next in list
            // if (tree_tracker->left && tmp->next && tmp->next->val == tree_tracker->left->val) {
            //     to_be_searched.push({tree_tracker->left, curr_list});
            //     found_flag = true;
            // }
            // // solution check
            // if (tmp->next == nullptr && tree_tracker->val == tmp->val) {
            //     return true;
            // }

            // // reset if no match was found
            // if (!found_flag) {
            //     tmp = head->next;
            // }
            // else {
            //     tmp = tmp->next;
            // }
            // found_flag = false;
        }
        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        // just dfs for the first element of head and then do a dfs 

        queue<TreeNode*> to_be_searched;

        // for dfs we can just pushback and look at the front element until to_be_searched is empty
        to_be_searched.push(root);

        while (!to_be_searched.empty()) {

            TreeNode * curr_node = to_be_searched.front();
            to_be_searched.pop();

            if (curr_node->val == head->val) {
                if (solution_search(head, curr_node)) {
                    return true;
                }
            }

            if (curr_node->left != nullptr) {
                to_be_searched.push(curr_node->left);
            }
            if (curr_node->right != nullptr) {
                to_be_searched.push(curr_node->right);
            }
        }
        return false;
    }
};

TreeNode* buildBinaryTree(const std::vector<int>& values) {
    if (values.empty() || values[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(values[0]);
    std::queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    size_t i = 1;
    while (i < values.size()) {
        TreeNode* currentNode = nodeQueue.front();
        nodeQueue.pop();

        // Add left child
        if (i < values.size() && values[i] != -1) {
            currentNode->left = new TreeNode(values[i]);
            nodeQueue.push(currentNode->left);
        }
        i++;

        // Add right child
        if (i < values.size() && values[i] != -1) {
            currentNode->right = new TreeNode(values[i]);
            nodeQueue.push(currentNode->right);
        }
        i++;
    }

    return root;
}

ListNode* buildLinkedList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}


int main() {

    Solution sol;

    vector<int> tmp_head = {10,2,3,3,5,8,3,10,7,5,5};
    vector<int> tmp_root = {10,4,2,-1,2,2,3,-1,-1,8,3,9,3,9,-1,7,-1,2,3,5,5,10,1,-1,-1,9,4,1,7,7,-1,8,8,-1,-1,-1,-1,-1,-1,-1,-1,9,10,-1,-1,-1,1,3,5,-1,4,8,7,10,-1,-1,2,10,3,9,5,-1,-1,-1,6,-1,6,-1,-1,-1,-1,7,-1,6,-1,-1,6,-1,-1,-1,-1,3,6,-1,5,-1,-1,-1,-1,6,-1,-1,-1,5,-1,-1,-1,4};

    TreeNode* root = buildBinaryTree(tmp_root);
    ListNode* head = buildLinkedList(tmp_head);
    cout << "Result: "<< sol.isSubPath(head, root) << "\n";

    return 0;
}