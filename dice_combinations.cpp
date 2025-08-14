#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

int helper(vector<int>& dp , int n){
    if(n < 0) return 0;
    if(n == 0) return 1;

    if(dp[n] != -1) return dp[n];
     
    int ways = 0;
    for(int i = 1; i <= 6; i++){
        ways = (ways + helper(dp, n - i)) % MOD;
    }
    
    return dp[n] = ways;
}

signed main(){
    int n;
    cin >> n;
    
    vector<int> dp(n + 1, -1);
    int count = helper(dp, n);

    cout << count % MOD;
}
