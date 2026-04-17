#include <stdio.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int visited[26] = {0}; // for 'a' to 'z'

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        if (visited[index] == 1) {
            printf("%c", s[i]);
            return 0;
        }

        visited[index] = 1;
    }

    // If no repeated character found
    printf("-1");

    return 0;
}
