class Solution {
private:
    void backtrack(vector<vector<int>>& image, int i, int j, int n, int m, int colour, int prev, vector<vector<bool>>& visited){
        if(i < 0 || i >= n || j < 0 || j >= m || image[i][j] != prev || visited[i][j] == true){
            return;
        }

        image[i][j] = colour;
        visited[i][j] = true;

        backtrack(image, i+1, j, n, m, colour, prev, visited);
        backtrack(image, i-1, j, n, m, colour, prev, visited);
        backtrack(image, i, j+1, n, m, colour, prev, visited);
        backtrack(image, i, j-1, n, m, colour, prev, visited);
        return;
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        backtrack(image, sr, sc, n, m, color, image[sr][sc], visited);

        return image;
    }
};