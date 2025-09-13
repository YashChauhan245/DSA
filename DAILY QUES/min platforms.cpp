https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1


class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int mindept=0;
        int result=0;
        int i=0;
        int j=0;
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        while(i<arr.size() &&j<dep.size()){
            if(arr[i]<=dep[j]){
                mindept++;
                result=max(result,mindept);
                i++;
            }
            else{
                mindept--;
                j++;
            }
            
        }
        return result;
    }
};
