package com.leetcode.algorithm;

import java.util.*;

public class CombinationSum2 {
	
	public static void dfs(int []candidates,List<List<Integer>> resList ,List<Integer> path,int target,int last ,int sum){
		if(sum>target) return;
		if(sum==target){resList.add(new ArrayList<Integer>(path));return;}
		for(int i=last;i<candidates.length;i++){
			path.add(candidates[i]);
			dfs(candidates, resList, path, target, i+1, sum+candidates[i]);
			path.remove(path.size()-1);
			while(i<candidates.length-1&&candidates[i]==candidates[i+1]) i++;
		}
	}
    public static List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer> > res=new ArrayList<List<Integer>>();
        List<Integer> path=new ArrayList<Integer>();
        dfs(candidates,res,path,target,0,0);
    	return res;
    }
    public static void main(String []args){
    	int []candidates={10,1,2,7,6,1,5};
    	int target=8;
    	System.out.println(combinationSum2(candidates, target));
    }
}
