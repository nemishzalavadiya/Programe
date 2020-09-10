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
#define V 9

void print(int distance[]){
    cout<<"Distance info from source to vertex : "<<endl;
    for(int i=0;i<V;i++){
        cout<<"Vertex "<<i<<" : "<<distance[i]<<endl;
    }
    cout<<endl;
}

int minimumInSet(int distanceFromSource[],bool shortestPathTree[]){
    int minDistance = INT_MAX,u;
    for(int i=0;i<V;i++){
        if(shortestPathTree[i]==false && minDistance>distanceFromSource[i])
            minDistance = distanceFromSource[i],u=i;
    }
    return u;
}

void dijkstra(int graph[V][V],int start){
    int distanceFromSource[V];bool shortestPathTree[V];
    for(int i=0;i<V;i++){
        distanceFromSource[i]=INT_MAX;shortestPathTree[i]=false;
    }
    distanceFromSource[0]=0;
    for(int i=0;i<V-1;i++){
        int u = minimumInSet(distanceFromSource,shortestPathTree);

        shortestPathTree[u]=true;
        
        for(int j=0;j<V;j++){
            if(!shortestPathTree[j] && graph[u][j] && distanceFromSource[u]!=INT_MAX && graph[u][j]+distanceFromSource[u]<distanceFromSource[j])
                distanceFromSource[j]=graph[u][j]+distanceFromSource[u];
        }

    }
    print(distanceFromSource);
}

int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 

    dijkstra(graph,0);
    return 0;
}