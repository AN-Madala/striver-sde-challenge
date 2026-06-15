class Solution {
public:
    double fractionalKnapsack(vector<long long>& val,
                              vector<long long>& wt,
                              long long capacity) {

        int n = val.size();

        vector<pair<double, int>> items;

        for(int i = 0; i < n; i++) {
            double ratio = (double)val[i] / wt[i];
            items.push_back({ratio, i});
        }

        sort(items.begin(), items.end(),
             [](auto &a, auto &b) {
                 return a.first > b.first;
             });

        double ans = 0.0;

        for(auto &item : items) {

            int idx = item.second;

            if(wt[idx] <= capacity) {
                ans += val[idx];
                capacity -= wt[idx];
            }
            else {
                ans += item.first * capacity;
                break;
            }
        }

        return ans;
    }
};
