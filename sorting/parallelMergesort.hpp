#ifndef PARALLEL_MERGESORT_H
#define PARALLEL_MERGESORT_H

#include <vector>
#include <thread>
#include <mutex>
#include <iostream>

class ParallelMergeSort {

    private:
      std::vector<int>* data;

    public:
      ParallelMergeSort(std::vector<int>* data);
      ~ParallelMergeSort();
      void parallelMergeSort(int low, int high);
      void parallelMerge(int low, int mid, int high);
      void parallelSort();
      void printData();
    
};









#endif // PARALLEL_MERGESORT_H