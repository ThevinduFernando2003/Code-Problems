#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int scenarios;
    cin >> scenarios;

    for (int scenario = 1; scenario <= scenarios; scenario++) {
        int transfers, queries;
        cin >> transfers >> queries;

        unordered_map<string, vector<string>> graph;
        unordered_set<string> allServers;

        for (int i = 0; i < transfers; i++) {
            string from, to, filename;
            cin >> from >> to >> filename;
            graph[from].push_back(to);
            allServers.insert(from);
            allServers.insert(to);
        }

        // BFS contamination levels from patient-zero
        unordered_map<string, int> level;
        queue<string> q;

        if (allServers.count("patient-zero")) {
            level["patient-zero"] = 0;
            q.push("patient-zero");
        }

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            if (graph.find(current) == graph.end()) {
                continue;
            }

            for (const string& next : graph[current]) {
                if (level.find(next) == level.end()) {
                    level[next] = level[current] + 1;
                    q.push(next);
                }
            }
        }

        cout << "Scenario " << scenario << "\n";

        for (int i = 0; i < queries; i++) {
            string server;
            cin >> server;

            if (level.find(server) == level.end()) {
                cout << server << " infinity\n";
            } else {
                cout << server << " " << level[server] << "\n";
            }
        }
    }

    return 0;
}
