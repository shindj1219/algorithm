class Solution {
  public:
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
      ListNode header(0);
      ListNode* cur_node = &header;
      while (l1 != NULL && l2 != NULL) {
        ListNode** next_node = (l1->val < l2->val ? &l1 : &l2);
        cur_node->next = *next_node;
        *next_node = (*next_node)->next;
        cur_node = cur_node->next;
      }
      cur_node->next = (l1 != NULL) ? l1 : l2;
      return header.next;
    }
};
