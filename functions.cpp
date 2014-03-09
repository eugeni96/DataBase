#include <iostream>
#include <fstream>
#include "functions.h"
#include <cstring>

using namespace std;

void intro(struct Country *ar, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"Enter country"<<endl;
        cin.ignore();
        cin.getline(ar[i].name,30,'\n');
        cout<<"Enter square"<<endl;
        cin>>ar[i].sqr;
        cin.ignore();
        cout<<"Enter population"<<endl;
        cin>>ar[i].population;
        cin.ignore();
        cout<<"Enter GDP"<<endl;
        cin>>ar[i].VVP;

    }
}

void outro(struct Country *ar, int n)
{
    printf("6      Country     7|8   Square    9|10 Population 11|12     GDP   13|");
    for (int i=0; i<n; i++)
    {
        printf("\n");
        printf("%20s|", ar[i].name);
        printf("%15.2f|", ar[i].sqr);
        printf("%16ld|", ar[i].population);
        printf("%15ld|", ar[i].VVP);
    }
}

void sortingNameAZ (struct Country *A, int a, int b)
{

    int m, n;
    char *k;
    m=a;
    n=b;
    k=A[(a+b)/2].name;
    Country t;
    do {
        while (strcmp(A[m].name,k)<0)
            m++;
        while (strcmp(A[n].name,k)>0)
            n--;
        if(m <= n)
        {
            t=A[n];
            A[n]=A[m];
            A[m]=t;
            m++;
            n--;
        }

    }
    while (m<=n);
    if (m<b)
        sortingNameAZ(A,m,b);
    if (a<n)
        sortingNameAZ(A,a,n);
}

void sortingNameZA (struct Country *A, int a, int b)
{

    int m, n;
    char *k;
    m=a;
    n=b;
    k=A[(a+b)/2].name;
    Country t;
    do {
        while (strcmp(A[m].name,k)>0)
            m++;
        while (strcmp(A[n].name,k)<0)
            n--;
        if(m <= n)
        {
            t=A[n];
            A[n]=A[m];
            A[m]=t;
            m++;
            n--;
        }

    }
    while (m<=n);
    if (m<b)
        sortingNameZA(A,m,b);
    if (a<n)
        sortingNameZA(A,a,n);
}

void sortingPopYbiv (struct Country *A, int a, int b)
{

    int m, n;
    long unsigned int k;
    m=a;
    n=b;
    k=A[(a+b)/2].population;
    Country t;
    do {
        while (A[m].population>k)
            m++;
        while (A[n].population<k)
            n--;
        if(m <= n)
        {
            t=A[n];
            A[n]=A[m];
            A[m]=t;
            m++;
            n--;
        }

    }
    while (m<=n);
    if (m<b)
        sortingPopYbiv(A,m,b);
    if (a<n)
        sortingPopYbiv(A,a,n);
}

void sortingPopVozrast (struct Country *A, int a, int b)
{

    int m, n;
    long unsigned int k;
    m=a;
    n=b;
    k=A[(a+b)/2].population;
    Country t;
    do {
        while (A[m].population<k)
            m++;
        while (A[n].population>k)
            n--;
        if(m <= n)
        {
            t=A[n];
            A[n]=A[m];
            A[m]=t;
            m++;
            n--;
        }

    }
    while (m<=n);
    if (m<b)
        sortingPopVozrast(A,m,b);
    if (a<n)
        sortingPopVozrast(A,a,n);
}


void sortingSqrVozrast (struct Country *A, int a, int b)
{

    int m, n;
    double k;
    m=a;
    n=b;
    k=A[(a+b)/2].sqr;
    Country t;
    do {
        while (A[m].sqr<k)
            m++;
        while (A[n].sqr>k)
            n--;
        if(m <= n)
        {
            t=A[n];
            A[n]=A[m];
            A[m]=t;
            m++;
            n--;
        }

    }
    while (m<=n);
    if (m<b)
        sortingSqrVozrast(A,m,b);
    if (a<n)
        sortingSqrVozrast(A,a,n);
}

void sortingSqrYbiv (struct Country *A, int a, int b)
{

    int m, n;
    double k;
    m=a;
    n=b;
    k=A[(a+b)/2].sqr;
    Country t;
    do {
        while (A[m].sqr>k)
            m++;
        while (A[n].sqr<k)
            n--;
        if(m <= n)
        {
            t=A[n];
            A[n]=A[m];
            A[m]=t;
            m++;
            n--;
        }

    }
    while (m<=n);
    if (m<b)
        sortingSqrYbiv(A,m,b);
    if (a<n)
        sortingSqrYbiv(A,a,n);
}

void sortingGDPVozrast (struct Country *A, int a, int b)
{

    int m, n;
    long unsigned int k;
    m=a;
    n=b;
    k=A[(a+b)/2].VVP;
    Country t;
    do {
        while (A[m].VVP<k)
            m++;
        while (A[n].VVP>k)
            n--;
        if(m <= n)
        {
            t=A[n];
            A[n]=A[m];
            A[m]=t;
            m++;
            n--;
        }

    }
    while (m<=n);
    if (m<b)
        sortingGDPVozrast(A,m,b);
    if (a<n)
        sortingGDPVozrast(A,a,n);
}


void sortingGDPYbiv (struct Country *A, int a, int b)
{

    int m, n;
    long unsigned int k;
    m=a;
    n=b;
    k=A[(a+b)/2].VVP;
    Country t;
    do {
        while (A[m].VVP>k)
            m++;
        while (A[n].VVP<k)
            n--;
        if(m <= n)
        {
            t=A[n];
            A[n]=A[m];
            A[m]=t;
            m++;
            n--;
        }

    }
    while (m<=n);
    if (m<b)
        sortingGDPYbiv(A,m,b);
    if (a<n)
        sortingGDPYbiv(A,a,n);
}
