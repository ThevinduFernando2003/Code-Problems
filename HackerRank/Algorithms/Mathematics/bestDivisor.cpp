#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int digitSum(int value) {
    int sum = 0;

    while (value > 0) {
        sum += value % 10;
        value /= 10;
    }

    return sum;
}

int bestDivisor(int n) {
    int best = 1;
    int bestSum = digitSum(1);

    for (int i = 1; i * i <= n; i++) {
        if (n % i != 0) {
            continue;
        }

        int divisors[] = {i, n / i};

        for (int divisor : divisors) {
            int currentSum = digitSum(divisor);

            if (currentSum > bestSum || (currentSum == bestSum && divisor < best)) {
                bestSum = currentSum;
                best = divisor;
            }
        }
    }

    return best;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    cout << bestDivisor(n) << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
