#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int countingsetbits(int n){
    int count=0;
    for(int i=0;i<31;i++){
        if(n&(1<<i)){
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin>>n;
    cout<<countingsetbits(n);
    return 0;
}
