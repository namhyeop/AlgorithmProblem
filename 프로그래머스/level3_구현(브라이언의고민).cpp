/*
1 - 1.대문자인 경우
	1- 1 - 1)다음 문자가 대문자인 경우
		1-1-1-1) 현재 문자를 하나의 단어로 취급한다(규칙을 적용받지 않는 단어들은 다른 단어로 구분)
	1- 1- 2)다음 문자가 소문자인 경우
		1-1-1-2) 찾고있는 문자열에서 동일한 소문자의 시작과 끝의 idx값, 개수를 구한다.

1- 2.소문자인 경우
	1-2-1)찾고 있는 문자열에서 동일한 소문자의 시작과 끝 idx값, 개수 정보를 구한다.
	1-2-2)동일 소문자가 두 개 있는 경우
		1-2-2-1) 규칙 2번이 확인 되어있는 상태이고 그 다음 문자가 대문자라면
			1-2-2-1-1) 규칙 1번을 확인한다.
		1-2-2-2) 그게 아니라면 규칙 2번을 확인한다.
	1-2-3)동일 소문자가 1개 또는 3개 이상인 경우
		1-2-3-1)규칙 1번을 확인한다
*/

#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

int N;
vector<int> group;
vector<bool> rule_1;
vector<bool> rule_2;
vector<bool> used;
int w_idx;

struct info
{
	int start, end, cnt;
};

string make_answer(string &sentence)
{
	//첫 번째 대문자를 인덱스로 설정
	int last_idx = 0;
	for (int i = 0; i < N; i++)
	{
		if (isupper(sentence[i]))
		{
			last_idx = group[i];
			break;
		}
	}

	string answer = "";
	for (int i = 0; i < N; i++)
	{
		char c = sentence[i];
		if (isupper(c))
		{
			if (group[i] != last_idx)
				answer += ' ';

			answer += c;
			last_idx = group[i];
		}
	}
	return answer;
}

bool check_rule_1(string &sentence, info l_info, char c)
{
	if (used[c - 'a'] == true)
		return false;

	if (l_info.start - 1 < 0 || l_info.end + 1 >= N)
		return false;

	if (islower(sentence[l_info.start - 1]) || islower(sentence[l_info.end + 1]))
		return false;

	int l_cnt = 0;
	int u_cnt = 0;

	for (int i = l_info.start - 1; i <= l_info.end + 1; i++)
	{
		char now = sentence[i];

		if (islower(now))
		{
			if (now == c)
			{
				group[i] = w_idx;
				l_cnt++;
				u_cnt = 0;
			}
			else
			{
				return false;
			}
		}
		else if (isupper(now))
		{
			l_cnt = 0;
			u_cnt++;

			if (rule_1[i] == true)
			{
				return false;
			}
			else
			{
				group[i] = w_idx;
				rule_1[i] = true;
			}
		}
		if (l_cnt > 1 || u_cnt > 1)
			return false;
	}

	++w_idx;
	used[c - 'a'] = true;
	return true;
}


bool check_rule_2(string& sentence, info l_info, char c)
{
	if (used[c - 'a'] == true)
	{
		return false;
	}

	if (l_info.end - l_info.start < 2)
		return false;

	group[l_info.start] = w_idx;
	group[l_info.end] = w_idx;

	for (int i = l_info.start + 1; i < l_info.end; i++)
	{
		char now = sentence[i];

		if (isupper(now))
		{
			if (rule_2[i] == true)
				return false;
			else
			{
				group[i] = w_idx;
				rule_2[i] = true;
			}
		}
	}

	++w_idx;
	used[c - 'a'] = true;
	return true;
}

info get_char_info(string &sentence, char c)
{
	int start = -1;
	int cnt = 0;
	int end = 0;

	for (int i = 0; i < N; i++)
	{
		if (sentence[i] == c)
		{
			if (start < 0)
			{
				start = i;
			}
			cnt++;
			end = i;
		}
	}
	return{ start, end, cnt };
}

bool decrtpying_possible(string &sentence)
{
	for (int i = 0; i < N; i++)
	{
		char now = sentence[i];

		if (now == ' ')
			return false;

		if (group[i] == 0)
		{
			if (isupper(now))
			{
				//마지막 문자일 경우. 현재 문자를 별개의 단어로 취급한다.
				if (i + 1 >= N)
				{
					group[i] = w_idx++;
					continue;
				}
				char next = sentence[i + 1];

				if (isupper(next))
				{
					group[i] = w_idx++;
				}
				//규칙의 시작을 의미한다. 그러므로 특수문자의 시작과 끝의 위치값, 갯수를 가져온다.
				else if (islower(next))
				{
					info l_info = get_char_info(sentence, next);

					//특수 문자의 개수가 2개이면 그것은 규칙 2를 의미. 하나의 단어로 취급한다.
					if (l_info.cnt == 2)
					{
						group[i] = w_idx++;
					}
					//특수 문자의 개수가 2개가 아니라면 현재 특수문자(next를 의미)가 한 번 더 나오는지 확인한다.
					else
					{
						if (check_rule_1(sentence, l_info, next) == false)
							return false;
					}
				}
			}

			else if (islower(now))
			{
				info l_info = get_char_info(sentence, now);

				if (l_info.cnt == 2)
				{
					//다음 문자가 대문자이고 규칙 2번이 이미 적용된 상태라면
					//현재 문자를 포함하는 단어가 규칙 1번을 적용한지 확인한다.
					if (isupper(sentence[i + 1]) && rule_2[i + 1])
					{
						if (check_rule_1(sentence, l_info, now) == false)
						{
							return false;
						}
					}
					//그렇지 않으면 현재 문자를 포함하는 단어가 규칙 2번을 적용하는지 확인한다.
					else
					{
						if (check_rule_2(sentence, l_info, now) == false)
							return false;
					}
				}
				else
				{
					if (check_rule_1(sentence, l_info, now) == false)
					{
						return false;
					}
				}
			}
		}
	}

	return true;
}

string solution(string sentence)
{
	N = sentence.size();
	group = vector<int>(N);
	rule_1 = vector<bool>(N);
	rule_2 = vector<bool>(N);
	used = vector<bool>(26);
	w_idx = 1;

	bool result = decrtpying_possible(sentence);

	if (!result)
		return "invalid";

	return make_answer(sentence);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string a = "HaEaLaLaObWORLDb";

	cout << solution(a) << "\n";
}
