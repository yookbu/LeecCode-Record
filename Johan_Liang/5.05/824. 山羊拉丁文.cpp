//824. 山羊拉丁文
// Created by Administrator on 2020/5/7 0007.
//

class Solution {
public:
    string toGoatLatin(string S) {
        if(S.empty()) return "";
        int i = 0;
        int cnt = 0;
        string res = "";
        while(S.find(" ", i) != string::npos){
            cnt++;
            int spaceIndex = S.find(" ", i);
            string w = S.substr(i, spaceIndex-i);
            if(w[0] == 'a' || w[0] == 'e' || w[0] == 'i' || w[0] == 'o' || w[0] == 'u'||
               w[0] == 'A' || w[0] == 'E' || w[0] == 'I' || w[0] == 'O' || w[0] == 'U'){
                w += "ma";
                string a(cnt, 'a');
                w += a;
                res += w + " ";
            }else{
                string ww(w.begin()+1, w.end());
                ww += w[0];
                ww += "ma";
                string a(cnt, 'a');
                ww += a;
                res += ww + " ";
            }
            i = spaceIndex+1;
        }
        cnt++;
        string w = S.substr(i);
        if(w[0] == 'a' || w[0] == 'e' || w[0] == 'i' || w[0] == 'o' || w[0] == 'u' ||
           w[0] == 'A' || w[0] == 'E' || w[0] == 'I' || w[0] == 'O' || w[0] == 'U'){
            w += "ma";
            string a(cnt, 'a');
            w += a;
            res += w;
        }else{
            string ww(w.begin()+1, w.end());
            ww += w[0];
            ww += "ma";
            string a(cnt, 'a');
            ww += a;
            res += ww;
        }
        return res;
    }
};