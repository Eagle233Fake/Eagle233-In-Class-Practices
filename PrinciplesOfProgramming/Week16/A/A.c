#include <stdio.h>

typedef union f
{
    double g;
    int e;
}f;

typedef struct car
{
    char id[21];
    char brand[51];
    int type;
    f fa;

}car;

int main(void)
{
    car cars;
    while (scanf("%s %s %d", cars.id, cars.brand, &cars.type) != EOF)
    {
        getchar();
        if (cars.type == 0)
        {
            scanf("%lf", &cars.fa.g);
            printf("License Plate: %s, Brand: %s, Engine Type: %d, Displacement: %.1lf\n", cars.id, cars.brand, cars.type, cars.fa.g);
        }
        else
        {
            scanf("%d", &cars.fa.e);
            printf("License Plate: %s, Brand: %s, Engine Type: %d, Battery Capacity: %d\n", cars.id, cars.brand, cars.type, cars.fa.e);
        }
    }
}