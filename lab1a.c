#include <stdlib.h>
#include <stdio.h>
#include "omp.h"
#include <time.h>

int randomNumber( int range){
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	srand((time_t)ts.tv_nsec);
	int num = rand()%range;
	return num; 
}

//procedure three
void func3(int*array, int*Dimensions){

	int n =0, mult = 1;
	int *temp = Dimensions;
        int* temp2 =array;
	while(*Dimensions != 0){
		n++;
		mult *= *Dimensions;
		Dimensions++;
	}	

	Dimensions = temp;
	int random_coordinates[n];
	int five = 0.05*mult;
	for(int i = 0; i < five; i++){
		for(int j =0; j < n; j++){
			random_coordinates[j] = randomNumber(*Dimensions);
			Dimensions++;

		}
		Dimensions = temp;

        int index = mapTo_oneNumber(random_coordinates,temp,n);
        int c =0;
        array=temp2;
        while(c<index){
         array++;
         c++;
        }
        Dimensions = temp;
        for(int i=0;i<n;i++)
         printf(" %d ", random_coordinates[i]);
         printf("       value %d \n ", *array );
	}
}

int mapTo_oneNumber(int Carray[], int DArray[], int size){
int prod= 0;
int c =0;
int total =0;


      for(int i=0;i<size;i++){
        }
      for(int i=0;i<size;i++){
           prod=Carray[i];
           for(int j=1+i;j<size;j++){
               prod*=DArray[j];
           }
                 total+= prod;
        }
return (total+1);
}

//Procedure one
void ZeroesArray(int* MultArray, int *Dimensions){
	int size =1;
	int* temp1 = Dimensions;
	int* temp2 = MultArray;

	while(*Dimensions!=0){
		size*= *Dimensions;
		Dimensions++;
	}

	Dimensions = temp1;
	for (int i =0; i<size; i++){
		*MultArray = 0;
		MultArray++;
	}
	MultArray = temp2;
}

//Procedure two
void OnesArray(int* MultArray, int *Dimensions){
	int size =1;
	int* temp1 =Dimensions;
	int* temp2 = MultArray;

	while (*Dimensions!=0){
		size*= *Dimensions;
		Dimensions++;
	}

	Dimensions = temp1;
	for (int i =0; i<size*0.1; i++){
		*MultArray =1;
		MultArray++;
	}
	MultArray = temp2;
}


void ZeroesArray1(int *Dimensions, int size){
int* temp1 =Dimensions;
	for (int i =0; i<size;i++){
	*Dimensions =0;
	Dimensions++;
}

Dimensions =temp1;;

}

int main(){

int *array1_ = calloc(100*100, sizeof(int));
int *array2_ = calloc(100*100*100, sizeof(int));
int *array3_ = calloc(50*50*50*50, sizeof(int));
int *array4_ = calloc(20*20*20*20*20, sizeof(int));
int array1Dimensions[20];

ZeroesArray1(array1Dimensions, 20);

array1Dimensions[0] = 100;
array1Dimensions[1] = 100;

int array2Dimensions[20];

ZeroesArray1(array2Dimensions, 20);

array2Dimensions[0] = 100;
array2Dimensions[1] = 100;
array2Dimensions[3] = 100;

int array3Dimensions[20];

ZeroesArray1(array3Dimensions, 20);

array3Dimensions[0] = 50;
array3Dimensions[1] = 50;
array3Dimensions[3] = 50;
array3Dimensions[4] = 50;

int array4Dimensions[20];

ZeroesArray1(array4Dimensions, 20);

array4Dimensions[0] = 20;
array4Dimensions[1] = 20;
array4Dimensions[3] = 20;
array4Dimensions[4] = 20;
array4Dimensions[4] = 20;

//testing using array1_
ZeroesArray(array1_,array1Dimensions);

OnesArray(array1_,array1Dimensions);

func3(array1_,array1Dimensions);

return 0;
}
