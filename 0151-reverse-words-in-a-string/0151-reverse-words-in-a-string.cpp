class Solution {
public:
    string reverseWords(string s) {
        int start = s.size() - 1;
        int end = s.size() - 1;
        string result;

        while (start >= 0) {

           
            while (start >= 0 && s[start] == ' ') {
                start--;
            }

            if (start < 0) break;

           
            end = start;

           
            while (start >= 0 && s[start] != ' ') {
                start--;
            } 
            int len = end - start;

            if (!result.empty()) {
                result += " ";
            }

            result += s.substr(start + 1, len);
        }

        return result;
    }
};