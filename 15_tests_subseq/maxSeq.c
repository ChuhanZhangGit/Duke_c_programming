
size_t maxSeq(int * array, size_t n){
  int maxseq = 1;
  if n == 1 {
      return 1;
    }
  else if n == 0{
      return 0;
    }
  else {
    int seq = 1;
    for (int i = 1; i < n; i++){
      if array[i] > array[i-1]{
	  seq += 1;
	}
      else {
	if maxseq < seq {
	    maxseq = seq;
	  }
	seq = 1;
      }
    }
    return maxseq
  }
}
	  
