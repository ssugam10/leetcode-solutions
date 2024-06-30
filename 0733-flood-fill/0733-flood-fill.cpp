class Solution {
public:
    void fill(vector<vector<int>>& image, int sr, int sc, int color){
        int prevColor = image[sr][sc];
        image[sr][sc] = color;
        if(sr + 1 < image.size() && image[sr+1][sc] == prevColor)    fill(image,sr+1,sc,color);
        if(sr - 1 >= 0 && image[sr-1][sc] == prevColor)    fill(image,sr-1,sc,color);
        if(sc + 1 < image[0].size() && image[sr][sc+1] == prevColor)    fill(image,sr,sc+1,color);
        if(sc - 1 >= 0 && image[sr][sc-1] == prevColor)    fill(image,sr,sc-1,color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color)  return image;
        fill(image,sr,sc,color);
        return image;
    }
};