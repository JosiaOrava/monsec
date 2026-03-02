#include <stdio.h>
#include <stdint.h>
#include "../includes/cpu.h"

int main() {
    float cpu_percent = cpu_percentage(DELTA_TIME);
    if(cpu_percent == -1) {
        printf("Error calculating CPU percentage\n");
        return -1;
    }
    printf("CPU: %.2f%%\n", cpu_percent);
    return 0;
}