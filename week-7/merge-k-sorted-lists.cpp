class Solution {
  struct comp {
    bool operator()(pair<ListNode*, int>& l, pair<ListNode*, int>& r) {
      return l.first->val > r.first->val;
    }
  };

 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<pair<ListNode*, int>, vector<pair<ListNode*, int>>, comp>
        minH;
    ListNode* ans = new ListNode(0);
    ListNode* head = ans;
    for (int i = 0; i < lists.size(); i++)
      if (lists[i]) minH.push({lists[i], i});
    while (!minH.empty()) {
      auto tp = minH.top();
      minH.pop();
      if (lists[tp.second]->next) {
        minH.push({lists[tp.second]->next, tp.second});
        lists[tp.second] = lists[tp.second]->next;
      }
      head->next = tp.first;
      head = head->next;
    }
    return ans->next;
  }
};