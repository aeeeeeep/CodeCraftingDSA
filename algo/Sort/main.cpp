#include "Sort.h"

using namespace std;

int main() {
    vector<int> nums = {9, 5, 2, 7, 1, 8, 3};
    cout<<"Raw Vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout<<endl;

    // 冒泡排序
    vector<int> bubbleSortNums = nums;
    bubbleSort(bubbleSortNums);
    cout << "Bubble Sort: ";
    for (int num : bubbleSortNums) {
        cout << num << " ";
    }
    cout << endl;

    // 选择排序
    vector<int> selectionSortNums = nums;
    selectionSort(selectionSortNums);
    cout << "Selection Sort: ";
    for (int num : selectionSortNums) {
        cout << num << " ";
    }
    cout << endl;

    // 希尔排序
    vector<int> shellSortNums = nums;
    shellSort(shellSortNums);
    cout << "Shell Sort: ";
    for (int num : shellSortNums) {
        cout << num << " ";
    }
    cout << endl;

    // 插入排序
    vector<int> insertionSortNums = nums;
    insertionSort(insertionSortNums);
    cout << "Insertion Sort: ";
    for (int num : insertionSortNums) {
        cout << num << " ";
    }
    cout << endl;

    // 归并排序
    vector<int> mergeSortNums = nums;
    mergeSort(mergeSortNums, 0, mergeSortNums.size() - 1);
    cout << "Merge Sort: ";
    for (int num : mergeSortNums) {
        cout << num << " ";
    }
    cout << endl;

    // 快速排序
    vector<int> quickSortNums = nums;
    quickSort(quickSortNums, 0, quickSortNums.size() - 1);
    cout << "Quick Sort: ";
    for (int num : quickSortNums) {
        cout << num << " ";
    }
    cout << endl;

    // 计数排序
    vector<int> countingSortNums = nums;
    countingSort(countingSortNums, countingSortNums.size());
    cout << "Counting Sort: ";
    for (int num : countingSortNums) {
        cout << num << " ";
    }
    cout << endl;

    // 基数排序
    vector<int> radixSortNums = nums;
    radixSort(radixSortNums, radixSortNums.size());
    cout << "Radix Sort: ";
    for (int num : radixSortNums) {
        cout << num << " ";
    }
    cout << endl;

    // 堆排序
    vector<int> heapSortNums = nums;
    heapSort(heapSortNums);
    cout << "Heap Sort: ";
    for (int num : heapSortNums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
