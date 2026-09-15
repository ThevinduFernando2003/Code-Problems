#include <bits/stdc++.h>
using namespace std;

/*
CSES - Fibonacci Numbers

n-th Fibonacci number mod 1e9+7, n up to 1e18.
F(0)=0, F(1)=1.

Pseudocode
----------
matrix [[1,1],[1,0]] ^ n  gives [[F(n+1), F(n)],[F(n), F(n-1)]]
*/

const long long MOD = 1e9 + 7;

struct Mat {
    long long a[2][2] = {{0, 0}, {0, 0}};
};

Mat mul(Mat x, Mat y) {
    Mat r;
    for (int i = 0; i < 2; i++)
        for (int k = 0; k < 2; k++)
            for (int j = 0; j < 2; j++)
                r.a[i][j] = (r.a[i][j] + x.a[i][k] * y.a[k][j]) % MOD;
    return r;
}

Mat mpow(Mat b, long long e) {
    Mat r;
    r.a[0][0] = r.a[1][1] = 1;
    while (e) {
        if (e & 1) r = mul(r, b);
        b = mul(b, b);
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }
    Mat b;
    b.a[0][0] = b.a[0][1] = b.a[1][0] = 1;
    cout << mpow(b, n).a[0][1] << "\n";
    return 0;
}
