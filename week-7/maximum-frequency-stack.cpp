class FreqStack {
 public:
  priority_queue<pair<int, pair<int, int>>> q;
  unordered_map<int, int> freq;
  int time = 0;
  FreqStack() {}

  void push(int val) {
    q.emplace(make_pair(++freq[val], make_pair(++time, val)));
  }

  int pop() {
    auto a = q.top();
    q.pop();
    int x = a.second.second;
    freq[x]--;
    return x;
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */