class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double>ans;
       unordered_map<string, vector<pair<string, double>>> adj;

        
        int i=0;
        for(auto it:equations){
            string n=it[0];
            string d=it[1];
             adj[n].push_back({d, values[i]});
            adj[d].push_back({n, 1.0 / values[i]});
            i++;
        }

        for(auto it:queries){
            string num=it[0];
            string den=it[1];

            if(adj.find(num)==adj.end()){
                ans.push_back(-1);
                continue;
            }
            int fl=0;
            queue<pair<string,double>>q;
            unordered_set<string>s;
            q.push({num,1});
            s.insert(num);
            while(!q.empty()){
                string node=q.front().first;
                double wt=q.front().second;
                q.pop();
                if(node==den){
                    ans.push_back(wt);
                   fl=1;
                    break;
            }

                for(auto neigh:adj[node]){
                    if(s.find(neigh.first)==s.end()){
                        s.insert(neigh.first);
                        q.push({neigh.first,neigh.second*wt});
                    }
                }
            }
            if(!fl){
                ans.push_back(-1);
            }
        }

        return ans;
       
    }
};