class Solution {
private:
    void DFS(vector<vector<int>>& image, int i, int j, int n, int m, int colour, int prev){
        if(i < 0 || i >= n || j < 0 || j >= m || image[i][j] != prev){
            return;
        }

        image[i][j] = colour;

        DFS(image, i+1, j, n, m, colour, prev);
        DFS(image, i-1, j, n, m, colour, prev);
        DFS(image, i, j+1, n, m, colour, prev);
        DFS(image, i, j-1, n, m, colour, prev);
        return;
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        int st = image[sr][sc];
        
        if(st != color){
            DFS(image, sr, sc, n, m, color, image[sr][sc]);
        }

        return image;
    }
};