#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>
#define ll long long 
#define vl vector<ll> 
#define vvl vector<vl> // v(r,vector<ll>(col,init_value?))
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define loop(x, n) for(long long x = 0; x < n; x++)
#define array1d(arr, NN) loop(ii, NN)cin>>arr[ii];
#define array2d(arr, NN, MM) loop(ii, NN)loop(jj, MM)cin>>arr[ii][jj]
#define ini(arr, N) loop(ii, N)scanf("%d", &arr[ii]);
#define be(x) (x).begin(),(x).end()
#define rbe(x) (x).rbegin(),(x).rend()
#define pl pair<ll, ll> 
#define mapl map<ll,ll>
#define umapl unordered_map<ll,ll>
#define setl set<ll,ll>
#define ff first
#define pb push_back
#define ss second
#define str to_string
#define de if(debug)
#define debug 0
using namespace std;
const int mod9 = 998244353;
const int mod7 = 10000007;
//setbase - cout << setbase (16)a; cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 <<endl;prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val 
int power(int a,int b){
	int res=1;
	while(b>0){
		if(b%2){
			res*=a;
			res%=mod9;
		}
		b/=2;
		a*=a;
		a%=mod9;
	}
	return res;
}

int main()
{   
    int t;
    cin>>t;
    while(t--)
    {
		ll n,k,happay=0;
		cin>>n>>k;
		vl integer(n);
		vl fri(k);
		array1d(integer,n);
		array1d(fri,k);
		sort(be(integer));
		sort(be(fri));
		for (int i = n - k; i < n; ++i)
            happay += integer[i];
        for (int i = 0, j = n - k; i < k; ++i) {
            j -= fri[i] - 1;
            if (fri[i] == 1) {
                happay += integer[n - i - 1];
            } else {
                happay += integer[j];
            }
        }
		cout<<happay<<endl;
    }
    return 0;
}
