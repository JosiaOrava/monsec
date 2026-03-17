#include <stdio.h>
#include <stdlib.h>
#include "../includes/memory.h"


int mem_read_stat(mem_usage_t *mem_usage) {
  FILE *f = fopen(MEMORY_FILE, "r");
  if(!f) return -1;
  int result;
  result = fscanf(f, "MemTotal: %llu kB\nMemFree: %llu kB\nMemAvailable: %llu kB\nBuffers: %llu kB\nCached: %llu", &mem_usage->mem_total, &mem_usage->mem_free, &mem_usage->mem_available, &mem_usage->mem_buff, &mem_usage->mem_cache);
  fclose(f);
  return result;
}

float *mem_percentages() {
  mem_usage_t s1;

  if(!mem_read_stat(&s1)) return NULL;

  float *result = malloc(sizeof(float) * 5);
  if(!result) return NULL;

  float total_GB = s1.mem_total / (1024.0 * 1024.0);
  float used_GB = (s1.mem_total - s1.mem_available) / (1024.0 * 1024.0);
  float available_GB = s1.mem_available / (1024.0 * 1024.0);
  float cache_GB = s1.mem_cache / (1024.0 * 1024.0);
  float free_GB = s1.mem_free / (1024.0 * 1024.0);
  
  result[0] = total_GB;
  result[1] = used_GB;
  result[2] = available_GB;
  result[3] = cache_GB;
  result[4] = free_GB;

  return result;
}
