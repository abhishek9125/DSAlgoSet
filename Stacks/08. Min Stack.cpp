
class MinStack {

private:
  stack<pair<int, int>> s;

public:
    MinStack() {
    }

  void push(int value) {
    if(s.empty()) {
      s.push({ value, value });
      return;
    }

    int mini = min(getMin(), value);
    s.push({ value, mini });
  }

  void pop() {
    s.pop();
  }

  int top() {
    return s.top().first;
  }

  int getMin() {
    return s.top().second;
  }
};