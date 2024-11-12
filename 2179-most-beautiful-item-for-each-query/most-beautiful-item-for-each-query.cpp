class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=items.size();
        sort(items.begin(), items.end());
        vector<int>ans;
        map<int,int>m;
        int max_beauty = 0;

        for(int i=0;i<n;i++){
            max_beauty=max(max_beauty,items[i][1]);
           m[items[i][0]]=max_beauty;
        }

       for (int q : queries) {
            auto it = m.upper_bound(q);
            if (it == m.begin()) {
                // No items with price <= q
                ans.push_back(0);
            } else {
                // Get the maximum beauty for items with price <= q
                --it;
                ans.push_back(it->second);
            }
        }

        return ans;
    }
};