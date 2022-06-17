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
  ListNode* swapPairs(ListNode* head) {
    ListNode top = ListNode(-1, head);
    ListNode *ptr = &top, *ans = ptr;
    while (ptr->next != NULL && ptr->next->next != NULL) {
      ListNode* temp = ptr->next;
      ptr->next = ptr->next->next;
      temp->next = ptr->next->next;
      ptr->next->next = temp;
      ptr = ptr->next->next;
    }
    return ans->next;
  }
};