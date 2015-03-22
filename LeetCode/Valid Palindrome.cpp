class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==0) return true;
        char *str=new char [s.size()];
        int k=0;
        for(int i=0;i<s.size();i++){
        	if(s[i]>='a'&&s[i]<='z') str[k++]=s[i];
        }
        str[k]='\0';
        int st=0,ed=k;
        while(str[st++]==str[ed--]&&str<ed);
        delete []str;
        if(st>=ed) return true;
        else return false;
    }
};
