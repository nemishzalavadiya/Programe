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

int solve(){
  int n;
  cin>>n;
  vector<int> num(n+1);
  
  //fill zeros
  for(int i=0;i<n+1;i++){
      num[i]=0;
  }
  
  //create dp array with minimum coins
  for(int i=1;i<n+1;i++){
      if(num[i]!=0){
          continue;
      }
      if(num[i]==0){
          num[i]=num[i-1]+1;
      }
      for(int j=1;j<=(i-1) && (i+j)<n+1;j++){
          num[i+j]=num[i];
      }

  }
  //return minimum at n
  return num[n];
}

int main(){
    int t;
    cin>>t;
    while(t--){
       cout<<solve()<<endl; 
    }
    return 0;
}