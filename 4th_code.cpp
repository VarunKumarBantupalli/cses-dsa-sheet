// #include <bits.stdc++.h>
// using namespace std;

// long long word_to_num(const string& w, const map<char, int>& m) {
//     long long n = 0;
//     for (char c : w) {
//         n = n * 10 + m.at(c);
//     }
//     return n;
// }

// int solution(vector<string> crypt) {
//     const string& w1 = crypt[0];
//     const string& w2 = crypt[1];
//     const string& w3 = crypt[2];

//     size_t max_l = max(w1.length(), w2.length());
//     if (w3.length() < max_l || w3.length() > max_l + 1) {
//         return 0;
//     }

//     set<char> char_set;
//     for (const auto& w : crypt) {
//         for (char c : w) {
//             char_set.insert(c);
//         }
//     }
//     vector<char> chars(char_set.begin(), char_set.end());
//     size_t k = chars.size();

//     if (k > 10) {
//         return 0;
//     }

//     set<char> leads;
//     if (w1.length() > 1) leads.insert(w1[0]);
//     if (w2.length() > 1) leads.insert(w2[0]);
//     if (w3.length() > 1) leads.insert(w3[0]);

//     vector<int> d = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//     int count = 0;

//     do {
//         map<char, int> m;
//         for (size_t i = 0; i < k; ++i) {
//             m[chars[i]] = d[i];
//         }

//         bool lead_z = false;
//         for (char c : leads) {
//             if (m.at(c) == 0) {
//                 lead_z = true;
//                 break;
//             }
//         }
//         if (lead_z) {
//             continue;
//         }
//         long long n1 = word_to_num(w1, m);
//         long long n2 = word_to_num(w2, m);
//         long long n3 = word_to_num(w3, m);

//         if (n1 + n2 == n3) {
//             count++;
//         }

//     } while (next_permutation(d.begin(), d.end()));
    
//     int fact = 1;
//     for (int i = 1; i <= 10 - k; ++i) {
//         fact *= i;
//     }

//     return count / fact;
// }



#include <bits/stdc++.h>
using namespace std;

long long word_to_num(const string& w, const map<char, int>& m) {
    long long n = 0;
    for (char c : w) {
        n = n * 10 + m.at(c);
    }
    return n;
}

int solution(vector<string> crypt) {
    const string& w1 = crypt[0];
    const string& w2 = crypt[1];
    const string& w3 = crypt[2];

    size_t max_l = max(w1.length(), w2.length());
    if (w3.length() < max_l || w3.length() > max_l + 1) {
        return 0;
    }

    set<char> char_set;
    for (const auto& w : crypt) {
        for (char c : w) {
            char_set.insert(c);
        }
    }
    vector<char> chars(char_set.begin(), char_set.end());
    size_t k = chars.size();

    if (k > 10) {
        return 0;
    }

    set<char> leads;
    if (w1.length() > 1) leads.insert(w1[0]);
    if (w2.length() > 1) leads.insert(w2[0]);
    if (w3.length() > 1) leads.insert(w3[0]);

    vector<int> d = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int count = 0;

    do {
        map<char, int> m;
        for (size_t i = 0; i < k; ++i) {
            m[chars[i]] = d[i];
        }

        bool lead_z = false;
        for (char c : leads) {
            if (m.at(c) == 0) {
                lead_z = true;
                break;
            }
        }
        if (lead_z) {
            continue;
        }
        long long n1 = word_to_num(w1, m);
        long long n2 = word_to_num(w2, m);
        long long n3 = word_to_num(w3, m);

        if (n1 + n2 == n3) {
            count++;
        }

    } while (next_permutation(d.begin(), d.end()));
    
    int fact = 1;
    for (int i = 1; i <= 10 - k; ++i) {
        fact *= i;
    }

    return count / fact;
}

int main() {
    

        vector<string> crypt = {"SEND" ,"MORE" , "MONEY"};
       
        cout << solution(crypt) << "\n";
    
    return 0;
}
































