#include <bits/stdc++.h>

using namespace std;

// Complete the angryChildren function below.
unsigned long long angryChildren(unsigned long long k, vector<unsigned long long> packets) {
    unsigned long long min=0,k_t=packets.size()-k;
    for(unsigned long long i=packets.size()-1;i>packets.size()-k;i--){
        min+=(packets[i]-packets[i-1])*(i-(k_t))-(packets[i-1]-packets[k_t-1]);
    }
    unsigned long long pre = min;
    for(unsigned long long i=packets.size()-2;i>(k-1);i--){
        unsigned long long minte=pre;
        cout<<"pre : "<<pre<<" i :"<<i<<endl;
        minte-=(packets[i+1]-packets[i])*(k-1)-(packets[i]-packets[i-k+1]);
        cout<<minte<<endl;
        minte+=packets[i] - packets[i-k+1] - (packets[i-k+1]-packets[i-k])*(k-1);
        cout<<minte<<" "<<packets[i] - packets[i-k+1]*k <<endl;
        if(minte<min){
            min=minte;
        }
        pre = minte;
        
    }
    return min;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    unsigned long long n;
    cin >> n;

    unsigned long long k;
    cin >> k;

    vector<unsigned long long> packets(n+1,0);

    for (unsigned long long i = 1; i < n+1; i++) {
        unsigned long long packets_item;
        cin >> packets_item;

        packets[i] = packets_item;
    }
    sort(packets.begin(),packets.end());
    for (unsigned long long i = 1; i < n+1; i++) {

        packets[i] +=packets[i-1];
    }
    unsigned long long result = angryChildren(k, packets);

    fout << result << "\n";

    fout.close();

    return 0;
}
