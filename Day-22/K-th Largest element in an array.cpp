class Solution {
public:

    vector<int> heap;

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

            if(largest == idx)
                break;

            swap(heap[idx], heap[largest]);
            idx = largest;
        }
    }

    void insert(int x){

        heap.push_back(x);

        heapifyUp(heap.size() - 1);
    }

    void extractMax(){

        swap(heap[0], heap.back());

        heap.pop_back();

        if(!heap.empty())
            heapifyDown(0);
    }

    int getMax(){

        return heap[0];
    }

    int kthLargestElement(vector<int>& nums, int k) {

        for(int num : nums){
            insert(num);
        }

        for(int i = 1; i < k; i++){
            extractMax();
        }

        return getMax();
    }
};
