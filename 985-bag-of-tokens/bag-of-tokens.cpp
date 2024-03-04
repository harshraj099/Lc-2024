class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int left=0,right=tokens.size()-1;
        sort(tokens.begin(),tokens.end());
        int ct=0;
        int ans=0;
        while(left<=right){
            if(tokens[left]<=power){
                ct++;
                power=power-tokens[left];
                left++;
                ans=max(ans,ct);
            }
          
               else if(ct>0){
                    ct--;
                    power+=tokens[right];
                    right--;
                }
            else break;
        }
        return ans;
    }
};