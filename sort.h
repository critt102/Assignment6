/** sort.h
 *Header file for sorting algorithms
 *@author Mary Kate Crittenden
 *2278514
 *critt102@mail.chapman.edu
 *CPSC 350-01
 *Assignment 6
 */
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

/**
 * Sort implement 5 sorting algoritms; Bubble, Selection, Insertion, Merge, and Quick Sort.
 * It also has methods print, and readFile.
 */
class Sort{
public:
  //stores name of file to be read from
  string filename;
  //stream to read file
  ifstream in_file;
  //string to hold current line from file
  string line;
  //represents the size of the array as read from the file
  int arr_size;
  //array for insertion sort
  double *arr_insert;
  //array for selection sort
  double *arr_select;
  //array for bubble sort
  double *arr_bubble;
  //array for merge sort
  double *arr_merge;
  //array for quick sort
  double *arr_quick;
  //timer for time stamping
  time_t timer;
  //default constructor
  Sort(){
    filename="";
    arr_size=0;
    line="";
  }
  //overloaded constructor
  Sort(string file){
    filename=file;
    arr_size=0;
    line="";
    readFile();
  }
  //destructor
  ~Sort(){
    arr_insert=NULL;
    arr_select=NULL;
    arr_bubble=NULL;
    arr_merge=NULL;
    arr_quick=NULL;
  }
  /**
   * Prints the contents of an array in order
   * @param arr, the array to be printed
   */
  void print(double *arr){
    for(int i=0; i<arr_size; ++i){
      cout<<arr[i]<<endl;
    }
  }
  /**
   * Reads the file and populates the arrays with the given data
   */
  void readFile(){
    in_file.open(filename, ios::in);
    if(in_file.is_open()==false){
      cout<<"File not found, try again."<<endl;
      exit(0);
    }
    //first line of file is number of doubles
    getline(in_file, line);
    arr_size=stod(line);
    //initialize the arrays with given array size
    arr_insert=new double[arr_size];
    arr_select=new double[arr_size];
    arr_bubble=new double[arr_size];
    arr_merge=new double[arr_size];
    arr_quick=new double[arr_size];
    //populate the arrays
    while(!in_file.eof()){
      for(int i=0; i<arr_size; ++i){
        getline(in_file, line);
        if(line!=""){
          double a=stod(line);
          arr_insert[i]=a;
          arr_select[i]=a;
          arr_bubble[i]=a;
          arr_merge[i]=a;
          arr_quick[i]=a;
        }
      }
    }
  }
  /**
   * Implements and runs functions of Insertion Sort
   */
  void insertSort(){
    time_t start=time(&timer);
    for(int j=0; j<arr_size; ++j){
      //marker
      double temp=arr_insert[j];
      int k=j;
      while(k>0 && arr_insert[k-1]>=temp){
        arr_insert[k]=arr_insert[k-1];
        --k;
      }
      arr_insert[k]=temp;
    }
    time_t end=time(&timer);
    cout<<"Insert Sort"<<endl;
    cout<<"Time sort started: "<<asctime(localtime(&start));
    cout<<"Time sort ended: "<<asctime(localtime(&end));
    cout<<endl;
  }
  /**
   * Implements and runs functions of Selection Sort
   */
  void selectionSort(){
    time_t start=time(&timer);
    int minIndex;
    double tmp;
    for(int i=0; i<arr_size; i++){
      minIndex=i;
      for(int j=0; j<arr_size-1; j++){
        if(arr_select[j]>arr_select[minIndex]){
        	 minIndex=j;
        }
        if(minIndex!= i){
          tmp=arr_select[i];
          arr_select[i]=arr_select[minIndex];
          arr_select[minIndex]=tmp;
         }
       }
     }
     time_t end=time(&timer);
     cout<<"Selection Sort"<<endl;
     cout<<"Time sort started: "<<asctime(localtime(&start));
     cout<<"Time sort ended: "<<asctime(localtime(&end));
     cout<<endl;
  }
  /**
   * Implements and runs functions of Bubble Sort
   */
  void bubbleSort(){
    time_t start=time(&timer);
    for(int i=0; i<arr_size; ++i){
      double temp=0;
      for(int j=0; j<arr_size-1;++j){
        if(arr_bubble[j] > arr_bubble[j+1]){
          temp=arr_bubble[j+1];
          arr_bubble[j+1]=arr_bubble[j];
          arr_bubble[j]=temp;
        }
      }
    }
    time_t end=time(&timer);
    cout<<"Bubble Sort"<<endl;
    cout<<"Time sort started: "<<asctime(localtime(&start));
    cout<<"Time sort ended: "<<asctime(localtime(&end));
    cout<<endl;
 }
  /**
   * Merges data of an array, to be used in Merge Sort
   * @param array, array to be merged
   * @param low, int representing lowest position of the array
   * @param mid, int representing the mid point of the array
   * @param high, int representing highest position of the array
   */
  void merge(double *array, int low, int mid, int high){
  	int i=low;
    int j=mid+1;
    int k=0;
    double *temp=new double[high-low+1];
  	while (i<=mid && j<=high){
  		if (array[i]<array[j]){
  			temp[k++]=array[i++];
  		}
  		else{
  			temp[k++]=array[j++];
  		}
  	}
  	while (i<=mid){
  		temp[k++]=array[i++];
  	}
  	while (j<=high){
  		temp[k++]=array[j++];
  	}
  	for(i=low; i<=high; ++i){
  		array[i]=temp[i-low];
  	}
    delete temp;
  }

  /**
   * Implements and runs functions of Merge Sort, recursive
   * @param array, array to be sorted
   * @param low, int representing lowest position of the array
   * @param high, int representing highest position of the array
   */
  void mergeSort(double *array, int low, int high)
  {
  	int mid;
  	if (low < high){
  		mid=(low+high)/2;
  		mergeSort(array, low, mid);
  		mergeSort(array, mid+1, high);
  		merge(array, low, mid, high);
  	}
  }
  /**
   * Used to sort values around the parititioning index, used in Quick Sort
   * @param array, array to be sorted
   * @param low, int representing lowest position of the array
   * @param high, int representing highest position of the array
   * @return int value used to calculate new high and low int
   */
 int partition(double *array, int low, int high){
    int pivot=array[high-1];
    int i=(low-1);
    double temp=0;
    for (int j=low; j<=high-1; ++j){
      if (array[j]<pivot){
        i++;
        temp=array[i];
        array[i]=array[j];
        array[j]=temp;
      }
    }
    temp=array[i+1];
    array[i+1]=array[high-1];
    array[high-1]=temp;
    return (i + 1);
  }
  /**
   * Implements and runs functions of Quick Sort, recursive
   * @param array, array to be sorted
   * @param low, int representing lowest position of the array
   * @param high, int representing highest position of the array
   */
  void quickSort(double *array, int low, int high){
    if(low<high){
      //partitioning index
      int part = partition(array, low, high);
      quickSort(array, low, part-1);
      quickSort(array, part+1, high);
    }
  }

};
