//#include<bits/stdc++.h>
//#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
//#define pii pair<int,int>
//#define mp(X,Y) make_pair(X,Y)
//#define mt(X,Y) make_tuple(X,Y)
//#define mtt(X,Y,Z) make_tuple(X,Y,Z)
//#define ll long long
//#define sz(v) (int)(v).size()
//
//using namespace std;
//
//int main(void)
//{
//    fastio;
//    int n, k;
//    cin >> n >> k;
//
//    int left = 1;
//    int right = k;
//
//    while(left + 1 < right)
//    {
//        int cnt = 0;
//        int mid = (left + right) / 2;
//        for(int i = 1; i <= n; i++)
//            cnt += min(mid/i, n);
//        if(cnt >= k)
//            right = mid;
//        else
//            left = mid;
//    }
//    cout << right << "\n";
//}

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n, k;

bool isValid(ll cand){
    ll cnt = 0;
    for(int i = 1; i <= n; i++){
        cnt += min((ll)n, cand / i);
    }
    return cnt>= k;
}

int main(){
    cin >> n >> k;

    ll left = 0;
    ll right = (ll)n * n;

    while(left + 1 < right){
        ll mid = (left + right) >> 1;
        if(!isValid(mid)){
            left = mid;
        }else{
            right = mid;
        }
    }
    cout << right <<"\n";
}