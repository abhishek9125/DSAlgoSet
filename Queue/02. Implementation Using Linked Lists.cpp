class QueueNode {
    public:
        int data;
        QueueNode* next;

        QueueNode(int d) {
            data = d;
            next = NULL; 
        }
};

class LinkedListQueue {

private:
    QueueNode* start;
    QueueNode* end;

public:
    LinkedListQueue() {
        start = NULL;
        end = NULL;
    }
    
    void push(int x) {
        QueueNode* temp = new QueueNode(x);
        if(start == NULL) {
            start = temp;
            end = temp;
        } else {
            end->next = temp;
            end = temp;
        }
    }
    
    int pop() {
        if(!isEmpty()) {
            QueueNode* temp = start;
            int data = temp->data;

            start = start->next;

            delete temp;
            return data;
        }

        return -1;
    }
    
    int peek() {
        if(!isEmpty()) {
            return start->data;
        }
        return -1;
    }
    
    bool isEmpty() {
        return start == NULL;
    }
};