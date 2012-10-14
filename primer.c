// I really like writing prime number functions
// here are two of my favorite that work together



int isPrime(const int i, int* prevPrimes)
{
	int ctr, primer = 0;
	
	for (ctr = prevPrimes[primer]; ctr*ctr < i; ctr = prevPrimes[++primer])
		{
		if (0 == i%ctr) return 0;
		}
	return 1;
}



int* arrayOfPrimes(int numElems)
{
	int* p1 = (int*) malloc(numElems*sizeof(int));
	int i, j = 0;
	p1[0] = 2;
	
	for (i=2; j<numElems; i++) if (isPrime(i, p1)) p1[j++] = i;
	
	return p1;
}