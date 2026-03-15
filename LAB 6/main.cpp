// Małgorzata Strusińska, PnP 13:15, Laboratorium 6, Data utworzenia: 23.01.2025, Godzina: 23:00, Data modyfikacji: 24.01.2025
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Towar
{
    char nazwa[21]; //uwzględniam znak końca \0, stąd 21, a nie 20
    float cena;
    int ilosc;
};

void utworzTablice(Towar *&tablica, int &rozmiar);

void wyswietlTablice(Towar *tablica, int rozmiar);

void dopiszDoTablicy(Towar *&tablica, int &rozmiar);

void usunElement(Towar *&tablica, int &rozmiar);

void usunPamiec(Towar *&tablica, int &rozmiar);

void zapiszDoPliku(Towar *tablica, int rozmiar);

void wczytajZPliku(Towar *&tablica, int &rozmiar);

int main()
{
    printf("Małgorzata Strusińska, PnP 13:15, Laboratorium 6, Data utworzenia: 23.01.2025, Godzina: 23:00, Data modyfikacji: 24.01.2025\n\n");

    Towar *tablica = NULL;
    int rozmiar = 0;

    int wybor = 0;
    do {
        printf("Adres tablicy: %p\nRozmiar tablicy: %i\n", (void*)tablica, rozmiar);
        printf("Wybierz opcję:\n");
        printf("1. Utwórz tablicę\n");
        printf("2. Wypisz elementy tablicy\n");
        printf("3. Dopisz elementy do tablicy\n");
        printf("4. Usuń wskazany element tablicy\n");
        printf("5. Usuń pamięć\n");
        printf("6. Zapisz dan do pliku\n");
        printf("7. Wczytaj dane z pliku\n");
        printf("0. Wyjdź\n");
        printf("Podaj numer: ");

        scanf("%i", &wybor);

        switch (wybor) {
            case 1:
                utworzTablice(tablica, rozmiar);
                break;
            case 2:
                wyswietlTablice(tablica, rozmiar);
                break;
            case 3:
                dopiszDoTablicy(tablica, rozmiar);
                break;
            case 4:
                usunElement(tablica, rozmiar);
                break;
            case 5:
                usunPamiec(tablica, rozmiar);
                break;
            case 6:
                zapiszDoPliku(tablica, rozmiar);
            break;
            case 7:
                wczytajZPliku(tablica, rozmiar);
            case 0:
                break;
        }
    } while (wybor != 0);

    usunPamiec(tablica, rozmiar); //czyszczę przed zakonczeniem programu

    return 0;
}

void utworzTablice(Towar *&tablica, int &rozmiar)
{
    printf("Podaj długość tablicy towarów:\n");
    if (scanf("%i", &rozmiar) != 1 || rozmiar < 0) {
        printf("Nieprawidłowy rozmiar.\n");
        rozmiar = 0;
    }

    //zwalniam tablicę, jeśli istniejee
    if (tablica != NULL) {
        free(tablica);
    }

    if (rozmiar == 0) {
        tablica = NULL;
        printf("Tablica jest pusta.\n");
        return;
    }

    tablica = (Towar *)malloc(sizeof(Towar) * rozmiar);
    if (tablica == NULL) {
        printf("Blad alokacji pamieci.\n");
        rozmiar = 0;
        return;
    }

    printf("\nDodaj towary:\n");
    for (int i = 0; i < rozmiar; i++)
    {
        printf("Podaj nazwę towaru (do 20 znaków):\n");
        scanf("%20s", tablica[i].nazwa);

        printf("Podaj cenę:\n");
        scanf("%f", &tablica[i].cena);

        printf("Podaj ilość:\n");
        scanf("%i", &tablica[i].ilosc);
    }
}

void wyswietlTablice(Towar *tablica, int rozmiar)
{
    if (tablica == NULL)
    {
        printf("Brak tablicy.\n");
        return;
    }
    printf("%20s | %8s | %8s\n", "Towar", "Cena", "Ilosc");
    for (int i = 0; i < rozmiar; i++)
    {
        printf("%20s | %8.2f | %8d\n", tablica[i].nazwa, tablica[i].cena, tablica[i].ilosc);
    }
}

void dopiszDoTablicy(Towar *&tablica, int &rozmiar)
{
    int nowy_rozmiar = rozmiar + 1;
    Towar* pom = (Towar *)realloc(tablica, sizeof(Towar) * nowy_rozmiar);

    tablica = pom;

    printf("Podaj nazwę do 20 znaków:\n");
    scanf("%20s", tablica[rozmiar].nazwa);
    printf("Podaj cenę:\n");
    scanf("%f", &tablica[rozmiar].cena);
    printf("Podaj ilość:\n");
    scanf("%i", &tablica[rozmiar].ilosc);

    rozmiar = nowy_rozmiar;
    printf("Dodano towar.\n");
}

void usunElement(Towar *&tablica, int &rozmiar)
{
    char pom[21];
    printf("Podaj nazwę towaru do usunięcia:\n");
    scanf("%20s", pom);

    int i = 0;
    bool szukany_towar = false;
    while (i < rozmiar){
        if (strcmp(tablica[i].nazwa, pom) == 0) {
            szukany_towar = true;
            break;
        }
        i++;
    }

    if (szukany_towar == false) {
        printf("Nie znaleziono towaru o nazwie '%s'.\n", pom);
        return;
    }

    for(int j = i; j < rozmiar -1; j++){
        tablica[j] = tablica[j+1];
    }

    rozmiar--;

    if (rozmiar > 0) {
        Towar* temp_tab = (Towar*)realloc(tablica, sizeof(Towar) * rozmiar);
        if (temp_tab != NULL) {
            tablica = temp_tab;
        }
    } else {
        free(tablica);
        tablica = NULL;
    }

    printf("Usunięto towar.\n");
}

void usunPamiec(Towar *&tablica, int &rozmiar) {
    if(tablica == NULL) {
        printf("Tablica jest juz pusta.\n");
    } else {
        free(tablica);
        tablica = NULL;
        rozmiar = 0;
        printf("Tablica została usunięta.\n");
    }
}
void zapiszDoPliku(Towar *tablica, int rozmiar) {
    char nazwa_pliku[50];
    printf("Podaj nazwę pliku do zapisu (.txt):\n");
    scanf("%49s", nazwa_pliku);

    FILE *plik = fopen(nazwa_pliku, "w");

    fprintf(plik, "%d\n", rozmiar);

    for(int i = 0; i < rozmiar; i++) {
        fprintf(plik, "%s\t%.2f\t%d\n", tablica[i].nazwa, tablica[i].cena, tablica[i].ilosc);
    }

    fclose(plik);
    printf("Zapisano dane\n");
}

void wczytajZPliku(Towar *&tablica, int &rozmiar) {
    char nazwa_pliku[50];
    printf("Podaj nazwę pliku:\n");
    scanf("%49s", nazwa_pliku);

    FILE *plik = fopen(nazwa_pliku, "r"); // wczytanie zawartości z pliku binarnego, stąd "rb"

    int nowy_rozmiar = 0;

    fscanf(plik, "%d", &nowy_rozmiar);

    Towar *nowa_tablica = NULL;
    if (nowy_rozmiar > 0) {
        nowa_tablica = (Towar *)malloc(sizeof(Towar) * nowy_rozmiar);

        size_t odczytane = fread(nowa_tablica, sizeof(Towar), nowy_rozmiar, plik);
        if (odczytane != (size_t)nowy_rozmiar) {
            printf("Błąd podczas odczytu.\n");
            free(nowa_tablica); //zwolnienie zaalokowanej pamieci
            fclose(plik); // zamknięcie pliku
            tablica = NULL;
            rozmiar = 0;
            return;
        }
    }

    fclose(plik);

    if (tablica != NULL) {
        free(tablica);
    }

    tablica = nowa_tablica;
    rozmiar = nowy_rozmiar;

    printf("wczytano dane '%s'.\n", nazwa_pliku);
}