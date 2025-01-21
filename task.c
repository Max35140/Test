#include <stdio.h>
#include <omp.h>

void task_function(int id) {
  printf("Task %d is being executed by thread %d\n", id, omp_get_thread_num());
}

int main() {
  omp_set_num_threads(4);
  #pragma omp parallel 
  {
    #pragma omp master
    {
      for (int i = 0; i < 10; i++) {
        #pragma omp task
        {
          task_function(i);
        }
      }
    }
  }
  return 0;
}
