/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto l1_iter{l1};
        auto l2_iter{l2};
        auto round_up{0};
        ListNode* result{nullptr};
        ListNode* iter{nullptr};
        while (l1_iter != nullptr && l2_iter != nullptr) {
            auto sum{l1_iter->val + l2_iter->val + round_up};
            auto units{sum%10};
            round_up = sum/10;
            
            auto node{new ListNode(units)};
            if(result == nullptr) {
                result = node;
            } else {
                iter->next = node;
            }
            iter = node;
            l1_iter = l1_iter->next;
            l2_iter = l2_iter->next;
        }
        while(l1_iter != nullptr) {
            auto sum{l1_iter->val + round_up};
            auto units{sum%10};
            round_up = sum/10;
            auto node{new ListNode(units)};
            iter->next = node;
            iter = node;
            l1_iter = l1_iter->next;
        }
        while(l2_iter != nullptr) {
            auto sum{l2_iter->val + round_up};
            auto units{sum%10};
            round_up = sum/10;
            auto node{new ListNode(units)};
            iter->next = node;
            iter = node;
            l2_iter = l2_iter->next;
        }
        if(round_up == 1) {
            auto node{new ListNode(round_up)};
            iter->next = node;
        }
        return result;
    }
};
