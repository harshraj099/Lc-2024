class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>m;
        for(auto it:arr){
            m[it]++;
        }
        multimap<int,int>mp;
        for(auto it:m){
            mp.insert({it.second,it.first});
        }
      int ct=0;
        for(auto it:mp){
          if(k-it.first>=0) {ct++;
              k=k-it.first;}
              else break;
        }
        return mp.size()-ct;
    }
};