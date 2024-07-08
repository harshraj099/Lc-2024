class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1;i<=n;i++)q.push(i);

        while(q.size()>1){
            for(int ct=1;ct<k;ct++){
                int node=q.front();
                q.push(node);
                q.pop();
            }
            q.pop();
        }

        return q.front();
    }
};