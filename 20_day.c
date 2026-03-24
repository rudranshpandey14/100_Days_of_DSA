#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix[n];
    int count = 0;

    prefix[0] = arr[0];

    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    // Check all pairs of prefix sums
    for(int i = 0; i < n; i++) {
        if(prefix[i] == 0)
            count++;

        for(int j = i + 1; j < n; j++) {
            if(prefix[i] == prefix[j])
                count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
