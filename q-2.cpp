#include <iostream>
using namespace std;

const int N = 10000001;
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i < N; i++) {
        if (cnt[i] == 0) {
            for (int j = i; j < N; j += i) {
                cnt[j]++;
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << (1 << cnt[n]) << '\n';
    }

    return 0;
} 