class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>  freq(26,0);

        for(int task: tasks){
            freq[task-'A']++;
        }

        int max_freq = 0;
        for(int f:freq){
            max_freq = max(max_freq, f);     
        }

        int countmax = 0;
        for(int f:freq){
            if(f == max_freq) countmax++;
        }

        int result = (max_freq - 1)*(n + 1) + countmax;

        return max((int)tasks.size(), result);
    }
};