# 01背包问题
容量C,数量n,代价v[i],价值w[i],dp[i],
``` 
//二维情况
    vector<int> v(n+1,0);
    vector<vector<int> > dp(n+1,vector<int>(m+1,0));//要求最大即可，不要求刚好装满
    //要求刚好装满，需要给f(*,0) = 0,f(*,!=0) = -INF
    for(int i = 1;i<=n;++i){
        for(int j = 0;j<=C;++j){
            dp[i][j] = dp[i-1][j];
            if(j>=v[i])
                dp[i][j] = max(dp[i][j],dp[i-1][j-v[i]]+w[i]);
        }
    }
//一维情况
    vector<int> dp(C+1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = C; j >= v[i]; --j) {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
```

# 完全背包问题
容量C,数量n,代价v[i],价值w[i],dp[i],
```
//一维情况
    //不需要正好装满 dp[0->C]<-0
    //要求正好装满  dp[0]<-0,dp[1->C]<-(-INF)
    vector<int> dp(C+1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = v[i]; j <= C; ++j) {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
```