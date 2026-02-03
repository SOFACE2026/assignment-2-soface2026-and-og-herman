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

struct ShoeShop {
    int * shelf;
    int size;

    void (* add_items_func)(struct ShoeShop, int, int);
    int (* in_stock_func)(struct ShoeShop, int);
    int (* count_items_func)(struct ShoeShop);
    bool (* clear_func)(struct ShoeShop, int);
};

