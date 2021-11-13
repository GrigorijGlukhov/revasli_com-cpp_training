#include <iostream>
#include <string>

enum Items {
    POTION,
    TORCH,
    ARROW,
    MAX_ITEMS
};

std::string getItemsType(Items item) {
    if (item == POTION) return "Health Potion";
    if (item == TORCH) return "Torch";
    if (item == ARROW) return "Arrow";
}

void countTotalItems( int items[], int &itemsCount) {
    for (int item = 0; item < itemsCount; ++item) {
        std::cout << "You have " << *(items+item) << " " << getItemsType(item) << "s.\n";
    }
}

int main(){
    int inventory[MAX_ITEMS] = {3, 6, 12};
    
    countTotalItems(inventory, MAX_ITEMS);
    
    return 0;
}