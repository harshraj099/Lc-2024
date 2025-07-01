class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else{
                while(!st.empty() && st.top()<abs(asteroids[i])){
                    st.pop();
                }
                if(!st.empty() && st.top()>abs(asteroids[i]))continue;
               else if(!st.empty() && st.top()==abs(asteroids[i])){
                st.pop();
               }
               else {
                ans.push_back(asteroids[i]);
               }
            }
        }
        vector<int>temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        for(auto it:temp)ans.push_back(it);
        return ans;
    }
};