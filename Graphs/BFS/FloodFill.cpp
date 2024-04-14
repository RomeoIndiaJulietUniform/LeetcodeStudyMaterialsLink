class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int n = image.size();
        int m = image[0].size();

        int ocolor = image[sr][sc];

        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        queue<pair<int, int>> q;

        q.push({sr, sc});

        while (!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            visited[x][y] = true;
            image[x][y] = color;

            for (int k = 0; k < 4; ++k) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && image[nx][ny] == ocolor && !visited[nx][ny]) {
                    q.push({nx, ny});
                }

            }
        }

        return image;

    }
};


//Time Complexity: O(n * m)
//Space Complexity: O(n * m)