class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<char>v={'A','C','G','T'};

        queue<pair<string,int>>q;
        q.push({startGene,0});
        vector<int>vis(bank.size(),0);
        while(!q.empty()){
            string s=q.front().first;
            int val=q.front().second;
            q.pop();
            if(s==endGene)return val;

            for(int i=0;i<bank.size();i++){
            int diff=0;
            string it=bank[i];
            if(!vis[i]){
              for(int j=0;j<8;j++){
                if(s[j]!=it[j])diff++;
            }
            if(diff==1){
                vis[i]=1;
                q.push({it,val+1});
            }
            }

            }
           
        }

        return -1;
    }
};