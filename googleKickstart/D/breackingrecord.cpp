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
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <utility>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <cstdlib>
#define ll int
#define vl vector<ll>
#define vvl vector<vl>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define loop(x, n) for (long long x = 0; x < n; x++)
#define array1d(arr, NN) loop(ii, NN) cin >> arr[ii];
#define array2d(arr, NN, MM) loop(ii, NN) loop(jj, MM) cin >> arr[ii][jj]
#define ini(arr, N) loop(ii, N) scanf("%d", &arr[ii]);
#define be(x) (x).begin(), (x).end()
#define rbe(x) (x).rbegin(), (x).rend()
#define pl pair<ll, ll>
#define mapl map<ll, ll>
#define endl "\n"
#define umapl unordered_map<ll, ll>
#define setl set<ll, ll>
#define usetl unordered_set<ll, ll>
#define ff first
#define pb push_back
#define ss second
#define str to_string
#define de if (debug)
#define debug 0
using namespace std;
const int mod9 = 998244353;
const int mod7 = 10000007;
int main()
{
    fastio;
    int t,init;
    cin >> t;
    init=t;
    while (t--)
    {
        ll n,count=0;
        cin>>n;
        int store[n],left[n];
        array1d(store,n);
        left[0]=store[0];
        for(int i=1;i<n;i++)left[i]=max(store[i],left[i-1]);
       
        for(int i=0;i<n;i++){
            if( (i==0 || store[i]>left[i-1]) && ( i==n-1 || store[i]>store[i+1] ))
                count++;
        }
        cout<<"Case #"<<init-t<<": "<<count<<endl;
    }
    return 0;
}