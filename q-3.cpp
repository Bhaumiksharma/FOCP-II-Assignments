#include <iostream>
using namespace std;

int main() {
    int L, R;
    cin >> L >> R;

    int x = 0;

    // XOR all numbers from L to R
    for (int i = L; i <= R; i++) {
        x = x ^ i;
    }

    // Check even or odd
    if (x % 2 == 0)
        cout << "even";
    else
        cout << "odd";

    return 0;
}