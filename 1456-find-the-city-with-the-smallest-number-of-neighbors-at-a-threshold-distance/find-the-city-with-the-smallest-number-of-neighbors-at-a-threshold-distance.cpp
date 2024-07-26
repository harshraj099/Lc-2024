class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>v(n,vector<int>(n,INT_MAX));
	  for(auto it:edges){
            v[it[0]][it[1]]=it[2];
           v[it[1]][it[0]]=it[2];
        }

        for(int i=0;i<n;i++)v[i][i]=0;

	    for(int via=0;via<n;via++){
	          for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){     
                 if(v[via][j]==INT_MAX || v[i][via]==INT_MAX)continue;
	                v[i][j]=min(v[i][j],v[via][j]+v[i][via]);     
	        }
	    }
	    }
       int ans=INT_MAX,num=0;
        for(int i=0;i<n;i++){
            int tmp=0;
            for(int j=0;j<n;j++){
                if(i!=j && v[i][j]<=distanceThreshold){
                    tmp++;
                }
            }
            if(tmp<=ans){
                ans=tmp;
                num=max(num,i);
            }
        }
        return num;
    }
};