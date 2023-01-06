#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

int main(){
  Catalogue c;
  TrajetSimple t1("Lyon", "Paris", "Train");
  TrajetSimple t2("Paris", "Marseille", "Avion");
  TrajetSimple t3("Lyon", "Marseille", "Bateau");
  TrajetSimple t4("Marseille", "Bordeaux", "Voiture");
  TrajetSimple t5("Bordeaux", "Paris", "Voiture");

  TrajetCompose tc1;
  tc1.AjouterTrajet(t3);
  tc1.AjouterTrajet(t4);
  tc1.AjouterTrajet(t5);

  TrajetCompose tc2;
  tc2.AjouterTrajet(t1);
  tc2.AjouterTrajet(t3);

  c.AjouterTrajet(&t1);
  c.AjouterTrajet(&t2);
  c.AjouterTrajet(&tc1);

  c.RechercheSimple("Lyon", "Paris");

  return 0;
}