#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

int solution(string s){

	int answer = 1;

	for (size_t i = 1; i <= s.size(); i++){
		int left = i - 1, right = i + 1, count_1 = 0, count_2 = 1;
		bool f1 = false, f2 = false;

	/*	cout << "======================" << "\n";
		cout << "left : " << left << ", right : " << right << '\n';*/
		while (left >= 0 && right <= s.size()){
			if (s[left] == s[right - 1]) count_1 += 2;
			else f1 = true;

			/*cout << "s[left] : " << s[left] << ", s[right -1] : " << s[right - 1] << ",count_1 : " << count_1 << "\n";*/
		
			if (s[left] == s[right]) count_2 += 2;
			else f2 = true;
			//cout << "s[left] : " << s[left] << ", s[right] : " << s[right] << ",count_2 : " << count_2 << "\n";
			left--, right++;
			if (f1 && f2) break;
		}


		int result = (count_1 > count_2) ? count_1 : count_2;
		answer = (result > answer) ? result : answer;
		/*cout << "answer : " << answer << "\n";
		cout << "======================" << "\n";*/
	}
	return answer;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cout << solution("abaabc") << "\n";
	//cout << solution("abacde") << "\n";
}
