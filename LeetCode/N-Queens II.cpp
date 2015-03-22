class Solution {
public:
	bool check(int cur,int *place){
		for(int i=0;i<cur;i++){
			int tmp=abs(place[i]-place[cur]);
			if(tmp==0||tmp==cur-i) return false;
		}
		return true;
	}
	void Queen(int cur,int n,int &cnt,int *place){
		if(cur==n){
			++cnt; return;
		}
		for(int i=0;i<n;i++){
			place[cur]=i;
			if(check(cur,place)) Queen(cur+1,n,cnt,place);
		}
	} 
    int totalNQueens(int n) {
        int place[n];
        int cnt=0;
        Queen(0,n,cnt,place);
        return cnt;
    }
};
