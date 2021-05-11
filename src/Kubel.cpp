#include "Kubel.hh"

// Konstruktor kubła - ustawia wskaźniki na NULL 
Kubel::Kubel() {  
  poczatek = NULL;  
  koniec = NULL;
}

// Sprawdzanie czy kubeł jest pusty
bool Kubel::isEmpty() {
  if (poczatek == NULL)
    return 1;
  return 0;
}

// Metoda dodająca nowy element na koniec kubła
void Kubel::addLast(Element nowyElement) {
  Segment* wskaznik = new Segment; // zajmij miejsce na nowy segment
  wskaznik->setElement(nowyElement); // dodaj element do segmentu
  wskaznik->setNastepny(NULL); // niech pokazuje na nicość
  if (this->isEmpty()) // jeśli to pierwszy segment
    poczatek = wskaznik; // niech początek do pamięta
  if (koniec != NULL) // jeśli już coś jest w kuble
    koniec->setNastepny(wskaznik); // niech ostatni segment pozakuje na ten nowy
  koniec = wskaznik; // koniec pokazuje na nowy 
}

Element Kubel::takeFront() {
  if (this->isEmpty()) // jeśli pusty kubeł
    exit(1);  // zakończ działanie programu
  
  Segment* pom = poczatek;  // pomocniczy wskaźnik na pierwszy segment
  poczatek = poczatek->getNastepny(); // początek przesuwa się do następnego
  pom->setNastepny(NULL); // niech wyjęty segment nic nie pamięta 
  Element zawartosc = pom->getElement(); // wyjmij z niego zawartość
  delete pom; // dezintegracja segmentu
  return zawartosc; // zwróc wyjętą zawartość
}
