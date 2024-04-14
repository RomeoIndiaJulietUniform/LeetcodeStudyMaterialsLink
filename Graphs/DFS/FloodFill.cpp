class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color, int ocolor, vector<vector<bool>>& visited) {
        int n = image.size();
        int m = image[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m || image[i][j] != ocolor || visited[i][j]) {
            return;
        }
        
        visited[i][j] = true;
        image[i][j] = color;
        
        dfs(image, i + 1, j, color, ocolor, visited);
        dfs(image, i, j - 1, color, ocolor, visited);
        dfs(image, i - 1, j, color, ocolor, visited);
        dfs(image, i, j + 1, color, ocolor, visited);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ocolor = image[sr][sc];
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        dfs(image, sr, sc, color, ocolor, visited);

        return image;
    }
};



//Time Complexity: O(n * m)
//Space Complexity: O(n * m)