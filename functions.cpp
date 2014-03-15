#include <iostream>
#include <fstream>
#include "functions.h"
#include <cstring>
#include <iomanip>

using namespace std;

void intro(struct Country *ar, int i0, int n)
{
    for(int i=i0; i<i0+n; i++)
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
        cin>>ar[i].GDP;
    }
}

void outro(struct Country *ar, int n)
{
    cout<<"6      Country     7|8   Square    9|10 Population 11|12     GDP   13|";
    for (int i=0; i<n; i++)
    {
        cout<<endl;
        cout.setf(ios::fixed);
        cout<<setw(20)<<ar[i].name<<"|";
        cout<<setw(15)<<setprecision(3)<<ar[i].sqr<<"|";
        cout<<setw(16)<<ar[i].population<<"|";
        cout<<setw(15)<<ar[i].GDP<<"|";
    }
}




void sortingV (struct Country *A, int a, int b, int (*fptr)(Country,Country))
{

    int m, n;
    Country k;
    m=a;
    n=b;
    k=A[(a+b)/2];
    Country t;
    do
    {
        while ((*fptr)(A[m],k)<0)
            m++;
        while ((*fptr)(A[n],k)>0)
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
        sortingV(A,m,b,(*fptr));
    if (a<n)
        sortingV(A,a,n,(*fptr));
}



void sortingY (struct Country *A, int a, int b, int (*fptr)(Country,Country))
{

    int m, n;
    Country k;
    m=a;
    n=b;
    k=A[(a+b)/2];
    Country t;
    do
    {
        while ((*fptr)(A[m],k)>0)
            m++;
        while ((*fptr)(A[n],k)<0)
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
        sortingY(A,m,b,(*fptr));
    if (a<n)
        sortingY(A,a,n,(*fptr));
}

void mysort (struct Country *A, int elements, int (*fptr)(Country,Country), bool vozrast)
{
    int a=0, b=elements-1;
    if (vozrast)
    {
        sortingV(A,a,b,(*fptr));
    } else
    {
        sortingY(A,a,b,(*fptr));
    }
}

int sortName(struct Country A, struct Country B)
{
    return strcmp(A.name,B.name);
}

int sortPop (struct Country A, struct Country B)
{
    return A.population-B.population;
}

int sortSqr (struct Country A, struct Country B)
{
    return A.sqr-B.sqr;
}

int sortGDP (struct Country A, struct Country B)
{
    return A.GDP-B.GDP;
}

