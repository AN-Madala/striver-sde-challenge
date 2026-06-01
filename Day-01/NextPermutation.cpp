class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int bdI = -1 ;
        for(int i = nums.size()-2 ; i >= 0 ; i--){
            if(nums[i] < nums[i+1]){
                bdI =  i ;
                break ;
            }
        }
        if(bdI == -1) {
            reverse(nums.begin() , nums.end()) ;
            return ;
        }
        else{
            for(int j = nums.size() - 1; j > bdI ; j--){
                if(nums[j] > nums[bdI]){
                    swap(nums[j], nums[bdI]) ;
                    break ;
                }
            }
        }
        reverse(nums.begin() + bdI + 1 , nums.end()) ;
    }
};
