
#include<stdio.h>
#include<stdlib.h>

int firstDayBeenInAllRooms(int* nextVisit, int nextVisitSize){
    long* dp = malloc(nextVisitSize*sizeof(long));
    dp[0] = 0;
    int mod = (int)1e9+7;
    for(int i = 1;i<nextVisitSize;i++){
        dp[i] = (2*dp[i-1]-dp[nextVisit[i-1]]+2+mod)%mod;
    }
    return (int)dp[nextVisitSize-1];
}


// 动态规划，dp[i]表示从0房间到第i个房间所需要的时间。

// 根据0<=nextVisit[i]<=i可以判定访问次数为基数时必回退到小于等于i的某个点，为偶数时才会 +1，故从dp[i+1]=dp[i]+(dp[i]-dp[nextVisit[i]])+2

// 公式如下：

// dp[i]=2∗dp[i−1]−dp[nextVisit[i−1]]+2
