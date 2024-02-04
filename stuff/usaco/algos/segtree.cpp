// Technically you could code this up using graphically using adjacency lists in-contest if it really came down to it. Constant factor would be a nightmare though.
// Took and edited off of GFGs
const int N = 200002; // array size 

int n;

// Max size of tree 
int tree[2 * N]; 

// function to build the tree 
void build(vector<int> arr) 
{ 
	// insert leaf nodes in tree 
	for (int i = 0; i < n; ++i) tree[n+i] = arr[i]; 
	
	// build the tree by calculating parents 
	for (int i = n - 1; i > 0; --i) tree[i] = tree[i<<1] + tree[i<<1 | 1];
}

// function to update a tree node 
void updateTreeNode(int p, int value)  
{  
    // set value at position p 
    tree[p+n] = value; 
    p = p+n; 
      
    // move upward and update parents 
    for (int i=p; i > 1; i >>= 1) 
        tree[i>>1] = tree[i] + tree[i^1]; 
}

// function to get sum on interval [l, r) 
int query(int l, int r) 
{
	int res = 0; 
	
	// loop to find the sum in the range 
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) { 
		if (l&1) res += tree[l++]; 
		if (r&1) res += tree[--r]; 
	} 
    
	return res; 
} 
