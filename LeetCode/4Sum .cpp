//time limits
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> >ans;
        vector<int> tmp;
        sort(num.begin(),num.end());
        for(int i=0;i<num.size();i++){
        	if(i>0&&num[i]==num[i-1]) continue;
        	for(int j=i+1;j<num.size();j++){
        		if(num[j]==num[j-1]&&j-1>i) continue;
        		for(int k=j+1;k<num.size();k++){
        			if(num[k]==num[k-1]&&k-1>j) continue;
        			int t=target-num[i]-num[j]-num[k];
        			int mid=0,beg=k+1,end=num.size()-1;
        			while(beg<=end){
        				mid=(beg+end)>>1;
        				if(num[mid]>t) end=mid-1;
        				else if(num[mid]==t){
        					tmp.push_back(num[i]);
        					tmp.push_back(num[j]);
        					tmp.push_back(num[k]);
        					tmp.push_back(num[mid]);
        					ans.push_back(tmp);
        					tmp.clear();
        					break;
        				}
        				else beg=mid+1;
        			}
        		}
        	}
        }
        return ans;
    }
};
