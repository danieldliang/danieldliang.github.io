void init() {
    for (int i = 0; i < N; ++i) {
        father[i] = i;
        height[i] = 0;
    }
}

int find(int node) { // gets the representative, or rather recursively assigns the original node and all nodes up the "tree" until it is assigned the "root"/representative
    if (father[node] != node) { // make sure father is global
        father[node] = find(father[node]);
    }
    return father[node];
}

void unite(int A, int B) {
    int rootA = find(A);
    int rootB = find(B);
    if (height[rootA] > height[rootB]) {
        father[rootB] = rootA;
        height[rootA] = max(height[rootA], height[rootB] + 1);
    } else {
        father[rootA] = rootB;
        height[rootB] = max(height[rootB], height[rootA] + 1);
    }
}
