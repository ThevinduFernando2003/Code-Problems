#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int finalPosition(int n, int k) {
    if (k == n) {
        return n;
    }

    long long position = k;

    for (int start = 0; start < n; start++) {
        if (position >= start) {
            position = start + (n - 1 - position);
        }
    }

    return static_cast<int>(position);
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int test = 0; test < t; test++) {
        string line;
        getline(cin, line);

        vector<string> parts = split(rtrim(line));
        int n = stoi(parts[0]);
        int k = stoi(parts[1]);

        cout << finalPosition(n, k) << "\n";
    }

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
