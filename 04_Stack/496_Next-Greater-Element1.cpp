// TC - O()
// SC - O()

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;

        for(int i = nums2.size() - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            
            if (st.empty()) mp[nums2[i]] = -1;  // If stack is empty, no greater element            
            else mp[nums2[i]] = st.top();   // Else top of stack is the answer
            st.push(nums2[i]);  // Push current element
        }
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};
