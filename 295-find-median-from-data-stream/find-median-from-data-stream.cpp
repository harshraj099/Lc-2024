class MedianFinder {
public:
    // define max and min heap
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;
    MedianFinder() {}
    
    void addNum(int num) {
        // note
        // minh is actually maxlist and maxh is actuall minlist
        // put in minlist then get max and put in maxlist then check conditon 
        // length of min and max list diff <=1 
        maxh.push(num);
        minh.push(maxh.top());
        maxh.pop();
        // now check
        if(minh.size()>maxh.size()){
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() {
        if(maxh.size()==minh.size())return (minh.top()+maxh.top())/2.0;
        return maxh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */