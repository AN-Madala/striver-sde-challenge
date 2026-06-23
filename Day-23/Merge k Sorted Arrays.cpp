class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        int m=mat.size();
        int n=mat[0].size();
        priority_queue<int,vector<int>, greater<int>> minHeap;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                minHeap.push(mat[i][j]);
        }}
         vector<int> ans;

        while(!minHeap.empty()) {

            ans.push_back(minHeap.top());
            minHeap.pop();
        }

        return ans;
    }
};
