// Approach 1: Brute Force
// TC - O(n2)
// SC - O(n)

class Solution {
    public int[] nextGreaterElements(int[] nums) {
        
        int n = nums.length;
        int[] ans = new int[n];
        Arrays.fill(ans, -1);

        for(int i=0; i<n; i++) {
            int currEl = nums[i];

            for(int j=1; j<n; j++) {
                int index = (i+j) % n;

                if(nums[index] > currEl) {
                    ans[i] = nums[index];
                    break;
                }
            }
        }
        return ans;
    }
}


// Approach 2: optimal solution
// TC - O()
// SC - O()

class Solution {
    public int[] nextGreaterElements(int[] nums) {
        
        int n = nums.length;
        int[] ans = new int[n];
        Stack<Integer> st = new Stack<>();

        for(int i = 2*n-1; i >= 0; i--) {
            int index = i % n;
            int currEl = nums[index];

            while(!st.isEmpty() && st.peek() <= currEl) {
                st.pop();
            }

            if(i < n) {
                if(st.isEmpty()) {
                    ans[index] = -1;
                }
                else {
                    ans[index] = st.peek();
                }
            }
            st.push(currEl);
        }
        return ans;
    }
}
