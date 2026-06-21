class Solution {
public:

    int countStudents(vector<int>& nums,
                      int pages) {

        int students = 1;
        long long pagesStudent = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(pagesStudent + nums[i] <= pages) {

                pagesStudent += nums[i];
            }
            else {

                students++;
                pagesStudent = nums[i];
            }
        }

        return students;
    }

    int findPages(vector<int>& nums, int m) {

        int n = nums.size();

        if(m > n)
            return -1;

        int low = *max_element(nums.begin(),
                         nums.end());

        int high =  accumulate(nums.begin(), nums.end(),  0);

        while(low <= high) {

            int mid =
                low + (high - low) / 2;

            int students =  countStudents(nums, mid);

            if(students > m) {

                low = mid + 1;
            }
            else {

                high = mid - 1;
            }
        }

        return low;
    }
};
