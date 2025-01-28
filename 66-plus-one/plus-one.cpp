class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        int n=digits.size();
        if(digits[n-1]+1<10){
             digits[n-1]+=1;
            return digits;
        }
        else{
            int temp=digits[n-1]+1;
             digits[n-1]=temp%10;
            int carry=temp/10;
            int i=n-2;
            while(carry && i>=0){
               int temp=digits[i]+carry;
               digits[i]=temp%10;
               carry=temp/10;
               i--;
            }
            if(!carry)return digits;
       digits.insert(digits.begin(),carry);
       return digits;
        }
    }
};