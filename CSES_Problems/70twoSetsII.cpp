#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long modInverse(long long value, long long mod) {
    return modPow(value, mod - 2, mod);
}

int main() {
    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    long long answer = 1;
    for (int i = 1; i <= n / 2; i++) {
        answer = (answer * (n - i + 1)) % MOD;
        answer = (answer * modInverse(i, MOD)) % MOD;
    }

    answer = (answer * modInverse(2, MOD)) % MOD;
    cout << answer << endl;
    return 0;
}
