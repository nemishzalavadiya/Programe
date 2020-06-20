// getchar_unlocked() > getchar() > scanf() > cin
// cout<<endl() < cout<<"\n";
#include<bits/stdc++.h>
#define ll long long 
#define vl vector<ll> 
#define vvl vector<vl> // v(r,vector<ll>(col,init_value?))
#define pll pair<ll, ll> 
#define ml map<ll,ll>
#define uml unordered_map<ll,ll>
#define sl set<ll>

// for faster input-output using cin/cout
// to avoid warning on large I/O data - toggle syncronization of c++ and c standard libraries.
// to flush std::cout before taking input in std:cin
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define loop(x, n) for(long long x = 0; x < n; x++)
#define array(arr, NN) loop(ii, NN)cin>>arr[ii];
#define array2d(arr, NN, MM) loop(ii, NN)loop(jj, MM)cin>>arr[ii][jj]
#define ini(arr, N) loop(ii, N)scanf("%d", &arr[ii]);

#define ff first
#define pb push_back
#define ss second
#define str to_string
#define line cout<<"\n"
#define be(x) (x).begin(),(x).end()
using namespace std;


int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll i=1,j=n,ans=0;
		while(i<=j){
			ll mid = i+(j-i)/2,check;
			check = (mid*(mid+1))/2;
			if(check >= n){
				ans = mid;
				j=mid-1;
			}
			else{
				i=mid+1;
			}
		}
		cout<<ans;line;
	}	
	return 0;    
}
