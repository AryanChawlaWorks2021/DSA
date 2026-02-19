// Approach 1: Brute Force Solution
// TC - O(n2)
// SC - O(n)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n, -1);

        for(int i=0; i<n; i++) {
            int currEl = nums[i];

            // nested loop to get the NGE
            for(int j=1; j<n; j++) {

                int index = (j+i) % n;
                if(nums[index] > currEl) {
                    ans[i] = nums[index];
                    break;
                }
            } 
        }
        return ans;
    }
};


// Approach 2: optimal solution
// TC - O(2n)
// SC - O(2n)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;

        for(int i=2*n-1; i>=0; i--) {
            while(s.size()>0 && nums[s.top()] <= nums[i%n]) {
                s.pop();
            }

            ans[i%n] = s.empty() ? -1 : nums[s.top()];
            s.push(i%n);
        }
        return ans;
    }
};
