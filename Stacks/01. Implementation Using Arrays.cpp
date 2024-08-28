class ArrayStack {

private:
    int topIndex;
    int *stackArr;
    int capacity;

public:
    ArrayStack(int size = 1000) {
        capacity = size;
        topIndex = -1;
        stackArr = new int[capacity];
    }
    
    void push(int x) {
        if(topIndex != capacity - 1) {
            stackArr[++topIndex] = x;
        }
    }
    
    int pop() {
        if(!isEmpty()) {
            return stackArr[topIndex--];
        }
        return -1;
    }
    
    int top() {
        if(!isEmpty()) {
            return stackArr[topIndex];
        }
    }
    
    bool isEmpty() {
        return topIndex == -1;
    }
};