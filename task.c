#include <stdio.h>
#include <omp.h>

void task_function(int id) {
  printf("Task %d is being executed by thread %d\n", id, omp_get_thread_num());
}

void test_function(int id) {
  int i;
  i = id + 2;
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
          test_function(i);
        }
      }
    }
  }
  return 0;
}
