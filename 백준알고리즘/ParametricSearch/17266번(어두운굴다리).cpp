#include<bits/stdc++.h>

using namespace std;

int n,m;
const int MAX = 1e5 + 1;
int arr[MAX];

bool isValid(int k){
    int start = 0;
    for(int i = 0; i < m; i++) {
        if(arr[i] - start <= k){
            start = arr[i] + k;
        }
        else{
            return false;
        }
    }
    return start >= n;
}

int main(){
    cin >> n >> m;
    for(int i  = 0; i < m; i++){
        cin >> arr[i];
    }
    int l = 0;
    int r = n + 1;
    while(l + 1 < r){
        int mid = (l + r) >> 1;
        if(!isValid(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << r << "\n";
}