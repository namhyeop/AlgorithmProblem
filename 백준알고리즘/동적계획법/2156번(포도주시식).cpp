#include<bits/stdc++.h>

using namespace std;
const int MAX = 10001;
int n;
int arr[MAX];
int cache[MAX];

int main(void)
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cache[1] = arr[1];

	if (n > 1)
		cache[2] = arr[1] + arr[2];

	if (n > 2)
	for (int i = 3; i <= n; i++)
	{
		cache[i] = max(cache[i-1], cache[i - 2] + arr[i]); //맨 끝에서 이전총합만 고를 수 있는 경우와 이전전총합과 자기 자신을 고르는 경우와 전전전총합과 현재값과 이전값을 고르는 경우
		cache[i] = max(cache[i], cache[i - 3] + arr[i - 1] + arr[i]);
	}
	cout << cache[n] << "\n";

	return 0;
}
