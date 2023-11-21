#include "LeetCodeBase.h"

int trap(vector<int>& height){
    int n = height.size();
    vector<int> l(n, 0), r(n, 0);
    l[0] = height[0], r[n - 1] = height[n - 1];
    for(int i = 1; i < n; ++i){
        l[i] = max(l[i - 1], height[i]);
        r[n - 1 - i] = max(r[n - 1 - i + 1], height[n - 1 - i]);
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans += max(min(l[i], r[i]) - height[i], 0);
    }
    return ans;
}