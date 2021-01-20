#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int K;
int ret;
int main(int argc, char *argv[])
{
	cin >> N;
	cin >> K;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	//집중국이 더 많으면 셀 필요가 없다.
	if (K >= N)
	{
		cout << "0" << "\n";
		return 0;
	}

	sort(v.begin(), v.end());
	vector<int> diff(N - 1);

	for (int i = 0; i < N - 1; i++)
		diff[i] = v[i + 1] - v[i];
	
	sort(diff.begin(), diff.end());

	for (int i = 0; i < N - K; i++)
		ret += diff[i];

	cout << ret << "\n";

	return 0;
}
