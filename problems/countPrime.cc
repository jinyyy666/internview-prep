int countPrime(int start, int end){
  // idea: http://fahad-cprogramming.blogspot.com/2014/12/c-program-to-find-prime-numbers-in.html
  int count = 0, found = 0;
  for(int i = start; i < end; ++i){
    for(int j = 2; j <= sqrt(i); j++){
      
      if(i%j == 0){
	count++;
      }
      if(count == 0 && i != 1){
	found++;
	cout<<"Prime Number -> "<<i<<endl;
	count = 0;
      }
      count = 0;
    }

  }
  
}
