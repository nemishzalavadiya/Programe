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
 * Complete the beautifulQuadruples function below.
 */
long beautifulQuadruples(vector<long> arr) {
    long count = 0;
    sort(arr.begin(),arr.end());
    vector<long> store(pow(2,ceil(log2(arr[3]+1))),0);
    for(long i=1;i<arr[2]+1;i++){
        for(long j=i;j<arr[3]+1;j++){
            store[i^j]+=1;
            count++;
        }
    }
    long ans=0;
    for(long i=1;i<arr[1]+1;i++){
        for(long j=1;j<min(arr[0],i)+1;j++){
            // reduce the pairs who produces zero to get !=0 pairs.
            ans+=count-store[i^j];
        }
        // reduce the pairs which are not need because they produces ==0
        long y=i;
        for(long k=i;k<arr[3]+1;k++){
            store[y^k]-=1;
            count--;
        }
    }
    return ans;
}

long main()
{

    vector<long> arr(4);
    for(long i=0;i<4;i++)
        cin>>arr[i];    

    long result = beautifulQuadruples(arr);

    cout << result << "\n";

    return 0;
}