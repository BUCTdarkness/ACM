class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num(n);
        int cnt=1;
        for(int i=0;i<n;i++){
        	num[i]=i+1;
        	cnt*=(i+1);
        }
        k--;
        string ans="";
        for(int i=0;i<n;i++){
        	cnt=cnt/(n-i);
        	int p=k/cnt;
        	ans+=('0'+num[p]);
        	for(int j=p;j<n-i-1;j++) num[j]=num[j+1];
        	k%=cnt;
        }
        return ans;
    }
};
