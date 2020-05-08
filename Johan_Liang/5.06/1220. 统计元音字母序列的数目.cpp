//1220. 统计元音字母序列的数目
// Created by Administrator on 2020/5/8 0008.
//

class Solution {
public:
    int countVowelPermutation(int n) {
        if(n == 0) return 0;
        long long int M = pow(10,9)+7;
        vector<vector<long long>> dp(n, vector<long long>(5, 0));
        for(int j = 0; j < 5; ++j){
            dp[0][j] = 1;
        }
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < 5; ++j){
                if(dp[i-1][j] && j == 0){
                    dp[i][1] += dp[i-1][j];
                    dp[i][1] %= M;
                }
                if(dp[i-1][j] && j == 1){
                    dp[i][0] += dp[i-1][j];
                    dp[i][0] %= M;
                    dp[i][2] += dp[i-1][j];
                    dp[i][2] %= M;
                }
                if(dp[i-1][j] && j == 2){
                    dp[i][0] += dp[i-1][j];
                    dp[i][0] %= M;
                    dp[i][1] += dp[i-1][j];
                    dp[i][1] %= M;
                    dp[i][3] += dp[i-1][j];
                    dp[i][3] %= M;
                    dp[i][4] += dp[i-1][j];
                    dp[i][4] %= M;
                }
                if(dp[i-1][j] && j == 3){
                    dp[i][2] += dp[i-1][j];
                    dp[i][2] %= M;
                    dp[i][4] += dp[i-1][j];
                    dp[i][4] %= M;
                }
                if(dp[i-1][j] && j == 4){
                    dp[i][0] += dp[i-1][j];
                    dp[i][0] %= M;
                }
            }
        }
        long long int res = 0;
        for(int j = 0; j < 5; ++j){
            res += dp[n-1][j];
            cout << res << endl;
        }
        return res%M;
    }
};