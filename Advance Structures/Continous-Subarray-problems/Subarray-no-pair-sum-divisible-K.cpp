// naive takes O(n^4)

// Efficient Approach(Using Hashing) :
//     We create an empty hash table and insert arr[0] % k into it. Now we traverse remaining 
//     elements and maintain a window such that no pair in the window is divisible by k. 
//     For every traversed element, we remove starting elements while there exist an element in 
//     current window which makes a divisible pair with current element. To check if there is an 
//     element in current window, we check if following.

//     1) If there is an element x such that (K – x % K) is equal to arr[i] % K
//     2) OR arr[i] % k is 0 and it exists in the hash.
//     Once we make sure that all elements which can make a pair with arr[i] are removed, 
//     we add arr[i] to current window and check if size of current window is more than the 
//     maximum window so far.

// Time Complexity : O(n)


// CPP code to find the subarray with 
// no pair sum divisible by K 
#include<bits/stdc++.h> 
using namespace std; 

// function to find the subarray with 
// no pair sum divisible by k 
void subarrayDivisibleByK(int arr[], int n, int k) 
{ 
	// hash table to store the remainders 
	// obtained on dividing by K 
	map<int,int> mp; 

	// s : starting index of the 
	// current subarray, e : ending 
	// index of the current subarray, maxs : 
	// starting index of the maximum 
	// size subarray so far, maxe : ending 
	// index of the maximum size subarray 
	// so far 
	int s = 0, e = 0, maxs = 0, maxe = 0; 

	// insert the first element in the set 
	mp[arr[0] % k]++; 

	for (int i = 1; i < n; i++) 
	{ 
		int mod = arr[i] % k; 

		// Removing starting elements of current 
		// subarray while there is an element in 
		// set which makes a pair with mod[i] such 
		// that the pair sum is divisible. 
		while (mp[k - mod] != 0 || 
			(mod == 0 && mp[mod] != 0)) 
		{ 
			mp[arr[s] % k]--; 
			s++; 
		} 

		// include the current element in 
		// the current subarray the ending 
		// index of the current subarray 
		// increments by one 
		mp[mod]++; 
		e++; 

		// compare the size of the current 
		// subarray with the maximum size so 
		// far 
		if ((e - s) > (maxe - maxs)) 
		{ 
			maxe = e; 
			maxs = s; 
		} 

	} 

	cout << "The maximum size is "
		<< maxe - maxs + 1 << " and "
		"the subarray is as follows\n"; 

	for (int i=maxs; i<=maxe; i++) 
		cout << arr[i] << " "; 
} 

int main() 
{ 
	int k = 3; 
	int arr[] = {5, 10, 15, 20, 25}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	subarrayDivisibleByK(arr, n, k); 
	return 0; 
} 


