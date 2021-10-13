#include<bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = INT_MAX;

    //종료지점 설정으 위해 weak[i] + n 값을 더해준다. 이런 과정을 통해 탐색의 범위를 지정해줄수 있다.
    int wSize= weak.size();
    for(int i = 0; i < wSize; i++){
        weak.push_back(weak[i] + n);
    }
    //next_permutaion을 통한 순열을 사용하기 위한 정렬
    sort(dist.begin(), dist.end());

    do{
        for(int i = 0; i < wSize; i++){
            int start = weak[i];
            int end = weak[i + wSize - 1];
            for(int j = 0; j < dist.size(); j++){
                start += dist[j];
                //다음 지점이 종료지점을 넘었으면 갱신후 다음탐색 진행
                if(start >= end){
                    answer = min(answer, j + 1);
                    break;
                }
                //외벽을 넘는 가장 큰 지점을 탐색
                int next = upper_bound(weak.begin(), weak.end(), start) - weak.begin();
                start = weak[next];
            }
        }
    }while(next_permutation(dist.begin(), dist.end()));

    if(answer == INT_MAX)
        return -1;
    return answer;
}

int main(){
    int n = 12;
    vector<int> weak = {1, 5, 6, 10};
    vector<int> dist  {1, 2, 3, 4};
    cout << solution(n, weak, dist) <<"\n";
}
