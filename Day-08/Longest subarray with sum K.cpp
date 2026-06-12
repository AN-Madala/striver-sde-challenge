class Solution {
public:
    int longestSubarray(vector<int> &nums, int k) {
        unordered_map<long long, int> mp;

        long long prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            // Subarray from 0 to i
            if (prefixSum == k) {
                maxLen = i + 1;
            }

            // Check if (prefixSum - k) exists
            if (mp.find(prefixSum - k) != mp.end()) {
                maxLen = max(maxLen, i - mp[prefixSum - k]);
            }

            // Store first occurrence only
            if (mp.find(prefixSum) == mp.end()) {
                mp[prefixSum] = i;
            }
        }

        return maxLen;
    }
};
