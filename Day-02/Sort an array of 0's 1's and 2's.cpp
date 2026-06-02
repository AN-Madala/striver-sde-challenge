class Solution {
public:
    void swap(vector<int>&nums,int i, int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    void sortColors(vector<int>& nums) {
        int n= nums.size();
       int low=0,mid=0,high=n-1;
       while(mid<=high){
        if(nums[mid]==0){
            swap(nums,low,mid);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums,mid,high);
            high--;
        }
       } 
        
    }
};
