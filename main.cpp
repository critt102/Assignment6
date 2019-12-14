/** main.cpp
 *Contains main method for running sorting algoritms
 *@author Mary Kate Crittenden
 *2278514
 *critt102@mail.chapman.edu
 *CPSC 350-01
 *Assignment 6
 */
#include <iostream>
#include <ctime>
#include "sort.h"
using namespace std;
/**
 * main method, implements and runs database.h
 * @param  argc numer of arguments
 * @param  argv command lines arguments
 * @return 0 to end main call
 */
int main(int argc, char**argv){
  //timer for time stamps
  time_t timer;
  //takes in file name as command line argument
  if(argv[1]==NULL){
    cout<<"Please enter file name as command line argument."<<endl;
    exit(0);
  }
  else{
    Sort sort(argv[1]);
    sort.bubbleSort();
    sort.selectionSort();
    sort.insertSort();

    time_t start_merge=time(&timer);
    sort.mergeSort(sort.arr_merge, 0, sort.arr_size-1);
    time_t end_merge=time(&timer);
    cout<<"Merge Sort"<<endl;
    cout<<"Time sort started: "<<asctime(localtime(&start_merge));
    cout<<"Time sort ended: "<<asctime(localtime(&end_merge));
    cout<<endl;

    time_t start_quick=time(&timer);
    sort.quickSort(sort.arr_quick, 0, sort.arr_size);
    time_t end_quick=time(&timer);
    cout<<"Quick Sort"<<endl;
    cout<<"Time sort started: "<<asctime(localtime(&start_quick));
    cout<<"Time sort ended: "<<asctime(localtime(&end_quick));
    cout<<endl;
  }
  
  return 0;
}
