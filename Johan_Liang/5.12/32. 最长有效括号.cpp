//
// Created by Administrator on 2020/5/12 0012.
//


// dp
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        vector<int> dp(s.size(), 0);
        for(int i = 1; i < s.size(); ++i){
            if(s[i] == ')' && s[i-1] == '('){
                dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
            }
            if(s[i] == ')' && s[i-1] == ')' && (i - dp[i-1]) > 0 && s[i-dp[i-1]-1] == '('){
                dp[i] = (i-dp[i-1] >= 2 ? dp[i-dp[i-1]-2] : 0) + dp[i-1] + 2;
            }

            res = dp[i] > res ? dp[i] : res;
        }
        return res;
    }
};