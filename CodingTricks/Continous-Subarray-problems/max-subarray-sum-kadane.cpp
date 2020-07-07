// not work if all are negative value
// solution is in other part

// Time Complexity: O(n)
// Algorithmic : Dynamic Programming

// problem with all negative in array
int maxSubArraySum(int a[], int size) 
{ 
int max_so_far = 0, max_ending_here = 0; 
for (int i = 0; i < size; i++) 
{ 
	max_ending_here = max_ending_here + a[i]; 
	if (max_ending_here < 0) 
		max_ending_here = 0; 

	/* Do not compare for all elements. Compare only 
		when max_ending_here > 0 */
	else if (max_so_far < max_ending_here) 
		max_so_far = max_ending_here; 
} 
return max_so_far; 
} 

// solution to above problem,

#include<iostream> 
using namespace std; 

int maxSubArraySum(int a[], int size) 
{ 
int max_so_far = a[0]; 
int curr_max = a[0]; 

for (int i = 1; i < size; i++) 
{ 
		curr_max = max(a[i], curr_max+a[i]); 
		max_so_far = max(max_so_far, curr_max); 
} 
return max_so_far; 
} 

/* Driver program to test maxSubArraySum */
int main() 
{ 
int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
int n = sizeof(a)/sizeof(a[0]); 
int max_sum = maxSubArraySum(a, n); 
cout << "Maximum contiguous sum is " << max_sum; 
return 0; 
} 

