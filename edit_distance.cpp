#include <bits/stdc++.h>
using namespace std;
#define int long long

int helper(int i , int j , string& word1 , string& word2 , vector < vector<int>>& dp){
    if(i < 0)return j+1;
    if(j < 0)return i+1;

    if(word1[i] == word2[j]){
        return helper(i-1 ,j-1 ,word1,word2,dp);
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int insert = helper(i,j-1,word1,word2,dp);
    int deleted = helper(i-1,j,word1,word2,dp);
    int replace = helper(i-1,j-1,word1,word2,dp);

    return dp[i][j] = 1 + min({insert,deleted,replace});
}


signed main(){

    string word1;
    string word2;

    cin>>word1;
    cin>>word2;

    int m = word1.size();
    int n = word2.size();

    vector < vector<int> >dp(m , vector<int>(n,-1));

    int count = helper(m-1 ,n-1 ,word1,word2 ,dp);
    cout<<count;

}