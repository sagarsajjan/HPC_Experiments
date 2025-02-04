#include <stdio.h>
#include <omp.h>
void sequential_pi(){
 long long num_terms = 100000000;  
    double pi = 0.0;
    double start,end;
    start = omp_get_wtime();
    for (long long i = 0; i < num_terms; i++) {
        double term = 4.0 / (2 * i + 1);
        if (i % 2 != 0){
                term = -term;
        }
        pi += term;
    }
    end = omp_get_wtime();
printf("For sequential Calculation: \n\n");
    printf("Value of Pi: %f\n", pi);
    printf("Required time :%f\n",end-start);
}
int main() {
    sequential_pi();
    long long num_terms = 100000000;  
    double pi = 0.0;
    double start,end;
    start = omp_get_wtime();
    #pragma omp parallel for reduction(+:pi)
    for (long long i = 0; i < num_terms; i++) {
        double term = 4.0 / (2 * i + 1);
        if (i % 2 != 0){ 
		term = -term;
	}  
        pi += term;
    }
    end = omp_get_wtime();
printf("\nFor Parallel Calculation: \n\n");
    printf("Value of Pi: %f\n", pi);
	printf("Required time :%f\n",end-start);
    return 0;
}
