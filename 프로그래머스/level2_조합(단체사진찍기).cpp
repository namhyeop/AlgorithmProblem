#include<bits/stdc++.h>

using namespace std;

struct rule {
    char sender;
    char recivier;
    char sign;
    int dist;
};

int solution(int n, vector<string> data) {
    vector<rule> rules;
    for (int i = 0; i < n; i++) {
        string curData = data[i];

        char sender = curData[0];
        char reciver = curData[2];
        char sign = curData[3];
        int dist = curData[4] - '0';
        rules.push_back({sender, reciver, sign, dist});
    }

    vector<char> bar = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

    int count = 0;
    do {
        bool flag = true;
        for(auto rule : rules){
            auto[sender, reciver, sign, dist] = rule;
            int pos1 = find(bar.begin(), bar.end(), sender) - bar.begin();
            int pos2 = find(bar.begin(), bar.end(), reciver) - bar.begin();
            int between = pos1 - pos2;

            if(sign == '<'){
                if(!(abs(between)-1 < dist)) {
                    flag = false;
                    break;
                }
            }
            else if(sign == '>'){
                if(!(abs(between)-1 > dist)) {
                    flag = false;
                    break;
                }
            }
            else if(sign == '='){ // ==
                if(!(abs(between)-1 == dist)) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
            count++;
    } while (next_permutation(bar.begin(), bar.end()));

    cout << count <<"\n";
    return count;
}

int main() {
    int n = 2;
    vector<string> data = {"N~F=0", "R~T>2"};
    solution(n, data);

}