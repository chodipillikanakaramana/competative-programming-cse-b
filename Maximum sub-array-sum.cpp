#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int maxsubarray(vector<int>&v){
    int maxend=v[0];
    int sum=v[0];
    for(int i=1;i<v.size();i++){
        maxend=max(v[i],v[i]+maxend);
        sum=max(sum,maxend);
    }
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<maxsubarray(v);  
    return 0;
}
