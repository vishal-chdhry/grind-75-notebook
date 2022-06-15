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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *ptr = head, here;
    int length = 0;
    while (ptr != NULL) {
      ptr = ptr->next;
      length++;
    }
    if (length == 1) return NULL;
    ptr = head;
    int pos = length - n - 1;
    if (pos < 0) return head->next;
    for (int i = 0; i < pos; i++) ptr = ptr->next;
    if (ptr->next != NULL) ptr->next = ptr->next->next;
    return head;
  }
};