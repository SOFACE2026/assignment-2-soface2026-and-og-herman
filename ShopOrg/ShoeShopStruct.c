#include "ShoeShopStructC.h"

void add_items(struct ShoeShop * s, int row, int num){
    s->shelf[row] += num;
}
 
int in_stock(struct ShoeShop * s, int row){
    return s->shelf[row] > 0;
}

int count_items(struct ShoeShop * s){
    int tot = 0;
    for (int k = 0; k < s->size; k++) {
        tot += s->shelf[k];
    }
    return tot;
}

bool clear(struct ShoeShop * s, int row){
    bool rem = s->shelf[row] > 0;
    s->shelf[row] = 0;
    return rem;
}

void ShoeShopDestructor(struct ShoeShop * s) {
    free(s);
   
}

// constructs a ShoeShop
struct ShoeShop ShoeShopConstructor(int size) { 
    struct ShoeShop * shoeshop = malloc(sizeof(struct ShoeShop));
    
    shoeshop->shelf = malloc(sizeof(int[100])); // vi må ikke alokere dynamisk så tallet bliver sat til 100
    shoeshop->size = size;

    shoeshop->add_items_func = &add_items;
    shoeshop->in_stock_func = &in_stock;
    shoeshop->count_items_func = &count_items;
    shoeshop->clear_func = &clear;
}