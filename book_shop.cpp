// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// int helper(int amount , int idx , vector<int>& prices , vector<int>& pages ,
//    vector < vector<int> >& dp){
//     if(amount < 0 || idx < 0)return 0;
//     if(amount == 0)return 0;
//     if(idx == 0 && prices[idx] <= amount)return pages[idx];

//     if(dp[amount][idx] != -1){
//         return dp[amount][idx];
//     }
    
//     int not_take =0 + helper(amount ,idx-1 , prices ,pages ,dp);
//     int take = 0;

//     if(prices[idx] <= amount){
//         take = pages[idx] + helper(amount-prices[idx] ,idx-1 , prices ,pages ,dp);
//     }
    
//     return dp[amount][idx] = max(take ,not_take);
//    }

// signed main(){
//     int n;
//     int x;
//     cin>>n;
//     cin>>x;

//     vector<int>prices;
//     vector<int>pages;

//     for(int i = 0 ; i < n ; i++){
//         int x;
//         cin>>x;
//         prices.push_back(x);
//     }
//         for(int i = 0 ; i < n ; i++){
//         int x;
//         cin>>x;
//         pages.push_back(x);
//     }
    
//     vector < vector<int> >dp(x+1 , vector<int>(n+1 ,-1));

//     int count = helper(x , n-1 , prices ,pages , dp);

//     cout<<count;

// }

//optimal code 

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, x;
    cin >> n >> x;

    vector<int> prices(n), pages(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int cap = x; cap >= prices[i]; cap--) {
            dp[cap] = max(dp[cap], pages[i] + dp[cap - prices[i]]);
        }
    }

    cout << dp[x];
}
