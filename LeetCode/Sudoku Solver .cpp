class Solution {
public:
bool isValid(vector<vector<char> > &board, int a, int b) {
		int i,j;
		for(i = 0; i < 9; i++)
			if(i != a && board[i][b] == board[a][b])
				return false;

		for(j = 0; j < 9; j++)
			if(j != b && board[a][j] == board[a][b])
				return false;

		int x = a/3*3;
		int y = b/3*3;
		for(i = 0; i < 3; i++)
			for(j = 0; j< 3; j++)
				if(x+i != a && y+j != b && board[x+i][y+j] == board[a][b])
					return false;
		return true;
    }
	bool solveSudokudfs(vector<vector<char> > &board)
	{
		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++)
			{
				if(board[i][j] == '.')
				{
					for(int k = 1; k <= 9; k++)
					{
						board[i][j] = '0' + k;
						if(isValid(board,i,j) && solveSudokudfs(board))
							return true;
						board[i][j] = '.';
					}
					return false;
				}
			}
		return true;
	}
	void solveSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once.
        solveSudokudfs(board);
    }
};