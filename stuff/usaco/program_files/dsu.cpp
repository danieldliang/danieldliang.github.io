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

// if you want to implement Kruskal's, initialize a DSU. 
// Then add the sorted from least to greatest weighted edges one-by-one to the DSU, with the exception of the edges from which their nodes are in the same component (which you check using the find() function)
// for such exception, you just skip/continue the loop. And then you're done!
