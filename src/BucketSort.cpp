#include "BucketSort.hh"

void BucketSort(Element Tablica[], long int pierwszy_element, long int ostatni_element) {
  Kubel Wiadro[11]; // stwórz tablice kubłów 
  long int k = 0; // zmienna pomocnicza do obsługi tablicy
  
  for(long int i = pierwszy_element; i <= ostatni_element; i++) // Powtarzaj dla całej tablicy
    Wiadro[Tablica[i].getOcena()].addLast(Tablica[i]); // Wrzuć elementy do odpowiedniego kubła
  
  for(int j = 0; j <= 10; j++) // powtarzaj dla każdego kubła
    while(!Wiadro[j].isEmpty())  // Az kubeł nie będzie pusty
      Tablica[k++] = Wiadro[j].takeFront(); // Wrzucaj z kubła do tablicy
}
