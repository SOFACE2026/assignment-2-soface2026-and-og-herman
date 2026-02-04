#include "ShoeShopStructC.h"

// adds the number of items to a specific row in the shelf
void add_items(struct ShoeShop * s, int row, int num){
    s->shelf[row] += num;
}
 
// checks if the stock in the row of the shelf is 0 or not
int in_stock(struct ShoeShop * s, int row){
    return s->shelf[row] > 0;
}

// counts the total number of items for all shelves
int count_items(struct ShoeShop * s){
    int tot = 0;
    for (int k = 0; k < s->size; k++) {
        tot += s->shelf[k];
    }
    return tot;
}

// clear a specific shelf row. returns true if the shelf contained any items, otherwise false
bool clear(struct ShoeShop * s, int row){
    bool rem = s->shelf[row] > 0;
    s->shelf[row] = 0;
    return rem;
}

// deletes a ShoeShop
void ShoeShopDestructor(struct ShoeShop * s) {
    free(s);
   
}

// constructs a ShoeShop
struct ShoeShop ShoeShopConstructor(int size) { 
    struct ShoeShop * shoeshop = malloc(sizeof(struct ShoeShop));
    
    shoeshop->shelf = malloc(sizeof(int[100])); // vi må ikke alokere dynamisk så tallet bliver sat til 100
    shoeshop->size = size;                      // number of slots in the shelf

    shoeshop->add_items_func = &add_items;      // adds a quantity of an item, calls the add_item function
    shoeshop->in_stock_func = &in_stock;        // checks stock on an item, calls the in_stock function
    shoeshop->count_items_func = &count_items;  // counts total items, calls the count_items function
    shoeshop->clear_func = &clear;              // removes an item, calls the clear function
}