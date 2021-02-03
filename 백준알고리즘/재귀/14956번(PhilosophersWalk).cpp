#include<bits/stdc++.h>

using namespace std;

int n, m, ret;

pair<int, int> hilbert(int N, int M)
{
	pair<int, int> p;
	if (N == 2)
	{
		switch (M)
		{
		case 0:
			p = { 1, 1 };
			return p;
		case 1:
			p = { 1, 2 };
			return p;
		case 2:
			p = { 2, 2 };
			return p;
		case 3:
			p = { 2, 1 };
			return p;
		}
	}

	int half = N / 2;
	int quadrant = M / (half * half);
	switch (quadrant)
	{
		//좌하
	case 0:
		p = hilbert(half, M % (half *half));
		swap(p.first, p.second);
		return p;
		//좌상
	case 1:
		p = hilbert(half, M % (half * half));
		p.second += half;
		return p;
	case 2:
		//우상
		p = hilbert(half, M % (half * half));
		p.first += half;
		p.second += half;
		return p;
	case 3:
		//우하
		p = hilbert(half, M % (half * half));
		pair<int, int> temp = { 2 * half - p.second + 1, half - p.first + 1 };
		return temp;
	}
}
int main(int argc, char *argv[])
{
	cin >> n >> m;
	pair<int, int> ret = hilbert(n, m - 1);
	cout << ret.first << " " << ret.second << "\n";
}
