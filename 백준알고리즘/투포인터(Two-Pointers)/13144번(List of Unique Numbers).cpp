#include <bits/stdc++.h>

using namespace std;
const int MAX = 100001;
#define ll long long
int n;
int arr[MAX];
int cnt[MAX];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    ll ans = 0;
    for(int l = 0, r = -1; l < n; l++){
        while(r + 1< n && cnt[arr[r + 1]] == 0){
            r++;
            cnt[arr[r]]++;
        }
        ans += r - l + 1;

        cnt[arr[l]]--;
    }
    cout << ans <<"\n";
}