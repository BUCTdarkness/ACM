class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        add(digits,1);
        return digits;
    }
private:
	void add(vector<int> &digits,int v){
		int c=v,n=digits.size();
		for(int i=n-1;i>=0;i--){
			digits[i]+=c;
			c=digits/10;
			digits[i]%=10;
		}
		if(c>0) digits.insert(digits.begin(),c);
	}
};
