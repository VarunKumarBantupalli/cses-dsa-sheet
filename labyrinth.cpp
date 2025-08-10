#include <bits/stdc++.h>
using namespace std;
#define int long long

bool dfs(int row, int col, int m, int n,
         vector<vector<char>>& grid,
         vector<vector<int>>& visited,
         string& path) {
    
    if (row < 0 || row >= m || col < 0 || col >= n) return false;
    if (visited[row][col]) return false;
    
    visited[row][col] = 1;
    if (grid[row][col] == 'B') return true;
    
    // Left
    path.push_back('L');
    if (dfs(row, col-1, m, n, grid, visited, path)) return true;
    path.pop_back();
    
    // Right
    path.push_back('R');
    if (dfs(row, col+1, m, n, grid, visited, path)) return true;
    path.pop_back();
    
    // Up
    path.push_back('U');
    if (dfs(row-1, col, m, n, grid, visited, path)) return true;
    path.pop_back();
    
    // Down
    path.push_back('D');
    if (dfs(row+1, col, m, n, grid, visited, path)) return true;
    path.pop_back();
    
    return false;
}

signed main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> visited(m, vector<int>(n, 0));
    string path = "";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'A') {
                if (dfs(i, j, m, n, grid, visited, path)) {
                    cout << "YES\n" << path.size() << "\n" << path;
                    return 0;
                }
            }
        }
    }

    cout << "NO";
}
