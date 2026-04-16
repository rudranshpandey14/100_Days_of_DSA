#include <stdio.h>

#define MAX 1000

int maxLenZeroSum(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Initialize hash array with -1
    int hash[MAX];
    for (int i = 0; i < MAX; i++) {
        hash[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum = 0
        if (sum == 0) {
            maxLen = i + 1;
        }

        // Case 2: sum seen before
        if (hash[sum + MAX/2] != -1) {
            int len = i - hash[sum + MAX/2];
            if (len > maxLen)
                maxLen = len;
        } else {
            // store first occurrence
            hash[sum + MAX/2] = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLenZeroSum(arr, n));

    return 0;
}
