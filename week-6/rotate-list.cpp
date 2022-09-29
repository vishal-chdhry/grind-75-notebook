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
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL) return NULL;
    ListNode *ptr1 = head, *ptr2 = head;
    int length = 0;
    while (ptr1 != NULL) {
      ptr1 = ptr1->next;
      length++;
    }
    ptr1 = head;
    while ((k--) % length) ptr2 = ptr2->next;
    while (ptr2->next != NULL) {
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }
    ptr2->next = head;
    ListNode* ans = ptr1->next;
    ptr1->next = NULL;
    return ans;
  }
};