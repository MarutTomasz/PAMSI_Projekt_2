#include "QuickSort.hh"

// Funkcja zamienijąca miejscami dwa elemnety tablicy 
void SwapElements(Element Tablica[], long int jeden, long int drugi){
  Element pom = Tablica[jeden];
  Tablica[jeden] = Tablica[drugi];
  Tablica[drugi] = pom;
  return;
}

// Funkcja segregująca elementy względem piwota
int Segregacja(Element Tablica[], long int pierwszy_element, long int ostatni_element){
  int piwot = Tablica[ostatni_element].getOcena(); // wartość oceny piwota do porównań
  long int i = pierwszy_element-1;  // element 1 mniejszy od pierwszego, żeby można zacząć z preinkrementacją
  long int j = ostatni_element+1; //  element 1 większy od ostatniego, żeby można zacząć z preinkrementacją
  
  while(i < j) { // powtarzaj aż indeksy się miną 
    while(Tablica[++i].getOcena() < piwot && i < j) {} // szukaj elementu nie mniejszego niż piwot z lewej strony
    
    while(Tablica[--j].getOcena() > piwot && i < j) {}  // szukaj elementu nie większego niż piwot z prawej strony
    
    if(i<j){  // gdy są takie elementy a indeksy się nie minęły
      SwapElements(Tablica,i,j);  // zamień je miejscami 
    } 
  }
  SwapElements(Tablica,i,ostatni_element); // wrzuć piwot w odpowiednie miejsce 
  return i; // zwróc pozycje piwota
}

void QuickSort(Element Tablica[], long int pierwszy_element, long int ostatni_element){
  if(pierwszy_element >= ostatni_element)  // jeśli tablica pusta lub jednoelementowa
    return;  // koniec rekurencji

  long int i = (pierwszy_element + ostatni_element) / 2;  // wybierz piwot ze środka
  SwapElements(Tablica,i,ostatni_element); // wrzuć go na koniec 
  long int l = Segregacja(Tablica,pierwszy_element,ostatni_element); // posegreguj wartościami względem piwota 
  QuickSort(Tablica,pierwszy_element,l-1); // rekurencja dla elementów nie większych niż obecny piwot
  QuickSort(Tablica,l+1,ostatni_element); // rekurencja dla elementów nie większych niż obecny piwot
  return;
}
