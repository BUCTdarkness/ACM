class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        int len=s1.size();
        bool f[len][len][len];
        memset(f,0,sizeof(bool)*len*len*len);
        for(int k=1;k<=len;k++)
        	for(int i=0;i<len-k+1;i++)
        		for(int j=0;j<len-k+1;j++){
        			if(k==1){
        				f[i][j][k]= s1[i]==s2[j];
        			}
        			else{
        				for(int l=1;l<k;l++){
        					if(f[i][j][l]&&f[i+l][j+l][k-l]|| (f[i][j+k-l][l]&&f[i+l][j][k-l])){
        						f[i][j][k]=true;break;
        					}
        				}
        			}
        		}
        return f[0][0][len];
    }
};
