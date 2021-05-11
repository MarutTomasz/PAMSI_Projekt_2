#ifndef ELEMENT
#define ELEMENT

#include <iomanip>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::cerr;


class Element { // Klasa przechowująca tytuł i ocene filmu
private:
  string nazwa;  // Pole na nazwę filmu
  int ocena;   // Pole na ocenę
public:
  // Metody pobierające wartości przechowywane przez clasę
  string getNazwa() const {return nazwa;}   
  int getOcena() const {return ocena;}
  
  // Metody ustanawiające nowe wartości, które ma przechowywać struktura 
  void setNazwa(string nowaNazwa) {nazwa = nowaNazwa;}
  void setOcena(int nowaOcena) {ocena = nowaOcena;}

  // Przeciążenie operatora przypisania
  Element operator = (Element  Skl);
};

//Funkcja wyświetlająca pola klasy element
std::ostream & operator << (std::ostream &strm, const Element &Skl);


#endif
