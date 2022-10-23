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
  ListNode* reverse(ListNode* head) {
    if (head == NULL) return NULL;
    ListNode* current = head;
    ListNode *prev = NULL, *next = NULL;

    while (current != NULL) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    return prev;
  }

 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* CAP = (ListNode*)malloc(sizeof(ListNode));
    CAP->next = head;
    CAP->val = -1;

    ListNode *ptr_to_next = CAP->next, *ptr = CAP, *temp_head = NULL;
    ListNode* last_group = CAP;

    while (ptr->next != NULL) {
      temp_head = ptr->next;
      last_group = ptr;

      int i = k;
      while (i-- && ptr->next != NULL) ptr = ptr->next;
      if (i >= 0) break;

      ptr_to_next = ptr->next;
      ptr->next = NULL;
      last_group->next = reverse(temp_head);

      temp_head->next = ptr_to_next;
      ptr = temp_head;
    }
    return CAP->next;
  }
};