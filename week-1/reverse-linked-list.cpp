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
  ListNode* reverseList(ListNode* head) {
    ListNode *HEAD = new ListNode(-1), *valueThatShouldBeHere = NULL,
             *valueThatWasHere = NULL;
    HEAD->next = head;
    while (HEAD->next != NULL) {
      valueThatWasHere = HEAD->next->next;
      HEAD->next->next = valueThatShouldBeHere;
      valueThatShouldBeHere = HEAD->next;
      HEAD->next = valueThatWasHere;
    }
    head = valueThatShouldBeHere;
    return head;
  }
};