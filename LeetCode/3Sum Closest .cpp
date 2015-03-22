class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        int dis=-1,ans=0;
        for(int i=0;i<num.size();i++){
        	if(i>0&&num[i]==num[i-1]) continue;
        	for(int j=i+1;j<num.size();j++){
        		if(num[j]==num[j-1]&&j-1>i) continue;
        		int k=target-num[i]-num[j];
        		int mid=0,beg=j+1,end=num.size()-1;
        		while(beg<=end){
        			mid=(beg+end)>>1;
        			if(num[mid]>k) end=mid-1;
        			else if(num[mid]==k) return target;
        			else beg=mid+1;
        		}
        		if(mid!=0&&(dis<0||abs(k-num[mid])<dis)){
        			dis=abs(k-num[mid]);
        			ans=target-k+num[mid];
        		}
        		if(mid>j+1&&(dis<0||abs(k-num[mid-1])<dis)){
        			dis=abs(k-num[mid-1]);
        			ans=target-k+num[mid-1];        			
        		}
         		if(mid<num.size()-1&&(dis<0||abs(k-num[mid+1])<dis)){
        			dis=abs(k-num[mid+1]);
        			ans=target-k+num[mid+1];        			
        		}       		
        	}
        }
        return ans;
    }
};
