class Solution {  
public:  
    bool searchMatrix(vector<vector<int> > &matrix, int target) {  
        int left = 0;  
        int right = matrix.size()-1;  
        if(left != right)  
        {  
            while(left<=right)  
            {  
                int middle = left + (right-left)/2;  
                if(matrix[middle][0] < target)  
                {  
                    left = middle+1;  
                }  
                else if(matrix[middle][0] > target)  
                {  
                    right = middle-1;  
                }  
                else  
                {  
                    return true;  
                }  
            }  
        }  
        if(right == -1)  
        {  
            return false;  
        }  
        else  
        {  
            int row = right;  
            int left = 0;  
            int right = matrix[row].size()-1;  
            while(left<=right)  
            {  
                int middle = left + (right-left)/2;  
                if(matrix[row][middle] < target)  
                {  
                    left = middle+1;  
                }  
                else if(matrix[row][middle] > target)  
                {  
                    right = middle-1;  
                }  
                else  
                {  
                    return true;  
                }  
            }  
            return false;  
        }  
          
    }  
};  