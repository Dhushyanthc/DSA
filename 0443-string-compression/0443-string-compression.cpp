class Solution {
public:
    int compress(vector<char>& chars) {
        string result = "";
        int i = 0;
        int n = chars.size();

        while (i < n) {
            int count = 1;

            while (i + 1 < n && chars[i] == chars[i + 1]) {
                count++;
                i++;
            }

            result += chars[i];
            if (count > 1) {
                result += to_string(count);
            }
            
            i++; 
        }

        for (int j = 0; j < result.size(); j++) {
            chars[j] = result[j];
        }

        return result.size();
    }
};
