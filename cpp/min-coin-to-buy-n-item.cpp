#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> num(n+1);
        for(int i=0;i<n+1;i++){
            num[i]=0;
        }
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
        cout<<num[n]<<endl;
    }
    return 0;
}