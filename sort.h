#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

class Sort{
public:
  string filename;
  ifstream in_file;
  string line;
  int arr_size;
  double *arr_insert;
  double *arr_select;
  double *arr_bubble;
  double *arr_merge;
  double *arr_quick;
  time_t timer;

  Sort(){
    filename="";
    arr_size=0;
    line="";
  }
  Sort(string file){
    filename=file;
    arr_size=0;
    line="";
  }
  ~Sort(){
    arr_insert=NULL;
    arr_select=NULL;
    arr_bubble=NULL;
    arr_merge=NULL;
    arr_quick=NULL;
  }

  void print(double *arr){
    for(int i=0; i<arr_size; ++i){
      cout<<arr[i]<<endl;
    }
  }

  void readFile(){
    in_file.open(filename, ios::in);
    if(in_file.is_open()==false){
      cout<<"File not found, try again."<<endl;
      exit(0);
    }
    getline(in_file, line);
    arr_size=stod(line);
    arr_insert=new double[arr_size];
    arr_select=new double[arr_size];
    arr_bubble=new double[arr_size];
    arr_merge=new double[arr_size];
    arr_quick=new double[arr_size];
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

  void insertSort(){
    time_t start=time(&timer);
    for(int j=0; j<arr_size; ++j){ //marker
      double temp=arr_insert[j]; //store marked item
      int k=j; //where to start shifting
      while(k>0 && arr_insert[k-1]>=temp){ //while the thing to the left is larger, shift
        arr_insert[k]=arr_insert[k-1];
        --k;
      }
      arr_insert[k]=temp; //put marked item into right spot
    }
    time_t end=time(&timer);
    cout<<"Insert Sort"<<endl;
    cout<<"Time sort started: "<<asctime(localtime(&start));
    cout<<"Time sort ended: "<<asctime(localtime(&end));
    cout<<endl;
  }

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

void merge(double *array, int low, int mid, int high){
	// We have low to mid and mid+1 to high already sorted.
	int i;
  int j;
  int k;
  double *temp=new double[high-low+1];
	i=low;
	j=mid+1;
  k=0;

	// Merge the two parts into temp[].
	while (i<=mid && j<=high){
		if (array[i]<array[j]){
			temp[k++]=array[i++];
		}
		else{
			temp[k++]=array[j++];
		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (i<=mid){
		temp[k++]=array[i++];
	}

	// Insert all the remaining values from j to high into temp[].
	while (j<=high){
		temp[k++]=array[j++];
	}

	// Assign sorted data stored in temp[] to a[].
	for (i=low; i<=high; ++i){
		array[i]=temp[i-low];
	}
  delete temp;
}

// A function to split array into two parts.
void mergeSort(double *array, int low, int high)
{
	int mid;
	if (low < high){
		mid=(low+high)/2;
		// Split the data into two half.
		mergeSort(array, low, mid);
		mergeSort(array, mid+1, high);

		// Merge them to get sorted output.
		merge(array, low, mid, high);
	}
}

 int partition(double *array, int low, int high){
    int pivot=array[high-1];
    int i=(low-1);
    double temp=0;
    for (int j=low; j<=high-1; ++j){
        // If current element is smaller than the pivot
        if (array[j]<pivot){
            i++;
            //swap(&arr[i], &arr[j]);
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
             // increment index of smaller element
        }
    }
    //swap pivot with
    temp=array[i+1];
    array[i+1]=array[high-1];
    array[high-1]=temp;
    return (i + 1);
  }

  void quickSort(double *array, int low, int high){
    if(low<high){
        /* pi is partitioning index, arr[p] is now
        at right place */
        int part = partition(array, low, high);
        // Separately sort elements before
        // partition and after partition
        quickSort(array, low, part-1);
        quickSort(array, part+1, high);
    }
  }
};
