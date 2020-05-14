//
// Created by Administrator on 2020/5/14 0014.
//

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> cur;
        vector<string> res;
        helper(0, 0, s, cur, res);
        return res;
    }
    void helper(int index, int count, string& s, vector<string>& cur, vector<string>& res){
        if(count == 4 && index == s.size()){
            string temp = cur[0];
            for(int i = 1; i < cur.size(); ++i){
                temp += '.' + cur[i];
            }
            res.push_back(temp);
        }else if (count < 4){
            for(int i = 1; i <=3; ++i){
                string num_s(s.begin()+index, s.begin()+index+i);
                if(num_s.size() > 1 && num_s[0] == '0') continue;
                int num = atoi(num_s);
                if(num >=0 && num <=255){
                    cur.push_back(num_s);
                    helper(index+i, count+1,s, cur, res);
                    cur.pop_back();
                }
            }
        }
    }

    int atoi(string s){
        int res = 0;
        for(char c : s){
            res = res*10 + (c-'0');
        }
        return res;
    }
};