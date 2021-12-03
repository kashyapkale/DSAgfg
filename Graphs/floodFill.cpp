//https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1#
//Flood Fill Agorithm - Done using BFS

bool isValid(int x, int y, int row, int col){
        return (x >= 0 && x < row && y < col && y >= 0);
}

vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) {
                return image;
        }

        queue<pair<int, int> > q;
        int row = image.size();
        int column = image[0].size();

        vector<vector<int> > newImage;

        for (auto row : image) {
                vector<int> temp;
                for (auto it : row) {
                        temp.push_back(it);
                }
                newImage.push_back(temp);
        }

        int oldColor = newImage[sr][sc];

        newImage[sr][sc] = newColor;
        q.push(make_pair(sr, sc));

        int xDir[] = { 0, 1, 0, -1 };
        int yDir[] = { 1, 0, -1, 0 };

        while (!q.empty()) {
                pair<int, int> temp = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                        int nextX = temp.first + xDir[i];
                        int nextY = temp.second + yDir[i];
                        if (isValid(nextX, nextY, row, column) && newImage[nextX][nextY] == oldColor) {
                                newImage[nextX][nextY] = newColor;
                                q.push(make_pair(nextX, nextY));
                        }
                }
        }

        return newImage;

}
