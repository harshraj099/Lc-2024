class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)return false;

        map<int,int>m;
        for(auto it:hand)m[it]++;

        vector<int>unique;
        for(auto it:m)unique.push_back(it.first);

        sort(unique.begin(),unique.end());
       
       for(auto it:unique){
        if(m[it]>0){
        int check=m[it];
        for(int i=it;i<it+groupSize;i++){
           if(m[i]<check)return false;
           m[i]-=check;
        }
        }
       }
       return true;
    }
};