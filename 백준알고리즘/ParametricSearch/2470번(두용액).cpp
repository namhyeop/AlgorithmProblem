/**
  5
 -2 4 -99 -1 98
 -99, -2, -1, 4, 98
-3 1 3 3 3 4
 5 2 4 7
 */
#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 1;
int n, arr[MAX];
int maxValue = INT_MAX;

int lower_bound(int l, int r, int findValue) {
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (!(arr[m] >= findValue)) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}

void process() {
    sort(arr, arr + n);
    int ret1 = 0, ret2 = 0;
    for (int i = 0; i < n - 1; i++) {
        int pos = lower_bound(i + 1, n - 1, -arr[i]);
        if (i < pos - 1 && abs(arr[i] + arr[pos - 1]) < maxValue) {
            ret1 = arr[i];
            ret2 = arr[pos - 1];
            maxValue = abs(arr[i] + arr[pos - 1]);
        }
        if (pos < n && abs(arr[i] + arr[pos]) < maxValue) {
            ret1 = arr[i];
            ret2 = arr[pos];
            maxValue = abs(arr[i] + arr[pos]);
        }
    }
    cout << ret1 << " " << ret2 << "\n";
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    process();
}
