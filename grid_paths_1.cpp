#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int MOD = 1e9+7;

int helper(int row , int col , vector<vector<char> >& grid ,vector< vector<int> >& dp){
    if(row < 0 || col < 0)return 0;
    if(row == 0 && col == 0)return 1;

    if(dp[row][col] != -1){
        return dp[row][col];
    }

    if(grid[row][col] == '*'){
        return 0;
    }

    int left = helper(row ,col-1 , grid ,dp);
    int up = helper(row-1 ,col , grid ,dp);

    return dp[row][col] = (left+up)%MOD;
}

signed main(){
    int n;
    cin>>n;

    vector<vector<char> >grid(n , vector<char>(n,'-'));
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ;j++){
            char x;
            cin>>x;
            grid[i][j] = x;
        }
    }

    if(grid[0][0] == '*'){
        cout<<0;
        return 0;
    }

    vector< vector<int> >dp(n+1 , vector<int>(n+1 ,-1));
    
    int count = helper(n-1,n-1,grid,dp) % MOD;

    cout<<count;


}