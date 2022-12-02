#include "Catalogue.h"
#include "TrajetSimple.h"

int main(){
  Catalogue c;
  TrajetSimple t1("Lyon", "Paris", "Train");
  TrajetSimple t2("Paris", "Marseille", "Avion");

  c.AjouterTrajet(&t1);
  c.AjouterTrajet(&t2);

  c.Affichage();

  return 0;
}