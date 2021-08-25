/*
Programa testado no servidor da PUC:

Tempo original (solução da tarefa 3)
5761455

real    0m3.647s
user    0m6.760s
sys     0m0.084s
5761455

real    0m3.900s
user    0m7.052s
sys     0m0.072s
5761455

real    0m3.667s
user    0m6.834s
sys     0m0.084s



----------------------------------

Tempo otimizado:
5761455

real    0m2.539s
user    0m9.714s
sys     0m0.088s
5761455

real    0m2.527s
user    0m9.675s
sys     0m0.088s
5761455

real    0m2.506s
user    0m9.622s
sys     0m0.092s
*/
     
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
     
int sieveOfEratosthenes(int n)
{
   // Create a boolean array "prime[0..n]" and initialize
   // all entries it as true. A value in prime[i] will
   // finally be false if i is Not a prime, else true.
   int primes = 0; 
   bool *prime = (bool*) malloc((n+1)*sizeof(bool));
   int sqrt_n = sqrt(n);
     
   memset(prime, true,(n+1)*sizeof(bool));
   
   int i, p;
   
   #pragma omp parallel for schedule(dynamic)
   for (p=2; p <= sqrt_n; p++)
   {
       // If prime[p] is not changed, then it is a prime
       if (prime[p] == true)
       {
           // Update all multiples of p
   		   #pragma omp parallel for
		   for(i=p*2; i<=n; i += p)
	           prime[i] = false;
       }
   }
   
   // count prime numbers
	#pragma omp parallel for reduction(+:primes)   
	for (int p=2; p<=n; p++)
       if (prime[p])
         primes++;
 
      return(primes);
   }
     
int main()
{
   int n = 100000000;
   printf("%d\n",sieveOfEratosthenes(n));
   return 0;
} 
