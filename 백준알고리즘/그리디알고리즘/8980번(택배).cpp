#include<bits/stdc++.h>

using namespace std;
const int MAX = 2001;
int n, c, m;

class info
{
public:
	int from;
	int to;
	int weight;
	info(int from, int to, int weight)
	{
		this -> from = from;
		this -> to = to;
		this -> weight = weight;
	}
};

bool cmp(info a, info b)
{
	if (a.to < b.to)
		return true;
	else
		return false;
}

int main()
{
	cin >> n >> c >> m;
	vector<info> arr;
	vector<int> left(n + 1, c);
	int box_cnt = 0;

	for (int i = 0; i < m; i++)
	{
		int from, to, cnt;
		cin >> from >> to >> cnt;
		arr.push_back({ from, to, cnt });
	}
	sort(arr.begin(), arr.end(), cmp);
	
	for (auto d : arr)
	{
		//정렬된 박스정보를 활용하여 정보의 가장 첫 번째 값 부터 도착지점까지
		//박스를 실을 수 있는 공간이 가장 적게 남은곳 구하기
		int min = left[d.from];
		for (int i = d.from + 1; i < d.to; i++)
		{
			if (min > left[i])
				min = left[i];
		}

		//만약 공간(min)보다 실어야 하는 박스가 많을 경우 공간 만큼만 싣는다.
		int cnt = d.weight;
		if (min < cnt)
			cnt = min;

		//계속 싣은 박스 갯수 저장해주기
		box_cnt += cnt;

		//공간에 실은 박스들의 갯수만큼 빼주기
		for (int i = d.from; i < d.to; i++)
		{
			left[i] -= cnt;
		}
	}
	cout << box_cnt;

	return 0;
}
