class Solution {
public:
    bool isPalindrome(string s) {
                int len = s.size();
        int i = 0;
        int j = len;

        while (true)
        {
            if (i <= j)
            {   
                if (isalnum(s[i]) && isalnum(s[j]))
                {
                if (tolower(s[i]) == tolower(s[j]))
                {
                    i++;
                    j--;
                }else
                {
                    return false;
                }
                } else
                {
                    if (!isalnum(s[i]))
                    {
                        i++;
                    }else
                    {
                        j--;
                    }
                }

            }
            else
            {
                return true;
            }
            
        }
        return false;
        
    }
};