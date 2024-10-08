
#include<iostream>
#include<vector>
#include"sorting/mergeSort.hpp"
#include "sorting/parallelMergesort.hpp"

int main( int argc , char * argv[]){
    const int SIZE = 10000000;
    std::vector<int> data(SIZE);
    std::vector<int> data2(SIZE);

    for(int i=0;i<SIZE;i++){
        data[i]=rand()%SIZE;
        data2[i]=data[i];
    }
    auto start=std::chrono::high_resolution_clock::now();
    MergeSort * mergesort = new MergeSort(&data);
    mergesort->sort();
    // mergesort->printData();
    auto end=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergeSortTime=end-start;
    
   

    auto st=std::chrono::high_resolution_clock::now();
    ParallelMergeSort * pmergesort = new ParallelMergeSort(&data);
    pmergesort->parallelSort();
    // pmergesort->printData();
    auto en=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> parallelMergeSortTime=en-st;
    
   

    std::cout<<"Merge Sort Time: "<<mergeSortTime.count()<<" seconds"<<std::endl;
    std::cout<<"Parallel Merge Sort Time: "<<parallelMergeSortTime.count()<<" seconds"<<std::endl;

    delete mergesort;
    delete pmergesort;

    return 0;
}

