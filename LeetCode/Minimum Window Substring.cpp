class Solution {
public:
    string minWindow(string S, string T) {
        int slen=S.size(),tlen=T.size();
        if(tlen==0) return "";
        int need[256]={0},has[256]={0};
        for(int i=0;i<tlen;i++) need[T[i]]++;
        int minbeg,minend,minwindow=slen+1,cnt=0;
    	for(int beg=0,end=0;end<slen;end++){
    		if(need[S[end]]==0) continue;
    		char c=S[end];
    		has[c]++;
    		if(has[c]<=need[c]) cnt++;
    		if(cnt==tlen){
    			while(need[S[beg]]==0||has[S[beg]]>need[S[beg]]){
    				if(has[S[beg]]>need[S[beg]]) has[S[beg]]--;
    				beg++;
    			}
    			int len=end-beg+1;
    			if(len<minwindow){
    				minbeg=beg;
    				minend=end;
    				minwindow=len;
    			}
    		}
    	}
    	return minwindow<=slen?S.substr(minbeg,minwindow):"";
    }
};