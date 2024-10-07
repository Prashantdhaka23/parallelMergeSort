#include"mergeSort.hpp"
#include<iostream>

MergeSort::MergeSort(std::vector<int> * data) {
    this->data = data;
}

MergeSort::~MergeSort(){
}

void MergeSort::mergeSort(int low , int high){
     if(low>=high){
         return;
     }
     int mid=low + (high-low)/2;
     mergeSort(low,mid);
     mergeSort(mid+1,high);
     merge(low,mid,high);     

}

void MergeSort::sort(){
    if((*data).size()==0){
        return;
    }
    mergeSort(0,(*data).size()-1);
}


void MergeSort::merge(int low, int mid, int high){
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

void MergeSort::printData(){
    for(int i=0;i<(*data).size();i++){
        std::cout<<(*data)[i]<<" ";
    }
    std::cout<<std::endl;
}