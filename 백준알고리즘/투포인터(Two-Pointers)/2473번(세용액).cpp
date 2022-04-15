#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MAX = 5001;
int n;
int arr[MAX];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    sort(arr + 1, arr + 1 + n);
    ll sum = LLONG_MAX;
    int v1 = 0, v2 = 0, v3 = 0;
    for(int i = 1; i <= n - 2; i++){
        int l = i + 1, r = n;
        while(l < r){
            if(sum > abs((ll)arr[l] + arr[r] + arr[i])){
                sum = abs((ll)arr[l] + arr[r] + arr[i]);
                v1 = arr[i];
                v2 = arr[l];
                v3 = arr[r];
            }
            //자신의 탐색값과 부호가 반대인 값을 기준으로 생각해야 0에 가까워짐
            if(-arr[i] > arr[r] + arr[l]){
                l++;
            }else
                r--;
        }
    }
    cout << v1 << " " << v2 << " " << v3 <<"\n";
}

//-10 -4 -3 -2  10
//-97 - 6 -2 6 98

