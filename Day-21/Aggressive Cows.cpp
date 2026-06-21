class Solution {
public:

    bool canPlace(vector<int>& nums,int dist, int cows) {

        int cntCows = 1;
        int last = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] - last >= dist) {

                cntCows++;
                last = nums[i];
            }

            if(cntCows >= cows)
                return true;
        }

        return false;
    }

    int aggressiveCows(vector<int>& nums,int k) {

        sort(nums.begin(), nums.end());

        int low = 1;
        int high = nums.back() - nums.front();

        while(low <= high) {

            int mid =
                low + (high - low) / 2;

            if(canPlace(nums, mid,  k)) {

                low = mid + 1;
            }
            else {

                high = mid - 1;
            }
        }

        return high;
    }
};
