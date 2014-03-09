#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;


void control(struct Country *ar, int n)
{
    fstream mystream;
    int vvod=1;
    int elements;
    int elemAdd;
    int del;
    mystream.open("system.txt",ios::in|ios::binary);
    mystream.read((char *) &elements, sizeof(int));
    mystream.close();
    while (vvod)
    {
        cout<<endl<<"vvedite operaciIO"<<endl;
        cin>>vvod;
        if(vvod==1)
        {
            cout<<"Enter size"<<endl;
            cin>>elemAdd;
            intro(ar,0,elemAdd);
            mystream.open("mydata.txt",ios::out|ios::binary|ios::trunc);
            mystream.write((char *) ar, elemAdd*sizeof(Country));
            mystream.close();
            elements=elemAdd;
        }
        if(vvod==2)
        {
            cout<<"Enter size"<<endl;
            cin>>elemAdd;
            intro(ar,elements,elemAdd);
            elements=elements+elemAdd;
            mystream.open("mydata.txt",ios::out|ios::binary|ios::trunc);
            mystream.write((char *) ar, elements*sizeof(Country));
            mystream.close();

        }
        if(vvod==3)
        {
            cout<<"Enter number of element"<<endl;
            cin>>del;
            if (del<=elements)
            {
                ar[del-1]=ar[elements-1];
                elements--;
                mystream.open("mydata.txt",ios::out|ios::binary|ios::trunc);
                mystream.write((char *) ar, elemAdd*sizeof(Country));
                mystream.close();
            }


        }
        if(vvod==4)
        {
            mystream.open("mydata.txt",ios::in|ios::binary);
            mystream.read((char *) ar, elements*sizeof(Country));
            mystream.close();
        }
        if(vvod==5)
        {
            outro(ar,elements);
        }
        if(vvod==6)
        {
            sortingNameAZ(ar,0,elements-1);
        }
        if(vvod==7)
        {
            sortingNameZA(ar,0,elements-1);
        }
        if(vvod==8)
        {
            sortingSqrVozrast(ar,0,elements-1);
        }
        if(vvod==9)
        {
            sortingSqrYbiv(ar,0,elements-1);
        }
        if(vvod==10)
        {
            sortingPopVozrast(ar,0,elements-1);
        }
        if(vvod==11)
        {
            sortingPopYbiv(ar,0,elements-1);
        }
        if(vvod==12)
        {
            sortingGDPVozrast(ar,0,elements-1);
        }
        if(vvod==13)
        {
            sortingGDPYbiv(ar,0,elements-1);
        }
        if(vvod==14)
        {
            mystream.open("mydata.txt",ios::out|ios::binary|ios::trunc);
            mystream.write((char *) ar, elements*sizeof(Country));
            mystream.close();
        }
        mystream.open("system.txt",ios::out|ios::binary|ios::trunc);
        mystream.write((char *) &elements, sizeof(int));
        mystream.close();
    }

}

int main()
{
    cout<<"Base of data created by Eugeni"<<endl
        <<"Dlya vihoda vvedite - 0"<<endl
        <<"Dlya zapisi poverh starogo faila vvedite - 1"<<endl
        <<"Dlya dobavleniya novih elementov BD vvedite - 2"<<endl
        <<"Dlya ydaleniya elementa vvedite - 3"<<endl
        <<"Dlya zagryzki faila vvedite - 4"<<endl
        <<"Dlya vivoda BD vvedite - 5"<<endl
        <<"Dlya sortirovki po nazvaniIO ot A do Z vvedite - 6"<<endl
        <<"Dlya sortirovki po nazvaniIO ot Z do A vvedite - 7"<<endl
        <<"Dlya sort po square po vozrastaniIO vvedite - 8"<<endl
        <<"Dlya sort po square po ybivaniIO vvedite - 9"<<endl
        <<"Dlya sort po population po vozrast vvedite - 10"<<endl
        <<"Dlya sort po population po ybiv vvedite - 11"<<endl
        <<"Dlya sort po GDP po vozrast vvedite - 12"<<endl
        <<"Dlya sort po GDP po ybiv vvedite - 13"<<endl
        <<"Dlya sohraneniya v fail vvedite - 14"<<endl;

    Country *ar;
    const int n=20;
    ar = new Country[n];
    control(ar,n);
    delete [] ar;
    return 0;
}
