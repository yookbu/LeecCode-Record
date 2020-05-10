//
// Created by Administrator on 2020/5/10 0010.
//

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        set<string> seen;
        string cur = "";
        helper(0, s, res, seen);
        return res;
    }

    void helper(int index, string s, vector<string>& res, set<string>& seen){
        if(index == s.size() && seen.find(s) == seen.end()){
            res.push_back(s);
            seen.insert(s);
        }else{
            for(int i = index; i < s.size(); ++i){
                char temp = s[index];
                s[index] = s[i];
                s[i] = temp;
                helper(index+1, s, res, seen);
                temp = s[index];
                s[index] = s[i];
                s[i] = temp;
            }
        }
    }
};