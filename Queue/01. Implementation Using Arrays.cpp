class ArrayQueue {

private:
    int front;
    int rear;
    int capacity;
    int currentCapacity;
    int *queueArray;

public:
    ArrayQueue(int size = 100) {
        front = 0;
        rear = 0;
        currentCapacity = 0;
        capacity = size;
        queueArray = new int[capacity];
    }
    
    void push(int x) {
        if(currentCapacity == capacity) {
            return;
        }
        queueArray[rear] = x;
        rear = (rear + 1) % capacity;
        currentCapacity++;
    }
    
    int pop() {
        if(!isEmpty()) {
            int element = queueArray[front];
            front = (front + 1) % capacity;
            currentCapacity--;
            return element;
        }

        return -1;
    }
    
    int peek() {
        if(!isEmpty()) {
            return queueArray[front];
        }
        return -1;
    }
    
    bool isEmpty() {
        return currentCapacity == 0;
    }
};