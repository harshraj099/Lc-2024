class Solution {
public:
        int f(int idx,vector<pair<int,int>>adj[],int k,int n){
        vector<int>dis(n,1e9);
        vector<int>vis(n,0);
        vis[idx]=1;
        dis[idx]=0;
            queue<pair<int,int>>q;
            q.push({idx,0});
            int ct=0;
            while(!q.empty()){
                int node=q.front().first;
                int wt=q.front().second;
                q.pop();
                for(auto it:adj[node]){
                    if(wt+it.second<=k && wt+it.second<dis[it.first]){
                        if(!vis[it.first])ct++;
                        vis[it.first]=1;
                        dis[it.first]=wt+it.second;
                        q.push({it.first,dis[it.first]});
                    }
                }
            }
           return ct;
        }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {


            vector<pair<int,int>>adj[n];

          for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
          adj[it[1]].push_back({it[0],it[2]});
        }

            int maxi=1e9;
            int res;
        for(int i=0;i<n;i++){
           int cnt=f(i,adj,distanceThreshold,n);
        //    cout<<cnt;
           if(cnt<=maxi){
            maxi=cnt;
            res=i;
           }
        }

        return res;



    //     vector<vector<int>>v(n,vector<int>(n,INT_MAX));
	//   for(auto it:edges){
    //         v[it[0]][it[1]]=it[2];
    //        v[it[1]][it[0]]=it[2];
    //     }

    //     for(int i=0;i<n;i++)v[i][i]=0;

	//     for(int via=0;via<n;via++){
	//           for(int i=0;i<n;i++){
	//         for(int j=0;j<n;j++){     
    //              if(v[via][j]==INT_MAX || v[i][via]==INT_MAX)continue;
	//                 v[i][j]=min(v[i][j],v[via][j]+v[i][via]);     
	//         }
	//     }
	//     }
    //    int ans=INT_MAX,num=0;
    //     for(int i=0;i<n;i++){
    //         int tmp=0;
    //         for(int j=0;j<n;j++){
    //             if(i!=j && v[i][j]<=distanceThreshold){
    //                 tmp++;
    //             }
    //         }
    //         if(tmp<=ans){
    //             ans=tmp;
    //             num=max(num,i);
    //         }
    //     }
    //     return num;
    }
};