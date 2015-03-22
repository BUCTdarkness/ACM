//abed ?b*d**
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
		const char *star=NULL,*tmp=s;
		while(*s){
			if((*s==*p)||(*p=='?') ){s++;p++;continue;}
			if(*p=='*'){star=p++;tmp=s;continue;} 
			if(star){p=star+1;s=++tmp;continue;}
			return false;
		}
		while(*p=='*') p++;
		return !*p;        
    }
};
