#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

struct Country
{
    char name[20];
    double sqr;
    unsigned long int population;
    unsigned long int GDP;

};


void intro(struct Country *ar, int i0, int n);

void outro(struct Country *ar, int n);

int sortPop (struct Country A, struct Country B);

int sortSqr (struct Country A, struct Country B);

int sortGDP (struct Country A, struct Country B);

int sortName(struct Country A, struct Country B);

void sortingV (struct Country *A, int a, int b, int (*fptr)(Country,Country));

void sortingY (struct Country *A, int a, int b, int (*fptr)(Country,Country));

void mysort (struct Country *A, int elements, int (*fptr)(Country,Country), bool vozrast);

#endif // FUNCTIONS_H_

