#include<bits/stdc++.h>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;

    string arr = "";
    for(int i = 0; i < dungeons.size(); i++){
        arr += to_string(i);
    }

    do{
        int remainValue = k;
        int count = 0;

        for(int i = 0; i < dungeons.size(); i++){
            int pos = find(arr.begin(), arr.end(), '0' + i) - arr.begin();
            int needMinValue = dungeons[pos][0];
            int cost = dungeons[pos][1];

            if(remainValue > cost && remainValue >= needMinValue){
                remainValue -= cost;
                count++;
            }
            else{
                break;
            }
        }
        answer = max(answer, count);
    }while(next_permutation(arr.begin(), arr.end()));
    return answer;
}
int main() {
    cout << solution(80, {{80,20},{50,40},{30,10}}) << "\n";
}