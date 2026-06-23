class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        priority_queue<pair<int, int>> maxHeap;
        for(auto it = freq.begin(); it != freq.end();it++) {
            maxHeap.push({it->second,it->first });
        }
        vector<int> ans;
        while(k--) {
            ans.push_back(  maxHeap.top().second );
            maxHeap.pop();
        }
        return ans;
    }
};
