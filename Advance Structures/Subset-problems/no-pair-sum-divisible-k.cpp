//    Exceptions on k being even

// In below code array numbers with remainder 0 and remainder K/2 are handled separately. 
// If we include more than 2 numbers with remainder 0 then their sum will be divisible by K, 
// so we have taken at max 1 number in our consideration, same is the case with array numbers 
// giving remainder K/2.

// Time Complexity: O(N + K)
// Auxiliary Space: O(K)

// C++ program to get size of subset whose 
// each pair sum is not divisible by K 
#include <bits/stdc++.h> 
using namespace std; 

// Returns maximum size of subset with no pair 
// sum divisible by K 
int subsetPairNotDivisibleByK(int arr[], int N, 
										int K) 
{ 
	// Array for storing frequency of modulo 
	// values 
	int f[K]; 
	memset(f, 0, sizeof(f)); 

	// Fill frequency array with values modulo K 
	for (int i = 0; i < N; i++) 
		f[arr[i] % K]++; 

	// if K is even, then update f[K/2] 
	if (K % 2 == 0) 
		f[K/2] = min(f[K/2], 1); 

	// Initialize result by minimum of 1 or 
	// count of numbers giving remainder 0 
	int res = min(f[0], 1); 

	// Choose maximum of count of numbers 
	// giving remainder i or K-i 
	for (int i = 1; i <= K/2; i++) 
		res += max(f[i], f[K-i]); 

	return res; 
} 

// Driver code to test above methods 
int main() 
{ 
	int arr[] = {3, 7, 2, 9, 1}; 
	int N = sizeof(arr) / sizeof(arr[0]); 
	int K = 3; 
	cout << subsetPairNotDivisibleByK(arr, N, K); 
	return 0; 
}
