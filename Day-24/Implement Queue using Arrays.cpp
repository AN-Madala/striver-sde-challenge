class ArrayQueue {
public:

    vector<int> arr;

    int front;
    int rear;

    ArrayQueue() {

        front = 0;
        rear = -1;
    }

    void push(int x) {

        arr.push_back(x);
        rear++;
    }

    int pop() {

        int val = arr[front];
        front++;

        return val;
    }

    int peek() {
        return arr[front];
    }

    bool isEmpty() {
        return front > rear;
    }
};
