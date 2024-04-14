class Solution {
private:
    unordered_map<string, unordered_map<string, double>> adj;

public:
    bool addVertex(string vertex) {
        if (adj.count(vertex) == 0) {
            adj[vertex];
            return true;
        }
        return false;
    }

    bool addEdge(string vertex1, string vertex2, double weight) {
        if (adj.count(vertex1) != 0 && adj.count(vertex2) != 0) {
            adj[vertex1][vertex2] = weight;
            adj[vertex2][vertex1] = 1.0 / weight;
            return true;
        }
        return false;
    }

    double bfs(string src, string tar) {
        if (adj.count(src) == 0 || adj.count(tar) == 0) {
            return -1.0;
        }

        deque<pair<string, double>> q;
        set<string> visited;

        q.push_back({src, 1.0});
        visited.insert(src);

        while (!q.empty()) {
            auto [current, weight] = q.front();
            q.pop_front();

            if (current == tar) {
                return weight;
            }

            for (auto& neighbor : adj[current]) {
                if (visited.find(neighbor.first) == visited.end()) {
                    q.push_back({neighbor.first, weight * neighbor.second});
                    visited.insert(neighbor.first);
                }
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();

        for (int i = 0; i < n; i++) {
            addVertex(equations[i][0]);
            addVertex(equations[i][1]);
            addEdge(equations[i][0], equations[i][1], values[i]);
        }

        vector<double> ans;

        for(auto& it : queries){
            double temp = bfs(it[0], it[1]);
            ans.push_back(temp);
        }

        return ans;
    }
};


//Time complexity: O((V + E) * m) where V is vertices, E is edges, and m is queries
//O(V + E) for the adjacency map and O(V) for BFS