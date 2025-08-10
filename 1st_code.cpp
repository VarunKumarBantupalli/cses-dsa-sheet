#include <bits/stdc++.h>
using namespace std;

string w1, w2, w3;
vector<char> letters;          // unique letters
unordered_map<char, int> mp;   // letter → digit
bool used[10];                 // digit usage
int n1, n2, n3;                 // lengths of words
long long solutions = 0;

// Function to check column addition validity so far
bool checkPartial(int col, int carry) {
    if (col >= max({n1, n2, n3})) {
        return carry == 0;
    }

    int c1 = (col < n1) ? mp[w1[n1 - col - 1]] : 0;
    int c2 = (col < n2) ? mp[w2[n2 - col - 1]] : 0;
    int c3 = (col < n3) ? mp[w3[n3 - col - 1]] : 0;

    if (c1 == -1 || c2 == -1 || c3 == -1) {
        return true; // can't check yet
    }

    int sum = c1 + c2 + carry;
    return (sum % 10 == c3) && checkPartial(col + 1, sum / 10);
}

void solve(int idx) {
    if (idx == letters.size()) {
        if (checkPartial(0, 0)) solutions++;
        return;
    }

    char letter = letters[idx];
    for (int d = 0; d <= 9; d++) {
        if (used[d]) continue;

        // skip leading zero
        if (d == 0 && ((letter == w1[0] && n1 > 1) || (letter == w2[0] && n2 > 1) || (letter == w3[0] && n3 > 1)))
            continue;

        mp[letter] = d;
        used[d] = true;

        if (checkPartial(0, 0)) {
            solve(idx + 1);
        }

        used[d] = false;
        mp[letter] = -1;
    }
}

int main() {
    vector<string> crypt = {"SEND", "MORE", "MONEY"};
    w1 = crypt[0]; w2 = crypt[1]; w3 = crypt[2];
    n1 = w1.size(); n2 = w2.size(); n3 = w3.size();

    // collect unique letters
    set<char> s;
    for (auto &w : crypt) s.insert(w.begin(), w.end());
    letters.assign(s.begin(), s.end());

    // impossible if more than 10 unique letters
    if (letters.size() > 10) {
        cout << 0 << "\n";
        return 0;
    }

    // initialize mapping
    for (char c : letters) mp[c] = -1;
    memset(used, false, sizeof(used));

    solve(0);

    cout << solutions << "\n";
    return 0;
}
