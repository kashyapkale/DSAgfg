//https://practice.geeksforgeeks.org/problems/steps-by-knight5927/0
struct knight {
	int X;
	int Y;
	int steps;
};

bool isValid(int row, int col, int N){
	return row >= 0 && col >= 0 && col < N && row < N;
}

int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	vector<vector<bool> > visited(N, vector<bool>(N, false));
	int targetX = TargetPos[0] - 1;
	int targetY = TargetPos[1] - 1;
	int sourceX = KnightPos[0] - 1;
	int sourceY = KnightPos[1] - 1;

	return minStepUtil(N, sourceX, sourceY, targetX, targetY, visited);

}

int minStepUtil(int N, int i, int j, int targetX, int targetY, vector<vector<bool> > &visited){
	int xDir[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
	int yDir[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
	if(i==targetX && j==targetY)
	    return 0;
	//cout<<"Target : "<<targetX<<" "<<targetY<<endl;
	queue<struct knight> q;
    visited[i][j] = true;
	q.push({ i, j, 0 });
	while (!q.empty()) {
		struct knight temp = q.front();
		//cout<<temp.X<<" "<<temp.Y<<" "<<temp.steps<<endl;
		
		
		for (int k = 0; k < 8; k++) {
			int nextX = temp.X + xDir[k];
			int nextY = temp.Y + yDir[k];
			if (isValid(nextX, nextY, N) && !visited[nextX][nextY])
				{
				    if (nextX == targetX && nextY == targetY) {
		        	    return temp.steps+1;
		            }
				    q.push({ nextX, nextY, temp.steps + 1 });
		            visited[nextX][nextY] = true;		    
				}
		}
		q.pop();
	}
	
	return -1;
}
