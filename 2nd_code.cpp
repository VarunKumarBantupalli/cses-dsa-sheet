#include <bits/stdc++.h>
using namespace std;

string w1, w2, w3;
vector<char> letters;          
unordered_map<char, int> mp;   
bool used[10];                 
int n1, n2, n3;                 
long long solutions;           

bool checkPartial(int col, int carry) {
    if (col >= max({n1, n2, n3})) {
        return carry == 0;
    }
    int c1 = (col < n1) ? mp[w1[n1 - col - 1]] : 0;
    int c2 = (col < n2) ? mp[w2[n2 - col - 1]] : 0;
    int c3 = (col < n3) ? mp[w3[n3 - col - 1]] : 0;

    if (c1 == -1 || c2 == -1 || c3 == -1) {
        return true; 
    }
    int sum = c1 + c2 + carry;
    return (sum % 10 == c3) && checkPartial(col + 1, sum / 10);
}

void backtrack(int idx) {
    if (idx == letters.size()) {
        if (checkPartial(0, 0)) solutions++;
        return;
    }
    char letter = letters[idx];
    for (int d = 0; d <= 9; d++) {
        if (used[d]) continue;
        if (d == 0 && ((letter == w1[0] && n1 > 1) || 
                       (letter == w2[0] && n2 > 1) || 
                       (letter == w3[0] && n3 > 1))) continue;

        mp[letter] = d;
        used[d] = true;
        if (checkPartial(0, 0)) backtrack(idx + 1);
        used[d] = false;
        mp[letter] = -1;
    }
}

int solution(vector<string> crypt) {
    w1 = crypt[0];
    w2 = crypt[1];
    w3 = crypt[2];
    n1 = w1.size();
    n2 = w2.size();
    n3 = w3.size();

    set<char> s;
    for (auto &w : crypt) s.insert(w.begin(), w.end());
    letters.assign(s.begin(), s.end());

    if (letters.size() > 10) return 0;

    mp.clear();
    for (char c : letters) mp[c] = -1;
    memset(used, false, sizeof(used));
    solutions = 0;

    backtrack(0);
    return solutions;
}

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         vector<string> crypt(3);
//         for (int i = 0; i < 3; i++) cin >> crypt[i];
//         cout << solution(crypt) << "\n";
//     }
//     return 0;
// }
