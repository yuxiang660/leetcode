#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& arr) {
   for (auto& elem : arr) {
      cout << elem << " ";
   }
   cout << endl;
}

// 平均时间复杂度：O(n^2)，最好时间复杂度：O(n)
vector<int> bubbleSort(const vector<int>& arr) {
   vector<int> ret = arr;
   bool didSwap = false;
   for (int i = 0; i < ret.size(); i++) {
      didSwap = false;
      for (int j = 1; j < ret.size() - i; j++) {
         if (ret[j - 1] > ret[j]) {
            int temp = ret[j - 1];
            ret[j - 1] = ret[j];
            ret[j] = temp;
            didSwap = true;
         }
      }
      if (didSwap == false) return ret;
   }

   return ret;
}

// 平均时间复杂度：O(n^2)，最好时间复杂度：O(n)
vector<int> insertSort(const vector<int>& arr) {
   auto ret = arr;

   for (int i = 1; i < ret.size(); i++) {
      int j, val = ret[i];
      for (j = i - 1; j >= 0 && val < ret[j]; j--) {
         ret[j + 1] = ret[j];
      }
      ret[j + 1] = val;
   }

   return ret;
}

// 平均时间复杂度：O(n^2)，最好时间复杂度：O(n^2)
vector<int> selectSort(const vector<int>& arr) {
   vector<int> ret = arr;

   for (int i = 0; i < ret.size(); i++) {
      for (int j = i; j < ret.size(); j++) {
         if (ret[j] < ret[i]) {
            int temp = ret[j];
            ret[j] = ret[i];
            ret[i] = temp;
         }
      }
   }

   return ret;
}

int patition(int arr[], int left, int right) {
   const int pivotVal = arr[left];
   int pivotIndex = left;

   int low = left + 1;
   int high = right;

   while (low <= high)
   {
      while (arr[high] >= pivotVal && high >= low)
      {
         high--;
      }
      if (high >= low) {
         arr[pivotIndex] = arr[high];
         arr[high] = pivotVal;
         pivotIndex = high;
      }
      while (arr[low] <= pivotVal && high >= low)
      {
         low++;
      }
      if (high >= low) {
         arr[pivotIndex] = arr[low];
         arr[low] = pivotVal;
         pivotIndex = low;
      }
   }
   return pivotIndex;
}

void quickSortImpl(int arr[], int left, int right) {
   if (right <= left) return;

   const int pivot = patition(arr, left, right);
   quickSortImpl(arr, left, pivot - 1);
   quickSortImpl(arr, pivot + 1, right);
}

// 平均时间复杂度：O(nlogn)，最好时间复杂度：O(nlogn)
vector<int> quickSort(const vector<int>& arr) {
   vector<int> ret = arr;

   quickSortImpl(ret.data(), 0, ret.size() - 1);

   return ret;
}

void merge(int arr[], int left, int mid, int right) {
   vector<int> leftArr(arr+left, arr+mid+1);
   vector<int> rightArr(arr+mid+1, arr+right+1);

   int leftIndex = 0;
   int rightIndex = 0;
   for (int i = left; i <= right; i++) {
      if (leftIndex < leftArr.size() && rightIndex < rightArr.size()) {
         if (leftArr[leftIndex] <= rightArr[rightIndex]) {
            arr[i] = leftArr[leftIndex++];
         }
         else {
            arr[i] = rightArr[rightIndex++];
         }
      }
      else if (leftIndex == leftArr.size()) {
         arr[i] = rightArr[rightIndex++];
      }
      else {
         arr[i] = leftArr[leftIndex++];
      }
   }
}

void mergeSortImpl(int arr[], int left, int right) {
   if (left >= right) return;
   int mid = (left + right) / 2;

   mergeSortImpl(arr, left, mid);
   mergeSortImpl(arr, mid + 1, right);
   merge(arr, left, mid, right);
}

// 平均时间复杂度：O(nlogn)，最好时间复杂度：O(nlogn)
vector<int> mergeSort(const vector<int>& arr) {
   vector<int> ret = arr;
   mergeSortImpl(ret.data(), 0, arr.size() - 1);
   return ret;
}

int main() {
   cout << "All Sort Algorithm" << endl;

   vector<int> arr{3, 2, 1, 8, 10};

   cout << "Befor sort: ";
   print(arr);

   cout << "Bubble sort: ";
   print(bubbleSort(arr));

   cout << "Insert sort: ";
   print(insertSort(arr));

   cout << "Select sort: ";
   print(selectSort(arr));

   cout << "Quick sort: ";
   print(quickSort(arr));

   cout << "Merge sort: ";
   print(mergeSort(arr));

   return 0;
}
