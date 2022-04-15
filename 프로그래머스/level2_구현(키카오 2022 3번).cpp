#include<bits/stdc++.h>

using namespace std;

/**
 * 어떤 차량이 입차된 후 출차된 내역 없을 경우 23:59분 출차
 * 누적 주차 시간이 기본 시간 이하면 기본 요금 청구
 * 누적 주차 시간이 기본 시간을 초과시 기본 요금에 더해서 초과한 시간에 대해 단위 시간 마다 단위 요금 청구(나누어 떨어지지 않을 경우 올림처리)
 * 1.데이터 파싱
 * 2.번호, cost 구조체 하나 선언
 * 3.시각, 번호, 내역 용 구초체 선언
 * 4.찾고, 지우는 방식으로 진행
 */

/**
 * 차 넘버, 비용이 들어갈 최종 자료형
 * /
map<int, int> retTime;

/**
 * records 자료들을 파싱한 정보들이 들어가 자료형
 */
struct info {
    int time;
    int carNum;
    string state;
};

/**
 * 파싱할 정보들의 컨테이너
 */
vector<info> infoList;

/**
 * 파싱해주는 함수
 */
info to_parse(string str) {
    info ret;
    stringstream ss(str);
    string tmp;
    vector<string> arr;
    while (getline(ss, tmp, ' ')) {
        arr.push_back(tmp);
    }
    int h = stoi(arr[0].substr(0, 2)) * 60;
    int m = stoi(arr[0].substr(3, 2));
    ret.time = h + m;
    ret.carNum = stoi(arr[1]);
    ret.state = arr[2];
    return ret;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    /**
     * to_parse 함수를 사용하여 파싱
     */
    for (auto str: records) {
        infoList.push_back(to_parse(str));
    }
    /**
     * 차량이 IN인 경우에는 그 다음에 OUT이 존재하므로 j는 i + 1로 설정
     */
    for (int i = 0; i < infoList.size(); i++) {
        if (infoList[i].state == "IN") {
            for (int j = i + 1; j < infoList.size(); j++) {
                if (infoList[i].carNum == infoList[j].carNum && infoList[j].state == "OUT") {
                    int time = infoList[j].time - infoList[i].time;
                    retTime[infoList[i].carNum] += time;
                    infoList.erase(infoList.begin() + j);
                    infoList.erase(infoList.begin() + i);
                    /**
                     * 차량 정보값을 갱신했다면 위에서 삭제 연산이 진행되므로 i를 한 칸 낮춰줘야 한다.
                     */
                    i--;
                }
            }
        }
    }

    /**
     * 정보가 남아 있는 경우는 OUT한 경우가 아니므로 23:59(1439)로 -연산을 진행해준다.
     */
    for (int i = 0; i < infoList.size(); i++) {
        retTime[infoList[i].carNum] += (1439 - infoList[i].time);
    }

    vector<pair<int, int>> v(retTime.begin(), retTime.end());

    /**
     * 비용 산정 과정
     */
    for (auto &item: v) {
        if (item.second <= fees[0]) {
            item.second = fees[1];
        } else {
            item.second = fees[1] + (ceil(((double) item.second - fees[0]) / fees[2]) * fees[3]);
        }
    }

    sort(v.begin(), v.end());
    for (const auto &a: v) {
        answer.push_back(a.second);
    }
    return answer;
}

int main() {
    solution({180, 5000, 10, 600},
             {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN",
              "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"});
}