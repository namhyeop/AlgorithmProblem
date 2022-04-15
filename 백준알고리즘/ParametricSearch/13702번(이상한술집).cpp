#include <bits/stdc++.h>

using namespace std;
const int MAX = 10001;
#define ll long long
int n, m;
int arr[MAX];

int isMin(int k){
    ll ret = 0;
    for(int i = 0; i < n; i++){
        ret += arr[i] / k;
    }
    if(ret < m)
        return false;
    else
        return true;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    ll left = 0;
//     ll right = (1ll << 31) - 1;
    ll right = arr[n - 1] + 1;

    while(left + 1 < right){
        ll mid = (left + right) >> 1;
        if(isMin(mid)){
            left = mid;
        }else{
            right = mid;
        }
    }
    cout << left << "\n";
}