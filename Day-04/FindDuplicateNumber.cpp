class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int x : nums){
            if(mp.count(x)){
                return x;
            }
            mp[x]++;
        }

        return -1;
    }
};
