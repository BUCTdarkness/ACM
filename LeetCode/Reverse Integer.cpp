class Solution {
public:
    int reverse(int x) {
        bool flag=false;
        if(x<0) flag=true;
        x=abs(x);
        int ans=0;
        while(x)
        {
            ans=ans*10+x%10;
            x/=10;
        }
        if(flag)
            ans=-ans;
        return ans;
    }
};