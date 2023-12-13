#include "LeetCodeBase.h"

int findKthElement(vector<int>& nums1, vector<int>& nums2, int k){
    int m = nums1.size(), n = nums2.size();
    int index1 = 0, index2 = 0;
    while(true){
        if(index1 == m){
            return nums2[index2 + k - 1];
        }
        if(index2 == n){
            return nums1[index1 + k - 1];
        }
        if(k == 1){
            return min(nums1[index1], nums2[index2]);
        }

        int newIndex1 = min(index1 + k / 2 - 1, m - 1);
        int newIndex2 = min(index2 + k / 2 - 1, n - 1);
        if(nums1[newIndex1] <= nums2[newIndex2]){
            k -= newIndex1 - index1 + 1;
            index1 = newIndex1 + 1;
        }else{
            k -= newIndex2 - index2 + 1;
            index2 = newIndex2 + 1;
        }
    }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int totalLen = nums1.size() + nums2.size();
    if(totalLen % 2 == 1){
        return findKthElement(nums1, nums2, (totalLen + 1) / 2);
    }else{
        return (findKthElement(nums1, nums2, totalLen / 2) + findKthElement(nums1, nums2, (total + 1) / 2)) / 2.0;
    }
}