#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0; 
    
    #pragma omp parallel
    {
        int partial_sum = 0;
        #pragma omp for lastprivate(sum) 
        for (int i = 1; i <= 20; i++) {
            partial_sum += i;  

        } 
        sum += partial_sum;
    }
    
    printf("Total Sum of first %d natural numbers: %d\n", 20, sum);
    return 0;
}

