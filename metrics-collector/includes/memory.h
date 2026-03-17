#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>
#define MEMORY_FILE "/proc/meminfo"

typedef struct {
  unsigned long long mem_total;
  unsigned long long mem_available;
  unsigned long long mem_cache;
  unsigned long long mem_buff;
  unsigned long long mem_free;
} mem_usage_t;

int mem_read_stat(mem_usage_t *mem_usage);
float *mem_percentages();

#endif
