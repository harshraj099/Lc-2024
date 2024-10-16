class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
       if(a>0) pq.push({a,'a'});
       if(b>0) pq.push({b,'b'});
      if(c>0)  pq.push({c,'c'});

        string ans="";

        while(!pq.empty()){
            int no=pq.top().first;
            char ch=pq.top().second;
                pq.pop();
                // cout<<ch;
            if(ans.size()>=2 && ans.back()==ch && ans[ans.size()-2]==ch){
                if(pq.empty())break;
                    int no2=pq.top().first;
                    char ch2=pq.top().second;
                      pq.pop();
                      ans+=ch2;
                      no2--;
                    if(no2>0)pq.push({no2,ch2});
                    pq.push({no,ch});
            }
            else {
                ans+=ch;
                no--;
                if(no>0)pq.push({no,ch});
            }
        }
        return ans;
    }
};