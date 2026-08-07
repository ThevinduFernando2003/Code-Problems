#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<int> solve(vector<int> c, vector<vector<int>> tree) {
    int n = static_cast<int>(c.size());
    vector<vector<int>> adj(n + 1);

    for (const vector<int>& edge : tree) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n + 1);
    for (int i = 1; i <= n; i++) {
        color[i] = c[i - 1];
    }

    vector<int> parent(n + 1, 0);
    vector<int> subtree(n + 1, 1);
    vector<int> tin(n + 1, 0);
    vector<int> tout(n + 1, 0);
    vector<int> euler(n + 1, 0);
    int timer = 0;

    vector<pair<int, int>> dfsStack;
    dfsStack.push_back({1, 0});
    parent[1] = 0;

    while (!dfsStack.empty()) {
        auto [node, state] = dfsStack.back();
        dfsStack.pop_back();

        if (state == 0) {
            tin[node] = ++timer;
            euler[timer] = node;
            dfsStack.push_back({node, 1});

            for (int neighbor : adj[node]) {
                if (neighbor != parent[node]) {
                    parent[neighbor] = node;
                    dfsStack.push_back({neighbor, 0});
                }
            }
        } else {
            for (int neighbor : adj[node]) {
                if (parent[neighbor] == node) {
                    subtree[node] += subtree[neighbor];
                }
            }
            tout[node] = timer;
        }
    }

    unordered_map<int, int> frequency;
    unordered_map<int, vector<int>> nodesByColor;
    for (int i = 1; i <= n; i++) {
        frequency[color[i]]++;
        nodesByColor[color[i]].push_back(i);
    }

    vector<int> answer(n + 1, n);
    vector<long long> eulerDiff(n + 2, 0);

    auto addEulerRange = [&](int left, int right, int value) {
        if (left > right) {
            return;
        }
        eulerDiff[left] += value;
        eulerDiff[right + 1] -= value;
    };

    for (int node = 1; node <= n; node++) {
        if (frequency[color[node]] != 1) {
            continue;
        }

        for (int neighbor : adj[node]) {
            if (parent[neighbor] == node) {
                addEulerRange(tin[neighbor], tout[neighbor], n - subtree[neighbor]);
            }
        }

        addEulerRange(1, tin[node] - 1, subtree[node]);
        addEulerRange(tout[node] + 1, n, subtree[node]);
    }

    long long running = 0;
    for (int i = 1; i <= n; i++) {
        running += eulerDiff[i];
        answer[euler[i]] += running;
    }

    vector<int> removedStamp(n + 1, 0);
    vector<int> visitedStamp(n + 1, 0);
    int stamp = 0;
    vector<int> stack;
    stack.reserve(n);

    for (const auto& entry : nodesByColor) {
        const vector<int>& coloredNodes = entry.second;
        if (static_cast<int>(coloredNodes.size()) == 1) {
            continue;
        }

        stamp++;
        for (int node : coloredNodes) {
            removedStamp[node] = stamp;
        }

        for (int start = 1; start <= n; start++) {
            if (removedStamp[start] == stamp || visitedStamp[start] == stamp) {
                continue;
            }

            stack.clear();
            vector<int> component;
            stack.push_back(start);
            visitedStamp[start] = stamp;
            component.push_back(start);

            while (!stack.empty()) {
                int current = stack.back();
                stack.pop_back();

                for (int neighbor : adj[current]) {
                    if (removedStamp[neighbor] != stamp && visitedStamp[neighbor] != stamp) {
                        visitedStamp[neighbor] = stamp;
                        stack.push_back(neighbor);
                        component.push_back(neighbor);
                    }
                }
            }

            int contribution = n - static_cast<int>(component.size());
            for (int node : component) {
                answer[node] += contribution;
            }
        }
    }

    vector<int> result(n);
    for (int i = 1; i <= n; i++) {
        result[i - 1] = answer[i];
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        c[i] = stoi(c_temp[i]);
    }

    vector<vector<int>> tree(n - 1);
    for (int i = 0; i < n - 1; i++) {
        tree[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> tree[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = solve(c, tree);

    for (int i = 0; i < static_cast<int>(result.size()); i++) {
        fout << result[i];

        if (i != static_cast<int>(result.size()) - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
