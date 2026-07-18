class Solution {
public:

    int find_max(const vector<int>& f) {
        int max_val = 0;
        for (int count : f) {
            if (count > max_val) {
                max_val = count;
            }
        }
        return max_val;
    }

    int characterReplacement(string s, int k) {

        int low = 0; 
        int res = 0;
        vector<int> f(26,0);
        for (int high = 0; high < s.size(); high++){
            f[s[high] - 'A']++;
            int len = high - low + 1;
            int max_count = find_max(f);
            int diff = len - max_count;
            while ( diff > k){
                f[s[low] - 'A']--;
                low++;
                len = high - low + 1;
                max_count = find_max(f);
                diff = len - max_count;
            }

            len = high - low + 1;
            res = max(res, len);


        }
        return res;
    }
};