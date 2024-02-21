class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
       int ct=0;
       while(left!=right){
        //    if(left==right)break;
          left=left>>1;
          right=right>>1;
           ct++;
       }
       return left<<ct;
    }
};