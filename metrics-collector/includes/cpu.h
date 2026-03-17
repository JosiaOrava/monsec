#ifndef CPU_H
#define CPU_H

#include <stdint.h>

#define CPU_FILE "/proc/stat"
#define DELTA_TIME 3000 // 15 seconds in milliseconds

typedef struct {
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
    unsigned long long iowait;
    unsigned long long irq;
    unsigned long long softirq;
    unsigned long long steal;
    unsigned long long guest;
    unsigned long long guest_nice;
} cpu_usage_t;

float cpu_percentage(int interval_ms);
int cpu_read_stat(cpu_usage_t *cpu_usage);

#endif
