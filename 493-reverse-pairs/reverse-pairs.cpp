class Solution {
public:
     void solve(vector<int> &arr,int l,int mid,int r,int &ct){
         int j = mid + 1;
    for (int i = l; i <= mid; i++) {
        while (j <= r && (long long)arr[i] > 2LL * arr[j]) {
            j++;
        }
        ct += (j - (mid + 1));
    }
        int ptr=mid+1;
        vector<int>temp;
        int base=l,limit=r;;
        while(l<=mid && ptr<=r){
            if(arr[l]>arr[ptr]){
            //    if(arr[l]>2LL*arr[ptr]) ct+=(mid-l+1);
                temp.push_back(arr[ptr]);
                ptr++;
            }
            else {
                temp.push_back(arr[l]);
                l++;
            }
        }
        
        while(l<=mid){
             temp.push_back(arr[l]);
             l++;
        }
        
         while(ptr<=r){
             temp.push_back(arr[ptr]);
             ptr++;
        }
        
        for(int i=base;i<=limit;i++){
            arr[i]=temp[i-base];
        }
        
    }
    
    void merge(vector<int> &arr,int l,int r,int &ct){
        if(l>=r)return;
        
        int mid=(l+r)/2;
        merge(arr,l,mid,ct);
        
        merge(arr,mid+1,r,ct);
        
       solve(arr,l,mid,r,ct);
       
    }
    int reversePairs(vector<int>& nums) {
        int ct=0;
        merge(nums,0,nums.size()-1,ct);
        return ct;
    }
};