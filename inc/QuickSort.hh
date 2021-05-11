#ifndef QUICKSORT
#define QUICKSORT

#include "Element.hh"

// Funkcja zamieniająca elementy miejscami
void SwapElements(Element Tablica[], long int jeden, long int drugi);

// Funkcja segregująca elementy względem piwota
int Segregacja(Element Tablica[], long int pierwszy_element, long int ostatni_element);

// Funkcja sortowania szybkiego in situ
void QuickSort(Element Tablica[], long int pierwszy_element, long int ostatni_element);

#endif
