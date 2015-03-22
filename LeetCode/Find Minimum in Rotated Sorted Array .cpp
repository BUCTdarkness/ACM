#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
class SolutionNaive{
public:
    int findMin(vector<int> &num){
        int minv=num[0];
        for(int i=0;i<num.size();i++){
            minv=min(minv,num[i]);
        }
        return minv;
    }
};
class Solution{
public:
    int findMin(vector<int> &num){
        int left=0,right=num.size()-1;
        while(left<right){
            if(num[left]<num[right]) return num[left];
            int mid=(left+right)>>1;
            if(num[mid]>num[left]) left=mid+1;
            else if(num[mid]<num[right])right=mid;
            else left++;
        }
        return num[left];
    }
};
int main(){

    return 0;
}
