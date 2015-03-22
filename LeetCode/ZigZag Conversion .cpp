class Solution {
public:
    string convert(string s, int nRows) {
        string *tmps=new string[nRows+1];
        string ans;
        if(nRows<2) return s;
        int row=0;
        bool down=true;
        for(int i=0;i<s.size();i++){
        	if(row==-1){
        		row=1;
        		down=true;
        		tmps[row]+=s[i];
        		row++;
        	}
        	else if(row==nRows){
        		row=nRows-2;
        		down=false;
        		tmps[row]+=s[i];
        		row--;
        	}
        	else{
        		tmps[row]+=s[i];
        		if(down) row++;
        		else row--;
        	}
        }
        for(int i=0;i<nRows;i++) ans+=tmps[i];
        return ans;
    }
};
