class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        map<string,int> words;
        map<string,int> cur;
        vector<int> res;
        if(L.size()==0) return res;
        int wnum=L.size(),wlen=L[0].size();
        for(int i=0;i<wnum;i++) words[L[i]]++;
        for(int i=0;i<=(int)S.size()-wlen*wnum;i++){
        	int j;
        	cur.clear();
        	for(j=0;j<wnum;j++){
        		string word=S.substr(i+j*wlen,wlen);
        		if(words.find(word)==words.end()) break;
        		cur[word]++;
        		if(cur[word]>words[word]) break;
        	}
        	if(j==wnum) res.push_back(i);
        }
        return res;
    }
};