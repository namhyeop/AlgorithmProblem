#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main(int argc, char * argv[])
{
	//입력 안잠구면 시간 초과 발생함
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	int n;
	int m;
	cin >> n >> m;

	vector<string> v(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];

	//입력값들에 고유번호 부여 과정
	vector<pair<string, int>> inputV(n);
	for (int i = 0; i < n; i++)
	{
		inputV[i].first = v[i + 1]; //초기 입력값에 대한 값들 부여
		inputV[i].second = i + 1; //각 언어나 숫자에 고유번호 부여
	}

	//알파벳순으로 검색하기 위한 정렬
	sort(inputV.begin(), inputV.end());

	//검색시작
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;

		//숫자가 입력된 경우
		if (s[0] >= '0' && s[0] <= '9')
		{
			int idx = 0;
			for (int i = 0; i < s.length(); i++)
			{
				idx += s[i] - '0';
				idx *= 10 ; //자릿수 찾는 과정
			}
			idx /= 10;
			cout << v[idx] << "\n";
		}
		//문자열이 입력된 경우
		else
		{
			int start = 0;
			int end = n - 1;
			while (start <= end)
			{
				int mid = (start + end) / 2;

				if (inputV[mid].first == s)
				{
					cout << inputV[mid].second << "\n";
					break;
				}
				//알파벳 순이니까 찾으려는 s값보다 더 크면 시작 지점을 바꿔준다.
				else if (inputV[mid].first < s)
					start = mid + 1;
				//찾으려는 s보다 중간값이 더 작으면 end값을 중간값으로 바꿔서 단축시킨다.
				else
					end = mid - 1;
			}
		}
	}

	return 0;
}
