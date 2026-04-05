class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Step 1: prefix sum
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }

        // Step 2: coordinate compression
        vector<int> all = prefix;
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());

        // Fenwick Tree
        vector<int> BIT(all.size() + 1, 0);

        auto update = [&](int i) {
            for (; i < BIT.size(); i += i & -i)
                BIT[i]++;
        };

        auto query = [&](int i) {
            int s = 0;
            for (; i > 0; i -= i & -i)
                s += BIT[i];
            return s;
        };

        int ans = 0;

        for (int i = 0; i <= n; i++) {
            int idx = lower_bound(all.begin(), all.end(), prefix[i]) - all.begin() + 1;
            
            // count how many prefix values < current
            ans += query(idx - 1);

            // add current prefix
            update(idx);
        }

        return ans;
    }
};