class Solution {
public:
    void nextPermutation(vector<int> &num) {
		//next_permutation(num.begin(), num.end());
		if(num.size()<=1) return;
		int i=num.size()-1;
		for(;i>=1;i--){
			if(num[i-1]<num[i]) break;
		}
		if(i==0) reverse(num.begin(),num.end());
		else{
			int ii=i;i--;
			int j=num.size()-1;
			for(;j>=0;j--){
				if(num[i]<num[j]) break;
			}
			swap(num[i],num[j]);
			reverse(num.begin()+ii,num.end());
		}
    }
};
