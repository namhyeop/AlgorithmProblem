#include <bits/stdc++.h>

using namespace std;

int n,m, a[500000 + 1], b[500000 + 1];

int lower_bound(int k){
    int left = -1;
    int right = n;
    while(left + 1 < right){
        int mid = (left + right) / 2;
        if(!(a[mid] >= k)) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    return right;
}

int upper_bound(int k){
    int left = -1;
    int right = n;
    while(left + 1 < right){
        int m = (left + right) >> 1;
        if(!(a[m] > k)) {
            left = m;
        }
        else {
            right = m;
        }
    }
    return right;
}

int main(){
    cin >> n ;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(a, a + n);
    for(int i = 0; i < m; i++) {
        int pos1 = lower_bound(b[i]);
        int pos2 = upper_bound(b[i]);
        cout <<pos2 - pos1 <<" ";
    }
    cout <<"\n";
}