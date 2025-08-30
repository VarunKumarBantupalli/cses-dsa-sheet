#include <bits/stdc++.h>
using namespace std;
#define int long long

int helper(int left, int right, vector<int> &arr, vector<vector<int>> &dp)
{

    int n = arr.size();

    if (left < 0 || left >= n || right < 0 || right >= n)
        return 0;

    if (left > right)
        return 0;
    if (left == right)
        return arr[left];

    if (dp[left][right] != -1)
    {
        return dp[left][right];
    }

    int l = arr[left] + min(helper(left + 2, right, arr, dp), helper(left + 1, right - 1, arr, dp));
    int r = arr[right] + min(helper(left, right - 2, arr, dp), helper(left + 1, right - 1, arr, dp));

    return dp[left][right] = max(l, r);
}

signed main()
{
    int n;
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    bool allZero = true;
    for (int x : arr)
    {
        if (x != 0)
        {
            allZero = false;
            break;
        }
    }
    if (allZero)
    {
        cout << -1;
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));

    int count = helper(0, n - 1, arr, dp);

    cout << count;
}