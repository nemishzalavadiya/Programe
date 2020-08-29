

// Time Complexity: 

//     Let’s consider a query [l = 1 and r = n-2] (n is the size of the array and has a 
//     0 based indexing). Therefore, for this query exactly ( sqrt(n) – 2 ) blocks will 
//     be completely overlapped where as the first and last block will be partially 
//     overlapped with just one element left outside the overlapping range. So, the 
//     completely overlapped blocks can be summed up in ( sqrt(n) – 2 ) ~ sqrt(n) iterations, 
//     whereas first and last block are needed to be traversed one by one separately. But as 
//     we know that the number of elements in each block is at max sqrt(n), to sum up last 
//     block individually we need to make,
//     (sqrt(n)-1) ~ sqrt(n) iterations and same for the last block.
//     So, the overall Complexity = O(sqrt(n)) + O(sqrt(n)) + O(sqrt(n)) = O(3*sqrt(N)) = O(sqrt(n))

// Update Queries(Point update) :

//     In this query we simply find the block in which the given index lies, then subtract its 
//     previous value and add the new updated value as per the point update query.
//     Time Complexity : O(1)


// C++ program to demonstrate working of Square Root 
// Decomposition. 
#include "iostream" 
#include "math.h" 
using namespace std; 

#define MAXN 10000 
#define SQRSIZE 100 

int arr[MAXN];			 // original array 
int block[SQRSIZE];		 // decomposed array 
int blk_sz;					 // block size 

// Time Complexity : O(1) 
void update(int idx, int val) 
{ 
	int blockNumber = idx / blk_sz; 
	block[blockNumber] += val - arr[idx]; 
	arr[idx] = val; 
} 

// Time Complexity : O(sqrt(n)) 
int query(int l, int r) 
{ 
	int sum = 0; 
	while (l<r and l%blk_sz!=0 and l!=0) 
	{ 
		// traversing first block in range 
		sum += arr[l]; 
		l++; 
	} 
	while (l+blk_sz <= r) 
	{ 
		// traversing completely overlapped blocks in range 
		sum += block[l/blk_sz]; 
		l += blk_sz; 
	} 
	while (l<=r) 
	{ 
		// traversing last block in range 
		sum += arr[l]; 
		l++; 
	} 
	return sum; 
} 

// Fills values in input[] 
void preprocess(int input[], int n) 
{ 
	// initiating block pointer 
	int blk_idx = -1; 

	// calculating size of block 
	blk_sz = sqrt(n); 

	// building the decomposed array 
	for (int i=0; i<n; i++) 
	{ 
		arr[i] = input[i]; 
		if (i%blk_sz == 0) 
		{ 
			// entering next block 
			// incementing block pointer 
			blk_idx++; 
		} 
		block[blk_idx] += arr[i]; 
	} 
} 

// Driver code 
int main() 
{ 
	// We have used separate array for input because 
	// the purpose of this code is to explain SQRT 
	// decomposition in competitive programming where 
	// we have multiple inputs. 
	int input[] = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10}; 
	int n = sizeof(input)/sizeof(input[0]); 

	preprocess(input, n); 

	cout << "query(3,8) : " << query(3, 8) << endl; 
	cout << "query(1,6) : " << query(1, 6) << endl; 
	update(8, 0); 
	cout << "query(8,8) : " << query(8, 8) << endl; 
	return 0; 
} 
