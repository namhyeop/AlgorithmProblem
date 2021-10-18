#include<bits/stdc++.h>

using namespace std;

struct web {
    int idx;
    int basicPoint;
    vector<string> outLink;
    double linkPoint;
    double matchPoint;
};

map<string ,int> webNum;

bool Cmp(web a, web b){
    if(a.matchPoint != b.matchPoint){
        return a.matchPoint > b.matchPoint;
    }
    if(a.matchPoint == b.matchPoint){
        return a.idx < b.idx;
    }
    return false;
}

struct master {
    string word;
    vector<string> pages;
    master(string word, vector<string> pages) : word(word), pages(pages) {}

    vector<web> makeInfo(){
        vector<web> info;
        word = smallLetter(word);
        int idx = 0;
        for(auto str : pages){
            string parsingStr = smallLetter(str);
            string myUrl = findMyUrl(str);
            webNum[myUrl] = idx + 1;
            int basicPoint = cntWord(parsingStr);
            vector<string> outLink = findOutLink(parsingStr);
            info.push_back({idx++, basicPoint, outLink, 0.0, 0.0});
        }
        for(auto i : info){ //i는 info의 위치
            for(auto s : i.outLink){//s는 i번째 web의 외부링크들을 의미
                if(webNum[s] == 0)
                    continue;
                info[webNum[s] - 1].linkPoint += (double)i.basicPoint / (double)i.outLink.size();
            }
        }
        for(auto &i : info){
            i.matchPoint = (double)i.basicPoint + (double)i.linkPoint;
        }
        sort(info.begin(), info.end(), Cmp);
        return info;
    }

    string findMyUrl(string str){
        string ret;
        int pos1 = str.find("<meta property=\"og:url\" content=\"https://");
        pos1 += string("<meta property=\"og:url\" content=\"https://").length();
        while(str[pos1] != '\"'){
            ret += str[pos1++];
        }
        return ret;
    }

    string smallLetter(string str){
        string ret;
        for(auto c : str){
            if(c == '\n'){
                ret += " ";
            }
            else if(c >= 'A' &&  c <= 'Z')
                ret += c + 32;
            else
                ret += c;
        }
        return ret;
    }

    int cntWord(string str){
        int wordCnt = 0;
        int pos1 = str.find("<body>");
        pos1 += 7;
        int pos2 = str.find("</body>");
        pos2 += 7;
        str = str.substr(pos1, pos2 - pos1);

        string cur = "";
        for(int i = 0; i < str.length(); i++){
            if(isalpha(str[i]) == 0){
                if(cur == word)
                    wordCnt++;
                cur ="";
            }
            else
                cur += str[i];
        }
        return wordCnt;
    }

    vector<string> findOutLink(string str){
        vector<string> ret;
        int pos = str.find("<a href=\"https://");
        while(pos != -1){
            pos += string("<a href=\"https://").length();
            string url = "";
            while(str[pos] != '\"'){
                url += str[pos++];
            }
            ret.push_back(url);
            str = str.substr(pos);
            pos = str.find("<a href=\"https://");
        }
        return ret;
    }
};

int solution(string word, vector <string> pages) {
    int answer = 0;
    master op(word, pages);
    vector<web> ret = op.makeInfo();
    answer = ret[0].idx;
    return answer;
}

int main() {
    cout << solution("blind",
                     {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>",
                      "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>",
                      "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"
                     }) <<"\n";
    cout <<solution("Muzi", {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"});
}

