class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>m;
        for(auto it:arr){
            m[it]++;
        }
        multiset<int>s;
        for(auto it:m){
            s.insert(it.second);
        }
      int ct=0;
        for(auto it:s){
          if(k-it>=0) {ct++;
              k=k-it;}
              else break;
        }
        return s.size()-ct;
    }
};