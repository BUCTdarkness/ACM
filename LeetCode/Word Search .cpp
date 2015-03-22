class Solution {
public:
    int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };    
    bool find(vector<vector<char> >&board,int i,int j,string word){
    	if(word.size()==0) return true;
    	bool flag=false;
 		
    	for(int k=0;k<4&&flag==false;k++){
    		int x=i+dir[k][0],y=j+dir[k][1];
    		if(x>=0&&x<board.size()&&y>=0&&y<board[0].size()&&board[x][y]==word[0]){
    			board[x][y]='#';
    			flag=find(board,x,y,word.substr(1));
    			board[x][y]=word[0];
    		}
    	}
    	return flag;
    }
    bool exist(vector<vector<char> > &board, string word) {
    	if(word.size()==0) return true;

        for(int i=0;i<board.size();i++)
        	for(int j=0;j<board[0].size();j++){
        		if(board[i][j]==word[0]){
        			board[i][j]='#';
        			if(find(board,i,j,word.substr(1))) return true;
        			board[i][j]=word[0];
        		}
        	}
        return false;
    }
};