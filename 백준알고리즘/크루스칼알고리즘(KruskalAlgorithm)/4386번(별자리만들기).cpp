#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

const int MAX = 101;
int parents[MAX];
vector<pair<double, double>> v;
vector<tuple<int, int, double>> distan;

int n;
double ret;
bool cmp(tuple<int, int, double> a, tuple<int, int, double> b)
{
	if (get<2>(a) != get<2>(b))
		return get<2>(a) < get<2>(b);
}
int find(int x)
{
	if (parents[x] == x)
		return x;
	return x = find(parents[x]);
}

bool merge(int p, int c)
{
	p = find(p);
	c = find(c);

	if (p == c)
		return false;

	parents[p] = c;

	return true;
}

double cal_dist(double y1, double x1, double y2, double x2)
{
	double num1 = pow(y1 - y2, 2);
	double num2 = pow(x1 - x2, 2);
	return sqrt(num1 + num2);
}

int main(void)
{
	fastio;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		double x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	for (int i = 1; i <= n; i++)
		parents[i] = i;

	for (int i = 0; i < n - 1; i++)
	for (int j = i + 1; j < n; j++)
	{
		double d = cal_dist(v[i].first, v[i].second, v[j].first, v[j].second);
		distan.push_back(mt(i,j,d));
	}

	sort(distan.begin(), distan.end(), cmp);

	for (auto &d : distan)
	{
		if (merge(get<0>(d), get<1>(d)))
			ret += get<2>(d);
	}
	cout << fixed;
	cout.precision(2);
	cout << ret << "\n";
}
