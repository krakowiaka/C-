#include <iostream>
#include <random>
using namespace std;

int wybor, liczba_losowan, ilosc_trapezow;                                           //zmienne//
double a, b, c, d, minimum, maksimum, wysokosc, szukana_calka, dlugosc_odcinka;

double wielomian(double x )                                      //funkcja dla wielomianu //
{
    return a*x*x*x + b*x*x + c*x + d;
}

random_device rd;
mt19937 engine(rd());
uniform_real_distribution <double> dist{0.0, 1.0};
double losowa()                                               //funkcja dla szukania losowej liczby //
{
   return dist(engine);
}

int main()
{
    cout << "PROGRAM DO OBLICZANIA CALKI OZNACZONEJ" << endl;
    do
    {
        cout << "UZUPELNIJ WSPOLCZYNNIKI: " << endl;
        cout << "Wspolczynnik przy najwiekszej potedze: " << endl;            //wykrywam bledy przy wspólczynnikach //
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000000000, '\n');
        }
        cin >> a;

        cout << "Wspolczynnik przy drugiej potedze: " << endl;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000000000, '\n');
        }
        cin >> b;

        cout << "Wspolczynnik przy pierwszej potedze: " << endl;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000000000, '\n');
        }
        cin >> c;

        cout << "Wyraz wolny: " << endl;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000000000, '\n');
        }
        cin >> d;

        cout << "Twoj wzor na wielomian to: " << endl;
        cout << a << "x*x*x + " << b << "x*x + " << c << "x + " << d << endl;
        cout << endl;

        if(cin.fail())                                                 //wykrywam bledy do menu//
        {
            cin.clear();
            cin.ignore(1000000000, '\n');
        }
        cout << "1. METODA TRAPEZOW" << endl;
        cout << "2. METODA MONTE-CARLO" << endl;
        cout << "3. ZAKONCZ PROGRAM" << endl;
        cin >> wybor;
        cout << endl;

        cout << "TWOJ WYBOR TO: " << wybor << endl;
        switch(wybor)
        {
            case 1:
                cout << "WYBRANO METODE TRAPEZOW" << endl;
                cout << endl;
                cout << "Podaj przedzial calkowania: " << endl;
                cout << endl;
                cout << "Wartosc minimalna: " << endl;
                if(cin.fail())                                          // wykrywam bledy do wpisywania minimum, maksimum przedzialu i do ilosci trapezow//
                {
                    cin.clear();
                    cin.ignore(1000000000, '\n');
                }
                cin >> minimum;

                cout << "Wartosc maksymalna: " << endl;
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000000000, '\n');
                }
                cin >> maksimum;
                cout << endl;

                cout << "Na ile czesci podzielic odcinek o dlugosci (max - min):" << endl;
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000000000, '\n');
                }
                cin >> ilosc_trapezow;
                cout << endl;

                cout << "Podany zakres calkowania to: <" << minimum << "," << maksimum << ">" << endl;          // wypisanie danych//
                cout << "Ilosc czesci odcinka: " << ilosc_trapezow << endl;
                cout << endl;

                // odliczam wysokosci trapezów //
                wysokosc = (maksimum - minimum) / ilosc_trapezow;

                // suma pol trapezu na poczatku wynosi 0 //
                szukana_calka=0;

                for( int i=1; i < ilosc_trapezow; i++)
                {
                    szukana_calka+=wielomian(minimum+wysokosc*i);                                           // obliczanie sumy pol trapezow //
                }
                szukana_calka = (szukana_calka + (wielomian(maksimum)+wielomian(minimum))/2) * wysokosc;   //szukana calka do wysokosc pomnozona przez sume pol trapezow i srednia arytemtyczna wartosci wielomianu w punkatach maksimum i minimum //

                cout << "Szukana wartosc calki to: " << szukana_calka << endl;
                cout << endl;
            break;

            case 2:
                cout << "WYBRANO METODE MONTE-CARLO" << endl;
                cout << endl;
                cout << "Podaj przedzial calkowania: " << endl;
                cout << endl;
                cout << "Wartosc minimalna: " << endl;
                if(cin.fail())                                          // wykrywam bledy do wpisywania minimum, maksimum przedzialu i liczby losowan//
                {
                    cin.clear();
                    cin.ignore(1000000000, '\n');
                }
                cin >> minimum;

                cout << "Wartosc maksymalna: " << endl;
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000000000, '\n');
                }
                cin >> maksimum;

                cout << "Podaj liczbe losowan:" << endl;
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000000000, '\n');
                }
                cin >> liczba_losowan;
                cout << endl;

                cout << "Podany zakres calkowania to: <" << minimum << "," << maksimum << ">" << endl;    //wypisanie danych//
                cout << "Liczba losowan to: " << liczba_losowan << endl;
                cout << endl;

                //calka na poczatku równa siê 0//
                szukana_calka=0;

                //dlugosc calkowania//
                dlugosc_odcinka = maksimum - minimum;

                for(int i=1; i<=liczba_losowan; i++)
                {
                    double los_liczba=losowa();                                                             // znalezienie losowej liczby z przedzialu//
                    szukana_calka+=wielomian(minimum + los_liczba *dlugosc_odcinka);                        //obliczanie sumy//
                }
                szukana_calka=(szukana_calka*dlugosc_odcinka)/liczba_losowan;                               // obliczanie sredniej arytmetycznej//

                cout << "Szukana wartosc calki to: " << szukana_calka << endl;
                cout << endl;

            break;
        }
    }
    while(cin.fail() || wybor!=3);
    return 0;
}
