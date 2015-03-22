package com.leetcode.algorithm;

import java.util.*;

class Interval {
   int start;
   int end;
   Interval() { start = 0; end = 0; }
   Interval(int s, int e) { start = s; end = e; }
};
public class InsertInterval {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        if(intervals==null||newInterval==null){
        	return intervals;
        }
    	if(intervals.size()==0){
    		intervals.add(newInterval);
    		return intervals;
    	}
    	ListIterator<Interval> it = intervals.listIterator();
    	while(it.hasNext()){
    		Interval tmpInterval = it.next();
    		if(newInterval.end<tmpInterval.start){
    			it.previous();
    			it.add(newInterval);
    			return intervals;
    		}
    		else{
    			if(newInterval.start>tmpInterval.end){
    				continue;
    			}
    			else{
    				newInterval.start = Math.min(newInterval.start, tmpInterval.start);
    				newInterval.end = Math.max(newInterval.end,tmpInterval.end);
    				it.remove();
    			}
    		}
    	}
    	intervals.add(newInterval);
    	return intervals;
    }
}
