class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;

        for (int x:bills){
            if (x == 5){
                fives++;
            }else if(x == 10){
                if(fives<= 0){
                    return false;
                }
                fives--;
                tens++;
            }else if(x == 20){
                if (tens > 0 && fives > 0){
                        tens--;
                        fives--;
                    }
                else if (fives >= 3) {
                    fives -= 3;
                   
                }else{
                    return false;
                }
            }
        }

    return true;
    }
};