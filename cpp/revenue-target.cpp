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
#define ll long long;
using namespace std;
vector<int> patient(12);
long long ans,value_rev;
int value(int m,int d){
    return (6-m)*(6-m)+abs(d-15);
}
bool istarget(int n,int tv,int wtv,long long target){
    int i=0,j=n;
    vector<int> day={ 31,28,31,30,31,30,31,31,30,31,30,31};
    while(i<=j){
       int mid = i+(j-i)/2;
        long long revenue=0;
        //cout<<"\n\nfor mid : "<<mid<<" ";
        for(int i=0;i<12;i++){
            //cout<<i+1;
            for(int j=0;j<day[i];j++){
                int pat = value(i+1,j+1);
                //cout<<" "<<j+1<<" : "<<pat<<" ";
                if(pat>(n-mid)){
                    int withouttv = n-mid;
                    int tvPat = pat - withouttv;
                    if(tvPat>mid) tvPat=mid;
                    revenue+= withouttv*wtv + tvPat*tv;
                }
                else{
                    revenue+=pat*wtv;
                }
            }
            //cout<<endl;
        }
        if(revenue==target){
            ans=mid;
            value_rev = revenue;
            //cout<<"Ans have been : "<<ans<<endl;
            return true;
        }
        else if(revenue<target){
            i=mid+1;
        }
        else{
            ans=mid;
            value_rev = revenue;
            //cout<<"Ans have been : "<<ans<<endl;
            j=mid-1;
        }
        //cout<<"\n\nRevenue : "<<revenue<<"  "<<(revenue<target)<<endl;
    }
    if(value_rev>=target) return true;
    else return false;
}

int main(){

    int n,tv,wtv;
    long long target;
    cin>>n>>tv>>wtv;
    cin>>target;

    if(istarget(n,tv,wtv,target)){
        //cout<<"here achieved ans is"<<endl;
        cout<<ans<<endl;
    }
    else{
        cout<<n<<endl;
    }
    
    return 0;
}