gcc sieve.c -o sieve -fopenmp -lm 
for i in 1 2 3; do
  time ./sieve   
done
