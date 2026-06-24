class ArrayStack {
public:

    vector<int> arr;
    int topIndex;

    ArrayStack() {

        topIndex = -1;
    }

    void push(int x) {

        arr.push_back(x);
        topIndex++;
    }

    int pop() {
        int val = arr[topIndex];
        arr.pop_back();
        topIndex--;
        return val;
    }

    int top() {
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};
