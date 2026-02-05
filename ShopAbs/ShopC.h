#include <stdbool.h>

void add_items(struct ShoeShop, int, int);
int in_stock(struct ShowShop, int);
int count_items(struct ShoeShop);
bool clear(struct ShoeShop, int);

struct Shop {

    void (* add_items_func)(struct ShoeShop, int, int);
    int (* in_stock_func)(struct ShoeShop, int);
    int (* count_items_func)(struct ShoeShop);
    bool (* clear_func)(struct ShoeShop, int);
};


//Funktioner i ShoeShop er identiske til Shop. Dette gør at vi ved at statisk cast shop * s = (shop *) shoeshop virker
//Når shoeshop er af typen ShoeShop. Prøver vi at access s->clear_func tilgår vi dermed den rigtige i shop variablen, selvom det i virkeligheden 
// er funktionen i shoeshop instansen der bliver kørt. Dette giver dog et problem, da vores funktion i sig selv kræver at selve structen også
// bliver sat som argument og vi skal derfor kalde s->clear_fun((ShoeShop *)s, int). Altså vi må lave endnu et cast den anden vej. 
// alternative havde været at ændre funktionerne til at tage en instans af shop ind. Dette ville dog resultere i at vi i fx add_items_func skulle prøve
// at tilgå s->shelf[row], hvilket giver en fejl, da s ikke har en shelf attribut når den optræder som en shop instans.

struct ShoeShop {
    int * shelf;
    int size;

    void (* add_items_func)(struct ShoeShop, int, int);
    int (* in_stock_func)(struct ShoeShop, int);
    int (* count_items_func)(struct ShoeShop);
    bool (* clear_func)(struct ShoeShop, int);
};

