// https://practice.geeksforgeeks.org/problems/quick-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

  //Function to sort an array using quick sort algorithm.
  void quickSort(int arr[], int low, int high)
  {
      if(low<high){
          int pindex = partition(arr,low,high);
          quickSort(arr, low, pindex-1);
          quickSort(arr, pindex+1, high);
      }
  }

  int partition (int arr[], int low, int high)
  {
     int pivotEle = arr[high];
     int i = low, j = low;
     // i is used to loop through all values from low to high
     // j points to position where smaller elements than pivot element can be placed
     while(i<=high){
         if(arr[i]<=pivotEle){
             swap(arr[i],arr[j++]);
         }
         ++i;
     }
    swap(arr[high],arr[j]);
     return j;
  }
