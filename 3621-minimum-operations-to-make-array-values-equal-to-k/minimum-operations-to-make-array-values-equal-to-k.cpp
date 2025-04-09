class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        set<int>s;
        for(auto it:nums){
            if(it==k)continue;
            if(it<k)return -1;
            else s.insert(it);
        }

        return s.size();
    }
};