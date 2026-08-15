class Solution {
public:
    int elevatorRequests(int n, vector<int>& R) {
        // check what if R is empty hai 
        if (R.empty()) return 0;
         int total_min =  abs(R[0] - 0);
        for (int i = 1; i < R.size(); ++i) {
            total_min += abs(R[i] - R[i-1]);
        }

        return total_min;
    }
};