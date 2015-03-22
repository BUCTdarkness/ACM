class Solution {
public:
    bool check(vector<string> &board,int x,int y){
    	for(int i=0;i<x;i++) if(board[i][y]=='Q') return false;
    	for(int i=0;i<board.size();i++)
    		for(int j=0;j<board.size();j++){
    			if(i!=x&&j!=y&&i-j==x-y&&board[i][j]=='Q') return false;
    			if(i!=x&&j!=y&&i+j==x+y&&board[i][j]=='Q') return false;
    		}
    	return true;
    }
    void dfs(vector<vector<string> >&ans,vector<string> &board,int cur){
    	if(cur==board.size()){
    		ans.push_back(board);
    		return;
    	}
    	for(int i=0;i<board.size();i++){
    		board[cur][i]='Q';
    		if(check(board,cur,i)) dfs(ans,board,cur+1);
    		board[cur][i]='.';
    	}
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        string row(n,'.');
        vector<string> board(n,row) ;
        dfs(ans,board,0);
        return ans;
    }
};
