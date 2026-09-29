#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> interchange(vector<int>v){
    int mini=0;
    int maxi=0;
    for(int i=1;i<v.size();i++){
        if(v[mini]>v[i]){
            mini=i;
        }
        if(v[maxi]<v[i]){
            maxi=i;
        } 
    }
    swap(v[mini],v[maxi]);
    return v;
}
void display(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }
    vector<int>u=interchange(v);
    display(u);
    return 0;
}
