#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int majorityelement(vector<int>&v){
    int count=1;
    int cand=v[0];
    for(int i=1;i<v.size();i++){
        if(cand==v[i]){
            count++;
            if(count>(v.size())/2){
                return cand;
            }
        }
        else{
            if(count==0){
                cand=v[i];
                count++;
            }
            else{
                count--;
               // cand=v[i];
            }
        }
    }
    count=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==cand){
            count++;
        }
    }
    if(count>(v.size())/2){
        return cand;
    }
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }  
    cout<<majorityelement(v);
    return 0;
}
