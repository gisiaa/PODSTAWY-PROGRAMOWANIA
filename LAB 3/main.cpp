#include <iostream>
#include <stdio.h>
#define ROZMIAR 5

using namespace std;

float tab[ROZMIAR] = {0};

void WczytanieElementowTablicy(float tablica[]) {
    printf("\n\n");
    printf("Podaj elementy tablicy: \n");
    for (int i = 0; i < ROZMIAR; i++) {
        printf("Tab[%d] = ", i);
        scanf("%f", &tablica[i]);
    }
    printf("\n\n");
}

void WypiszElementyTablicy(float tablica[]) {
    printf("\n\n");
    printf("Tab = [  ");
    for (int i = 0; i < ROZMIAR; i++) {
        printf("%.1f  ", tablica[i]);
    }
    printf("]\n");
    printf("\n\n");
}

void SprawdzanieIWypisywanieKomunikatow(float tablica[]) {
    printf("\n\n");
    int DodatnieElementy = 0;
    int UjemneElementy = 0;
    float SumaDodatnich = 0;
    float SumaUjemnych = 0;
    for (int i = 0; i < ROZMIAR; i++) {
        if (tablica[i] > 0) {
            DodatnieElementy++;
            SumaDodatnich += tablica[i];
        } else {
            UjemneElementy++;
            SumaUjemnych += tablica[i];
        }
    }
    float SredniaDodatnich = SumaDodatnich / (float)DodatnieElementy;
    float SredniaUjemnych = SumaUjemnych / (float)UjemneElementy;

    if (DodatnieElementy < 0) {
        printf("Nie ma dodatnich elementów\n");
    }
    else {
        printf("Dodatnich elementów jest: %d\n", DodatnieElementy);
        printf("Suma dodatnich elementów wynosi: %f\n", SumaDodatnich);
        printf("Średnia dodatnich elementów wynosi %f\n", SredniaDodatnich);
    }

    if (UjemneElementy < 0) {
        printf("Nie ma ujemnych elementów\n");
    } else {
        printf("Ujemnych elementów jest: %d\n", UjemneElementy);
        printf("Suma ujemnych elementów wynosi: %f\n", SumaUjemnych);
        printf("Średnia ujemnych elementów wynosi %f\n", SredniaUjemnych);
    }

    printf("\n\n");
}

void UporzadkowanieElementowTablicy(float tablica[]) {
    printf("\n\n");
    int rosnąco = 1;
    int niemalejąco = 1;
    int jednakowe = 1;
    int nierosnąco = 1;
    int malejąco = 1;
    int nieuporządkowane = 1;
    for (int i = 0; i < ROZMIAR - 1; i++) {
        if (tablica[i] < tablica[i + 1]) {
            malejąco = 1;
            nierosnąco = 1;
            jednakowe = 1;
        }
        else if (tablica[i] == tablica[i + 1]) {
            rosnąco = 1;
            malejąco = 1;
        }
        else if (tablica[i] > tablica[i + 1]) {
            rosnąco = 0;
            malejąco = 0;
        }
    }
    set <float> tabb(tablica, tablica
    iff ()
    if (rosnąco) {
        printf("Wszystkie elementy są uporządkowane rosnąco");
    }
    else if (niemalejąco) {
        printf("Wszystkie elementy są uporządkowane niemalejąco");
    }
    else if (jednakowe) {
        printf("Wszystkie elementy mają jednakową wartość");
    }
    else if (nierosnąco) {
        printf("Wszystkie elementy uporządkowane są nierosnąco");
    }
    else if (malejąco) {
        printf("Wszystkie elementy uporządkowane są malejąco");
    }
    else if (nieuporządkowane) {
        printf("Elementy tablicy są nieuporządkowane");
    }
    printf("\n\n");
}

void zadanie1() {
    float tab[ROZMIAR];
    int ListaWyboruZadanie1;

    while (true) {
        printf("Wybierz funkcję:\n");
        printf("1. Wczytanie z klawiatury wszystkich elementów.\n");
        printf("2. Wypisanie na ekranie wszystkich elementów tablicy.\n");
        printf("3. Sprawdzanie i wypisanie komunikatów o: liczbie dodatnich i ujemnych elementów tablicy, sumie wszystkich dodatnich i sumie wszystkich ujemnych elementów, wartośći średniej wszystkich liczb dodatnich i wartości średniej liczb ujemnych\n");
        printf("4. Uporządkowanie elementów tablicy\n");
        printf("0. WYJŚCIE\n");
        printf("Podaj numer funkcji: ");
        scanf("%d", &ListaWyboruZadanie1);

        switch (ListaWyboruZadanie1) {
            case 1:
                WczytanieElementowTablicy(tab);
            break;
            case 2:
                WypiszElementyTablicy(tab);
            break;
            case 3:
                SprawdzanieIWypisywanieKomunikatow(tab);
            break;
            case 4:
                UporzadkowanieElementowTablicy(tab);
            break;
            case 0:
                return;
        }
    }
}

void WypelnijTabliceLosowymi(float tablica[], float mini, float maxi) {
    for (int i = 0; i < ROZMIAR; i++) {
        tablica[i] = mini + (maxi - mini * (float)rand() / (double)RAND_MAX);
    }
}

void zadanie2() {
    float min, max;
    printf("Podaj minimalną wartość dla przedziału [min, max) do wylosowania liczb");
    scanf("%f", &min);
    printf("Podaj maksymalną wartość dla przedziału [min, max) do wylosowania liczb");
    scanf("%f", &max);
    WypelnijTabliceLosowymi(tab, min, max);
}

void SortowanieRosnacoPrzezWstawianie(float tablica[]) {
    for (int i = 0; i < ROZMIAR - 1; i++) {
        float przesuniecie = tablica[i];
        int j = i - 1;

        while (j >= 0 && tablica[j] > przesuniecie) {
            tablica[j + 1] = tablica[j];
            j--;
        }
        tablica[j + 1] = przesuniecie;
    }

    for (int i = 0; i < ROZMIAR; i++) {
        printf("%.1f ", tablica[i]);
    }
    printf("\n");
}

void zadanie3() {
    printf("Uporządkowane elementy tablicy rosnąco:");
    SortowanieRosnacoPrzezWstawianie(tab);
}

int main()
{
    int lista_wyboru;
    srand(time(NULL));
    while (true) {
        printf("Wybierz zadanie:\n");
        printf("1. ZADANIE 1\n");
        printf("2. ZADANIE 2\n");
        printf("3. ZADANIE 3\n");
        printf("0. WYJŚCIE\n");
        printf("Podaj numer zadania: ");
        scanf("%d", &lista_wyboru);

        switch (lista_wyboru) {
            case 1:
                zadanie1();
            break;
            case 2:
                zadanie2();
            break;
            case 3:
                zadanie3();
            break;
            case 0:
                return 0;
        }
    }
}
