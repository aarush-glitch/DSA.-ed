class Solution {
  public:
    // int result = 0;
    int merge(vector<int>& arr, int l, int m, int h) {
        vector<int>temp;
        int left=l;
        int right=m+1;
        int result = 0;
        while(left<=m && right<=h) {
            if(arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            }
            else {
                temp.push_back(arr[right++]);
                result += (m-left+1);
            }
        }
        while(left<=m) temp.push_back(arr[left++]);
        while(right<=h) temp.push_back(arr[right++]);
        
        for(int i=l; i<=h; i++) arr[i]=temp[i-l];
        return result;
    }
  
    int mergeSort(vector<int>& arr, int low, int high) {
        if(low>=high) return 0;
        int mid = low + (high-low)/2;
        int result = 0;
        result+=mergeSort(arr, low, mid);
        result+=mergeSort(arr, mid+1, high);
        result+=merge(arr, low, mid, high);
        return result;
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        int result = mergeSort(arr, 0, arr.size()-1);
        return result;
    }
};
