#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int findinggcd(int a,int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    return findinggcd(b%a,a);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int a,b;
    cin>>a>>b;
    cout<<findinggcd(a,b);  
    return 0;
}
