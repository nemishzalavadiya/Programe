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

long dfs(vector<vector<long>> &cities,vector<long> &v,long now){
    v[now]=1;
    long count=0;
    for(long child:  cities[now]){
        if(v[child]==0){
            count++;
            count+=dfs(cities,v,child);
        }
    }
    return count;
}
// Complete the roadsAndLibraries function below.
long roadsAndLibraries(long n, long c_lib, long c_road, vector<vector<long>> &cities) {
    long cost=0;
    vector<long> visited(n+1,0);
    vector<long> parent(n+1,-1);
    if(c_road>=c_lib){
        return n*c_lib;
    }
    for(long i=1;i<n+1;i++){
        if(visited[i]==0){
        long count = dfs(cities,visited,i);
        cost+=(count*c_road)+c_lib;
        }
    }
    cout<<cost<<endl;
    return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    long q;
    cin >> q;

    for (long q_itr = 0; q_itr < q; q_itr++) {

        long n ;
        cin>>n;
        long m ;
        cin>>m;
        long c_lib ;
        cin>>c_lib;
        long c_road ;
        cin>>c_road;
        vector<vector<long>> cities(n+1);
        for (long i = 0; i < m; i++) {
            long t1,t2;
            cin>>t1>>t2;
            cities[t1].push_back(t2);
            cities[t2].push_back(t1);
        }
        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }


    return 0;
}
