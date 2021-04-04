#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)

using namespace std;

int n, m;

int gcd(int a, int b)//최대공약수
{
	while (b != 0)
	{
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b) //최소공배수
{
	return a * b / gcd(a, b);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	cout << gcd(n, m) << "\n";
	cout << lcm(n, m) << "\n";

	return 0;
}
