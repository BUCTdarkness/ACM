class Solution {
public:
    int removeDuplicates(int A[], int n) {
        map<int,int> mp;
        mp.clear();
        int len=0;
        for(int i=0;i<n;i++)
        {
            if(mp[A[i]]>=2) continue;
            mp[A[i]]++;
            A[len++]=A[i];
        }
        return len;
    }
};