#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int findlength(string name){
    int length=0;
    for(int i=0;i<name.size();i++){
        length++;
    }
    return length;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string name;
    cin>>name;
    cout<<findlength(name);   
    return 0;
}
