class Solution {
public:
	void dfs(string digits,int index,char *letter[],vector<string>&res,string &tmp,int dep){
		while(index<digits.size()&&(digits[index]=='0'||digits[index]=='1')) index++;
		if(index>=digits.size()) {
			res.push_back(tmp); return;
		}
		for(int i=0;letter[digits[index]-'0'][i]!='\0';i++){
			if(tmp.size()==dep) tmp+=letter[digits[index]-'0'][i];
			else tmp[dep]=letter[digits[index]-'0'][i];
			dfs(digits,index+1,letter,res,tmp,dep+1);
		}
	}
    vector<string> letterCombinations(string digits) {
        char *letter[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    	vector<string> res;
    	int len=digits.size();
    	if(len==0) {
    		res.push_back("");return res;
    	}
    	int index=0;
    	while((digits[index]=='0'||digits[index]=='1')&&index<len) index++;
    	if(index>=len){
    		res.push_back("");return res;
    	}
    	for(int i=0;letter[digits[index]-'0'][i]!='\0';i++){
    		string tmp="";
    		tmp+=letter[digits[index]-'0'][i];
    		dfs(digits,index+1,letter,res,tmp,1);
    	}
    	return res;
    }
};