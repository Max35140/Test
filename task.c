#include <stdio.h>
#include <omp.h>

int main() {
  omp_set_num_threads(4);
  #pragma omp parallel 
  {
    #pragma omp master
    {
      for (int i = 0; i < 10; i++) {
        #pragma omp task
        {
          int j = 1
        }
      }
    }
  }
  return 0;
}
