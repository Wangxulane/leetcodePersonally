#include<stdio.h>
#include<stdlib.h>

int minimumAddedCoins(int* coins, int coinsSize, int target) {
    coins=sortcoins(coins,coinsSize);
}

// 冒泡排序
int* sortcoins(int* coins,int coinsSize){
    int temp;
    for(int i=0;i<coinsSize-1;i++){
        for(int j=0;j<coinsSize-1-i;j++){
            if(coins[j]>coins[j+1]){
                temp=coins[j];
                coins[j]=coins[j+1];
                coins[j+1]=temp;
            }
        }
    }
    return coins;
}