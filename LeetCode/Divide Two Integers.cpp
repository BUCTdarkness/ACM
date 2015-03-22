class Solution {
public:
    int divide(int dividend, int divisor) {
       bool positive=true;
       if((dividend>=0&&divisor<0)||(dividend<0&&divisor>0)) positive=false;
       long long a=abs((double)dividend),b=abs((double)divisor),res=0;
       while(a>=b){
       		long long c=b;
       		for(int i=0;a>=c;i++,c<<=1){
       			a-=c;
       			res+=1<<i;
       		}
       } 
       if(positive==false) res=-res;
       return res; 
    }
};