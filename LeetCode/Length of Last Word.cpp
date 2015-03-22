class Solution {
public:
    int lengthOfLastWord(const char *s) {
		int cnt=0;
		for(int i=strlen(s)-1;i>=0;){
			if(s[i]==' '){
				while(s[i]==' '&&i>=0) i--;
			}
			else{
				while(s[i]!=' '&&i>=0) {cnt++;i--;}
				break;
			}
		}
		return cnt;        
    }
};
