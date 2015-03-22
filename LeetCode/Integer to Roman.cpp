class Solution{
public:
	const string romans[4][10]={
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"", "M", "MM", "MMM", "", "", "", "", "", ""}
	};
	string intToRoman(int num){
		string ans="";
		int i=0;
		while(num!=0){
			ans=romans[i++][num%10]+ans;
			num/=10;
		}
		return ans;
	}
};
