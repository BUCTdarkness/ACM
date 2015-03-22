class Solution//牛顿迭代法 
{
public:
    int sqrt(int x) 
    {
    	x==0?return 0; 
    	double pv=0,v=1;
    	while(abs(v-pv)>0.00001)
    	{
    		pv=v;
    		v=(pv+x/pv)/2.0;
    	} 
    	return (int) v;  
    }
};