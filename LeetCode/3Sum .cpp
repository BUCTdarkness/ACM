class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        vector<int> tmp;
        sort(num.begin(),num.end());
        for(int i=0;i<num.size();i++){
        	if(i>0&&num[i]==num[i-1]) continue;
        	for(int j=i+1;j<num.size();j++){
        		if(num[j]==num[j-1]&&j-1>i) continue;
        		int k=0-num[i]-num[j];
        		int mid=0,beg=j+1,end=num.size()-1;
        		while(beg<=end){
        			mid=(beg+end)>>1;
        			if(num[mid]>k) end=mid-1;
        			else if(num[mid]==k){
        				tmp.push_back(num[i]);
        				tmp.push_back(num[j]);
        				tmp.push_back(num[mid]);
        				ans.push_back(tmp);
        				tmp.clear();
        				break;
        			}
        			else beg=mid+1;
        		}
        	}
        }
        return ans;
    }
};
