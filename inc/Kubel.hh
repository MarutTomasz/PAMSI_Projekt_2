#ifndef KUBEL
#define KUBEL

#include "Element.hh"


class Segment { // element wrzucany do kubła
private:
  Element elem;   // wartość elementu 
  Segment* nastepny;   // wskaźnik na następny segment
public:
  // Metody pobierające wartości przechowywane przez clasę
  Element getElement() const {return elem;}   
  Segment* getNastepny() const {return nastepny;}
  
  // Metody ustanawiające nowe wartości, które ma przechowywać struktura 
  void setElement(Element nowyElement) {elem = nowyElement;}
  void setNastepny(Segment* nowyNastepny) {nastepny = nowyNastepny;}
};

class Kubel { // klasa przechowująca elementy w postaci listy jednokierunkowej
private:
  Segment* poczatek;   // wskaźnik na początek kubła, pierwsze do wyjścia
  Segment* koniec;  // wskaźnik na koniec kubła, ostatnie do wyścia
public:
  // Metody pobierające wartości przechowywane przez clasę
  Segment* getPoczatek() const {return poczatek;}   
  Segment* getKoniec() const {return koniec;}
  
  // Metody ustanawiające nowe wartości, które ma przechowywać struktura 
  void setPoczatek(Segment* nowyPoczatek) {poczatek = nowyPoczatek;}
  void setKoniec(Segment* nowyKoniec) {koniec = nowyKoniec;}

  // Konstruktor kubła 
  Kubel();

  // Metoda sprawdzająca pustość kubła
  bool isEmpty();

  // Dodawanie elementu na koniec kubła
  void addLast(Element nowyElement);

  // Zabieranie elementu z początku kubła
  Element takeFront();
};


#endif
