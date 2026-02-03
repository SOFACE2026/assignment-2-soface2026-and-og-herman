#include "ShopC.h"

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

