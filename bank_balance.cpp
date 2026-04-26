#include <bits/stdc++.h>
using namespace std;

class Bank {
    unordered_map<string, long long> mp;
public:
    bool CREATE(string X, long long Y) {
        auto it = mp.find(X);
        if (it == mp.end()) { mp[X] = Y; return true; }
        it->second += Y;
        return false;
    }

    bool DEBIT(string X, long long Y) {
        auto it = mp.find(X);
        if (it == mp.end() || it->second < Y) return false;
        it->second -= Y;
        return true;
    }

    bool CREDIT(string X, long long Y) {
        auto it = mp.find(X);
        if (it == mp.end()) return false;
        it->second += Y;
        return true;
    }

    long long BALANCE(string X) {
        auto it = mp.find(X);
        return it == mp.end() ? -1 : it->second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q; cin >> Q;
    cin.ignore();
    Bank bank;

    while (Q--) {
        string type, X;
        cin >> type >> X;
        if (type == "BALANCE") {
            cout << bank.BALANCE(X) << "\n";
        } else {
            long long Y; cin >> Y;
            bool res;
            if      (type == "CREATE") res = bank.CREATE(X, Y);
            else if (type == "DEBIT")  res = bank.DEBIT(X, Y);
            else                       res = bank.CREDIT(X, Y);
            cout << (res ? "true" : "false") << "\n";
        }
    }
}