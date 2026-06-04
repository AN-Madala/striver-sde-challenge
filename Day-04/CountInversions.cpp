class Solution {
public:
    long long merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;
        long long cnt = 0;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                cnt += (mid - left + 1);
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return cnt;
    }

    long long mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;

        long long cnt = 0;
        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);
        cnt += merge(nums, low, mid, high);

        return cnt;
    }

    long long numberOfInversions(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
