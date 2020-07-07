// Naive C++ implementation to find LCA in a tree 
// Time Complexity : We pre-calculate the depth for each node using one DFS traversal in O(n). 
//         Now in worst case, the two nodes will be two bottom most node on the tree in different 
//         child branches of the root node. Therefore, in this case the root will be the LCA of 
//         both the nodes. Hence, both the nodes will have to jump exactly h height above, where
//         h is the height of the tree. So, to answer each LCA query Time Complexity will be O(h).
#include<bits/stdc++.h> 
using namespace std; 
#define MAXN 1001 

int depth[MAXN];		 // stores depth for each node 
int parent[MAXN];		 // stores first parent for each node 

vector < int > adj[MAXN]; 

void addEdge(int u,int v) 
{ 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
} 

void dfs(int cur, int prev) 
{ 
	// marking parent for each node 
	parent[cur] = prev; 

	// marking depth for each node 
	depth[cur] = depth[prev] + 1; 

	// propogating marking down the tree 
	for (int i=0; i<adj[cur].size(); i++) 
		if (adj[cur][i] != prev) 
			dfs(adj[cur][i],cur); 
} 

void preprocess() 
{ 
	// a dummy node 
	depth[0] = -1; 

	// precalclating 1)depth. 2)parent. 
	// for each node 
	dfs(1,0); 
} 

// Time Complexity : O(Height of tree) 
// recursively jumps one node above 
// till both the nodes become equal 
int LCANaive(int u,int v) 
{ 
	if (u == v) return u; 
	if (depth[u] > depth[v]) 
		swap(u, v); 
	v = parent[v]; 
	return LCANaive(u,v); 
} 

// Driver function to call the above functions 
int main(int argc, char const *argv[]) 
{ 
	// adding edges to the tree 
	addEdge(1,2); 
	addEdge(1,3); 
	addEdge(1,4); 
	addEdge(2,5); 
	addEdge(2,6); 
	addEdge(3,7); 
	addEdge(4,8); 
	addEdge(4,9); 
	addEdge(9,10); 
	addEdge(9,11); 
	addEdge(7,12); 
	addEdge(7,13); 

	preprocess(); 

	cout << "LCA(11,8) : " << LCANaive(11,8) << endl; 
	cout << "LCA(3,13) : " << LCANaive(3,13) << endl; 

	return 0; 
} 
