class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) 
    {
        long long ans=1;
          if(w==0)
          {
             set<long long>s;
             vector<long long int>v;
             for(long long int i=0;i<points.size();i++)
              {
                v.push_back(points[i][0]);
              }
             for(long long int i=0;i<v.size();i++)
             {
                s.insert(v[i]);
             }
             ans=s.size();
          }
          else
          {
              vector<long long int>v;
              for(long long int i=0;i<points.size();i++)
              {
                v.push_back(points[i][0]);
              }
              sort(v.begin(),v.end());
              long long int a=v[0];
              for(long long int i=0;i<v.size();i++)
              {
                  if(v[i]-a<=w)
                  {
                    continue;
                  }
                  else
                  {
                    a=v[i];
                    ans++;
                  }
              }

          }
          return ans;
        
    }
};