    #include "LeetCodeBase.h"
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(int num : nums){
            ++cnt[num];
        }
        struct cmp{
            bool operator()(pair<int, int> a, pair<int, int> b){
                return a.second > b.second;
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> heap;
        for(auto iter : cnt){
            if(heap.size() < k || cnt[heap.top().first] < iter.second){
                heap.emplace(iter.first, iter.second);
            }
            while(heap.size() > k){
                heap.pop();
            }
        }
        vector<int> ans;
        while(heap.size() > 0){
            ans.push_back(heap.top().first);
            heap.pop();
        }
        return ans;
    }