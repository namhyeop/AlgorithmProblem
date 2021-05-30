#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

const int MAX = 2;
const int MOD = 1e9 + 7;

class Fibonacci
{
private:
	long long fibonacci[MAX][MAX];
public:
	Fibonacci()
	{
		memset(fibonacci, 0, sizeof(fibonacci));
	}
	Fibonacci &operator*(Fibonacci &f)
	{
		Fibonacci result;

		for (int k = 0; k < MAX; k++)
		for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			result.fibonacci[k][i] += (fibonacci[k][j] * f.fibonacci[j][i]) % MOD;
		
		for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			fibonacci[i][j] = result.fibonacci[i][j];

		return *this;
	}

	long long *operator[](int i)
	{
		return fibonacci[i];
	}

	long long answer(void)
	{
		return fibonacci[0][1];
	}
};

Fibonacci unitmatrix, formula;

Fibonacci pow(Fibonacci &f, ll n)
{
	if (n == 0)
		return unitmatrix;

	if (n == 1)
		return formula;

	if (n % 2)
		return pow(f, n - 1) * f;

	Fibonacci half = pow(f, n / 2);
	
	return half * half;
}

void initalize(void)
{
	formula[0][0] = formula[0][1] = formula[1][0] = 1;
	formula[1][1] = 0;

	unitmatrix[0][0] = unitmatrix[1][1] = 1;
	unitmatrix[0][1] = unitmatrix[1][0] = 0;
}

int main(void)
{
	fastio;

	long long n;
	cin >> n;

	initalize();
	Fibonacci result = pow(formula, n);

	cout << result.answer() % MOD<< "\n";
}
