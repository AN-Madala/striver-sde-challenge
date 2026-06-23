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

            int left = 2*idx + 1;
            int right = 2*idx + 2;

            int largest = idx;

            if(left < n &&
               heap[left] > heap[largest])
                largest = left;

            if(right < n &&
               heap[right] > heap[largest])
                largest = right;

            if(largest == idx)
                break;

            swap(heap[idx],
                 heap[largest]);

            idx = largest;
        }
    }

    void insert(int x){

        heap.push_back(x);

        heapifyUp(heap.size()-1);
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

    vector<int> maxSumCombinations(
        vector<int>& nums1,
        vector<int>& nums2,
        int k) {

        int n = nums1.size();

        for(int i = 0; i < n; i++){

            for(int j = 0; j < n; j++){

                insert(
                    nums1[i] + nums2[j]
                );
            }
        }

        vector<int> ans;

        while(k--){

            ans.push_back(getMax());

            extractMax();
        }

        return ans;
    }
};
