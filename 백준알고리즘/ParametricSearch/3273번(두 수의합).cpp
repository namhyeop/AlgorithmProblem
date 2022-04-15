#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 1;
int n, x, arr[MAX], ret;
bool flag;

bool check(int arg1, int arg2){
    int value = arg1 + arg2;
    if(value == x) {
        ret++;
        flag = true;
    }
    return value < x;
}

void lower_bound(int l, int r, int searchValue){
    while(l + 1 < r){
        int m = (l + r) >> 1;
        if(check(searchValue, arr[m])) {
            if (flag)
                return;
            l = m;
        }
        else
            r = m;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    cin >> x;

    for(int i = 0; i < n - 1; i++){
        lower_bound(i, n - 1, arr[i]);
        flag = false;
    }
    cout << ret <<"\n";
}