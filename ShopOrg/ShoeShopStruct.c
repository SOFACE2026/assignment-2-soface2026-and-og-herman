#include "ShoeShopStructC.h"

void add_items(struct ShoeShop * s, int row, int num){ // samme som klassen bare med struct
    s->shelf[row] += num;
}
 
int in_stock(struct ShoeShop * s, int row){ // samme som klassen bare med struct
    return s->shelf[row] > 0;
}

int count_items(struct ShoeShop * s){ // samme som klassen bare med struct
    int tot = 0;
    for (int k = 0; k < s->size; k++) {
        tot += s->shelf[k];
    }
    return tot;
}

bool clear(struct ShoeShop * s, int row){ // samme funktion som i klassen bare nu hvor structen tilgås.
    bool rem = s->shelf[row] > 0;
    s->shelf[row] = 0;
    return rem;
}

void ShoeShopDestructor(struct ShoeShop * s) { // gør memory for s fri igen (så sletter den)
    free(s);
   
}

struct ShoeShop ShoeShopConstructor(int size) { 
    struct ShoeShop * shoeshop = malloc(sizeof(struct ShoeShop));
    
    shoeshop->shelf = malloc(sizeof(int[100])); // vi må ikke alokere dynamisk så tallet bliver sat til 100 istedet for size
    shoeshop->size = size;

    // funktionspointerne sættes til adresser for de respektive funktioner
    shoeshop->add_items_func = &add_items;
    shoeshop->in_stock_func = &in_stock;
    shoeshop->count_items_func = &count_items;
    shoeshop->clear_func = &clear;
}