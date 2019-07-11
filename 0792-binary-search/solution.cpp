class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int hi =  nums.size() - 1;
        int lo = 0;
        int mid = (hi + lo)/2;
        int counter = 0;
        
        while(hi >= lo){
            
            if(nums[mid] > target){
                hi = mid - 1;
            }
            
            else if(nums[mid] < target){
                lo = mid + 1;
            }
            
            else if(nums[mid] == target){
                return mid;
            }
            
            else if(hi == lo && counter == 0)
            {
                counter += 1;
            }
            
            else if(counter != 0)
            {
                break;
                
            }
            
            mid = (lo + hi)/2;
        }
        return -1   ;
    }
};
