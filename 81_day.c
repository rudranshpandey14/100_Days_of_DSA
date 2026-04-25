void topView(struct node *root) {
    if (root == NULL) return;

    // queue for BFS
    struct node *queue[1000];
    int hd[1000];   // horizontal distances
    int front = 0, rear = 0;

    // map arrays (offset by 500 to handle negatives)
    int seen[1000] = {0};
    int values[1000];

    // enqueue root
    queue[rear] = root;
    hd[rear++] = 0;

    int minHD = 0, maxHD = 0;

    while (front < rear) {
        struct node *cur = queue[front];
        int curHD = hd[front++];
        
        if (!seen[curHD + 500]) {
            seen[curHD + 500] = 1;
            values[curHD + 500] = cur->data;
            if (curHD < minHD) minHD = curHD;
            if (curHD > maxHD) maxHD = curHD;
        }

        if (cur->left) {
            queue[rear] = cur->left;
            hd[rear++] = curHD - 1;
        }
        if (cur->right) {
            queue[rear] = cur->right;
            hd[rear++] = curHD + 1;
        }
    }

    for (int i = minHD; i <= maxHD; i++) {
        if (seen[i + 500]) {
            printf("%d ", values[i + 500]);
        }
    }
}
