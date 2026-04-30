# Laboratorium 5

## Operacje na tablicach dynamicznych

W pliku `TabliceLiczb.pdf` zostały przedstawione przykładowe programy umożliwiające wykonywanie typowych operacji na tablicach, w których będą pamiętane liczby. W przykładzie zostały wyróżnione 4 przypadki:
* statyczna tablica liczb,
* dynamiczna tablica liczb,
* statyczna tablica wskaźników na liczby,
* dynamiczna tablica wskaźników na liczby.

Dla każdego przypadku zostały przedstawione następujące elementy:
* sposób deklaracji tablicy,
* sposób implementacji funkcji `Drukuj`, która jedynie odczytuje zawartość tablicy i drukuje dane na ekranie,
* sposób implementacji funkcji `DodajDane`, która dopisuje do tablicy nową liczbę, przekazaną do funkcji jako parametr `dane`,
* sposób implementacji funkcji `UsunDane`, która usuwa z tablicy liczbę zapisaną w tablicy na pozycji przekazanej do funkcji przez parametr `ktory`.

Proszę przeanalizować te programy i zwrócić szczególną uwagę na elementy wyróżnione pogrubioną czcionką, a w szczególności na sposób deklaracji zmiennej `TAB`, sposób przekazywania tablicy jako parametru do funkcji (instrukcje wyróżnione kolorem żółtym) oraz sposób tworzenia, realokacji i usuwania zmiennych dynamicznych (instrukcje wyróżnione kolorem zielonym).

W pliku `Tablice Dwuwymiarowe.pdf` przedstawiono sposoby deklarowania i odwoływania się do elementów tablic dwuwymiarowych za pomocą wskaźników. Proszę przeanalizować podane przykłady ze szczególnym uwzględnieniem sposobu wykonywania operacji na dwuwymiarowej dynamicznej tablicy znaków.

---

## Zadanie 1 (obowiązkowe)
Na podstawie materiałów zawartych w pliku `Tablice Dwuwymiarowe.pdf` proszę napisać program, który w oparciu o dwuwymiarową dynamiczną tablicę znaków tworzy słownik imion. Program powinien posiadać menu, które umożliwia wykonywanie następujących operacji:
* dodawanie do słownika nowego imienia wprowadzanego z klawiatury,
* drukowanie na ekranie wszystkich imion zapamiętanych w słowniku,
* drukowanie na ekranie wszystkich imion rozpoczynających wskazaną literą alfabetu,
* usuwanie imienia znajdującego się na wskazanej pozycji w tablicy (należy podać indeks pozycji, na której znajduje się imię do usunięcia),
* usuwanie z tablicy imienia, wprowadzonego z klawiatury (program powinien odszukać pozycję tablicy, na której znajduje się wskazane imię, a następnie wywołać funkcję realizującą operację usuwania z poprzedniego punktu),
* sortowanie wszystkich imion zawartych w tablicy według alfabetu,
* sortowanie wszystkich imion zawartych w tablicy według długości łańcuch znaków.

**Struktura programu:**
W programie należy wydzielić funkcje wykonujące wszystkie wskazane powyżej operacje. Do tych funkcji należy przekazywać niezbędne dane za pomocą parametrów. Prototypy tych funkcji należy umieścić w początkowej części programu.

Następnie w programie należy umieścić funkcję `main`, od której rozpoczyna się wykonywanie programu. W tej funkcji należy umieścić deklarację zmiennej wskaźnikowej, w której będzie pamiętany adres dynamicznej tablicy wskaźników na łańcuchy znaków zawierających pamiętane imiona, które będą również tworzone jako zmienne dynamiczne. W tej funkcji należy zaimplementować proste menu umożliwiające wykonywanie wszystkich operacji. W menu powinny być wywoływane funkcje, których prototypy znajdują się przed funkcją `main`.

Poniżej funkcji `main` należy umieścić implementację wszystkich funkcji.

**Proponowane prototypy funkcji:**
```cpp
// Inicjalizacja dynamicznej tablicy dwuwymiarowej.
// Funkcję należy wywołać na początku programu.
void InitTab(char **&wsk);

// Dodawanie nowego imienia do tablicy dynamicznej
void AddName(char *buf, char **&wsk);

// Usuwanie imienia znajdującego się w tablicy na pozycji nr
void RemoveName(int nr, char **&wsk);

// Usuwanie z tablicy imienia, wprowadzonego z klawiatury
void RemoveName(char *buf, char **&wsk);

// drukowanie na ekranie wszystkich imion
void PrintAllNames(char **wsk);

// drukowanie na ekranie imion rozpoczynających wskazaną literą
void PrintNames(char first_letter, char **wsk);

// sortowanie imion zawartych w tablicy według alfabetu
void SortAlphabet(char **wsk);

// sortowanie imion zawartych w tablicy według długości
void SortLength(char **wsk);
```

**Znaczenie parametrów:**
* `wsk` - wskaźnik na dynamiczną dwuwymiarową tablicę znaków, w której są pamiętane wszystkie imiona,
* `buf` - wskaźnik na tablicę znaków w której jest wprowadzone z klawiatury imię,
* `nr` - indeks pozycji na której znajduje się imię które ma zostać usunięte,
* `first_letter` - znak określający pierwszą literę imion, które mają być drukowane.

**Przykładowy zarys funkcji `main`:**
```cpp
int main() { 
    char **WSK;     // wskaźnik na dwuwymiarową tablice dynamiczną
                    // w której będą pamiętane wszystkie imiona.
    char buf[81];   // bufor na dane wczytywane z klawiatury
    
    InitTab(WSK);   // Inicjalizacja tablicy dynamicznej
    
    // implementacja menu, w którym będą wywoływane
    // funkcje wykonujące operacje na tablicy dynamicznej
    
    return 0;
}
```

**Wskazówki pomocnicze:**
* Do wczytywania łańcucha znaków zawierającego imię można wykorzystać funkcję `gets` lub funkcję `fgets` z biblioteki `<stdio.h>` np.:
  ```cpp
  char buf[81];
  printf("Wprowadź imię: ");
  fgets(buf, 81, stdin);
  AddName(buf, WSK);
  ```

---

## Zadanie 2 (dla ambitnych)
Osoby ambitne mogą zmodyfikować program z poprzedniego zadania, tak by do tworzenia i usuwania zmiennych dynamicznych były wykorzystywane wyłącznie operatory `new` oraz `delete` dostępne jedynie w języku C++.

**Wskazówki pomocnicze:**
* Do tworzenia nowych zmiennych dynamicznych będących tablicami o wskazanym rozmiarze zamiast funkcji `malloc` i `calloc` należy użyć operatora `new`.
* Do usuwania zmiennych dynamicznych zamiast funkcji `free` należy użyć operatora `delete`.
* Kopiowanie łańcucha znaków z bufora do tablicy dynamicznej za pomocą funkcji `strdup` należy zastąpić dwoma instrukcjami. W pierwszej za pomocą operatora `new` należy utworzyć dynamiczną tablicę znaków o rozmiarze umożliwiającym zapamiętanie wprowadzonego z klawiatury imienia. Następnie za pomocą funkcji `strcpy` należy skopiować wprowadzone imię z tymczasowego bufora do nowo utworzonej dynamicznej tablicy znaków.
* W języku C++ nie ma bezpośredniej funkcji, która umożliwia zmianę rozmiaru tablicy dynamicznej, czyli nie ma prostego odpowiednika funkcji `realloc`. Zmianę rozmiaru tablicy dynamicznej trzeba przeprowadzić w trzech krokach:
  1. Za pomocą operatora `new` należy utworzyć nową tablicę dynamiczną o pożądanym rozmiarze,
  2. Do tak utworzonej nowej tablicy dynamicznej należy przepisać dane z modyfikowanej tablicy (można użyć pętlę `for` i element po elemencie lub wykorzystać funkcję `memcpy` z biblioteki `<string.h>`),
  3. Poprzednią tablicę dynamiczną należy usunąć za pomocą operatora `delete`.
