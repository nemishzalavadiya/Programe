#include <iostream>
#include<stdio.h>
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
#include<unordered_map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>
#define ll long long 
#define vll vector<ll>
#define vvll vecotr<vll >
#define vl vector<ll> 
#define vvl vector<vl> // v(r,vector<ll>(col,init_value?))
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define loop(x, n) for(long long x = 0; x < n; x++)
#define array(arr, NN) loop(ii, NN)cin>>arr[ii];
#define array2d(arr, NN, MM) loop(ii, NN)loop(jj, MM)cin>>arr[ii][jj]
#define print2d(arr,row,col) loop(i,row)loop(j,col){cout<<arr[i][j]<<" ";}cout<<endl;
#define ini(arr, N) loop(ii, N)scanf("%d", &arr[ii]);
#define pll pair<ll, ll> 
#define ff first
#define pb push_back
#define ss second
#define str to_string
using namespace std;
#define de if(debug)
#define debug 0
 
void createsieve(ll n,vector<ll> &isprime){
 
    bool checker[n+1];
    memset(checker,true,sizeof(checker));
    checker[0]=false;checker[1]=false;
    for(ll i=2;i*i<n;i++){
        if(checker[i]){
 
            for(ll j=i*2;j<n;j+=i){
                checker[j]=false;
            }
        }
    }
    for(ll i=2;i<n;i++){
        if(checker[i]){
            isprime.push_back(i);
        }
    }
}
 
void print_prime(ll a,ll b,vector<ll> &isprime)
{
 
    ll lower = a;
    ll higher = b;
 
        bool checker[higher-lower+1];
        memset(checker,true,sizeof(checker));
 
        for(ll i=0;isprime[i]*isprime[i]<=b;i++){
            ll find_first_multiple = ((lower/isprime[i]))*isprime[i];
            if(find_first_multiple<lower) find_first_multiple+=isprime[i];
            for(ll j=find_first_multiple;j<=higher;j+=isprime[i]){
                checker[j-lower]=false;
            }
            if(find_first_multiple==isprime[i])checker[find_first_multiple-lower]=true;
        }
        for(ll i=0;i<=higher-lower;i++){
            if(checker[i] && i+lower>1){
                cout<<i+lower<<endl;
            }
        }
       
}
 
int32_t main()
{
    ll t,sqrt_max=100001;
    cin>>t;
    vector<ll> prime;
    createsieve(sqrt_max,prime);
    while(t--){
      ll a,b;
      cin>>a>>b;
      print_prime(a,b,prime);
    }
}