#include <stdio.h>
#include <omp.h>

int task_funktion(int id) {
  for (int i = 0; i < 10; i++) {
    print(i)
  }
  printf("Task %d is being executed by thread %d\n", id, omp_get_thread_num());
  if(id == 100) {
    task_funktion(100);
  }
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
          task_funktion(i);
        }
        #pragma omp task
          {
            task_funktion(100);
          }
      }
    }
  }
  return 0;
}
