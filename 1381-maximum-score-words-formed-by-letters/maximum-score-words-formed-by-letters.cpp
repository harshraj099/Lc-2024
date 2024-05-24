class Solution {
public:
    int f(int idx,vector<string>& words,vector<int>&score,vector<int>m){
        if(idx==0){
            string end=words[0];
            int scr=0;
            for(char it:end){
                if(m[it-'a']>0){
                    scr+=score[it-'a'];
                    m[it-'a']-=1;
                }
                else {
                    return 0;
                }
            }
            return scr;
        }

        string mid=words[idx];
        int midscr=0;
        vector<int>temp=m;
        // take
        for(int i=0;i<mid.size();i++){
             if(m[mid[i]-'a']>0){
                    midscr+=score[mid[i]-'a'];
                    m[mid[i]-'a']-=1;
                }
                else {
                    midscr=0;
                    break;
                }
        }
      int take=midscr+f(idx-1,words,score,m);

        // leave
        int leave=0+f(idx-1,words,score,temp);

        return max(take,leave);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>m(26,0);
        for(int i=0;i<letters.size();i++)m[letters[i]-'a']++;
        int n=words.size();
        return f(n-1,words,score,m);
    }
};