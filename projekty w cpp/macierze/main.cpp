#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream plik;
    plik.open("dane.txt", ios::in);                                    //otwarcie pliku z danymi
    int ilosc_macierzy;                                                //przyporzadkowanie danych z pliku nazwami; wiersz - to wiersz pierwszej macierzy, kolumna to to kolumna pierwszej macierzy itp.
    int wiersz, kolumna, wiersz2, kolumna2, wiersz3, kolumna3;
    double temp, temp2;                                                //zmienne pomocnicze
    double wynik_mnozenia;

    if (plik.good())                                                   //warunek otwarcia pliku
    {
        plik >> ilosc_macierzy;                                        //wczytywanie danych
        plik >> wiersz;
        plik >> kolumna;
        double **wynik = new double *[wiersz];                          //alokacja pamieci na pierwsza macierz; wskaznik na tablice wskaznikow (jest ich tyle co wierszy)
        for (int i = 0; i < wiersz; i++)                                //kazdy z tych wskaznikow wskazuje na tablice o ilosci elementow = kolumna
        {
            wynik[i] = new double [kolumna];                        // tu nie ma gwiazdki, poniewaz sa juz uzyta alokacja pamieci
        }
        for(int i=0; i<wiersz; i++)                                     //wpisanie wartosci do pierwszej macierzy z pliku
        {
            for(int j=0; j<kolumna; j++)
            {
                plik >> temp;
                wynik[i][j] = temp;
            }
        }

        cout <<"Macierz 1"<<endl;
        for(int i=0; i<wiersz; i++)                                      //wyswietlenie mcierzy 1
        {
            for(int j=0; j<kolumna; j++)
            {
                cout << wynik [i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for(int i=1; i<ilosc_macierzy; i++)                               // wpisywanie wartosci do kolejnych macierzy
        {
            plik >> wiersz2;
            plik >> kolumna2;
            double **macierz2 = new double *[wiersz2];
            for( int i=0; i<wiersz2; i++)
            {
                macierz2[i]= new double [kolumna2];
            }
            cout <<"Macierz "<<i+1<<endl;                            //wypisanie kolejnych macierzy
            for(int i=0; i<wiersz2; i++)
            {
                for(int j=0; j<kolumna2; j++)
                {
                    plik >> temp2;
                    macierz2[i][j] = temp2;
                    cout << macierz2[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;

            if (kolumna==wiersz2)                                  //warunek na pomnozenie macierzy
            {
                double **macierz3 = new double *[wiersz];
                for( int i=0; i<wiersz; i++)
                {
                    macierz3[i]= new double [kolumna2];
                }
                kolumna3 = kolumna2;                         //zmienne na kolumny i wiersze powstalej macierzy
                wiersz3 = wiersz;
                for(int i=0; i<wiersz; i++)
                {
                    for(int j=0; j<kolumna2; j++)
                    {
                        wynik_mnozenia = 0;
                        for( int k=0; k < wiersz2; k++)
                        {
                            wynik_mnozenia+= wynik[i][k]*macierz2[k][j];
                        }
                        macierz3[i][j] = wynik_mnozenia;
                    }
                }
                for (int i = 0; i < wiersz; i++)
                    delete[] wynik[i];                       //zwolnienie pamieci i zastapienie ja nowa, czyli dla wyniku mnozenia
                wynik = macierz3;
            }
            else                                                              // przypadek gdy nie mozna mnozyc
            {
                cout << "Mnozenie nie moze zostac wykonane" << endl;
                cout << "Wynik przed nie udanym mnozeniem: " << endl;
                for(int i=0; i<wiersz; i++)                                //wyswietlenie wyniku poprzedniego w przypadku niepowodzenia
                {
                    for(int j=0; j<kolumna2; j++)
                    {
                        cout << wynik [i][j] << " ";
                    }
                    cout << endl;
                }
                return 1;                                        // konczy program
            }
            kolumna = kolumna3;
            wiersz = wiersz3;
        }
        cout<<"Twoj wynik to:"<<endl;                               //wyslwietlenie wyniku ponozonych wszystkich macierzy
        for(int i=0; i<wiersz3; i++)
        {
            for(int j=0; j<kolumna3; j++)
            {
                cout << wynik [i][j] << " ";
            }
            cout << endl;
        }
        plik.close();                                                // zamkniecie pliku
    }
    else
        cout << "Plik nie zostal otwarty" << endl;                   // przypadek gdy pliku nie otwarto
    return 0;
}
