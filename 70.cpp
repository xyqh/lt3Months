    #include "LeetCodeBase.h"

    int climbStairs(int n){
        /**
         * 爬楼梯，就是斐波那契。
         * 1 2 3 5
        */
        if(n < 4){
            return n;
        }
        int pre2 = 2, pre1 = 3;
        while(n-- > 3){
            int sum = pre2 + pre1;
            pre2 = pre1;
            pre1 = sum;
        }
        return pre1;
    }