int comp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int minimumAddedCoins(int* coins, int coinsSize, int target) {
    qsort(coins, coinsSize, sizeof(int), comp);
    int ans = 0;
    int x = 1;
    int index = 0;
    while (x <= target) {
        if (index < coinsSize && coins[index] <= x) {
            x += coins[index];
            index++;
        } else {
            x <<= 1;
            ans++;
        }
    }
    return ans;
}