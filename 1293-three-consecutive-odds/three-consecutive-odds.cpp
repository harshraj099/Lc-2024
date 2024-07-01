class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int ct=3;
        for(auto it:arr){
            if(it%2!=0){ct--;
            if(ct==0)return true;}
            else ct=3;
        }
        return false;
    }
};