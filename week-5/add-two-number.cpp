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
    int count = (l1->val + l2->val) / 10;
    ListNode* head = new ListNode((l1->val + l2->val) % 10);
    ListNode *ptr = head, *ptr1 = l1->next, *ptr2 = l2->next;
    while (ptr1 != NULL && ptr2 != NULL) {
      ptr->next = new ListNode((ptr1->val + ptr2->val + count) % 10);
      count = (ptr1->val + ptr2->val + count) / 10;
      ptr = ptr->next;
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }
    while (ptr1 != NULL) {
      cout << count << ptr1->val;
      ptr->next = new ListNode((ptr1->val + count) % 10);
      count = (ptr1->val + count) / 10;
      ptr = ptr->next;
      ptr1 = ptr1->next;
    }
    while (ptr2 != NULL) {
      ptr->next = new ListNode((ptr2->val + count) % 10);
      count = (ptr2->val + count) / 10;
      ptr = ptr->next;
      ptr2 = ptr2->next;
    }
    if (count != 0) {
      ptr->next = new ListNode(count);
    }
    return head;
  }
};