#include <iostream>

//------------------------------------------------------------------
enum class ItemsType {
  HEALTH_POTION,
  TORCH,
  ARROW,
  TOTAL_COUNT
};

std::string GetItemType(ItemsType item) {
  switch ( item ) {
    default:
    case ItemsType::HEALTH_POTION : return "Health potion";
    case ItemsType::TORCH : return "Torch";
    case ItemsType::ARROW : return "Arrow";
  }
}
//------------------------------------------------------------------

void countTotalItems(const int * array, int count ){
  std::cout << "\nPrint total count of items:\n";
  for ( int item = 0; item < count; ++item )
    std::cout << item+1 << " - " << *(array+item) << " of " << GetItemType(static_cast<ItemsType>(item)) << (item == 1 ? "es\n" : "s\n");
}

//------------------------------------------------------------------
// Main
//------------------------------------------------------------------
int main() {

  const int playerItems[] {3, 6, 12}; // player has these items

  countTotalItems( playerItems, sizeof(playerItems)/sizeof(playerItems[0]));

  return EXIT_SUCCESS;
}


