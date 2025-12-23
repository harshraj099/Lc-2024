class Solution {
    public int longestPalindrome(String s) {
         int fl=0;
         Map<Character,Integer>m=new HashMap();
         for(char ch:s.toCharArray()){
           m.put(ch,m.getOrDefault(ch,0)+1);
         }
         int res=0;

         for(char k:m.keySet()){
            res+=(m.get(k)/2)*2;
            if(m.get(k)%2==1)fl=1;
         }

         if(fl==1)res+=1;

         return res;
    }
}