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

using namespace std;

/*
 * Complete the swapNodes function below.
 */
vector<int> ans;
void swaping(vector<vector<int>> tree,int node,int tdepth,int cdepth){
    cout<<"checking for "<<node<<endl;
    if(node==-1) return;
    if(cdepth%tdepth==0){
        int temp = tree[node][0];
        tree[node][0] = tree[node][1];
        tree[node][1] = temp;
    }
    swaping(tree,tree[node][0],tdepth,cdepth+1);
    ans.push_back(node);
    swaping(tree,tree[node][1],tdepth,cdepth+1);
}
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    /*
     * Write your code here.
     */
    int n=indexes.size();
    vector<vector<int>> ans_result;
    for(int i=0;i<queries.size();i++){
        cout<<"running for query : i "<<i+1<<endl;
        swaping(indexes,1,queries[i],1);
        cout<<"back from swaping for query : i "<<i+1<<" \nsize of ans : "<<ans.size()<<endl;
        for(int j=0;j<ans.size();j++){
            ans_result[i].push_back(ans[j]);
            cout<<"Running fro j : "<<j<<endl;
        }
        ans.clear();
    }
    return ans_result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n+1);
    for (int indexes_row_itr = 1; indexes_row_itr < n+1; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
