class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> res;
        vector<pair<int,int>>map;
        multimap<int,int>m;
        for(int i=0;i<nums.size();i++){
            string s=to_string(nums[i]);
            string st="";
            for(int i=0;i<s.size();i++){
                st+=to_string(mapping[s[i]-'0']);
            }
            m.insert({stoi(st),nums[i]});
            // map.push_back({stoi(st),nums[i]});
        }
        // sort(map.begin(),map.end());

        for(auto it:m){
            res.push_back(it.second);
        }

        return res;
    }
};