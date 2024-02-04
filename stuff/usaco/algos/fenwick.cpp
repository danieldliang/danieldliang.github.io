// everything in a fenwick can be done in a segment tree I'm pretty sure
// there's 2 key ideas in constructing the fenwick tree; when you understand one of the two then you can just derive an implementation using adj_list or whatever
// Idea 1: a fenwick consists of intervals of lengths of powers of 2 starting with 1, 2, 4...etc. For each interval, start with the interval, then "skip a beat", then repeat. So like for lengths of 1 (interval format [l, r)): take 0 - 1, skip 1 - 2, take 2 - 3, skip 3 - 4... etc. And then for lengths 2: take 0 - 2, skip 2 - 4, take 4 - 6, skip 6 - 8... etc.
// Idea 2: a fenwick tree consists of layers of intervals. The first layer is unique: You take the floor of log base 2(the length of the entire array). Call that value X.You then take the interval 0 - X, interval format [l, r), and set that as an interval for the Fenwick tree. Next you "cut off" the first X items from the interval and you repeat the process for the interval starting at X instead of 0, and rinse and repeat. Now for the remaining layers: check the layer below it. That is the active layer. From each interval in the active layer, take them as a subtask. Note that all subtasks have a length which is a power of 2. Fill them up left to right as follows: half length, quarter length, eighth length, sixteenth length... etc. until you reach an interval of length zero (essentially, no length). These new intervals are the subtasks for the new layer. Repeat this process for all active subtasks. 
// implementation is as follows (taken off of GFGs) 

// C++ code to demonstrate operations of Binary Index Tree 
#include <iostream> 

using namespace std; 

/*		 n --> No. of elements present in input array. 
	BITree[0..n] --> Array that represents Binary Indexed Tree. 
	arr[0..n-1] --> Input array for which prefix sum is evaluated. */

// Returns sum of arr[0..index]. This function assumes 
// that the array is preprocessed and partial sums of 
// array elements are stored in BITree[]. 
int getSum(int BITree[], int index) 
{ 
	int sum = 0; // Initialize result 

	// index in BITree[] is 1 more than the index in arr[] 
	index = index + 1; 

	// Traverse ancestors of BITree[index] 
	while (index>0) 
	{ 
		// Add current element of BITree to sum 
		sum += BITree[index]; 

		// Move index to parent node in getSum View 
		index -= index & (-index); 
	} 
	return sum; 
} 

// Updates a node in Binary Index Tree (BITree) at given index 
// in BITree. The given value 'val' is added to BITree[i] and 
// all of its ancestors in tree. 
void updateBIT(int BITree[], int n, int index, int val) 
{ 
	// index in BITree[] is 1 more than the index in arr[] 
	index = index + 1; 

	// Traverse all ancestors and add 'val' 
	while (index <= n) 
	{ 
	// Add 'val' to current node of BI Tree 
	BITree[index] += val; 

	// Update index to that of parent in update View 
	index += index & (-index); 
	} 
} 

// Constructs and returns a Binary Indexed Tree for given 
// array of size n. 
int *constructBITree(int arr[], int n) 
{ 
	// Create and initialize BITree[] as 0 
	int *BITree = new int[n+1]; 
	for (int i=1; i<=n; i++) 
		BITree[i] = 0; 

	// Store the actual values in BITree[] using update() 
	for (int i=0; i<n; i++) 
		updateBIT(BITree, n, i, arr[i]); 

	// Uncomment below lines to see contents of BITree[] 
	//for (int i=1; i<=n; i++) 
	//	 cout << BITree[i] << " "; 

	return BITree; 
} 


// Driver program to test above functions 
int main() 
{ 
	int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9}; 
	int n = sizeof(freq)/sizeof(freq[0]); 
	int *BITree = constructBITree(freq, n); 
	cout << "Sum of elements in arr[0..5] is "
		<< getSum(BITree, 5); 

	// Let use test the update operation 
	freq[3] += 6; 
	updateBIT(BITree, n, 3, 6); //Update BIT for above change in arr[] 

	cout << "\nSum of elements in arr[0..5] after update is "
		<< getSum(BITree, 5); 

	return 0; 
} 
