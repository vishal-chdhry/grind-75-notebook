class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if (head == NULL) return NULL;
    ListNode *ptr = head->next, *curr = head;
    while (ptr != NULL) {
      ListNode* nxt = ptr->next;
      if (nxt == NULL) break;
      ptr->next = ptr->next->next;
      nxt->next = curr->next;
      curr->next = nxt;
      curr = curr->next;
      ptr = ptr->next;
    }
    return head;
  }
};