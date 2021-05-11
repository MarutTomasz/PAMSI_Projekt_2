#include "MergeSort.hh"

// Funkcja scalające elementy tablicy w odpowiedniej kolejności
void Scalanie(Element Tablica[], long int pierwszy_element, long int ostatni_element){  
  Element *pom = new Element[ostatni_element - pierwszy_element + 1]; // tablica dynamiczna pomocna przy sortowaniu
  long int srodek = (ostatni_element+pierwszy_element)/2; // element środkowy, względem którego wcześniej była dzielona tablica
  long int i = pierwszy_element;  // zmienna pomocnicza do pętli, "pierwsza" scalana tablica
  long int j = srodek + 1; // zmienna pomocnicza do pętli, "druga" scalana tablica
  long int k = 0;  // zmienna do obsługi pomocniczej tablicy 

  
  while(k <= ostatni_element-pierwszy_element) {  // powtarzaj dla wszystkich elementów tablicy
    if(i <= srodek && j <= ostatni_element){  // jeśli są jeszcze elementy w obu połówkach
      if(Tablica[i].getOcena() <= Tablica[j].getOcena())  // jeśli element z pierwszej połowy jest mniejszy od elementu w drugiej połowie
	pom[k++] = Tablica[i++]; // przepisz element z pierwszej połowy i przesuń indeksy

      else   // // jeśli element z drugiej połowy jest mniejszy
	pom[k++] = Tablica[j++]; // przepisz element i przesuń indeksy  
    }
    
    else{ // jeśli któraś tablica już się skończła
      while(i <= srodek)  // powtarzaj aż skończy się pierwsza połowa
	pom[k++] = Tablica[i++];  // przepisz element i przesuń indeksy
      
      while(j <= ostatni_element) // powtarzaj aż skończy się druga połowa 
	pom[k++] = Tablica[j++]; // przepisz element i przesuń indeksy
    }
  }

  for(k = 0, i = pierwszy_element; k <= ostatni_element-pierwszy_element; k++) // dla wszystkich elementóœ
    Tablica[i++] = pom[k];  // przepisz z pomocniczaej do głównej
  
  delete[] pom;  // zwolnienie pamięci po pomocniczej tablicy
}

// Funkcja sortowania przez scalanie
void MergeSort(Element Tablica[], long int pierwszy_element, long int ostatni_element){  
  if(ostatni_element <=  pierwszy_element) // jeśli tablica jednoelementowa
    return; // koniec rekurencji

  long int srodek = (ostatni_element+pierwszy_element)/2; // wybierz element w połowie jako dzielnik tablicy

  MergeSort(Tablica,pierwszy_element,srodek); // rekurencja dla pierwszej połowy tablicy 
  MergeSort(Tablica,srodek+1,ostatni_element); // rekurencja dla drugiej połowy tablicy

  Scalanie(Tablica,pierwszy_element,ostatni_element);  // Scal połowy tablic w odpowiedniej kolejności
}
    
