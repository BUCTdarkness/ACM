#define CLR(A,N) fill(A,A+N,0)
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        return isValidRow(board)&&isValidColumn(board)&&isValidBox(board);
    }
private:
	inline bool check(int *cnt,char v){
		if(v=='.') return true;
		return (++cnt[v-'1'])<=1;
	}
	bool isValidRow(vector<vector<char> > &board){
		int cnt[9];
		for(int i=0;i<9;i++){
			CLR(cnt,9);
			for(int j=0;j<9;j++){
				if(!check(cnt,board[i][j])) return false;
			}
		}
		return true;
	}
	bool isValidColumn(vector<vector<char> >&board){
		int cnt[9];
		for(int i=0;i<9;i++){
			CLR(cnt,9);
			for(int j=0;j<9;j++){
				if(!check(cnt,board[j][i])) return false;
			}
		}
		return true;
	}
	bool isValidBox(vector<vector<char> >&board){
		int cnt[10];
		int point[9][2] = {  
        {1, 1}, {1, 4}, {1, 7}, {4, 1}, {4, 4}, {4, 7}, {7, 1}, {7, 4}, {7, 7}  
        };  
        int dir[8][2] = {
        {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}
    	};    
        for(int i=0;i<9;i++){
        	CLR(cnt,10);
        	int x=point[i][0],y=point[i][1];
        	check(cnt,board[x][y]);
        	for(int j=0;j<8;j++){
        		if(!check(cnt,board[dir[j][0]+x][dir[j][1]+y])) return false;
        	}
        }
        return true;
	}
};
