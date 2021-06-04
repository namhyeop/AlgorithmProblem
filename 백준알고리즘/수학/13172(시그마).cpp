#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
#define int int64_t

const int MOD = (int)1e9 + 7;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int minv(int a, int b)
{
	if (a == 0 && b == 1)
		return 0;
	if (a == 1)
		return 1;
	return b - minv(b%a, a) * b / a;
}

int32_t main(void)
{
	fastio;
	int t, ans = 0;
	cin >> t;

	while (t--) //1. n면체 주사위를 t번 받는다.
	{
		int a, b;
		cin >> a >> b; //2. n번째 주사위의 a값과 b값을 받는다.
		int g = gcd(a, b);//3. 최대공약수를 구한다.
		a /= g; //4.최대공약수로 a값을 한 번 나눈다.
		b /= g; //5/최대공약수로 b값을 한 번 나눈다.
		ans = (ans + b * minv(a, MOD)) % MOD; //6.ans는 정답을 담는 변수. minv함수를 이용해 b^-1의 최소값을 찾는다.
	}
	cout << ans << "\n";
}
