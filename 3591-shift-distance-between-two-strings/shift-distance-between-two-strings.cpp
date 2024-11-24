class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
         long long ans=0;
        vector<long long>prefixsum(26,0);
           prefixsum[0]=nextCost[0];
        for(int i=1;i<26;i++){
        prefixsum[i]=prefixsum[i-1]+nextCost[i];
        }
        vector<long long>suffixsum(26,0);
       suffixsum[25]=previousCost[25];
        for(int i=24;i>=0;i--){
        suffixsum[i]=suffixsum[i+1]+previousCost[i];
        }
        for(int i=0;i<s.size();i++){
            char ini=s[i];
            char aft=t[i];
            if(aft==ini)continue;
             long long mini= LLONG_MAX;;
            if (aft > ini) {
                mini = min(mini, (long long)(prefixsum[(aft - 'a') - 1] - (((ini - 'a') > 0) ? prefixsum[ini - 'a' - 1] : 0)));
                mini = min(mini, (long long)(suffixsum[0]-suffixsum[(ini-'a')+1]+((aft-'a'<25)?suffixsum[aft-'a'+1]:0)));
                // cout<<mini<<endl;
            } else {
                mini = min(mini, (long long)(suffixsum[aft-'a'+1]-((ini-'a'<25)?suffixsum[ini-'a'+1]:0)));
                // cout<<mini<<endl;
                mini = min(mini, (long long)(prefixsum[25]-prefixsum[ini-'a'-1]+((aft - 'a' > 0) ? prefixsum[(aft - 'a' )- 1] : 0)));
            //   cout<<mini<<endl;
            }
            ans+=mini;
        }
        return ans;
    }
};