/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) return false;
    ListNode *ptr1 = head, *ptr2 = head->next;
    int count = 0;
    while (count < 1e5) {
      if (ptr1 == ptr2)
        return true;
      else {
        if (ptr1->next == NULL) return false;
        ptr1 = ptr1->next;
        if (ptr2->next == NULL || ptr2->next->next == NULL) return false;
        ptr2 = ptr2->next->next;
      }
      count++;
    }
    return false;
  }
};