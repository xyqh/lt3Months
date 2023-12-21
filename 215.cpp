    #include "LeetCodeBase.h"
    
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int num : nums){
            if(heap.size() < k || num > heap.top()){
                heap.push(num);
            }
            while(heap.size() > k){
                heap.pop();
            }
        }
        return heap.top();
    }