#include <bits/stdc++.h>

using namespace std;
const int MAX = 10001;
int n;
int arr[MAX];
//[i][0] : i번째 계단까지 오는 경우 이전 계단을 밟지 않고 온 경우의 최대값
//[i][1] : i번째 계단까지 오는 경우 이전 계단을 밟고 온 경우의 최대값
int cache[MAX][2];
void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
}

void pro(){
    cache[1][0] = arr[1];
    cache[1][1] = arr[1];

    cache[2][0] = arr[2];
    cache[2][1] = arr[1] + arr[2];

    for(int i = 3; i <= n; i++){
        cache[i][0] = max(cache[i - 2][0] + arr[i], cache[i - 2][1] + arr[i]);
        cache[i][1] = cache[i - 1][0] + arr[i];
    }
//
//    for(int i = 1; i <= n; i++){
//        cout << cache[i][0] <<" ";
//    }
//    cout <<"\n";
//    for(int i = 1; i <= n; i++){
//        cout << cache[i][1] <<" ";
//    }
//    cout <<"\n";
    cout << max(cache[n][0], cache[n][1]);
}

int main(){
    input();
    pro();
}

//최대값 경로 출력 버전
//#include <bits/stdc++.h>
//
//using namespace std;
//const int MAX = 10001;
//int n;
//int arr[MAX];
////[i][0] : i번째 계단까지 오는 경우 이전 계단을 밟지 않고 온 경우의 최대값
////[i][1] : i번째 계단까지 오는 경우 이전 계단을 밟고 온 경우의 최대값
//pair<int,int> cache[MAX][2];
//int parent[MAX];
//void input(){
//    cin >> n;
//    for(int i = 1; i <= n; i++){
//        cin >> arr[i];
//    }
//}
//
//void pro(){
//    cache[1][0] = {arr[1], 0};
//    cache[1][1] = {arr[1],0};
//
//    cache[2][0] = {arr[2], 0};
//    cache[2][1] = {arr[1] + arr[2], 1};
//
//    for(int i = 3; i <= n; i++){
//        cache[i][0] = {max(cache[i - 2][0].first + arr[i], cache[i - 2][1].first + arr[i]), i - 2};
//        cache[i][1] = {cache[i - 1][0].first + arr[i], i - 1};
//    }
//
//    for(int i = 1; i <= n; i++){
//        cout << cache[i][0].first <<" ";
//    }
//    cout <<"\n";
//    for(int i = 1; i <= n; i++){
//        cout << cache[i][1].first <<" ";
//    }
//    cout <<"\n";
//
//    int maxValue = max(cache[n][0].first, cache[n][1].first);
//    int startPos;
//    for(int i = 0; i <= 1; i++){
//        if(cache[n][i].first == maxValue){
//            startPos = cache[n][i].second;
//            break;
//        }
//    }
//
//    string ret; ret += to_string(n);
//    while(startPos != 0){
//        ret += to_string(startPos);
//        int maxValue = max(cache[startPos][0].first, cache[startPos][1].first);
//        for(int i = 0; i <= 1; i++){
//            if(cache[startPos][i].first == maxValue){
//                startPos = cache[startPos][i].second;
//                break;
//            }
//        }
//    }
//    reverse(ret.begin(), ret.end());
//    cout << ret <<"\n";
//    cout << max(cache[n][0].first, cache[n][1].first);
//}
//
//int main(){
//    input();
//    pro();
//}