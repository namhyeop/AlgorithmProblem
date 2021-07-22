#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1e6 + 1;
int n;
int numS[MAX];
int gcdLtoR[MAX];
int gcdRtoL[MAX];

int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main(void)
{
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> numS[i];

	gcdLtoR[0] = numS[0];
	for (int i = 1; i < n; i++)
	{
		gcdLtoR[i] = gcd(gcdLtoR[i - 1], numS[i]);
	}
	gcdRtoL[n - 1] = numS[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		gcdRtoL[i] = gcd(gcdRtoL[i + 1], numS[i]);
	}

	int max = 0;
	int maxIndex = 0;
	for (int i = 0; i < n; i++)
	{
		int gcd_value = 0;
		if (i == 0)
			gcd_value = gcdRtoL[1]; //누적합의 한칸전이 누적합 값을 의미
		else if (i == n - 1)
			gcd_value = gcdLtoR[n - 2];
		else
			gcd_value = gcd(gcdLtoR[i - 1], gcdRtoL[i + 1]);

		if (numS[i] % gcd_value != 0 && gcd_value > max) //뮨재에서 gcd로 뽑은 값이 나눠지면 안된다는 조건
		{
			max = gcd_value;
			maxIndex = i;
		}
	}
	if (max == 0)
		cout << -1 << "\n";
	else
		cout << max << " " << numS[maxIndex] << "\n";
	return 0;
}
