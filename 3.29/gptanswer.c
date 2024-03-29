#define MAX_VALUE 150
#define INVALID_RESULT -1

int minimumSum(int* nums, int numsSize) {
    int minSum = MAX_VALUE;

    for (int j = 1; j < numsSize - 1; j++) {
        int leftMin = MAX_VALUE, rightMin = MAX_VALUE;

        // 寻找左侧最小值
        for (int i = 0; i < j; i++) {
            if (nums[i] < nums[j]) {
                leftMin = nums[i] < leftMin ? nums[i] : leftMin;
            }
        }

        // 寻找右侧最小值
        for (int k = j + 1; k < numsSize; k++) {
            if (nums[k] < nums[j]) {
                rightMin = nums[k] < rightMin ? nums[k] : rightMin;
            }
        }

        // 如果找到了左右两侧的最小值，则计算元素和并更新最小值
        if (leftMin != MAX_VALUE && rightMin != MAX_VALUE) {
            int sum = leftMin + nums[j] + rightMin;
            minSum = sum < minSum ? sum : minSum;
        }
    }

    return minSum == MAX_VALUE ? INVALID_RESULT : minSum;
}