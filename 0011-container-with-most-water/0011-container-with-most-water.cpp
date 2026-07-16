class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1;
        int max_area = 0;
        
        while (i < j){
            int len =min(heights[i], heights[j]);
            int wid = j - i;
            max_area = max(max_area, len*wid);
            if (heights[i] < heights[j]){
                i++;
            }else{
                j--;
            }

        }
        return max_area;
    }
};
