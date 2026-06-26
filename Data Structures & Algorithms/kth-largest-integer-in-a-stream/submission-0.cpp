class KthLargest {
    priority_queue <int, vector<int> , greater<>> minHeap;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for (int i=0;i<nums.size();i++){
            minHeap.push(nums[i]);
            if (minHeap.size()>K) minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size()>K) minHeap.pop();
        return minHeap.top();
    }
};
