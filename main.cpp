
#include<iostream>
#include<vector>
#include"sorting/mergeSort.hpp"

int main( int argc , char * argv[]){
    const int SIZE = 100;
    std::vector<int> data(SIZE);
    for(int i=0;i<SIZE;i++){
        data[i]=rand()%SIZE;
    }
    auto start=std::chrono::high_resolution_clock::now();
    MergeSort * mergesort = new MergeSort(&data);
    mergesort->sort();
    mergesort->printData();
    auto end=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergeSortTime=end-start;
    std::cout<<"Merge Sort Time: "<<mergeSortTime.count()<<" seconds"<<std::endl;
    delete mergesort;
    return 0;
}

