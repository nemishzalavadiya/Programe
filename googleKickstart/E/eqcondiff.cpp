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
#define ll long long
#define vl vector<ll>
#define vvl vector<vl> 
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define loop(x, n) for (long long x = 0; x < n; x++)
#define array1d(arr, NN) loop(ii, NN) cin >> arr[ii];
#define array2d(arr, NN, MM) loop(ii, NN) loop(jj, MM) cin >> arr[ii][jj]
#define arrayscane(arr, N) loop(ii, N) scanf("%d", &arr[ii]);
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
    ll t,total;
    cin >> t;
    total=t;
    while (t--)
    {
        ll n,max=1,i=1;
        cin>>n;
        vl store(n);array1d(store,n);
        vl temp(n);
        temp[0]=store[0]-store[1];
        store[0]=1;
        for(;i<(n-1);i++){
            if(store[i]-store[i+1]==temp[i-1]){
                temp[i]=store[i]-store[i+1];
                store[i]=store[i-1]+1;
                
            }
            else{
                temp[i]=store[i]-store[i+1];
               store[i]=1; 
            }
            
            if(store[i]>max)max=store[i];
        }
        cout<<"Case #"<<(total-t)<<": "<<max+1<<endl;
    }
    return 0;
}