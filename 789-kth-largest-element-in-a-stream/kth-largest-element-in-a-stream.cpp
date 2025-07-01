class KthLargest {
public:
     int num;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    KthLargest(int k, vector<int>& nums) {
        num=k;
      for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
 if (minHeap.size() < num) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */