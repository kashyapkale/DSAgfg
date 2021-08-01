//https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1#
bool SolveSudoku(int grid[N][N])
{
  for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
        {
          if (!grid[i][j])
            {
              for (int ind = 1; ind < 10; ind++)
                {
                  if (isValid(grid, i, j, ind))
                    {
                      grid[i][j] = ind;
                      if (SolveSudoku(grid))
                        return true;
                      else
                        grid[i][j] = 0;
                    }
                }
              return false;
            }
        }
    }
  return true;
}

bool isValid(int grid[N][N], int row, int col, int ind)
{
  for (int i = 0; i < 9; i++)
    {
      if (grid[row][i] == ind)
        return false;
      if (grid[i][col] == ind)
        return false;
      if (grid[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == ind)
        return false;
    }
  return true;
}
//Function to print grids of the Sudoku.
void printGrid(int grid[N][N])
{
  for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
        {
          cout << grid[i][j] << " ";
        }
    }
}
