int minimumSum(int* nums, int numsSize) {
    int n = numsSize, res = 1000, mn = 1000;
    int left[n];
    for (int i = 1; i < n; i++) {
        left[i] = mn = (nums[i - 1] < mn) ? nums[i - 1] : mn;
    }

    int right = nums[n - 1];
    for (int i = n - 2; i > 0; i--) {
        if (left[i] < nums[i] && nums[i] > right) {
            res = (res < left[i] + nums[i] + right) ? res : left[i] + nums[i] + right;
        }
        right = (right < nums[i]) ? right : nums[i];
    }

    return res < 1000 ? res : -1;
}