#include <iostream>
using namespace std;

void wyswietl_tablice(int tab[23][23])                  //funkcja do wyswietlania tablicy
{
    cout <<"Y"<<endl;
    for (int i = 0; i < 15; i++)
    {
        cout << i+1;
        if (i < 9)
            cout << "  ";
        else
            cout << " ";
        for (int j = 0; j < 15; j++)
        {
            cout<<tab[i+5][j+5];
            if (j < 9)
                cout << " ";
            else
                cout <<"  ";
        }
        cout << endl;
    }
    cout <<"   ";

    for (int i = 1; i < 16; i++)
    {
        cout<<i<< " ";
    }
    cout <<"X";
    cout << endl;
}

void sprawdz_zajete(int tab[23][23],int x, int y)                //funkcja do sprawdzania czy miejsce jest zajete
{
    while(tab[y+4][x+4]!=0)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100000,'\n');
        }
        cout <<"WSPOLRZEDNE ZAJETE! WYBIERZ PONOWNIE"<<endl;
        cout << "WSPOLRZEDNA X= " << endl;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100,'\n');
        }
        cin >> x;
        cout << "WSPOLRZENA Y= " << endl;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100,'\n');
        }
        cin >> y;
        cout << endl;
    }
}

bool sprawdz_zwyciestwo( int tab[23][23],int x, int y, int gracz)     //funkcja do sprawdzania zwyciestw
{
    int najdluzszy = 0;
    int aktualny = 0;
    int wygrana = 0;

    for (int i = 0; i < 9; i++)                                                 //spawdzanie w poziomie
    {
        if(tab[y][x-4+i]==gracz)                                                //sprawdzanie czy ktorys wyraz jest dana cyferka
        {
            aktualny++;
        }
        else
        {
            if(aktualny>najdluzszy)                                            // jeseli nie to czy ostatni ciag jest dluzszy niz poprzedni
            {
                najdluzszy=aktualny;
                aktualny=0;
            }
        }
    }
    if(aktualny>najdluzszy)                             //zabezpieczenie przed tym, aby ostatni  wyraz zostal policzony, gdy nalezy do ciagu
    {
        najdluzszy = aktualny;
        aktualny = 0;
    }
    if(najdluzszy>=5)
    {
        wygrana=1;
    }
    if (wygrana == 1)
    {
        return true;
    }
    najdluzszy = 0;
    aktualny = 0;

    for (int i = 0; i < 9; i++)                                                 //sprawdzanie w pionie
    {
        if(tab[y-4+i][x]==gracz)
        {
            aktualny++;
        }
        else
        {
            if(aktualny>najdluzszy)
            {
                najdluzszy=aktualny;
                aktualny=0;
            }
        }
    }
    if(aktualny>najdluzszy)
    {
        najdluzszy = aktualny;
        aktualny = 0;
    }
    if(najdluzszy>=5)
    {
        wygrana=1;
    }
    if (wygrana == 1)
    {
        return true;
    }
    najdluzszy = 0;
    aktualny = 0;

    for (int i = 0; i < 9; i++)                                                 //sprawdzanie pierwsszego skosu '\'
    {
        if(tab[y-4+i][x-4+i]==gracz)
        {
            aktualny++;
        }
        else
        {
            if(aktualny>najdluzszy)
            {
                najdluzszy=aktualny;
                aktualny=0;
            }
        }
    }
    if(aktualny>najdluzszy)
    {
        najdluzszy = aktualny;
        aktualny = 0;
    }
    if(najdluzszy>=5)
    {
        wygrana=1;
    }
    if (wygrana == 1)
    {
        return true;
    }
    najdluzszy = 0;
    aktualny = 0;

    for (int i = 0; i < 9; i++)                                                 //sprawdzanie drugiego skosu '/'
    {
        if(tab[y+4-i][x-4+i]==gracz)
        {
            aktualny++;
        }
        else
        {
            if(aktualny>najdluzszy)
            {
                najdluzszy=aktualny;
                aktualny=0;
            }
        }
    }
    if(aktualny>najdluzszy)
    {
        najdluzszy = aktualny;
        aktualny = 0;
    }
    if(najdluzszy>=5)
    {
        wygrana=1;
    }
    if (wygrana == 0)
        return false;
    else
        return true;
}



int main()
{
    cout << "GOMOKU" << endl;                                                       //deklarowanie zmiennych, dlaczego tab[23][23] poniewaz chciałam latwiej sprawdzac wygrane
    int tab[23][23];
    int gracz1 = 1;                  //kolko
    int gracz2 = 2;                  //krzyzyk
    int wygrana;
    int ilosc_pol=225;
    int koniec = 0;
    int x,y;

    while (koniec != 2)
    {
        for(int i=0; i<23; i++)
        {
            for(int j=0; j<23; j++)
            {
                tab[i][j]=0;
            }
        }
        wyswietl_tablice(tab);

        for(int i=0; i<ilosc_pol; i++ && wygrana==0)                           //wprowadzanie wspolrzednych od uzytkownikow i je sprawdzamy potem wstawiamy do tablicy sprawdzamy czy miejsce nie jest zajete i czy ktos nie wyrgal
        {
            if (i%2==0)
            {
                cout << "RUCH PIERWSZEGO GRACZA" << endl;
                cout << endl;
                cout << "PODAJ WSPOLRZEDNE" << endl;
                cout << "WSPOLRZEDNA X= " << endl;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100,'\n');
                }
                cin >> x;
                cout << "WSPOLRZENA Y= " << endl;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100,'\n');
                }
                cin >> y;
                cout << endl;
                sprawdz_zajete(tab, x, y);
                cout << "WYBRANE WSPOLRZEDNE:(" << x << "," << y << ")" << endl;
                tab[y+4][x+4]=1;
                wyswietl_tablice(tab);
                if (sprawdz_zwyciestwo(tab, x+4, y+4, gracz1))
                {
                    wygrana = 1;
                }
            }
            else
            {
                cout << "RUCH DRUGIEGO GRACZA" << endl;
                cout << endl;
                cout << "PODAJ WSPOLRZEDNE" << endl;
                cout << "WSPOLRZEDNA X= " << endl;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100,'\n');
                }
                cin >> x;
                cout << "WSPOLRZENA Y= " << endl;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100,'\n');
                }
                cin >> y;
                cout << endl;
                sprawdz_zajete(tab, x, y);
                cout << "WYBRANE WSPOLRZEDNE:(" << x << "," << y << ")" << endl;
                tab[y+4][x+4]=2;
                wyswietl_tablice(tab);
                if (sprawdz_zwyciestwo(tab, x+4, y+4, gracz2))
                {
                    wygrana = 2;
                }
            }
            cout << endl;
            if (wygrana == 1)                                            //wyswietlanie kto wyral
            {
                cout <<"WYGRAL GRACZ PIERWSZY"<<endl;
                break;
            }
            else if(wygrana == 2)
            {
                cout <<"WYGRAL GRACZ DRUGI"<<endl;
                break;
            }

        }
        cout << "Zagraj jeszcze raz?" << endl;                                  //pytamy sie czy gramy dalej
        cout << "Wcisnij 1" << endl;
        cout << "Jesli nie? - Zakoncz program" << endl;
        cout << "Wcisnij 2" << endl;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100,'\n');
        }
        cin >> koniec;
    }
    return 0;
}
