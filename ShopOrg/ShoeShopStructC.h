#include <stdbool.h>

// functions for operating a ShoeShop
void add_items(struct ShoeShop, int, int);
int in_stock(struct ShowShop, int);
int count_items(struct ShoeShop);
bool clear(struct ShoeShop, int);

struct ShoeShop{        // struct for a ShoeShop, this almost looks identical to the shop struct
    int * shelf;        // array storing number of items
    int size;           // number of slots in the shelf

    void (* add_items_func)(struct ShoeShop, int, int); // adds a quantity of an item
    int (* in_stock_func)(struct ShoeShop, int);        // checks stock on an item
    int (* count_items_func)(struct ShoeShop);          // counts total items
    bool (* clear_func)(struct ShoeShop, int);          // removes an item
};


