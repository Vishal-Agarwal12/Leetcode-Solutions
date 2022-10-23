class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int count=1,maxi=INT_MIN;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++) {
            if(nums[i]-nums[i-1]==1)
                count++;
            else if(nums[i]-nums[i-1]==0) continue;
            else {
                maxi = max(maxi,count);
                count=1;
            }
        }
        maxi = max(maxi,count);
        if(nums.size()==0) return 0;
        else return maxi;
    }
};