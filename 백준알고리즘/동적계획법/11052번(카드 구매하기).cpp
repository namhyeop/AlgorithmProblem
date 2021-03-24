#include<bits/stdc++.h>

using namespace std;
const int MAX = 1001;
int cache[MAX];
int arr[MAX];
int n;

void solve()
{
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= i; j++)
		cache[i] = max(cache[i], cache[i - j] + arr[j]);
}
int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	solve();
	cout << cache[n];
}
/*
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int cache[10001];
int input[10001];
int n;
//count = 카드의 숫자들의 합을 의미한다
int search(int count)
{
	if (count >= n) //카드의 합이 n보다 크면 0을 반환하겠다
		return 0;

	int &ret = cache[count];

	if (ret != -1)
		return ret;
//nextstate는 1~n까지의 모든 카드들을 더하는 경우의 수를 테스트한다
	for (int nextstate = 1; nextstate <= n; nextstate++)
	{
		if (count +nextstate<=n) // 카드의 합이 되지 않았다면 계속 분할해서 
		ret = max(ret, search(count + nextstate) + input[nextstate]); //계속 더해준뒤 for문으로 모든 경우의 수를 탐색하겠다
	}

	return ret;	
}

int main(int argc, char * argv[])
{
	cin >> n;

	memset(cache, -1, sizeof(cache));
	for (int i = 1; i <= n; i++)
		cin >> input[i];

	cout << search(0) << endl;

}
*/
