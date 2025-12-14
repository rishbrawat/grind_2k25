#include<iostream>
using namespace std;

// sort the array first
void selectionSort(int *arr, int size) {
   int smallest;

   for(int i = 0; i < size-1; ++i) {
      smallest=i;

      // find the smallest
      for(int j=i+1; j < size; ++j) {
         if(arr[j] < arr[smallest]){
            smallest = j;
         }
      }

      // swap
      int temp = arr[smallest];
      arr[smallest] = arr[i];
      arr[i] = temp;
   }
}


/*
   binary search is divide and conquer algorithm, that divides the sorted array in half untill the loop is exhausted.

   we take 3 variables 
      - start : to keep the track for the first element in the array, whether new divided array or the initial array.
      - end : to keep the track of the last element, same as start but points to the last element in the array.
      - mid : its used to compare the element, but the core reason of mid variable is to act as an boundary between start and end varibles, based on the mid value of the array,  start and end values are updated (indicies).

*/
int binarySearch(int *arr, int size, int element) {
   int start = 0; // start at index 0
   int end = size-1; // last index

   // so we dont go out of the bounds in the array
   while(start<=end){
      // decalre mid position
      int mid = (start+(end-start)) / 2; // if start and end are very large, it may cause integer overflow, so this formula is used

      // now, if the element is equal to the arr[mid], we simply return the mid position
      if(element == arr[mid]){
         return mid;
      }
      // otherwise, if the element's value is lesser than the arr[mid] value, it means that the value resides in lower half of the array and the after part of mid array is discarded
      else if(element < arr[mid]) {
         end = mid - 1;
      }
      // similarly, if the element value is > mid value, that means the value resides in the higher half (after mid index), so we update the start position to be mid + 1
      else {
         start = mid + 1;
      }
   }

   // if not found we return -1
   return -1;
}

int main() {
   int size = 5;
   int arr[size] = {1, 3, -3, 9, 5};
   int element = 5;

   selectionSort(arr, size);
   cout << "array is sorted: ";
   for(int i = 0; i < size; ++i) {
      cout << arr[i] << ' ';
   } cout << endl;

   int position = binarySearch(arr, size, element);
   
   if(position!=-1) {
      cout << "element found at index: " << position << endl;
   } else {
      cout << "element not found!" << endl;
   }



   return 0;
}