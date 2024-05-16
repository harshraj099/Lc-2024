class Solution {
public:
 	
// Sieve of Eratosthenes
    int countPrimes(int n) {
       vector<int>vis(n+1,1);

        for(int i=2;i*i<=n;i++){
            for(int j=i*i;j<=n;j+=i){
                if(j%i==0)vis[j]=0;
            }
        }
        int ct=0;
        for(int i=2;i<n;i++){
            if(vis[i])ct++;
        }

        return ct;
    }
};