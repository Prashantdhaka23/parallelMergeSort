#include "parallelMergesort.hpp"
#include "mergeSort.hpp"

#include <mutex>


ParallelMergeSort::ParallelMergeSort(std::vector<int> * data) {
    this->data = data;
}

ParallelMergeSort::~ParallelMergeSort(){}

void ParallelMergeSort::parallelMergeSort(int low , int high){

    const int threshold = 60000;
    if(high-low<threshold){
         std::vector<int> nums;
         for(int i=low;i<=high;i++){
             nums.push_back((*data)[i]);
         }
         MergeSort * mergesort = new MergeSort(&nums);
         mergesort->sort();
         return;
    }
     if(low>=high){
         return;
     }
     int mid=low + (high-low)/2;
     std::thread t1 ([this,low,mid](){this->parallelMergeSort(low,mid);});
     std::thread t2 ([this,mid,high](){this->parallelMergeSort(mid+1,high);});
     t1.join();
     t2.join();
     Merge(low,mid,high);
     
}

void ParallelMergeSort::parallelSort(){
    if((*data).size()==0){
        return;
    }
    std :: thread t1([this]{parallelMergeSort(0,(*data).size()-1);});
    t1.join();
}

void ParallelMergeSort::Merge(int low, int mid, int high){
    int n1=mid-low+1;
    int n2=high-mid;
    std::vector<int> left(n1);
    std::vector<int> right(n2);
    for(int i=0;i<n1;i++){
        left[i]=(*data)[low+i];
    }
    for(int i=0;i<n2;i++){
        right[i]=(*data)[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=low;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            (*data)[k]=left[i];
            i++;
        }else{
            (*data)[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        (*data)[k]=left[i];
        i++;
        k++;
    }
    while(j<n2){
        (*data)[k]=right[j];
        j++;
        k++;
    }
}

void ParallelMergeSort::printData(){
    for(int i=0;i<(*data).size();i++){
        std::cout<<(*data)[i]<<" ";
    }
    std::cout<<std::endl;
}