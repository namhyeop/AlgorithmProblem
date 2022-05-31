#include<bits/stdc++.h>

using namespace std;
const int MAX = 5005;
string str;
int n;
const int mod = 1e6;
int dp[MAX];

bool check(char a, char b){
    if(a == '0')
        return false;
    if(a == '1')
        return true;
    if(a >= '3')
        return false;
    return b <= '6';
}

void input(){
    cin >> str;
    n = str.size();
}

void pro(){
    if(str[0] != '0')
        dp[0] = 1;

    for(int i = 1; i < n; i++){
        if(str[i] != '0')
            dp[i] = dp[i - 1];
        if(check(str[i - 1], str[i])){
            if(i >= 2)
                dp[i] += dp[i - 2];
            else
                dp[i] += 1;
            dp[i] %= mod;
        }
    }
    cout <<dp[n - 1] <<"\n";
}
int main(){
    input();
    pro();
}

//#include<bits/stdc++.h>
//
//using namespace std;
//const int MAX = 5001;
//long long cache[MAX];
//long long arr[MAX];
//
//int main()
//{
//	string s;
//	cin >> s;
//
//	int lenSize = s.length();
//
//	//정수형으로 변환해주는 과정
//	for (int i = 0; i < lenSize; i++)
//		arr[i + 1] = s[i] - '0';
//
//	cache[0] = 1;
//	for (int i = 1; i <= lenSize; i++)
//	{
//		if (arr[i] >= 1 && arr[i] <= 9)
//			cache[i] = cache[i] + cache[i - 1] % 1000000;;
//
//		//exceptDigit은 두 자리인 정수들을 의미, 두 자리 정수일 경우 i-2값도 더해준다
//		int exceptDigit = arr[i - 1] * 10 + arr[i];
//		if (exceptDigit >= 10 && exceptDigit <= 26)
//			cache[i] = (cache[i] + cache[i - 2]) % 1000000;
//	}
//	cout << cache[lenSize] << "\n";
//
//	return 0;
//}
