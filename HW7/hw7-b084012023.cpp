// Author : B084012023 鄭鈺丞
// Date : Dec 25, 2021
// Purpose : 測試五種排序(sorting)演算法的執行效率

#include<iostream>
#include <fstream>
#include <stdlib.h>
#include<time.h>
#include <algorithm>

using namespace std;
void swap(int* a, int* b);
void InsertionSort(int arr[], const int n);                                 //Insertionsort函式
void merge(int array[], int const left, int const mid, int const right);    
void mergeSort(int array[], int const begin, int const end);                //Mergesort函式
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);                               //Quicksort函式
int cmpfunc(const void* a, const void* b);

int main() {
    srand(time(0));                                                         //設定每次產生隨機變數都不同
    int number;                                                             //紀錄輸入者所輸入的變數並產生此數量的隨機變數
    double START, END;                                                      //紀錄函式執行的時間
    char choice;                                                            //紀錄輸入者想要哪種排序法
    cout << "How many random number do you want to generate?";
    cin >> number;
    int* num, *sort_num;
    num = new int[number];                                                  //創造使用者要的大小的陣列
    sort_num = new int[number];
    ofstream MyFile("input.txt");
    std::fstream fs;
    fs.open("RecordTimeSpend.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    MyFile << number << endl;
    for (int i = 0; i < number; i++) {                                      //將隨機變數列印至input記事本上
        num[i] = rand();
        MyFile << num[i] << endl;
    }
        MyFile.close();
    cout << "A:Insertion sort B:Merger sort C: Quick sort D: qsort(c) E: sort(c++) or (0 to exit)" << endl;
    cin >> choice;                                                          //輸入選擇直到使用者輸入0
    while (choice != '0') {                             
        if (choice == 'A' || choice == 'a') {                               //A為insertionsort
            ifstream myFile;
            ofstream MyFile("OutputA.txt");                                 //建立output的記事本存取input中排序完的數字
            myFile.open("input.txt");
            myFile >> number;
            for (int i = 0; i < number; i++)
                myFile >> sort_num[i];
            START = clock();                                                //紀錄開始時間
            InsertionSort(sort_num, number);                                //執行函式
            END = clock();                                                  //結束時間
            MyFile << "Insertion sort" << endl;
            for (int i = 0; i < number; i++)                                //列印到output記事本上
                MyFile << sort_num[i] << endl;
            cout << "InsertionSort Time Spend:" << (END - START) / CLOCKS_PER_SEC << " S" << endl;  //列印執行的秒數
            fs << "InsertionSort Time Spend(data = " << number << "):" << (END - START) / CLOCKS_PER_SEC << " S" << endl;    //紀錄每一次執行的時間並列印到RecordTimeSpend記事本
            MyFile.close();
            myFile.close();
        }
        else if (choice == 'B' || choice == 'b') {                          //B為mergesort
            ifstream myFile;
            ofstream MyFile("OutputB.txt");                                 //建立output的記事本存取input中排序完的數字
            myFile.open("input.txt");
            myFile >> number;
            for (int i = 0; i < number; i++)
                myFile >> sort_num[i];
            START = clock();                                                //紀錄開始時間
            mergeSort(sort_num, 0, number - 1);                             //執行函式
            END = clock();                                                  //結束時間
            MyFile << "Merge sort" << endl;
            for (int i = 0; i < number; i++)                                //列印到output記事本上
                MyFile << sort_num[i] << endl;
            cout << "MergeSort Time Spend:" << (END - START) / CLOCKS_PER_SEC << " S" << endl;  //列印執行的秒數
            fs << "MergeSort Time Spend(data = " << number << "):" << (END - START) / CLOCKS_PER_SEC << " S" << endl;    //紀錄每一次執行的時間並列印到RecordTimeSpend記事本
            MyFile.close();
            myFile.close();
        }
        else if (choice == 'C' || choice == 'c') {                          //C為quicksort
            ifstream myFile;
            ofstream MyFile("OutputC.txt");                                 //建立output的記事本存取input中排序完的數字
            myFile.open("input.txt");
            myFile >> number;
            for (int i = 0; i < number; i++)
                myFile >> sort_num[i];
            START = clock();                                                //紀錄開始時間
            quickSort(sort_num, 0, number - 1);                             //執行函式
            END = clock();                                                  //結束時間
            MyFile << "Quick Sort" << endl;
            for (int i = 0; i < number; i++)                                //列印到output記事本上
                MyFile << sort_num[i] << endl;
            cout << "QuickSort Time Spend:" << (END - START) / CLOCKS_PER_SEC << " S" << endl;  //列印執行的秒數
            fs << "QuickSort Time Spend(data = " << number << "):" << (END - START) / CLOCKS_PER_SEC << " S" << endl;    //紀錄每一次執行的時間並列印到RecordTimeSpend記事本
            MyFile.close();
            myFile.close();
        }
        else if (choice == 'D' || choice == 'd') {                          //D為c內建排序法
            ifstream myFile;
            ofstream MyFile("OutputD.txt");                                 //建立output的記事本存取input中排序完的數字
            myFile.open("input.txt");
            myFile >> number;
            for (int i = 0; i < number; i++)
                myFile >> sort_num[i];
            START = clock();                                                //紀錄開始時間
            qsort(sort_num, number, sizeof(int), cmpfunc);                  //執行函式
            END = clock();                                                  //結束時間
            MyFile << "qsort(c)" << endl;
            for (int i = 0; i < number; i++)                                //列印到output記事本上
                MyFile << sort_num[i] << endl;
            cout << "qsort(c) Time Spend:" << (END - START) / CLOCKS_PER_SEC << " S" << endl;  //列印執行的秒數
            fs << "qsort(c) Time Spend(data = " << number << "):" << (END - START) / CLOCKS_PER_SEC << " S" << endl;    //紀錄每一次執行的時間並列印到RecordTimeSpend記事本
            MyFile.close();
            myFile.close();
        }
        else if (choice == 'E' || choice == 'e') {                          //E為c++標準函式庫中的排序法
            ifstream myFile;
            ofstream MyFile("OutputE.txt");                                 //建立output的記事本存取input中排序完的數字
            myFile.open("input.txt");
            myFile >> number;
            for (int i = 0; i < number; i++)
                myFile >> sort_num[i];
            START = clock();                                                //紀錄開始時間
            sort(sort_num, sort_num + number);                              //執行函式
            END = clock();                                                  //結束時間
            MyFile << "sort(c++)" << endl;
            for (int i = 0; i < number; i++)                                //列印到output記事本上
                MyFile << sort_num[i] << endl;
            cout << "sort(c++) Time Spend:" << (END - START) / CLOCKS_PER_SEC << " S" << endl; //列印執行的秒數
            fs << "sort(c++) Time Spend(data = " << number << "):" << (END - START) / CLOCKS_PER_SEC << " S" << endl;    //紀錄每一次執行的時間並列印到RecordTimeSpend記事本
            MyFile.close();
            myFile.close();
        }
        cout << "A:Insertion sort B:Merger sort C: Quick sort D: qsort(c) E: sort(c++) or (0 to exit)" << endl;
        cin >> choice;
    }
    delete[] num;
    delete[] sort_num;
    fs.close();
	return 0;
}

void InsertionSort(int arr[], const int n) {
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot 
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int cmpfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}