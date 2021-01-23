#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

ll ret;
vector<ll> input;

int main(int argc, char *argv[])
{
	ll N;
	cin >> N;
	
	ll left = 0;
	ll right = N - 1;

	for (int i = 0; i < N; i++)
	{
		ll tmp;
		cin >> tmp;
		input.push_back(tmp);
	}

	sort(input.begin(), input.end());

	while (left < right)
	{
		if (input[left] < 1 && input[left + 1] < 1)
			ret += input[left] * input[left + 1];
		else
			break;

		left += 2;
	}
	
	while (right > 0)
	{
		if (input[right] > 1 && input[right - 1] > 1)
			ret += input[right] * input[right - 1];
		else
			break;

		right -= 2;
	}
	
	while (right >= left)
	{
		ret += input[right];
		right--;
	}

	cout << ret << "\n";

	return 0;
}
