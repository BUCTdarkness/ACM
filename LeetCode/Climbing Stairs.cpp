class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        else{
        	int *step=new int[n];
        	step[0]=1;step[1]=2;
        	for(int i=2;i<n;i++) step[i]=step[i-1]+step[i-2];
 			return step[n-1];
        }
    }
};