#include <iostream>

/*
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode* result{nullptr};

      auto iter1{l1};
      auto iter2{l2};
      ListNode* node{nullptr};
      ListNode* prev{result};
      while(iter1 != nullptr && iter2 != nullptr) {
        if(iter1->val < iter2->val) {
          node = new ListNode(iter1->val);
          iter1 = iter1->next;
        } else {
          node = new ListNode(iter2->val);
          iter2 = iter2->next;
        }
        if(prev != nullptr) {
          prev->next = node;
        } else {
          result = node;
        }
        prev = node;
      }

      while(iter1 != nullptr) {
        node = new ListNode(iter1->val);
        if(prev != nullptr) {
          prev->next = node;
        } else {
          result = node;
        }
        prev = node;
        iter1 = iter1->next;
      }

      while(iter2 != nullptr) {
        node = new ListNode(iter2->val);
        if(prev != nullptr) {
          prev->next = node;
        } else {
          result = node;
        }
        prev = node;
        iter2 = iter2->next;
      }

      return result;
    }
};

int main() {
  Solution s;
  ListNode* l1 = new ListNode(4);
  ListNode* l2 = new ListNode(4);
  {
    ListNode* temp1 = new ListNode(2, l1);
    ListNode* temp2 = new ListNode(1, temp1);
    ListNode* temp3 = new ListNode(3, l2);
    ListNode* temp4 = new ListNode(1, temp3);
    l1 = temp2;
    l2 = temp4;
  }
  auto result{s.mergeTwoLists(l1, l2)};
  std::cout << "Result : [";
  while(result != nullptr) {
    std::cout << result->val << " ";
    result = result->next;
  }
  std::cout << "]" << std::endl;
  return 0;
}
