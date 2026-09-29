#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a,int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int firstjug,secondjug,capacity;
    cin>>firstjug>>secondjug>>capacity;
    int ans=gcd(firstjug,secondjug);
    if(capacity%ans==0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO";
    }
    return 0;
}
