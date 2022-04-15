#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 1e5 + 1;
int n, m;
int arr[MAX];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    sort(arr + 1, arr + n + 1);

    int ans = INT_MAX;
    for(int l = 1, r = 1; l <= n; l++){
        while(r < n && arr[r] - arr[l] < m){
            r++;
        }
//        cout << l <<" "<< r << "\n";
        if(arr[r] - arr[l] >= m){
            ans = min(ans, arr[r] - arr[l]);
        }
    }
    cout << ans <<"\n";
}
