class Solution {
public:

    vector<int> maxOfMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() &&
                  arr[st.top()] >= arr[i]) {

                st.pop();
            }
            if(st.empty())
                left[i] = -1;
            else
                left[i] = st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();

        for(int i = n-1; i >= 0; i--) {

            while(!st.empty() &&
                  arr[st.top()] >= arr[i]) {

                st.pop();
            }
            if(st.empty())
                right[i] = n;
            else
                right[i] = st.top();
            st.push(i);
        }
        vector<int> ans(n+1, INT_MIN);
        for(int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            ans[len] =
            max(ans[len], arr[i]);
        }
        for(int i = n-1; i >= 1; i--) {

            ans[i] =
            max(ans[i], ans[i+1]);
        }

        vector<int> res;

        for(int i = 1; i <= n; i++) {

            res.push_back(ans[i]);
        }

        return res;
    }
};
