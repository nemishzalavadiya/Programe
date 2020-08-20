### Programe Skeleton and Practive Problems

>codechef

>Hackerrank

>HackerEarth

>Codeforces

## Cpp Template User Snippets

```cpp

{
	// Place your global snippets here. Each snippet is defined under a snippet name and has a scope, prefix, body and 
	// description. Add comma separated ids of the languages where the snippet is applicable in the scope field. If scope 
	// is left empty or omitted, the snippet gets applied to all languages. The prefix is what is 
	// used to trigger the snippet and the body will be expanded and inserted. Possible variables are: 
	// $1, $2 for tab stops, $0 for the final cursor position, and ${1:label}, ${2:another} for placeholders. 
	// Placeholders with the same ids are connected.
	// Example:
	// "Print to console": {
	// 	"scope": "javascript,typescript",
	// 	"prefix": "log",
	// 	"body": [
	// 		"console.log('$1');",
	// 		"$2"
	// 	],
	// 	"description": "Log output to console"
	// }
	"cpp template": {
		 	"scope": "cpp",
		 	"prefix": "mycpp",
		 	"body": [
				"#include <iostream>",
				"#include <string>",
				"#include <vector>",
				"#include <algorithm>",
				"#include <fstream>",
				"#include <queue>",
				"#include <deque>",
				"#include <bitset>",
				"#include <iterator>",
				"#include <list>",
				"#include <stack>",
				"#include <map>",
				"#include <unordered_map>",
				"#include <set>",
				"#include <unordered_set>",
				"#include <functional>",
				"#include <utility>",
				"#include <climits>",
				"#include <cmath>",
				"#include <cstdio>",
				"#include <cstring>",
				"#include <iomanip>",
				"#include <cassert>",
				"#define ll unsigned long long",
				"#define vl vector<ll>",
				"#define vvl vector<vl> ",
				"#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)",
				"#define loop(x, n) for (long long x = 0; x < n; x++)",
				"#define array1d(arr, NN) loop(ii, NN) cin >> arr[ii];",
				"#define array2d(arr, NN, MM) loop(ii, NN) loop(jj, MM) cin >> arr[ii][jj]",
				"#define ini(arr, N) loop(ii, N) scanf(\"%d\", &arr[ii]);",
				"#define be(x) (x).begin(), (x).end()",
				"#define rbe(x) (x).rbegin(), (x).rend()",
				"#define pl pair<ll, ll>",
				"#define mapl map<ll, ll>",
				"#define umapl unordered_map<ll, ll>",
				"#define setl set<ll, ll>",
				"#define usetl unordered_set<ll, ll>",
				"#define ff first",
				"#define pb push_back",
				"#define ss second",
				"#define str to_string",
				"#define de if (debug)",
				"#define debug 0",
				"using namespace std;",
				"const int mod9 = 998244353;",
				"const int mod7 = 10000007;",
				"int main()",
				"{",
				"fastio;",
				"int t;",
				"cin >> t;",
				"while (t--)",
				"{",
				"$1",
				"}",
				"return 0;",
				"}",
		 	],
		 	"description": "cpp skeleton template"
		 }
}

```

## Cpp header Template User Snippets

```cpp

{
	// Place your global snippets here. Each snippet is defined under a snippet name and has a scope, prefix, body and 
	// description. Add comma separated ids of the languages where the snippet is applicable in the scope field. If scope 
	// is left empty or omitted, the snippet gets applied to all languages. The prefix is what is 
	// used to trigger the snippet and the body will be expanded and inserted. Possible variables are: 
	// $1, $2 for tab stops, $0 for the final cursor position, and ${1:label}, ${2:another} for placeholders. 
	// Placeholders with the same ids are connected.
	// Example:
	// "Print to console": {
	// 	"scope": "javascript,typescript",
	// 	"prefix": "log",
	// 	"body": [
	// 		"console.log('$1');",
	// 		"$2"
	// 	],
	// 	"description": "Log output to console"
	// }
	"cpp header template": {
		 	"scope": "cpp",
		 	"prefix": "mycppheader",
		 	"body": [
				"#include <iostream>",
				"#include <string>",
				"#include <vector>",
				"#include <algorithm>",
				"#include <fstream>",
				"#include <queue>",
				"#include <deque>",
				"#include <bitset>",
				"#include <iterator>",
				"#include <list>",
				"#include <stack>",
				"#include <map>",
				"#include <unordered_map>",
				"#include <set>",
				"#include <unordered_set>",
				"#include <functional>",
				"#include <utility>",
				"#include <climits>",
				"#include <cmath>",
				"#include <cstdio>",
				"#include <cstring>",
				"#include <iomanip>",
				"#include <cassert>",
				"#define ll unsigned long long",
				"#define vl vector<ll>",
				"#define vvl vector<vl> ",
				"#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)",
				"#define loop(x, n) for (long long x = 0; x < n; x++)",
				"#define array1d(arr, NN) loop(ii, NN) cin >> arr[ii];",
				"#define array2d(arr, NN, MM) loop(ii, NN) loop(jj, MM) cin >> arr[ii][jj]",
				"#define ini(arr, N) loop(ii, N) scanf(\"%d\", &arr[ii]);",
				"#define be(x) (x).begin(), (x).end()",
				"#define rbe(x) (x).rbegin(), (x).rend()",
				"#define pl pair<ll, ll>",
				"#define mapl map<ll, ll>",
				"#define umapl unordered_map<ll, ll>",
				"#define setl set<ll, ll>",
				"#define usetl unordered_set<ll, ll>",
				"#define ff first",
				"#define pb push_back",
				"#define ss second",
				"#define str to_string",
				"#define de if (debug)",
				"#define debug 0",
				"using namespace std;",
				"const int mod9 = 998244353;",
				"const int mod7 = 10000007;",
				"$1",
		 	],
		 	"description": "cpp header skeleton template"
		 }
}

```
```````