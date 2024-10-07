#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

class MergeSort {
private:
    std::vector<int>* data;

public:
    MergeSort(std::vector<int>* data);
    ~MergeSort();
    void mergeSort(int low, int high);
    void merge(int low, int mid, int high);
    void sort();
    void printData();
};

#endif // MERGESORT_H