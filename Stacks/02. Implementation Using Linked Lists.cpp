class StackNode {
    public:
        int data;
        StackNode* next;

        StackNode(int d) {
            data = d;
            next = NULL;
        }
};

class LinkedListStack {

private:
    StackNode* topPointer;
    int size;

public:
    LinkedListStack() {
        topPointer = NULL;
        size = 0;
    }
    
    void push(int x) {
        StackNode* temp = new StackNode(x);
        temp->next = topPointer;
        topPointer = temp;
        size++;
    }
    
    int pop() {
        if(!isEmpty()) {
            StackNode* temp = topPointer;
            topPointer = topPointer->next;
            temp->next = NULL;
            int ans = temp->data;
            delete temp;
            size--;
            return ans;
        }

        return -1;
    }
    
    int top() {
        if(!isEmpty()) {
            return topPointer->data;
        }
        return -1;
    }
    
    bool isEmpty() {
        return topPointer == NULL;
    }
};