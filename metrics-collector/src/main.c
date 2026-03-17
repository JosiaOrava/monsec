#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../includes/cpu.h"
#include "../includes/memory.h"

int main() {
    float cpu_percent = cpu_percentage(DELTA_TIME);
    if(cpu_percent == -1) {
        printf("Error calculating CPU percentage\n");
        return -1;
    }
    printf("CPU: %.2f%%\n", cpu_percent);
    
    float *mem_usage = mem_percentages();
    if(mem_usage == NULL) {
      printf("Error reading MEM usage\n");
      free(mem_usage);
      return -1;
    }
    printf("MEMORY:\nTOTAL: %.2f GiB\nUSED: %.2f GiB\nAVAILABLE: %.2f GiB\nCACHE: %.2f GiB\nFREE: %.2f GiB\n", mem_usage[0], mem_usage[1], mem_usage[2], mem_usage[3], mem_usage[4]);
    free(mem_usage);
    return 0;
}
