class Solution {
public:
    int n;
    vector<int> t;
    int solve(vector<int> &S, int idx) {
        if (idx >= n) return 0;
        if (t[idx] != -1) return t[idx];
        
        int res = S[idx] - solve(S, idx + 1);
        if (idx + 1 < n) {
            res = max(res, S[idx] + S[idx + 1] - solve(S, idx + 2));
        }

        if (idx + 2 < n) {
            res = max(res, S[idx] + S[idx + 1] + S[idx + 2] - solve(S, idx + 3));
        }

        return t[idx] = res;
    }

    string stoneGameIII(vector<int>& stones) {
        n = stones.size();
        t.resize(n+1, -1);

        int diff = solve(stones, 0);

        if (diff < 0) 
            return "Bob";
        else if (diff > 0) 
            return "Alice";
        
        return "Tie";
    }
};