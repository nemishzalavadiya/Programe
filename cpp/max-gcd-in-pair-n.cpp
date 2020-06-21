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
#define pll pair<ll, ll> 
#define map map<ll,ll>
#define umap unordered_map<ll,ll>
#define set set<ll,ll>
#define ff first
#define pb push_back
#define ss second
#define str to_string
using namespace std;
long long int divisors(long long int n)
{long long int cnt=0;
 
 for (long long int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            cnt++;
            n = n/i;
            if(cnt==2) break;
        }
    if(cnt==2) break;}
    if(n>2)cnt++;
    return cnt; }
 
int main()
{   
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        if(n<=2){
            if(n==1)cout<<"FastestFinger";
            if(n==2)cout<<"Ashishgup";
        }
        else
        {
            if(n%2!=0)
            {
                cout<<"Ashishgup";
            }
            else
            {
                    long long int k=n&(-n);
                    if(k==n)
                    {cout<<"FastestFinger";}
                else{
                if(k>2)
                {cout<<"Ashishgup";}
                    if(k==2)
                        {if(divisors(n)>=2)
                        {cout<<"Ashishgup";}
                        else
                        {cout<<"FastestFinger";}
                    }
                }
            }
        }
        cout<<endl;
    }
}