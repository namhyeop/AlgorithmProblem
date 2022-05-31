#include <bits/stdc++.h>

using namespace std;
const int MAX = 10005;
int n;
int arr[MAX];
int cache[MAX][2];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
}

void pro() {
    cache[1][0] = arr[1];
    cache[1][1] = arr[1];
    cache[2][0] = arr[2];
    cache[2][1] = arr[1] + arr[2];

    for (int i = 3; i <= n; i++) {
        //2번째 전에 있는 잔을 고른 경우, 안고른 경우 중 더 큰걸 현재와 더한 값
        cache[i][0] = max(cache[i - 2][0] + arr[i], cache[i - 2][1] + arr[i]);
        cache[i][0] = max({cache[i][0], cache[i - 3][0] + arr[i], cache[i - 3][1] + arr[i]});
        cache[i][1] = cache[i - 1][0] + arr[i];
    }

    cout << max({cache[n][0], cache[n][1], cache[n - 1][0], cache[n -1][1]}) << "\n";
}

//6 10 13 9 8 1
//
//1. i번 잔을 마신 경우와 안마신 경우
//2. i번 잔이 3번째 연속인지 나누는 방법은?


int main() {
    input();
    pro();
}

//#include<bits/stdc++.h>
//
//using namespace std;
//const int MAX = 10001;
//int n;
//int arr[MAX];
//int cache[MAX];
//
//int main(void)
//{
//	cin >> n;
//
//	for (int i = 1; i <= n; i++)
//		cin >> arr[i];
//
//	cache[1] = arr[1];
//
//	if (n > 1)
//		cache[2] = arr[1] + arr[2];
//
//	if (n > 2)
//	for (int i = 3; i <= n; i++)
//	{
//		cache[i] = max(cache[i-1], cache[i - 2] + arr[i]); //맨 끝에서 이전총합만 고를 수 있는 경우와 이전전총합과 자기 자신을 고르는 경우와 전전전총합과 현재값과 이전값을 고르는 경우
//		cache[i] = max(cache[i], cache[i - 3] + arr[i - 1] + arr[i]);
//	}
//	cout << cache[n] << "\n";
//
//	return 0;
//}
