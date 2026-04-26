#include <bits/stdc++.h>
using namespace std;

class Bank {
    unordered_map<string, long long> mp;

public:
    bool CREATE(string x, long long y) {
        if (!mp.count(x)) return mp[x] = y, true;
        mp[x] += y; return false;
    }

    bool DEBIT(string x, long long y) {
        if (!mp.count(x) || mp[x] < y) return false;
        mp[x] -= y; return true;
    }

    bool CREDIT(string x, long long y) {
        if (!mp.count(x)) return false;
        mp[x] += y; return true;
    }

    long long BALANCE(string x) {
        return mp.count(x) ? mp[x] : -1;
    }
};

int main() {
    int q; cin >> q;
    Bank b;

    while (q--) {
        string t, x; cin >> t >> x;

        if (t == "BALANCE") cout << b.BALANCE(x) << "\n";
        else {
            long long y; cin >> y;
            if (t == "CREATE") cout << (b.CREATE(x,y)?"true":"false") << "\n";
            else if (t == "DEBIT") cout << (b.DEBIT(x,y)?"true":"false") << "\n";
            else cout << (b.CREDIT(x,y)?"true":"false") << "\n";
        }
    }
}