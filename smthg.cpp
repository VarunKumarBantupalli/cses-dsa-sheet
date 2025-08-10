#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <set>
#include <map>
#include <functional>

int solution(std::vector<std::string> cr) {
    const std::string& w1 = cr[0];
    const std::string& w2 = cr[1];
    const std::string& w3 = cr[2];

    std::set<char> cs;
    for (const auto& w : cr) {
        for (char c : w) {
            cs.insert(c);
        }
    }
    std::vector<char> ch(cs.begin(), cs.end());
    size_t k = ch.size();

    if (k > 10) return 0;

    size_t ml = std::max(w1.length(), w2.length());
    if (w3.length() < ml || w3.length() > ml + 1) return 0;

    std::set<char> ld;
    if (w1.length() > 1) ld.insert(w1[0]);
    if (w2.length() > 1) ld.insert(w2[0]);
    if (w3.length() > 1) ld.insert(w3[0]);

    int count = 0;
    std::vector<int> p(k);
    std::vector<bool> used(10, false);

    std::function<void(int)> solve = 
        [&](int ci) {
        
        if (ci == k) {
            std::map<char, int> m;
            for (size_t i = 0; i < k; ++i) {
                m[ch[i]] = p[i];
            }

            auto to_num = [&](const std::string& w) {
                long long n = 0;
                for (char c : w) n = n * 10 + m.at(c);
                return n;
            };

            if (to_num(w1) + to_num(w2) == to_num(w3)) {
                count++;
            }
            return;
        }

        char cc = ch[ci];
        for (int d = 0; d <= 9; ++d) {
            if (!used[d]) {
                if (d == 0 && ld.count(cc)) continue;
                
                p[ci] = d;
                used[d] = true;
                solve(ci + 1);
                used[d] = false;
            }
        }
    };

    solve(0);
    return count;
}