Code::Blocks 16.01 GNU GCC compiler
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <iomanip>

using namespace std;

void druk_statystyk(int *odp,int *popodp); // wyswietlanie statystyk
void przesun(int lnuty,char*nuty); //przesuwanie nut w tablicy kiedy odp jest poprawna
int minimum(int a); // przyrownanie pozostalej liczby nut do 3
void przewin(int lnuty,char*nuty); //przesuwanie zle odgadnietej nuty na koniec
void quiz(char *nuty, int *odp, int *popodp); //quiz
void program();// munu
void drukowanie(char *nuty,int l_nut); //drukowanie pieciolinii
void losowanie(char*nuty); //losowanie nut do quizu


char *nuty= new char [10]; //tablica z wylosowanymi nutami
int *odp= new int[7]; //tablica liczaca  odp danej nuty
int *popodp=new int[7]; //tablica liczaca poprawne odp dla danej nuty



int main()
{
    srand( time( NULL ) );
    //zerowanie tablic z odp
    for(int i=0; i<7; i++)
    {
        odp[i]=0;
        popodp[i]=0;
    }

    losowanie(nuty);
    program();
    return 0;
}

void losowanie(char *nuty)
{
    for(int i=0; i<10; i++)
    {
        switch(rand()%7 +1)
        {
        case 1:
            nuty[i]='c';
            break;
        case 2:
            nuty[i]='d';
            break;
        case 3:
            nuty[i]='e';
            break;
        case 4:
            nuty[i]='f';
            break;
        case 5:
            nuty[i]='g';
            break;
        case 6:
            nuty[i]='a';
            break;
        case 7:
            nuty[i]='h';
            break;
        }

    }
}


void przesun(int lnuty, char*nuty) //kiedy odp jest poprawna nuty przesuwaja sie o jedno miejsce do przodu
{
    for(int i=0; i<lnuty; i++)
    {
        nuty[i]=nuty[i+1];
    }
}

void przewin(int lnuty,char *nuty)//zle odgadnieta nuta idzie na koniec
{
    char buf;
    buf=nuty[0];
    for(int i=0; i<lnuty-1; i++)
    {
        nuty[i]=nuty[i+1];
    }
    nuty[lnuty-1]=buf;

}


int minimum(int a)
{
    int b= 3;
    if(a<3)
        b=a;
    return b;
}
void quiz(char *nuty, int *odp, int *popodp)
{
    int l_nut=10; //liczba nut
    char x;
    do
    {
        system("cls");



        drukowanie(nuty,l_nut);

        cout<<endl<<"Jaka to nuta?"<<endl;
        cin>>x;
        if(nuty[0]==x)
        {
            if(l_nut>1)
                przesun(l_nut, nuty);
            l_nut--;
            switch(x)
            {
            case 'c':
                odp[0]++;
                popodp[0]++;
                break;
            case 'd':
                odp[1]++;
                popodp[1]++;
                break;
            case 'e':
                odp[2]++;
                popodp[2]++;
                break;
            case 'f':
                odp[3]++;
                popodp[3]++;
                break;
            case 'g':
                odp[4]++;
                popodp[4]++;
                break;
            case 'a':
                odp[5]++;
                popodp[5]++;
                break;
            case 'h':
                odp[6]++;
                popodp[6]++;
                break;

            }
        }
        else
        {
            przewin(l_nut, nuty);
            switch(x)
            {
            case 'c':
                odp[0]++;
                break;
            case 'd':
                odp[1]++;
                break;
            case 'e':
                odp[2]++;
                break;
            case 'f':
                odp[3]++;
                break;
            case 'g':
                odp[4]++;
                break;
            case 'a':
                odp[5]++;
                break;
            case 'h':
                odp[6]++;
                break;

            }
        }


    }
    while(l_nut>0);
    program();
}

void drukowanie(char *nuty,int l_nut)
{
    system("cls");
    char plinia[11][30];
    for (int i=0; i<11; i++)
    {
        if(i%2==0 && i<10)
        {
            for (int j=0; j<30; j++)
            {
                plinia[i][j]='-';
            }
        }
        else
        {
            for (int j=0; j<30; j++)
            {
                plinia[i][j]=' ';
            }
        }
    }
    for(int i=0; i<minimum(l_nut); i++)
    {
        switch(nuty[i])
        {
        case 'c':
            plinia[10][i*8]='-';
            plinia[10][i*8 +1]='-';
            plinia[10][i*8 +2]='(';
            plinia[10][i*8 +4]=')';
            plinia[10][i*8 +5]='-';
            plinia[10][i*8 +6]='-';
            break;
        case 'd':
            plinia[9][i*8 +2]='(';
            plinia[9][i*8 +3]=' ';
            plinia[9][i*8 +4]=')';
            break;
        case 'e':
            plinia[8][i*8 +2]='(';
            plinia[8][i*8 +3]=' ';
            plinia[8][i*8 +4]=')';
            break;
        case 'f':
            plinia[7][i*8 +2]='(';
            plinia[7][i*8 +3]=' ';
            plinia[7][i*8 +4]=')';
            break;
        case 'g':
            plinia[6][i*8 +2]='(';
            plinia[6][i*8 +3]=' ';
            plinia[6][i*8 +4]=')';
            break;
        case 'a':
            plinia[5][i*8 +2]='(';
            plinia[5][i*8 +3]=' ';
            plinia[5][i*8 +4]=')';
            break;
        case 'h':
            plinia[4][i*8 +2]='(';
            plinia[4][i*8 +3]=' ';
            plinia[4][i*8 +4]=')';
            break;
        }
    }

    for(int i=0; i<11; i++)
    {
        for(int j=0; j<30; j++)
            cout<<plinia[i][j];
        cout<<endl;
    }
}

void program()
{
    losowanie(nuty);
    system("cls");
    cout << "Program wspomagajacy nauke nut." << endl<<endl<<"1.Uruchomienie quizu"<<endl<<"2.Statystyki"<<endl<<"3.Koniec programu"; //-----------
    cout<<endl;
    int x;
    cin>>x;
    switch(x)
    {
    case 1:
        quiz(nuty, odp,popodp);
        break;

    case 2:
        druk_statystyk(odp,popodp);
        break;
    case 3:
        exit(0);
        break;
    default:
        cout<<"Nie ma takiej opcji.";
    }
}


void druk_statystyk(int *odp,int *popodp)
{
    system("cls");
    losowanie(nuty);
    cout << "Program wspomagajacy nauke nut." << endl<<endl<<"1.Uruchomienie quizu"<<endl<<"2.Koniec programu";
    cout<<endl;
    int x;

    double procenty[7]; //proceny poprawnych odp dla danych nut
    int suma =0;
    int suma_podp=0;
    double procent_sumy=0; //procent poprawnych odp dla wszystkich odp

    suma_podp=popodp[0]+popodp[1]+popodp[2]+popodp[3]+popodp[4]+popodp[5]+popodp[6];
    suma= odp[0]+odp[1]+odp[2]+odp[3]+odp[4]+odp[5]+odp[6];
    if(suma!=0)
        procent_sumy=(static_cast<float>(suma_podp)/suma)*100;
    for(int i=0; i<7; i++)
    {
        if(odp[i]==0)
            procenty[i]=0;
        else
            procenty[i]=(static_cast<float>(popodp[i])/odp[i])*100;
    }

    cout<<endl<<endl<<"Efektywnosc:"<<endl<<endl;
    for(int i=0; i<79; i++)
        cout<<"_";
    cout<<endl<<"|            |"<<" Liczba poprawnych  | Liczba odpowiedzi | Liczba poprawnych odp/|"<<endl;
    cout<<"|            |"<<" odpowiedzi         |                   | Liczba odp            |"<<endl;

    cout<<"|";
    for(int i=0; i<77; i++)
        cout<<"_";
    cout<<"|"<<endl;
    cout<<"| Sumaryczna |"<<suma_podp<<" ";
    if(suma_podp<10)
    {
        for(int i=0; i<18; i++)
            cout<<" ";
    }
    else
    {
        for(int i=0; i<17; i++)
            cout<<" ";
    }
    cout<<"|"<<suma<<"                 ";
    if(suma<10) cout<<" ";
    cout<<"|"<<fixed<<setprecision(0)<<procent_sumy<<"%";
    if(procent_sumy<10)cout<<"  ";
    else if(procent_sumy>10&&procent_sumy<100)cout<<" ";
    cout<<"                   | ";

    cout<<"|";
    for(int i=0; i<77; i++)
        cout<<"_";
    cout<<"|"<<endl<<"| Nuta \"c\"   |"<<popodp[0]<<"                  ";
    if(popodp[0]<10) cout<<" ";
    cout<<"|"<<odp[0]<<"                  |"<<fixed<<setprecision(0)<<procenty[0]<< "%";
    if(procenty[0]<100&&procenty[0]>9)cout<<" ";
    else if(procenty[0]<10)cout<<"  ";
    cout<<"                   | ";

    cout<<"|";
    for(int i=0; i<77; i++)
        cout<<"_";
    cout<<"|"<<endl<<"| Nuta \"d\"   |"<<popodp[1]<<"                  ";
    if(popodp[1]<10) cout<<" ";
    cout<<"|"<<odp[1]<<"                  |"<<fixed<<setprecision(0)<<procenty[1]<< "%";
    if(procenty[1]<100&&procenty[1]>9)cout<<" ";
    else if(procenty[1]<10)cout<<"  ";
    cout<<"                   | ";


    cout<<"|";
    for(int i=0; i<77; i++)
        cout<<"_";
    cout<<"|"<<endl<<"| Nuta \"e\"   |"<<popodp[2]<<"                  ";
    if(popodp[2]<10) cout<<" ";
    cout<<"|"<<odp[2]<<"                  |"<<fixed<<setprecision(0)<<procenty[2]<< "%";
    if(procenty[2]<100&&procenty[2]>9)cout<<" ";
    else if(procenty[2]<10)cout<<"  ";
    cout<<"                   | ";

    cout<<"|";
    for(int i=0; i<77; i++)
        cout<<"_";
    cout<<"|"<<endl<<"| Nuta \"f\"   |"<<popodp[3]<<"                  ";
    if(popodp[3]<10) cout<<" ";
    cout<<"|"<<odp[3]<<"                  |"<<fixed<<setprecision(0)<<procenty[3]<< "%";
    if(procenty[3]<100&&procenty[3]>9)cout<<" ";
    else if(procenty[3]<10)cout<<"  ";
    cout<<"                   | ";


    cout<<"|";
    for(int i=0; i<77; i++)
        cout<<"_";
    cout<<"|"<<endl<<"| Nuta \"g\"   |"<<popodp[4]<<"                  ";
    if(popodp[4]<10) cout<<" ";
    cout<<"|"<<odp[4]<<"                  |"<<fixed<<setprecision(0)<<procenty[4]<< "%";
    if(procenty[4]<100&&procenty[4]>9)cout<<" ";
    else if(procenty[4]<10)cout<<"  ";
    cout<<"                   | ";

    cout<<"|";
    for(int i=0; i<77; i++)
        cout<<"_";
    cout<<"|"<<endl<<"| Nuta \"a\"   |"<<popodp[5]<<"                  ";
    if(popodp[5]<10) cout<<" ";
    cout<<"|"<<odp[5]<<"                  |"<<fixed<<setprecision(0)<<procenty[5]<< "%";
    if(procenty[5]<100&&procenty[5]>9)cout<<" ";
    else if(procenty[5]<10)cout<<"  ";
    cout<<"                   | ";

    cout<<"|";
    for(int i=0; i<77; i++)
        cout<<"_";
    cout<<"|"<<endl<<"| Nuta \"h\"   |"<<popodp[6]<<"                  ";
    if(popodp[6]<10) cout<<" ";
    cout<<"|"<<odp[6]<<"                  |"<<fixed<<setprecision(0)<<procenty[6]<< "%";
    if(procenty[6]<100&&procenty[6]>9)cout<<" ";
    else if(procenty[6]<10)cout<<"  ";
    cout<<"                   | ";

    for(int i=0; i<79; i++)
    {
        cout<<"_";
    }


    cin>>x; // wybranie opcji z menu
    switch(x) // menu
    {
    case 1:
        quiz(nuty, odp,popodp);
        break;
    case 2:
        exit(0);
        break;
    default:
        cout<<"Nie ma takiej opcji.";

    }

}





