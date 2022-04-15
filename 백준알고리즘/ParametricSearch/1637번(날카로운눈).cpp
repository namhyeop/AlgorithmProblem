#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 20005;
int n;
int arr[MAX][3];

int calculate(int a, int c, int b, int cand){
    //추측값이 a보다 작은 경우 정수 더미에는 개수가 존재하지 않음
    if(cand < a){
        return 0;
    }
    //추측값이 a보다 큰 경우 정수 더미에서 개수는 시작a가 있으모로 (c-a) / b + 1
    if(cand > c){
        return (c - a) / b + 1;
    }
    //추측값이 범위내에 있는 경우 정수 더미에서 개수는 시작a가 있으모로 (cand-a) / b + 1
    return (cand - a) / b + 1;
}

bool isOdd(ll cand){
    ll sum = 0;
    for(int i = 0; i < n; i++){
        //각 정수더미 구간의 홀수 갯수 파악
        sum += calculate(arr[i][0], arr[i][1], arr[i][2], cand);
    }
    //홀수 개수가 맞다면 참 아니면 거짓
    return sum % 2 == 1;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }
    ll l = 0;
    ll r = (1ll << 31);
    while(l + 1 < r){
        ll mid= (l + r) >> 1;
        if(isOdd(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    ll ansCnt = 0;
    if(r == (1ll << 31)){
        cout << "NOTHING" << "\n";
    }else{
        for(int i = 0; i < n ; i ++){
//            (r - arr[i][0] % arr[i][2] == 0) -> 내가 보고 있는 정수 더미에 포함 되어 있는가, 맞을 경우 Cnt UP!)
            if(arr[i][0] <= r && r <= arr[i][1] && (r - arr[i][0]) % arr[i][2] == 0) {
                ansCnt++;
            }
        }
        cout << r <<" " << ansCnt <<"\n";
    }
}