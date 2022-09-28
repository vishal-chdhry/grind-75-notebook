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
  void reorderList(ListNode* head) {
    ListNode *ptr = head, *temp = NULL;
    int length = 0;
    while (ptr != NULL) {
      length++;
      ptr = ptr->next;
    }
    length /= 2;
    stack<ListNode*> s;
    ptr = head;
    while (length--) {
      ptr = ptr->next;
    }

    temp = ptr->next;
    ptr->next = NULL;
    ptr = temp;

    while (ptr != NULL) {
      s.push(ptr);
      ptr = ptr->next;
    }
    ptr = head;
    while (!s.empty()) {
      temp = ptr->next;
      ptr->next = s.top();
      s.pop();
      ptr->next->next = temp;
      ptr = ptr->next->next;
    }
  }
};