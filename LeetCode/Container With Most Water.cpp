class Solution {
public:
    int maxArea(vector<int> &height) {
        int left=0,right=height.size()-1;
        int ma=0;
        while(left<right){
        	int tmp=(right-left)*min(height[left],height[right]);
        	ma=max(ma,tmp);
        	if(height[left]>height[right]) right--;
        	else left++;
        }
        return ma;
    }
};
