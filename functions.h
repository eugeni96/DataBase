#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

struct Country
{
    char name[20];
    double sqr;
    unsigned long int population;
    unsigned long int VVP;

};

void intro(struct Country *ar, int i0, int n);

void outro(struct Country *ar, int n);

void control(struct Country *ar, int n);

void sortingPopYbiv (struct Country *A, int a, int b);

void sortingPopVozrast (struct Country *A, int a, int b);

void sortingSqrVozrast (struct Country *A, int a, int b);

void sortingSqrYbiv (struct Country *A, int a, int b);

void sortingGDPVozrast (struct Country *A, int a, int b);

void sortingGDPYbiv (struct Country *A, int a, int b);

void sortingNameAZ (struct Country *A, int a, int b);

void sortingNameZA (struct Country *A, int a, int b);



#endif // FUNCTIONS_H_

