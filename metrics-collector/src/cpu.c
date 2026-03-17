#include "../includes/cpu.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

float cpu_percentage(int interval_ms) {
    cpu_usage_t s1, s2;

    if(!cpu_read_stat(&s1)) return -1;
    usleep(interval_ms * 1000);
    if(!cpu_read_stat(&s2)) return -1;

    unsigned long long idle1 = s1.idle + s1.iowait;
    unsigned long long idle2 = s2.idle + s2.iowait;
    unsigned long long total1 = s1.user + s1.nice + s1.system + s1.idle + s1.iowait + s1.irq + s1.softirq + s1.steal;
    unsigned long long total2 = s2.user + s2.nice + s2.system + s2.idle + s2.iowait + s2.irq + s2.softirq + s2.steal;

    unsigned long long delta_idle = idle2 - idle1;
    unsigned long long delta_total = total2 - total1;

    return (1 - (float)delta_idle / delta_total) * 100;
}

int cpu_read_stat(cpu_usage_t *cpu_usage) {
    FILE *f = fopen(CPU_FILE, "r");
    if(!f) return -1;
    int result;
    result = fscanf(f, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
        &cpu_usage->user, &cpu_usage->nice, &cpu_usage->system, &cpu_usage->idle, &cpu_usage->iowait, &cpu_usage->irq, &cpu_usage->softirq, &cpu_usage->steal, &cpu_usage->guest, &cpu_usage->guest_nice);
    
    fclose(f);
    return result;
}
