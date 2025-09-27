class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        vector<int>ans;
        while(i<nums1.size()-n && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()-n){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            ans.push_back(nums2[j]);
            j++;
        }
        nums1=ans;
       
        
    }
};