class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max1=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
                max1=max(max1,cnt);
            }
            else{
                cnt=0;
            }
        }
        return max1;
    }
};
