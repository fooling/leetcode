class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> array;
        vector<int>::iterator it1=nums1.begin();
        vector<int>::iterator it2=nums2.begin();
        while (array.size()!=nums1.size()+nums2.size()){
            if(it1==nums1.end() && it2!=nums2.end()){
                array.push_back(*it2++);
                continue;
            }
            if(it2==nums2.end() && it1!=nums1.end()){
                array.push_back(*it1++);
                continue;
            }
            
            if(*it1<=*it2){
                array.push_back(*it1++);
            }else{
                array.push_back(*it2++);
            }
        }
        
        if(array.size()%2==0){
            return (array[array.size()/2]+array[array.size()/2-1])/2.0;
        }
        return array[(nums1.size()+nums2.size())/2];
        
        
    }
};