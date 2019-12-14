#include <iostream>
#include <ctime>
#include "sort.h"
using namespace std;

int main(int argc, char**argv){
  time_t timer;
  Sort sort(argv[1]);
  sort.readFile();
  sort.insertSort();
  sort.selectionSort();
  sort.bubbleSort();

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

  return 0;
}
