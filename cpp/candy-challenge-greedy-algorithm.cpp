#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


// Complete the minimumPasses function below.
long long minimumPasses(long long m,long long w,long long p,long long n) {
    long long candyMade=0;
    long long current=0;
    long long maxDays = 1e12;
    while(candyMade<n){
        cout<<"running.. "<<candyMade<<endl;
        bool check = (m > 1e12/w);
        long long steps = check ?0 : (p - candyMade)/(m*w);
        if(steps<=0){
            long long buy = candyMade/p;
            long long  total = ceil(buy*1.0/2);
            if(m<w){
                m+=total;
                w+= buy-total;
            }
            else{
                m+= buy-total;
                w+= total;
            }
            candyMade%=p;
            steps=1;
            cout<<"going through.."<<candyMade<<" This step: "<<steps<<endl;
        }
        current+=steps;
        //cout<<"before ------>"<<candyMade<<" steps: "<<steps<<" m: "<<m<<" w: "<<w<<" incurre by : "<<steps*m*w<<endl;
        candyMade+= steps*m*w;
        //cout<<"after ------>"<<candyMade<<" steps: "<<steps<<" m: "<<m<<" w: "<<w<<endl;
        maxDays=max(min(maxDays,(long long)(current+ceil((n-candyMade)*1.0/(w*m)))),(long long)1);
    }
    //cout<<current<<" "<<maxDays<<endl;
    return max(min(current,maxDays),(long long)1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long long m;

    long long w;

    long long p;

    long long n;

    cin>>m>>w>>p>>n;

    long long result = minimumPasses(m, w, p, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
