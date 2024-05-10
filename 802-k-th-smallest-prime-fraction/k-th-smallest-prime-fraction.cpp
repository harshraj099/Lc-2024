class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        map<double,pair<int,int>>m;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
         m.insert({(double)arr[i]/arr[j],{arr[i],arr[j]}});
            }
        }
        for(auto it:m){
          k--;
          if(k==0)return {it.second.first,it.second.second};  
        }
        return {};
    }
};