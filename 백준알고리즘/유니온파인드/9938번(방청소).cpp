#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

const int MAX = 3e5;
pair<int, int> parent[MAX];
int level[MAX];
int naver, maver; //이걸 왜 11번째줄로 옮기면 오답이 나오지? 결국 해결 못함 - 2021.08.04

int find(int c)
{
	if (c == parent[c].first)
		return c;
	return parent[c].first = find(parent[c].first);
}

void merge(int c, int p)
{
	c = find(c);
	p = find(p);

	if (p == c)
	{
		if (parent[c].second - 1 < 0)
			cout << "SMECE\n";
		else
		{
			parent[c].second--;
			cout << "LADICA\n";
		}
		return;
	}
	//c의 레벨이 항상 더 크게 설정, c가 상위 루트로 정한다
	if (level[c] < level[p])
		swap(p, c);
	//부모의 루트가 c가 되도록한다.
	parent[p].first = c;
	//p와 c의 깊이가 같을 때 c의 깊이를 늘려준다
	if (level[p] == level[c])
		++level[c];

	if (parent[p].second + parent[c].second - 1 < 0)
		cout << "SMECE\n";
	else
	{
		parent[c].second += parent[p].second - 1;
		cout << "LADICA\n";
	}
}

int main(void)
{
	fastio;

	cin >> naver >> maver;

	for (int i = 1; i <= maver; i++)
	{
		parent[i].first = i;
		parent[i].second = 1;
		level[i] = 1;
	}

	for (int i = 0; i < naver; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		merge(tmp1, tmp2);
	}

	return 0;
}

