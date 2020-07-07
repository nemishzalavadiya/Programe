// Sqrt trick :- In naive approach we were jumping one parent up the tree till both 
//nodes aren’t on the same depth. But here we perform group wise jump. To perform this
//group wise jump, we need two parameter associated with each node : 1) parent and 2) jump parent
// Here parent for each node is defined as the first node above the current node that is 
//directly connected to it, where as jump_parent for each node is the node that is the first 
//ancestor of the current node in the group just above the current node.

// So, now we need to maintain 3 parameters for each node :
// 1) depth
// 2) parent
// 3) jump_parent

// Time Complexity Analysis:
//     We have divided the tree into sqrt(h) groups according to their depth and each group contain
//     nodes having max difference in their depth equal to sqrt(h). Now once again take an example of
//     worst case, let’s say the first node ‘u’ is in first group and the node ‘v’ is in sqrt(h)th 
//     group(last group). So, first we will make group jumps(single group jumps) till we reach group 
//     1 from last group; This will take exactly sqrt(h) – 1 iterations or jumps. So, till this step 
//     the Time Complexity is O(sqrt(h)).

// C++ program to find LCA using Sqrt decomposition 
#include "iostream" 
#include "vector" 
#include "math.h" 
using namespace std; 
#define MAXN 1001 

int block_sz;		 // block size = sqrt(height) 
int depth[MAXN];	 // stores depth for each node 
int parent[MAXN];	 // stores first parent for 
					// each node 
int jump_parent[MAXN]; // stores first ancestor in 
					// previous block 

vector < int > adj[MAXN]; 

void addEdge(int u,int v) 
{ 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
} 

int LCANaive(int u,int v) 
{ 
	if (u == v) return u; 
	if (depth[u] > depth[v]) 
		swap(u,v); 
	v = parent[v]; 
	return LCANaive(u,v); 
} 

// precalculating the required parameters 
// associated with every node 
void dfs(int cur, int prev) 
{ 
	// marking depth of cur node 
	depth[cur] = depth[prev] + 1; 

	// marking parent of cur node 
	parent[cur] = prev; 

	// making jump_parent of cur node 
	if (depth[cur] % block_sz == 0) 

		/* if it is first node of the block 
		then its jump_parent is its cur parent */
		jump_parent[cur] = parent[cur]; 

	else

		/* if it is not the first node of this block 
		then its jump_parent is jump_parent of 
		its parent */
		jump_parent[cur] = jump_parent[prev]; 


	// propogating the marking down the subtree 
	for (int i = 0; i<adj[cur].size(); ++i) 
		if (adj[cur][i] != prev) 
			dfs(adj[cur][i], cur); 
} 


// using sqrt decomposition trick 
int LCASQRT(int u, int v) 
{ 
	while (jump_parent[u] != jump_parent[v]) 
	{ 
		if (depth[u] > depth[v]) 

			// maintaining depth[v] > depth[u] 
			swap(u,v); 

		// climb to its jump parent 
		v = jump_parent[v]; 
	} 

	// u and v have same jump_parent 
	return LCANaive(u,v); 
} 

void preprocess(int height) 
{ 
	block_sz = sqrt(height); 
	depth[0] = -1; 

	// precalclating 1)depth. 2)parent. 3)jump_parent 
	// for each node 
	dfs(1, 0); 
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

	// here we are directly taking height = 4 
	// according to the given tree but we can 
	// pre-calculate height = max depth 
	// in one more dfs 
	int height = 4; 
	preprocess(height); 

	cout << "LCA(11,8) : " << LCASQRT(11,8) << endl; 
	cout << "LCA(3,13) : " << LCASQRT(3,13) << endl; 

	return 0; 
} 
