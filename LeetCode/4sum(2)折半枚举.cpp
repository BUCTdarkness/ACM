//AC
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> >ans;
        if(num.size()<4) return ans;
        sort(num.begin(),num.end());
        set<vector<int> > st;
        for(int i=0;i<num.size();i++){
            //if(i>0&&num[i]==num[i-1]) continue;
            for(int j=i+1;j<num.size();j++){
                //if(num[j]==num[j-1]&&j-1>i) continue;
                 int beg=j+1,end=num.size()-1;
                 while(beg<end){
                    int sum=num[i]+num[j]+num[beg]+num[end];
                    if(sum==target){
                        vector<int> tmp;
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[beg]);
                        tmp.push_back(num[end]);
                        st.insert(tmp);
                        beg++;end--;
                    }
                    else if(sum<target) beg++;
                    else end--;
                 } 
            }
        }
        for(set<vector<int> >::iterator it=st.begin();it!=st.end();it++){
            ans.push_back(*it);
        }
        return ans;
    }
};
