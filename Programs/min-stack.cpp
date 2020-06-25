//              MINSTACK - Smallest on the Stack ( SPOJ ) #stack

//  The output consists of a line containing an integer with the smallest present value in the stack 
//  for queries of type "MIN" or "EMPTY" for "MIN" and "POP" operations when the stack is empty.

//  Time Complexity - O(N)
#include<iostream>
#include<stack>
typedef long long ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll t;
    stack<pair<ll,ll>> santa;
    cin>>t;
    while(t--){
        string get_string;
        cin>>get_string;
        if(get_string=="PUSH"){
            ll num;
            cin>>num;
            if(santa.empty()){
                santa.push({num,num});
            }
            else{
                pair<ll,ll> temp;
                temp = santa.top();
                if(temp.second<num){
                    santa.push({num,temp.second});
                }
                else{
                    santa.push({num,num});
                }
            }
        }
        else if(get_string=="POP"){
            if(santa.empty()){
                cout<<"EMPTY"<<"\n";
            }
            else{
                santa.pop();
                cout<<"\n";
            }
        }
        else{
            if(santa.empty()){
                cout<<"EMPTY"<<"\n";
            }
            else{
                cout<<santa.top().second<<"\n";
            }
        }
    }
    return 0;
}