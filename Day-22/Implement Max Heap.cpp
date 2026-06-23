class Solution{
public:

    vector<int> heap;

    void initializeHeap(){
        heap.clear();
    }

    void heapifyUp(int idx){

        while(idx > 0){

            int parent = (idx - 1) / 2;

            if(heap[parent] < heap[idx]){
                swap(heap[parent], heap[idx]);
                idx = parent;
            }
            else{
                break;
            }
        }
    }

    void heapifyDown(int idx){

        int n = heap.size();

        while(true){

            int left = 2 * idx + 1;
            int right = 2 * idx + 2;

            int largest = idx;

            if(left < n && heap[left] > heap[largest])
                largest = left;

            if(right < n && heap[right] > heap[largest])
                largest = right;

            // If both children are equal, prefer LEFT
            if(left < n && right < n &&
               heap[left] == heap[right] &&
               heap[left] > heap[largest]){
                largest = left;
            }

            if(largest == idx)
                break;

            swap(heap[idx], heap[largest]);
            idx = largest;
        }
    }

    void insert(int key){

        heap.push_back(key);

        heapifyUp(heap.size() - 1);
    }

    void changeKey(int index, int new_val){

        int oldVal = heap[index];

        heap[index] = new_val;

        if(new_val > oldVal)
            heapifyUp(index);
        else
            heapifyDown(index);
    }

    void extractMax(){

        if(heap.empty())
            return;

        swap(heap[0], heap.back());

        heap.pop_back();

        if(!heap.empty())
            heapifyDown(0);
    }

    bool isEmpty(){

        return heap.empty();
    }

    int getMax(){

        return heap[0];
    }

    int heapSize(){

        return heap.size();
    }
};
