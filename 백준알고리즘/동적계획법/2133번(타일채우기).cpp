#include<bits/stdc++.h>

using namespace std;

int n;
int cache[31];//가로 n의 경우 최대 갯수

int solve(int num)
{
	if (num % 2 == 1) //한 칸이 남으면 모두 못 채우는 경우
		return 0;
	else if (num == 0)//기본 값일 경우
		return 1;
	else if (num == 2)//3 * 2의 경우를 채우는 경우의 수는 3가지
		return 3;

	int &ret = cache[num];
	if (ret != -1)
		return ret;

	ret = 3 * solve(num - 2);

	for (int i = 0; i <= num - 4; i++)
		ret += 2 * solve(i);

	return ret;
}
int main()
{
	cin >> n;
	memset(cache, -1, sizeof(cache));
	cout << solve(n) << "\n";
	
	return 0;
}
