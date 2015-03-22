class Solution {
public:
    int atoi(const char *str) 
    {
    	if(str==NULL)
    		return 0;
    	int i=0;
    	while(str[i]!='\0'&&str[i]==' ')
    		i++; 
    	if(str[i]=='\0') return 0;
    	int Ma=0x7fffffff;
    	int Mi=0x80000000;
    	int flag=1;
    	if(str[i]=='+')
    	{
    		flag=1;
    		i++;
    	}
    	else if(str[i]=='-')
    	{
    		flag=-1;
    		i++;
    	}
    	long long sum=0;
    	while(str[i]!='\0')
    	{
    		if(str[i]>='0'&&str[i]<='9')
    			sum=sum*10+flag*(str[i]-'0')
    		else
    			return sum;
    		if(sum>Ma||sum<Mi)
    			return sum>0?Ma|Mi;
    		i++;
    	}
    	return sum;
    }
};