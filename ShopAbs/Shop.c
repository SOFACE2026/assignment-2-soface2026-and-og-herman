#include "ShopC.h"

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

