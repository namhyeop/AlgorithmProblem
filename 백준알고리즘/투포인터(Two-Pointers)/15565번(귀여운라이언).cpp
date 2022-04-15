#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6 + 1;
int n, k;
int arr[MAX];
int aKind, bKind;
int ans = INT_MAX;

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    int sum = 0;
    for(int l = 1, r = 0; l <= n; l++){
        while(r < n && sum < k){
            r++;
            if(arr[r] == 1)
                sum++;
        }

        if(sum == k)
            ans = min(ans, r - l + 1);

        if(arr[l] == 1)
            sum--;
    }
    if(ans == INT_MAX)
        cout << -1 << "\n";
    else
        cout << ans <<"\n";
}
