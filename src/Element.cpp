#include "Element.hh"

// Przeciążenie operatora przypisania
Element Element::operator = (Element  Skl) {
  this->setNazwa(Skl.getNazwa());
  this->setOcena(Skl.getOcena());    
  return *this;
}

// Wyświetlanie zawartości elementu
std::ostream & operator << (std::ostream &strm, const Element &elem) {
  strm << "Ocena: " << elem.getOcena() << "/10  Tytuł: " <<  elem.getNazwa();
  return strm; 
}
