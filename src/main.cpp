#include "Element.hh"
#include "Kubel.hh"
#include "MergeSort.hh"
#include "QuickSort.hh"
#include "BucketSort.hh"
#include <fstream>

//using namespace std;
using std::ifstream;
using std::ofstream;
using std::ios_base;

int main() {
  Element* Tab = new Element[1000000];  // dynamiczna tablica na elementy (na ich maksymalną ilość)
  ifstream plik_z_nazwami("Tytuly.txt"); // otwórz plik z tytułami
  ifstream plik_z_ocenami("Oceny.txt"); // otwórz plik z ocenami
  ofstream plik("posortowane.txt", ios_base::app); // otwórz/stwórz plik na posortowane filmy
  
  long int liczba = -1; // zmienna na ostatni element tablicy 
  string tytul; // zmienna używana do pobierania tytułu z pliku
  string ocena; // zmienna do pobrania oceny 
  
  do
    {
      getline(plik_z_nazwami,tytul); // wczytaj tytul 
      getline(plik_z_ocenami,ocena); // wczytaj ocene
      if (ocena != "") { // jeśli przy tytule była ocena (eliminacja tytułów bez ocen)
	liczba++; // zwiększ indeks 
	Tab[liczba].setOcena(stoi(ocena)); // wrzuć ocenę do elementu o danym indeksie
	Tab[liczba].setNazwa(tytul); // wrzuć tytuł do elementu o danym indeksie
      }
    }
  while (tytul != ""); // powtarzaj do końca pliku
  
  // wybór sortowania, do wyboru: MergeSort, QuickSort, BucketSort.
  // Wystarczy smienić nazwę funkcji. Argumnety są te same. 
  MergeSort(Tab, 0, liczba);
  
  for(int i = 0; i <= liczba ; i++) // powtarzaj dla wszystkich elementów
    plik << Tab[i] << endl; // wpisz posortowane filmy do pliku
  
  plik.close();                // zamknij pliki
  plik_z_nazwami.close();
  plik_z_ocenami.close();
  
  delete [] Tab;
  
  return 1;
}
  
