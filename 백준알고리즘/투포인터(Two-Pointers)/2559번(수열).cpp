#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 1;
int n, k;
int arr[MAX];
int sum = 0;
int kind = 0;

void add(int r){
    sum += arr[r];
    kind++;
}

void erase(int l){
    sum -= arr[l];
    kind--;
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    int maxValue = INT_MIN;
    for(int l = 1, r = 1; r <= n; r++){
        add(r);
        while(kind > k) {
            erase(l++);
        }
//        cout << sum <<"\n";
        if(kind >= k)
            maxValue = max(maxValue, sum);
    }
    cout << maxValue <<"\n";
}