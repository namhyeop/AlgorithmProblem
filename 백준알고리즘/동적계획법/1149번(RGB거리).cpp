#include <bits/stdc++.h>

using namespace std;
const int MAX = 1001;
int n;
int arr[MAX][4];
int cache[MAX][4];

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 3; j++){
            cin >> arr[i][j];
        }
    }
}

void pro(){
    for(int i = 1; i <= n; i++){
        cache[i][1] = min(cache[i - 1][2], cache[i - 1][3]) + arr[i][1];
        cache[i][2] = min(cache[i - 1][1], cache[i - 1][3]) + arr[i][2];
        cache[i][3] = min(cache[i - 1][1], cache[i - 1][2]) + arr[i][3];
    }
//
//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j <= n; j++){
//            cout << cache[i][j] << " ";
//        }cout <<"\n";
//    }

    cout << min({cache[n][1], cache[n][2], cache[n][3]}) << "\n";
}

int main(){
    input();
    pro();
}

//#include<bits/stdc++.h>
//
//using namespace std;
//
//int DP[1001][3];
//int r[1001];
//int g[1001];
//int b[1001];
//int n;
//
//int main(void)
//{
//	cin >> n;
//
//	for (int i = 1; i <= n; i++)
//		cin >> r[i] >> g[i] >> b[i];
//
//	DP[1][0] = r[1];
//	DP[1][1] = g[1];
//	DP[1][2] = b[1];
//
//	for (int i = 2; i <= n; i++)
//	{
//		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + r[i];
//		DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + g[i];
//		DP[i][2] = min(DP[i - 1][0], DP[i - 1][1])  + b[i];
//	}
//	cout << *min_element(DP[n], DP[n] + 3);
//}
