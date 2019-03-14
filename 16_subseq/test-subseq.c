#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int * array, size_t n){
  int maxseq = 1;
  if (n == 1 ){
      return 1;
    }
  else if (n == 0){
      return 0;
    }
  else {
    int seq = 1;
    for (int i = 1; i < n; i++){
      if (array[i] > array[i-1]){
	  seq += 1;
	}
      else {
	seq = 1;
      }
    
      if (maxseq < seq) {
	maxseq = seq;
      }
    } 
    return maxseq;
  }
}


int printfunc(size_t max_fun, size_t right_max, int * array, size_t n) {
  if (max_fun != right_max){
    printf("Failed on {");
    for (int i =0; i <n; i++){
      if (i == n-1){
	printf("%d",array[i]);
      }
      else{	
	printf("%d,", array[i]);
      }
    }
    printf("%c",'}');
    return EXIT_FAILURE;    
  }
  else{
    return EXIT_SUCCESS;
  }
}


int main(void){
  int array1[] = { 1, 2, 1, 3, 5, 7, 2, 4, 6, -9};
  int array2[] = {2, 4, 67, 93, 94, 102};
  int array3[] = {-2};
  int array4[] = {-4,-4,-4, -3,-3};
  int array5[] = {1,-3,5,8};

  int * array_ptr[] = {array1, array2,array3, array4, array5};
  size_t size[] = {10, 6, 1, 5, 4};
  size_t right_array[] = {4, 6, 1, 2, 3};
  int num_test = 5;
  // test NULL array and array with size 0
  if (maxSeq(NULL, 0)){
    printf("Fail on NULL");
    return EXIT_FAILURE;
  }
  
  if (maxSeq(array1, 0)){
    printf("Fail on array1 with size 0");
    return EXIT_FAILURE;
  }

  printf("after the Null test.\n");

  for (int i = 0; i<num_test; i++){
    int result = printfunc(maxSeq(array_ptr[i], size[i]), right_array[i], array_ptr[i], size[i]);
    if (result != EXIT_SUCCESS) {
      return EXIT_FAILURE;
    }
  }
  printf("all test passed.\n");
  return EXIT_SUCCESS;
}
  
