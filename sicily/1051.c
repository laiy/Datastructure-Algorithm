#include <cstdio>
#define Pi 3.1415927

int main() {
    float diameter, time;
    int revolutions;
    short count = 1;
    while (scanf("%f %d %f", &diameter, &revolutions, &time)) {
        if (revolutions == 0)
            break;
        printf("Trip #%hd: %.2f %.2f\n", count++, (diameter / 63360) * Pi * revolutions, (diameter / 63360) * Pi * revolutions / (time / 3600));
    }
    return 0;
}
