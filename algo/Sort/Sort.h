#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
|排序| T(n)     | S(n)    |
|-------------------------|
|冒泡| O(n^2)   | O(1)    |
|选择| O(n^2)   | O(1)    |
|插入| O(n^2)   | O(1)    |
|希尔| O(nlogn) | O(1)    |
|归并| O(nlogn) | O(1)    |
|快速| O(nlogn) | O(logn) |
|堆  | O(nlogn) | O(1)    |
|计数| O(n+k)   | O(k)    |
|基数| O(n*k)   | O(n+k)  |
*/

// 冒泡排序
template<typename T>
void bubbleSort(vector <T> &q) {
    for (size_t i = q.size() - 1; i > 0; i--) {
        bool flag = false;
        for (size_t j = 0; j + 1 <= i; j++) {
            if (q[j] > q[j + 1]) {
                swap(q[j], q[j + 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}

// 选择排序
template<typename T>
void selectionSort(vector <T> &q) {
    for (size_t i = 0; i < q.size() - 1; i++) {
        for (size_t j = i + 1; j < q.size(); j++) {
            if (q[i] > q[j])
                swap(q[j], q[i]);
        }
    }
}

// 希尔排序
template<typename T>
void shellSort(vector <T> &q) {
    size_t gap = q.size() / 2;
    while (gap) {
        for (size_t i = gap; i < q.size(); i += gap) {
            size_t t = q[i], j;
            for (j = i - gap; j >= 0; j -= gap) {
                if (q[j] > t)
                    q[j + gap] = q[j];
                else
                    break;
            }
            q[j + gap] = t;
        }
        gap /= 2;
    }
}

// 插入排序
template<typename T>
void insertionSort(vector <T> &q) {
    for (size_t i = 1; i < q.size(); i++) {
        bool flag = false;
        for (size_t j = 0; j < i; j++) {
            if (q[j] > q[i]) {
                swap(q[j], q[i]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}

// 归并排序
template<typename T>
void mergeSort(vector <T> &q, size_t l, size_t r) {
    if (l >= r)
        return;
    size_t mid = (l + r) >> 1;
    mergeSort(q, l, mid);
    mergeSort(q, mid + 1, r);
    static vector <size_t> w;
    w.clear();
    size_t i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] > q[j])
            w.push_back(q[j++]);
        else
            w.push_back(q[i++]);
    }
    while (i <= mid)
        w.push_back(q[i++]);
    while (j <= mid)
        w.push_back(q[j++]);
    for (size_t i: w)
        q[l++] = i;
}

// 快速排序
template<typename T>
void quickSort(vector <T> &q, size_t l, size_t r) {
    if (l >= r)
        return;
    size_t i = l - 1, j = r + 1, x = q[l + rand() % (r - l + 1)];
    while (i < j) {
        do j--; while (q[j] > x);
        do i++; while (q[i] < x);
        if (i < j)
            swap(q[i], q[j]);
        else {
            quickSort(q, l, j);
            quickSort(q, j + 1, r);
        }
    }
}

// 计数排序
template<typename T>
void countingSort(vector <T> &q, size_t n) {
    vector <size_t> cnt(101, 0);
    for (size_t i = 0; i < n; i++)
        cnt[q[i]]++;
    for (size_t i = 0, k = 0; i <= 100; i++) {
        while (cnt[i]) {
            q[k++] = i;
            cnt[i]--;
        }
    }
}

template<typename T>
size_t get(T x, size_t i) {
    while (i--)
        x /= 10;
    return x % 10;
}

// 基数排序
template<typename T>
void radixSort(vector <T> &q, size_t n) {
    vector <vector<size_t>> cnt(10);
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 10; j++)
            cnt[j].clear();
        for (size_t j = 0; j < n; j++)
            cnt[get(q[j], i)].push_back(q[j]);
        for (size_t j = 0, k = 0; j < 10; j++) {
            for (size_t x: cnt[j])
                q[k++] = x;
        }
    }
}

// 推排序
template<typename T>
void heapify(vector <T> &q, size_t n, size_t i) {
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < n && q[left] > q[largest])
        largest = left;

    if (right < n && q[right] > q[largest])
        largest = right;

    if (largest != i) {
        swap(q[i], q[largest]);
        heapify(q, n, largest);
    }
}

template<typename T>
void heapSort(vector <T> &q) {
    size_t n = q.size();

    // 建立最大堆
    for (size_t i = n / 2 - 1; i >= 0 && i != static_cast<size_t>(-1); i--) {
        heapify(q, n, i);
    }

    // 逐步将最大元素移到末尾
    for (size_t i = n - 1; i >= 0 && i != static_cast<size_t>(-1); i--) {
        swap(q[0], q[i]);
        heapify(q, i, 0);
    }
}
