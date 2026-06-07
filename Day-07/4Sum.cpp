class Solution {
public:
  
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();
        set<vector<int>> st;  

        
        for (int i = 0; i < n; i++) {
           
            for (int j = i + 1; j < n; j++) {
                // HashSet to store numbers between j and k
                unordered_set<int> seen;

              
                for (int k = j + 1; k < n; k++) {
                    // Find required fourth number
                    long long required = (long long)target - arr[i] - arr[j] - arr[k];

                    // If required number is already in set, we found a quadruplet
                    if (seen.count(required)) {
                        vector<int> temp = {arr[i], arr[j], arr[k], (int)required};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }

                    // Add current third number into set
                    seen.insert(arr[k]);
                }
            }
        }

        // Convert set into vector and return
        return vector<vector<int>>(st.begin(), st.end());
    }
};
