class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        int l1=num1.size(),l2=num2.size();
        int *n1=new int [l1],*n2=new int [l2],*res=new int [l1+l2];
		memset(res,0,sizeof(int)*(l1+l2));
        for(int i=0;i<l1;i++) n1[i]=num1[i]-'0';
        for(int i=0;i<l2;i++) n2[i]=num2[i]-'0';
        for(int i=0;i<l1;i++)
        	for(int j=0;j<l2;j++)
        		res[i+j+1]+=n1[i]*n2[j];
        string ans="";
        for(int k=l1+l2-1;k>=0;k--){
        	if(k>0) res[k-1]+=res[k]/10;
        	res[k]%=10;
        	ans=char(res[k]+'0')+ans;
        }
        ans=ans[0]=='0'?ans.substr(1):ans;
        delete []n1;
        delete []n2;
        delete []res;
        return ans;
    }
};