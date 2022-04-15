#include<bits/stdc++.h>

#define ll long long

using namespace std;

int solution(int n){
    int useValue = 0;
    while(n != 0){
        if(n % 2 ==0){
            n /= 2;
        }
        else{
            n-= 1;
            useValue++;
        }
    }
    return useValue;
}

int main(){
    int test1 = solution(1000000000);
    cout << test1 <<"\n";
}