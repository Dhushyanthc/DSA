class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for(int i = 0; i < nums.size(); i++){
            if ( nums[i] >= 0)
                pos.push_back(nums[i]*nums[i]);
            else
                neg.push_back(nums[i]*nums[i]);
        }

        reverse(neg.begin(), neg.end());

        int i = 0, j = 0, z=0;
        while(i < neg.size() && j < pos.size()){
            if(pos[j] < neg[i]){
                nums[z] = pos[j];
                z++;
                j++; 
            }else{
                nums[z] = neg[i];
                z++;
                i++;
            }
        }

        while(i < neg.size()){
            nums[z] = neg[i];
            z++;
            i++;
        }

        while(j < pos.size()){
            nums[z] = pos[j];
            z++;
            j++;
        }

        return nums;
    }
};