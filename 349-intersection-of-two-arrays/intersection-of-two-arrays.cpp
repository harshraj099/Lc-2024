class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m;
        for(auto it:nums1){
            m[it]++;
        }
        vector<int>v;
        set<int>s;
        for(auto it:nums2){
         if(m.find(it)!=m.end())s.insert(it);
        }
          for(auto it:s){
         v.push_back(it);
        }
        return v;
    }
};