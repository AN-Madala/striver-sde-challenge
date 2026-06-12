class Solution {
public:
    // Function to count subarrays with given XOR
    int countSubarrays(vector<int>& A, int k) {

        unordered_map<int, int> freq;

        freq[0] = 1;


        int prefixXor = 0;

        int count = 0;

   
        for (int num : A) {

            prefixXor ^= num;


            int target = prefixXor ^ k;


            if (freq.find(target) != freq.end()) {
                count += freq[target];
            }

            freq[prefixXor]++;
        }
        return count;
    }
};
