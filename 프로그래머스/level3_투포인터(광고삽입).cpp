#include<bits/stdc++.h>
#define ll long long
using namespace std;


struct play{
    int timeArr[360000];
    string playTime;
    string advTime;
    vector<string> logs;
    play(string playTime, string advTime, vector<string> logs) : playTime(playTime), advTime(advTime), logs(logs), timeArr{} {}

    int strToint(string str){
        int h = stoi(str.substr(0,2)) * 3600;
        int m = stoi(str.substr(3,2)) * 60;
        int s = stoi(str.substr(6,2));
        return h + m + s;
    }

    string iTostr(int num){
        string h = to_string(num / 3600); num %= 3600;
        string m = to_string(num / 60); num %= 60;
        string s = to_string(num);

        if(h.size() == 1){
            h.push_back('0');
            reverse(h.begin(), h.end());
        }
        if(m.size() == 1){
            m.push_back('0');
            reverse(m.begin(), m.end());
        }
        if(s.size() == 1){
            s.push_back('0');
            reverse(s.begin(), s.end());
        }
        string ret = h + ":" + m + ":" +s;
        return ret;
    }

    //전체 진행과정
    string simulation(){
        for(auto s : logs){
            //logs 각 항목에 대한 시작값과 종료값을 정수형로 바꿔준다
            int start = strToint(s.substr(0,8));
            int end = strToint(s.substr(9, 8));
            //구간별 합을 구하기 위해서 시작값과 종료과의 범위의 값을 1씩 증가 시킨다.
            for(int i = start; i < end; i++){
                timeArr[i]++;
            }
        }

        //광고 상영 전체 시간과 광고의 시작 시간을 정수형으로 바꿔 준다.
        ll pTime = strToint(playTime);
        ll adTime = strToint(advTime);

        queue<int> q;
        ll sum = 0;
        ll maxSum = 0;
        //구간의 합의 최대를 비교하기 위해 sum 변수안에 값들을 저장해주고 투 포인터를 진행하기 위해 큐에 구간의 값을 넣어준다.
        for(int i = 0; i < adTime; i++){
            sum += timeArr[i];
            q.push(timeArr[i]);
        }
        maxSum = sum;
        int cursor = 0;
        //큐의 투 포인터를 진행하는 과정 61번줄에서 광고의 시작부터 광고 상영시간의 합까지 구했다. 그러므로 시작값을 광고의 상영시간(int i = adTime) 부터 종료시간까지의 구간합을 구하면 된다.
        for(int i = adTime; i < pTime; i++){
            sum += timeArr[i]; //1.광고의 다음 값을 더하고
            sum -= q.front(); //2.한 칸 이동했으니 광고의 첫 번째 값을 빼주고
            q.push(timeArr[i]);//큐의 값을 갱신
            q.pop();//큐의 값을 갱신
            if(sum > maxSum){//만약 광고의 합계값이 이전의 최고 값 보다 크면 현재 cursor값이 가장 큰 광고 시작 시간을 의미
                maxSum = sum;
                cursor = i - adTime + 1;
            }
        }
        return iTostr(cursor);
    }
};

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    play op(play_time, adv_time, logs);
    answer = op.simulation();
    return answer;
}

int main(){
    cout << solution("02:03:55", "00:14:15", {"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"}) <<"\n";
}

//#include<bits/stdc++.h>
//#define ll long long
//
//using namespace std;
//const int MAX = 360000;
//int ad[MAX];
//
//string secToStr(int n)
//{
//	string ret;
//	int h, m, s;
//
//	s = n % 60, n /= 60;
//	m = n % 60, n /= 60;
//	h = n;
//
//	if (h < 10)
//		ret += "0";
//	ret += to_string(h);
//	ret += ":";
//
//	if (m < 10)
//		ret += "0";
//	ret += to_string(m);
//	ret += ":";
//
//	if (s < 10)
//		ret += "0";
//	ret += to_string(s);
//
//	return ret;
//}
//
//string solution(string play_time, string adv_time, vector<string> logs)
//{
//	string answer = "";
//
//	ll maxValue = 0;
//
//	int allTime = stoi(play_time.substr(0, 2)) * 3600 + stoi(play_time.substr(3, 2)) * 60 + stoi(play_time.substr(6, 2));
//	int adTime = stoi(adv_time.substr(0, 2)) * 3600 + stoi(adv_time.substr(3, 2)) * 60 + stoi(adv_time.substr(6, 2));
//
//	for (int i = 0; i < logs.size(); i++)
//	{
//		int start = stoi(logs[i].substr(0, 2)) * 3600 + stoi(logs[i].substr(3, 2)) * 60 + stoi(logs[i].substr(6, 2));
//		int end = stoi(logs[i].substr(9, 2)) * 3600 + stoi(logs[i].substr(12, 2)) * 60 + stoi(logs[i].substr(15, 2));
//
//		for (int i = start; i < end; i++)
//			ad[i]++;
//	}
//
//	int idx = 0;
//	ll tmpSum = 0;
//
//	queue<int> q;
//	for (int i = 0; i < adTime; i++)
//	{
//		tmpSum += ad[i];
//		q.push(ad[i]);
//	}
//	maxValue = tmpSum; //00:00::00 부터 광고시작 시간의 합계, 지금은 초기값이다. 밑의 과정을 통해 최대 시청시간을 산출한다.
//
//	for (int i = adTime; i < allTime; i++)
//	{
//		tmpSum += ad[i];
//		q.push(ad[i]);
//		tmpSum -= q.front();
//		q.pop();
//
//		if (tmpSum > maxValue)
//		{
//			idx = i - adTime + 1;
//			maxValue = tmpSum;
//		}
//	}
//
//	answer = secToStr(idx);
//
//	return answer;
//}
//
//int main()
//{
//	string playTime = "99:59:59";
//	string adv_time = "25:00:00";
//	vector<string> logs = { "69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00" };
//
//	cout << solution(playTime, adv_time, logs) << "\n";
//}
