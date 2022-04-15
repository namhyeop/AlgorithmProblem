#include<bits/stdc++.h>

#define ll long long

using namespace std;

string to_trans(int n, int k) {
    string ret = "";
    while (n != 0) {
        ll value = n / k;
        ll mod = n % k;
        n = value;
        ret += to_string(mod);
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

bool isPrime(ll num){
    if(num < 2)
        return 0;
    for(ll i = 2; i * i <= num; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

int split(string str){
    int ret = 0;
    for (auto &item: str) {
        if(item == '0')
            item = ' ';
    }

    ll tmp;
    stringstream ss(str);
    while(ss >> tmp){
        ret += isPrime(tmp);
    }
    return ret;
}

int solution(int n, int k) {
    int answer = 0;
    string transformNum = to_trans(n, k);
    answer = split(transformNum);
    return answer;
}