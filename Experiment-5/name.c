#include<stdio.h>
#include<omp.h>

int main(){
	#pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        char *names[] = {"Sagar", "Pratik", "Prateek", "Harshal","Aman","Rajwardhan","Rajat","Sahil"}; 
        printf("Thread %d: %s\n", thread_id, names[thread_id]);
    }
return 0;
}
