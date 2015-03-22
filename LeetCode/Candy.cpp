class Solution {
public:
    int candy(vector<int> &ratings) {
  		int len=ratings.size(),cnt=1,ans;
  		int *can=new int[len+1];
  		fill(can,can+len,0);
  		for(int i=1;i<len;i++){
  			if(ratings[i]>ratings[i-1]) can[i]=max(cnt++,can[i]);
  			else cnt=1;
  		}
  		cnt=1;
  		for(int i=len-2;i>=0;i--){
  			if(ratings[i]>ratings[i+1]) can[i]=max(cnt++,can[i]);
  			else cnt=1;
  		}
  		ans=len;
  		for(int i=0;i<len;i++) ans+=can[i];
  		delete []can;
  		return ans;
    }
};