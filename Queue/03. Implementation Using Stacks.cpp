// Better Approach
class StackQueue {
public:
    stack<int> s1;
    stack<int> s2;
    StackQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int element = s2.top();
        s2.pop();
        return element;
    }
    
    int peek() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool isEmpty() {
        return (s1.size() == 0 && s2.size() == 0);
    }
};

// Aprroach 1
class StackQueue {
public:
    stack<int> s1;
    stack<int> s2;
    StackQueue() {
    }
    
    void push(int x) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int element = s1.top();
        s1.pop();
        return element;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool isEmpty() {
        return s1.size() == 0;
    }
};

