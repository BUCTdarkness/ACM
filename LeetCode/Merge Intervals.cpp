/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(const Interval &a,const Interval &b){return a.start<b.start;}
class Solution {
public:
    
    vector<Interval> ans;
    vector<Interval> merge(vector<Interval> &intervals) {
        ans.clear();
        sort(intervals.begin(),intervals.end(),cmp);
        for(int i=0;i<intervals.size();i++){
            if(ans.size()==0) ans.push_back(intervals[i]);
            else{
                int len=ans.size();
                if(ans[len-1].start<=intervals[i].start&&intervals[i].start<=ans[len-1].end){
                    ans[len-1].end=max(ans[len-1].end,intervals[i].end);
                }
                else{
                    ans.push_back(intervals[i]);
                }
            }
        }
        return ans;
    }
};
