#include <stdio.h>
#include <omp.h>

int main() {
    int total_sum = 0;

    #pragma omp parallel
    {
        int partial_sum = 0;  

        #pragma omp for
        for (int i = 1; i <= 20; i++) {
            partial_sum += i;  
        }

        #pragma omp atomic
        total_sum += partial_sum;  
    }

    printf("Total Sum: %d\n", total_sum);  
    return 0;
}
