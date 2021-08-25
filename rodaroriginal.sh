gcc sieve1.c -o sieveoriginal -fopenmp -lm 
for i in 1 2 3; do
  time ./sieveoriginal   
done
