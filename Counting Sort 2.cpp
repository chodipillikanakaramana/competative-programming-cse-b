#include <bits/stdc++.h>
using namespace std;
vector<int>countingsort(vector<int>&v){
    int maxi=INT_MIN;
    int mini=INT_MAX;
    for(int i=0;i<v.size();i++){
        maxi=max(v[i],maxi);
        mini=min(v[i],mini);
    }
    vector<int>temp(maxi+1,0);
    for(int i=0;i<v.size();i++){
        temp[v[i]]++;
    }
    int k=0;
    for(int i=0;i<temp.size();i++){
        while(temp[i]!=0){
            v[k++]=i;
            temp[i]--;
        }
    }
    return v;
}
void display(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>req=countingsort(v);
    display(req);
    return 0;
}
