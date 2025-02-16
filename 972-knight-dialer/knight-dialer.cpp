class Solution {
public:
    const int Mod=1e9+7;
    vector<pair<int,int>>dirc={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    int f(int i,int j,vector<vector<int>>&dial,int n,vector<vector<vector<int>>>&dp){
        if(n==0)return 1;

        if(dp[i][j][n]!=-1)return dp[i][j][n];
        // take
        long long take=0;
        for(auto it:dirc){
            int r=i+it.first;
            int c=j+it.second;

            if(r>=0 && r<4 && c>=0 && c<3 && dial[r][c]!=-1){
                take=(take+f(r,c,dial,n-1,dp))%Mod;
            }
        }

        return dp[i][j][n]=take;
    }
    int knightDialer(int n) {
        vector<vector<int>>dial={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        long long sum=0;
        vector<vector<vector<int>>>dp(4, vector<vector<int>>(3, vector<int>(n, -1)));
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(dial[i][j]!=-1){
                   sum=(sum+f(i,j,dial,n-1,dp))%Mod;
                }
            }
        }
        return sum;
    }
};