#include <bits/stdc++.h>
using namespace std;

int res;
unordered_set<char> z;
vector<string> c;
vector<char> u;
vector<int> current_assignment;
vector<bool> used_digits;

void h(int i) {
    if (i == u.size()) {
        long long sum = 0;
        long long right_side = 0;

        for (int k = 0; k < c.size() - 1; ++k) {
            long long num = 0;
            long long p = 1;
            for (int j = c[k].length() - 1; j >= 0; --j) {
                char ch = c[k][j];
                auto it = find(u.begin(), u.end(), ch);
                num += current_assignment[distance(u.begin(), it)] * p;
                p *= 10;
            }
            sum += num;
        }

        long long p_right = 1;
        for (int j = c.back().length() - 1; j >= 0; --j) {
            char ch = c.back()[j];
            auto it = find(u.begin(), u.end(), ch);
            right_side += current_assignment[distance(u.begin(), it)] * p_right;
            p_right *= 10;
        }
        
        if (sum == right_side) {
            res++;
        }
        return;
    }

    for (int j = 0; j < 10; ++j) {
        if (!used_digits[j]) {
            if (z.count(u[i]) && j == 0) {
                continue;
            }
            current_assignment[i] = j;
            used_digits[j] = true;
            h(i + 1);
            used_digits[j] = false;
        }
    }
}

// Main solution function
int s(vector<string>& crypt) {
    c = crypt;
    res = 0;
    unordered_set<char> l;
    u.clear();
    z.clear();

    for (const string& word : c) {
        for (char ch : word) {
            if (l.find(ch) == l.end()) {
                l.insert(ch);
                u.push_back(ch);
            }
        }
        if (word.length() > 1) {
            z.insert(word[0]);
        }
    }

    if (l.size() > 10) {
        return 0;
    }

    current_assignment.resize(u.size());
    used_digits.assign(10, false);
    h(0);
    return res;
}