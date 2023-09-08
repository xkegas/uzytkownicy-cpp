#include <iostream>
#include <fstream>
using namespace std;

struct Osoba
{
    string imie;
    string nazwisko;
    bool usuniety;
};

int Menu();
void Wybor(int wybor, int& aktualny_uzytkownik, Osoba* osoba, fstream& plik);
void Dodaj(string imie, string nazwisko, int &aktualny_uzytkownik, Osoba *osoba);
void Wyswietl(int& aktualny_uzytkownik, Osoba *osoba);
void Wyszukaj(int& aktualny_uzytkownik, Osoba* osoba, int wybor);
void Zapis(int& aktualny_uzytkownik, Osoba* osoba, fstream &plik);

int main()
{
    fstream plik;
    Osoba osoba[100];
    int aktualny_uzytkownik = 0;
    for (;;)
    {
        int wybor = Menu();
        Wybor(wybor, aktualny_uzytkownik, osoba, plik);
    }
}

int Menu()
{
    int wybor = 0;
    system("cls");
    cout << "1 - Dodaj uzytkownika " << endl;
    cout << "2 - Wypisz uzytkownikow " << endl;
    cout << "3 - Wyszukaj uzytkownika " << endl;
    cout << "4 - Zapisz uzytkownikow do pliku " << endl;
    cout << "5 - Odczytaj dane z pliku " << endl;
    cout << "Cokolwiek innego = wyjscie z programu " << endl;
    cin >> wybor;
    return wybor;
}

void Wybor(int wybor, int& aktualny_uzytkownik, Osoba* osoba, fstream& plik)
{
    switch (wybor)
    {
    case 1: {
        system("cls");
        string imie, nazwisko;
        cout << "Wprowadz imie uzytkownika: " << endl;
        cin >> imie;
        cout << "Wprowadz nazwisko uzytkownika: " << endl;
        cin >> nazwisko;
        cout << aktualny_uzytkownik;
        Dodaj(imie, nazwisko, aktualny_uzytkownik, osoba);
        break;
    }
    case 2:
    {
        Wyswietl(aktualny_uzytkownik, osoba);
        system("pause");
        break;
    }
    case 3:
    {
        system("cls");
        int wybor = 0;
        cout << "1 - Wyszukaj po imieniu " << endl;
        cout << "2 - Wyszukaj po nazwisku " << endl;
        cin >> wybor;
        Wyszukaj(aktualny_uzytkownik, osoba, wybor);
        break;
    }
    case 4:
    {
        Zapis(aktualny_uzytkownik, osoba, plik);
        system("pause");
        break;
    }
    default:
        exit(0);
    }
}

void Dodaj(string imie, string nazwisko, int &aktualny_uzytkownik, Osoba *osoba)
{
    osoba[aktualny_uzytkownik].imie = imie;
    osoba[aktualny_uzytkownik].nazwisko = nazwisko;
    osoba[aktualny_uzytkownik].usuniety = 0;
    aktualny_uzytkownik++;
}

void Wyswietl(int& aktualny_uzytkownik, Osoba* osoba)
{
    system("cls");
    for (int i = 0; i < aktualny_uzytkownik; i++)
    {
        if (!osoba[i].usuniety)
        {
            cout << "------------------------------------" << endl;
            cout << "Osoba nr. " << i + 1 << endl;
            cout << "Imie: " << osoba[i].imie << endl;
            cout << "Nazwisko: " << osoba[i].nazwisko << endl;
            cout << "------------------------------------" << endl;
        }
    }
}

void Wyszukaj(int& aktualny_uzytkownik, Osoba* osoba, int wybor)
{
    switch (wybor)
    {
    case 1:
    {
        string imie;
        cout << "Wpisz imie " << endl;
        cin >> imie;
        for (int i = 0; i < aktualny_uzytkownik; i++)
        {
            if (osoba[i].imie == imie)
            {
                cout << "------------------------------------" << endl;
                cout << "Osoba nr. " << i + 1 << endl;
                cout << "Imie: " << osoba[i].imie << endl;
                cout << "Nazwisko: " << osoba[i].nazwisko << endl;
                cout << "------------------------------------" << endl;
            }
        }
        system("pause");
        break;
    }
    case 2:
    {
        string nazwisko;
        cout << "Wpisz nazwisko " << endl;
        cin >> nazwisko;
        for (int i = 0; i < aktualny_uzytkownik; i++)
        {
            if (osoba[i].imie == nazwisko)
            {
                cout << "------------------------------------" << endl;
                cout << "Osoba nr. " << i + 1 << endl;
                cout << "Imie: " << osoba[i].imie << endl;
                cout << "Nazwisko: " << osoba[i].nazwisko << endl;
                cout << "------------------------------------" << endl;
            }
        }
        system("pause");
        break;
    }
    }
}

void Zapis(int& aktualny_uzytkownik, Osoba* osoba, fstream& plik)
{
    plik.open("uzytkownicy.txt", ios::out);
    plik << aktualny_uzytkownik << endl;
    for (int i = 0; i < aktualny_uzytkownik; i++)
    {
        plik << "------------------------------------" << endl;
        plik << "Osoba nr. " << i + 1 << endl;
        plik << "Imie: " << osoba[i].imie << endl;
        plik << "Nazwisko: " << osoba[i].nazwisko << endl;
        plik << "------------------------------------" << endl;
    }
    plik.close();
    cout << "Zapisano pomyslnie!" << endl;
}
