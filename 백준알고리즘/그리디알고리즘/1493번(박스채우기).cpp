#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;

ll length;
ll width;
ll height;
ll N;
ll ret;
int flag = 0;

vector<pair<int, int>> v; //2의 0승 개의 개수를 저장한다.
int cube[20];

void operate(int length, int width, int height, int curidx)
{
	if (length == 0 || width == 0 || height == 0)
		return;

	for (int i = curidx; i < v.size(); i++)
	{
		//v[i].second != 0 == 도형 수가 아직 남아있다면
		if (v[i].second != 0 && length >= v[i].first && width >= v[i].first && height >= v[i].first)
		{
			v[i].second--;
			ret++;
			operate(length - v[i].first, width, height, i);
			operate(v[i].first, width - v[i].first, height, i);
			operate(v[i].first, v[i].first, height - v[i].first, i);
			return;
		}
	}
	flag = 1;
}

int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> length >> width >> height;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		cube[a] += b;
	}

	//31줄 반복문 작업을 통해 길이가 긴 순서대로 정렬이 되게 v에 들어간다
	for (int i = 19; i >= 0; i--)
	{
		if (cube[i] != 0)
			v.push_back({ pow(2, i), cube[i] });
	}
	
	/*
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first <<" " <<  v[i].second<< "\n";
	*/

	operate(length, width, height, 0);
	
	if (flag)
		cout << -1 << "\n";
	else
		cout << ret << "\n";
	return 0;
}
