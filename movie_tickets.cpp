#include <bits/stdc++.h>
using namespace std;

class MovieTicket {
    unordered_map<int, unordered_set<int>> mp;

public:
    bool BOOK(int X, int Y) {
        if (mp[Y].count(X) || mp[Y].size() >= 100) return false;
        mp[Y].insert(X);
        return true;
    }

    bool CANCEL(int X, int Y) {
        return mp[Y].erase(X);  // erase returns 1 if found, 0 if not
    }

    bool IS_BOOKED(int X, int Y) {
        return mp[Y].count(X);  // count returns 1 if found, 0 if not
    }

    int AVAILABLE_TICKETS(int Y) {
        return 100 - mp[Y].size();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q; cin >> Q;
    MovieTicket mt;

    while (Q--) {
        string q; int X, Y;
        cin >> q;

        if (q == "AVAILABLE_TICKETS") {
            cin >> Y;
            cout << mt.AVAILABLE_TICKETS(Y) << "\n";
        } else {
            cin >> X >> Y;
            bool res;
            if      (q == "BOOK")     res = mt.BOOK(X, Y);
            else if (q == "CANCEL")   res = mt.CANCEL(X, Y);
            else                      res = mt.IS_BOOKED(X, Y);
            cout << (res ? "true" : "false") << "\n";
        }
    }
}