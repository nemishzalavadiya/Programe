//              ONP - Transform the Expression ( SPOJ ) #stack

//  Transform the algebraic expression with brackets into RPN form (Reverse Polish Notation). 
//  Two-argument operators: +, -, *, /, ^ (priority from the lowest to the highest), brackets ( ). 
//  Operands: only letters: a,b,...,z. Assume that there is only one RPN form (no expressions like a*b*c).

//  Time Complexity - O(N)

#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;
unordered_map<char,int> priority;
string RPN(string s){
    stack<int> notation;
    string answer="";
    for(int i=0;i<s.size();i++){
        if(s[i]==')'){
            int ele = notation.top();
            while(ele!='('){
                notation.pop();
                answer+=ele;
                ele = notation.top();
            }
            notation.pop();
            continue;
        }
        if(s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*' || s[i]=='(' || s[i]=='^'){
            notation.push(s[i]);
            continue;
        }
        answer+=s[i];
    }
    return answer;
}

int main(){
    int t;
    cin>>t;
    priority['+']=1;
    priority['-']=2;
    priority['*']=3;
    priority['/']=4;
    priority['^']=5;
    while(t--){
        string s;
        cin>>s;
        //cout<<"running for : "<<s<<endl;
        cout<<RPN(s)<<"\n";
    }
    return 0;
}