#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 1;
int n;
int arr[MAX];
void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

void pro(){
    int l = 0;
    int r = n - 1;
    int ans = INT_MAX;
    sort(arr , arr + n);
    int v1 = 0, v2 = 0;
    while(l < r){
        if(ans > abs(arr[l] + arr[r])){
            ans = abs(arr[l] + arr[r]);
            v1 = arr[l];
            v2 = arr[r];
        }
        if(arr[l] + arr[r] > 0)
            r--;
        else
            l++;
    }
    cout << v1 << " "<< v2 <<"\n";
}
int main(){
    input();
    pro();
}