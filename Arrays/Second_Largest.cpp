class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        int largest = arr[0];
        int slargest = -1;
        for(int i =1;i<arr.size();i++){
            if( largest <arr[i] ){
                slargest = largest;
                largest = arr[i];
            }
            else if(slargest < arr[i] && arr[i] <largest){
                slargest = arr[i];
            }
        }
        return slargest;
        
    }
};