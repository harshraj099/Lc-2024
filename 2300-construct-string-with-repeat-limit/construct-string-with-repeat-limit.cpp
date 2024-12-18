class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<int, int> m;
        priority_queue<pair<int, int>> pq;

        // Count frequencies of each character
        for (char c : s) {
            m[c - 'a']++;
        }

        // Push characters into the priority queue
        for (auto it : m) {
            pq.push({it.first, it.second});
        }

        string res = "";

        while (!pq.empty()) {
           char ch=pq.top().first+'a';
           int val=pq.top().second;
           pq.pop();
           int ct=min(val,repeatLimit);
           res.append(ct,ch);
           val-=ct;
           if(val>0){
            if(pq.empty())break;
          char ch2=pq.top().first+'a';
           int val2=pq.top().second;
           pq.pop();
           res.push_back(ch2);
           val2--;
           if(val2>0)pq.push({ch2-'a',val2});
            pq.push({ch-'a',val});
           }
        }

        return res;
    }
};
