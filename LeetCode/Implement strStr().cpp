class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int len1=strlen(haystack),len2=strlen(needle);
        vector<int> next(len2,-1);
        getNext(needle,next);
        int i=0,j=0;
        while(i<len1&&j<len2){
        	if(j==-1||haystack[i]==needle[j]){
        		i++,j++;
        	}
        	else{
        		j=next[j];
        	}
        }
        if(j==len2){
        	return haystack+i-j;
        }
        return NULL;
    }
    void getNext(char *needle,vector<int>&next){
    	int len=strlen(needle);
    	int i=0,j=-1;
    	while(i<len-1){
    		if(j==-1||needle[i]==needle[j]){
    			next[++i]=++j;
    		}
    		else{
    			j=next[j];
    		}
    	}
    }
};
