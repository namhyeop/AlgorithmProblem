#include<bits/stdc++.h>

using namespace std;
#define ll long long
int n;
int arr[2001];

bool isValid(int targetIdx) {
    int l = 0;
    int r = n - 1;
    int tValue = arr[targetIdx];
    while (l < r) {
        if (l == targetIdx)
            l++;
        else if (r == targetIdx)
            r--;
        else {
            if (arr[l] + arr[r] == tValue) {
//                cout << l << r << " " << tValue << "\n";
                return true;
            }

            if (arr[l] + arr[r] > tValue) {
                r--;
            } else
                l++;
        }
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (isValid(i))
            ans++;
    }
    cout << ans << "\n";
}