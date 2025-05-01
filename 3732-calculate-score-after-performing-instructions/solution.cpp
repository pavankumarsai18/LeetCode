class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        size_t num_instructions = instructions.size();
        int cur_index = 0;
        long long score = 0;

        while (cur_index < num_instructions) {
            if (instructions[cur_index] == "add") {
                instructions[cur_index] = "executed";
                score += values[cur_index];
                cur_index++;
            } else if (instructions[cur_index] == "jump") {
                instructions[cur_index] = "executed";
                cur_index += values[cur_index];
            } else if (instructions[cur_index] == "executed") {
                return score;
            } 
        }
    
        return score;
    }
};
