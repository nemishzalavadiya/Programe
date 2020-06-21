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
bool isPrime(int n) 
{ 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 

    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
}


void print_fibo(int min,int max,int count){
    long long ans,first = (long long) min,second = (long long) max;

    //cout<<min<<" "<<max<<" "<<count<<endl;
    count-=2;
    while(count--){
        //cout<<ans<<endl;
        ans=first+second;
        first = second;
        second = ans;
    }
    cout<<ans;
    cout<<"\n";
}

int digit__(int number){
    int count=1;
    if((number/10)>0){
        count++;
        number=number/10;
    }
    return count;
}

void create_set(vector<int> prime){
    int size = prime.size();
    int min=10000,max=2,count=0;
    set<int> set_use;
    //cout<<"Numbers : "<<endl;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i==j)continue;
            int number = prime[i]*pow(10,digit__(prime[j]))+prime[j];
            if(set_use.find(number)!=set_use.end()) continue;
            else set_use.insert(number);
            if(isPrime(number)){
               if(number<min)min=number;
               if(number>max)max=number; 
               count++;
               //cout<<number<<" ";
            }
        }
    }
    print_fibo(min,max,count);
}

int main()
{
    
      int a,b;
      vector<int> allprime;
      cin>>a>>b;
      for(int i=a;i<=b;i++){
          if(isPrime(i)){
              allprime.push_back(i);
          }
      }
      create_set(allprime);
 
    return 0;
}