// Time Complexity

// T(n) : O(n)
// S(n) : O(1)

// C++ program of above approach 
#include <bits/stdc++.h> 
using namespace std; 

// function to find longest subarray 
int longestsubarray(int arr[], int n, int k) 
{ 
	int current_count = 0; 
	// this will contain length of longest subarray found 
	int max_count = 0; 

	for (int i = 0; i < n; i++) { 
		if (arr[i] % k == 0) 
			current_count++; 
		else
			current_count = 0; 
		max_count = max(current_count, max_count); 
	} 
	return max_count; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 2, 5, 11, 32, 64, 88 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 8; 
	cout << longestsubarray(arr, n, k); 
	return 0; 
} 
