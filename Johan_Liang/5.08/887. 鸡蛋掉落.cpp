//
// Created by Administrator on 2020/5/9 0009.
//

class Solution {
public:
    map<pair<int, int>, int> m;
    int superEggDrop(int K, int N) {
        return dp(K,N);
    }
    int dp(int K, int N){
        if(m.find({K, N}) == m.end()){
            int ans;
            if(N == 0){
                ans = 0;
            }else if(K == 1){
                ans = N;
            }else{
                int l = 1, r = N;
                while(l+1 < r){
                    int mid = (l + r)/2;
                    int t1 = dp(K-1, mid-1);
                    int t2 = dp(K, N-mid);

                    if(t1 < t2){
                        l = mid;
                    }else if(t2 < t1){
                        r = mid;
                    }
                    else{
                        l = r = mid;
                    }
                }
                ans = 1+min(max(dp(K-1, l-1), dp(K,N-l)), max(dp(K-1,r-1), dp(K,N-r)));
            }
            m.insert({{K, N}, ans});
        }
        return m[{K,N}];
    }
};