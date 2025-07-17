class MedianFinder {
public:
    vector<int>v;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       if(v.empty()) v.push_back(num);
       else{
        int i=0,fl=0;
        while(i<v.size()){
            if(v[i]<num){
                i++;
            }
            else{
                v.insert(v.begin()+i,num);
                fl=1;
                break;
            }
        }
        if(!fl)v.push_back(num);
       }
    }
    
    double findMedian() {
        // sort(v.begin(),v.end());
        int n=v.size();
        if(n%2==1){
            return v[n/2];
        }
        else {
            double ans=double(v[n/2]+v[(n/2)-1])/2;
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */