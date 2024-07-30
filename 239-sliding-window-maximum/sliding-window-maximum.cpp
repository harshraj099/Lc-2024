class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0,j=0;
       priority_queue<pair<int,int>> q;
        vector<int> ans;
        
        while(j<nums.size())
        {
           
            if(j-i+1<k){
                q.push({nums[j],j});
                j++;
            }
            else {
                 q.push({nums[j],j});
                while(!q.empty() && j-q.top().second+1>k)q.pop();
                ans.push_back(q.top().first);
                i++;
                j++;
            }
        }
     return ans;
        
    }
};