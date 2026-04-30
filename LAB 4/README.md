# Laboratorium 3

## Wymagania ogólne
Proszę wykonać obowiązkowo zadanie 1, 2, 3. Osoby ambitne mogą wykonać również zadanie 4.

Program do wszystkich zadań należy podzielić na oddzielne funkcje realizujące wskazane operacje. Ponadto proszę napisać funkcję `main`, w której zostaną wywołane funkcje będące rozwiązaniami poszczególnych zadań. W metodzie `main` proszę dopisać MENU umożliwiające wywoływanie poszczególnych funkcji lub zakończenie programu.

**UWAGA:** Każdy program musi być w komentarzu podpisany! Po uruchomieniu każdy program powinien na początku wyświetlać na ekranie imię i nazwisko autora. Do oceny proszę wysłać tylko plik źródłowy tzn. plik z rozszerzeniem `*.cpp`.

---

## Zadanie 1: Operacje na tablicy jednowymiarowej
1. Na początku programu za pomocą dyrektywy `#define` zdefiniuj stałą całkowitą o nazwie `ROZMIAR`, która będzie oznaczać liczbę elementów tablicy liczb rzeczywistych. Początkowo stała ta powinna mieć wartość 5. Podczas testowania poprawności zadania 2 i 3 wartość tej stałej można zwiększyć np. do 25.
2. Zadeklaruj tablicę liczb rzeczywistych typu `float`, której wielkość określa stała `ROZMIAR`.
   * *UWAGA:* Na elementach tej tablicy mają być wykonywane operacje przez wszystkie funkcje napisane do zadania 1, 2, i 3. W prostszym wariancie programu, wystarczy używać wyłącznie funkcje bez parametrów. W takim wariancie tablica musi być zadeklarowane jako zmienna globalna przed wszystkimi funkcjami. Osoby ambitne mogą napisać program, w którym tablica będzie przekazywana do wszystkich funkcji przez parametr. Wówczas tablicę proszę zadeklarować jako zmienną lokalną w funkcji `main()`.
3. **Funkcja wczytująca:** Napisz funkcję, która umożliwia wczytanie z klawiatury wszystkich elementów tablicy. Podczas wczytywania proszę wyświetlać teksty pomocnicze informujące o numerze wprowadzanego elementu np.
   * `Tab[0]=12.0`
   * `Tab[1]=3.14`
   * `Tab[3]=....`
4. **Funkcja wypisująca:** Napisz funkcję, która umożliwia wypisanie na ekranie wszystkich elementów tablicy. Wszystkie elementy tablicy powinny być wypisane kolejno w jednym wierszu. Liczby powinny być wypisane z dokładnością do jednego miejsca po kropce dziesiętnej oraz powinny być rozdzielone dwoma spacjami np.
   * `Tab = [ 12.0  3.1  2.0  -65.8  99.9 ]`
5. **Funkcja statystyczna:** Napisz funkcję, która sprawdzi i wypisze na ekranie komunikaty:
   * liczbę wszystkich liczb dodatnich oraz liczbę wszystkich liczb ujemnych w tablicy,
   * sumę wszystkich liczb dodatnich oraz sumę wszystkich liczb ujemnych w tablicy,
   * wartość średnią wszystkich liczb dodatnich oraz wartość średnią wszystkich liczb ujemnych.
6. **Funkcja sprawdzająca posortowanie:** Napisz funkcję, która sprawdzi i wyświetli na ekranie informację o uporządkowaniu elementów tablicy. Proszę wyróżnić następujące przypadki:
   * wszystkie elementy tablicy są uporządkowane rosnąco,
   * wszystkie elementy tablicy są uporządkowane niemalejąco,
   * wszystkie elementy mają jednakową wartość,
   * wszystkie elementy tablicy są uporządkowane nierosnąco,
   * wszystkie elementy tablicy są uporządkowane malejąco,
   * elementy tablicy są nie uporządkowane.

W funkcji `main` dodaj menu umożliwiające wywołanie poszczególnych funkcji. Podczas testowania programu proszę zmienić wartość stałej `ROZMIAR` np. na 10 i sprawdzić czy program działa poprawnie na tablicy o zmienionej wielkości.

**Wskazówki:**
* Deklaracja stałej ma postać instrukcji: `#define NAZWA WARTOSC` (Przykład: `#define PI 3.1415926`). Uwaga: Na końcu dyrektywy `#define` nie ma średnika!!!
* W całym programie, w miejscach gdzie odwołujemy się do rozmiaru tablicy zamiast konkretnej liczby należy wpisywać nazwę stałej `ROZMIAR`.
* Deklaracja stałej `ROZMIAR` oraz deklaracja tablicy muszą być przed wszystkimi funkcjami.

---

## Zadanie 2: Losowanie liczb do tablicy (kontynuacja zad 1)
W programie z zadania 1 dopisz funkcję która umożliwia wypełnienie tablicy liczbami losowymi z zadanego przedziału. Funkcja powinna pytać użytkownika o zakres losowanych liczb.
W funkcji `main` dopisz wywołania tej funkcji oraz ponownie przetestuj poprawność działania wszystkich funkcji.

**Wskazówki:**
* Do losowania liczb należy wykorzystać funkcję `rand()`, która zwraca wybraną losowo liczbę całkowitą dodatnią z przedziału od 0 do `RAND_MAX`.
* Jeśli trzeba wylosować liczbę całkowitą z zakresu `[min, max]` to można użyć instrukcji: 
  * `losowa = min + rand() % (max - min + 1);` *(poprawiono błąd ze skryptu)*
* Jeśli trzeba wylosować liczbę rzeczywistą z przedziału `[min, max)` to można użyć instrukcji:
  * `losowa = min + (max - min) * rand() / ((double) RAND_MAX);` *(poprawiono błąd ze skryptu)*
* Przed rozpoczęciem losowania należy uruchomić generator liczb losowych przez wywołanie następującej instrukcji: `srand(time(NULL));`

---

## Zadanie 3: Sortowanie tablicy (kontynuacja zadania 1)
W programie z poprzedniego zadania proszę dopisać funkcję, która uporządkuje elementy tablicy rosnąco. W zadaniu można wykorzystać dowolny algorytm sortowania.

Szczególnie polecam algorytmy, których działanie zostało przedstawione w formie artystycznej przez tancerzy:
* Algorytm sortowania przez wstawianie: [link do YT](http://www.youtube.com/watch?v=ROalU37913U)
* Algorytm sortowania przez selekcję: [link do YT](http://www.youtube.com/watch?v=Ns4TPTC8whw)
* Algorytm sortowania bąbelkowego (od 52 s.): [link do YT](http://www.youtube.com/watch?v=lyZQPjUT5B4)

W funkcji `main` dopisz wywołania tej funkcji oraz przetestuj działanie programu dla różnych wielkości tablicy i różnych zakresów losowania.

---

## Zadanie 4: Histogram znaków (dla ambitnych - nieobowiązkowe)
Proszę napisać nowy program, który będzie czytać za pomocą funkcji `getch()` znaki aż do momentu naciśnięcia klawisza Esc (znak o kodzie 27). Program powinien zliczać liczbę wczytanych liter alfabetu angielskiego (26 znaków od A do Z).
`A, B, C, D, E, F ... Z`

**UWAGA:** proszę zliczać zarówno małe jak i wielkie litery. Małe litery należy zamieniać na wielkie litery.

Po zakończeniu wczytywania program powinien wypisać na ekranie ogólną liczbę wprowadzonych znaków oraz liczbę poszczególnych liter w postaci odwróconego wykresu słupkowego drukowanego za pomocą znaków `#`. Przykładowy wydruk powinien wyglądać tak jak na rysunku poniżej:

```text
Wpisuj litery: abpAgE8BhZd tatUoAaMw5blk
Wpisano ogolem 25 znakow w tym:
litera A 5 #####
litera B 3 ###
litera C 0
litera D 1 #
litera E 1 #
..... i tak dalej do litery Z
```

**Wskazówki:**
* Do pamiętania liczby wczytanych liter proszę zadeklarować tablicę liczb całkowitych o rozmiarze 26 elementów.
* Przed rozpoczęciem wczytywania wszystkie elementy tablicy należy wyzerować.
* Pierwszy element tablicy (o indeksie 0) powinien zliczać liczbę liter 'A' oraz 'a'.
* Drugi element tablicy (o indeksie 1) powinien zliczać liczbę liter 'B' oraz 'b'. Kolejne elementy liczbę 'C', 'D' itd.
* Wielkie litery można zliczać w następujący sposób:
  ```cpp
  int Tab[26];
  char znak;
  // ... wczytywanie znaku ...
  if (znak >= 'A' && znak <= 'Z') Tab[znak - 'A']++;
