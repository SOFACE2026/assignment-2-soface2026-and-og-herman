#include <stdbool.h>

// funktionssignaturer
void add_items(struct ShoeShop, int, int);
int in_stock(struct ShowShop, int);
int count_items(struct ShoeShop);
bool clear(struct ShoeShop, int);
struct ShoeShop ShoeShopConstructor(int size);
void ShoeShopDestructor(struct ShoeShop * s);

struct ShoeShop{
    int * shelf;
    int size;

    void (* add_items_func)(struct ShoeShop, int, int);
    int (* in_stock_func)(struct ShoeShop, int);
    int (* count_items_func)(struct ShoeShop);
    bool (* clear_func)(struct ShoeShop, int);
};


