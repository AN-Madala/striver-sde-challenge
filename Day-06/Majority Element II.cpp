class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // size of the array
        int n = nums.size(); 
        
        // list of answers
        vector<int> result; 
        
        // declaring a map
        unordered_map<int, int> mpp;
        
        // least occurrence of the majority element
        int mini = int(n / 3) + 1;
        
        // storing the elements with its occurrence
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
            
            // checking if nums[i] is the majority element
            if (mpp[nums[i]] == mini) {
                result.push_back(nums[i]);
            }
            
            // if result size is equal to 2 break out of loop
            if (result.size() == 2) {
                break;
            }
        }
        return result;
    }
    
};
