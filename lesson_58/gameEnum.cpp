#include <iostream> 
#include <string>

enum MonsterType {
    MONSTER_ORC,
    MONSTER_TROLL,
    MONSTER_OGRE,
    MONSTER_GOBLIN,
    MONSTER_SKELETON
};

enum ItemType {
    ITEMTYPE_GUN,
    ITEMTYPE_ARBALET,
    ITEMTYPE_SWORD
};

std::string GetItemType (ItemType itemType) {
    if (itemType == ITEMTYPE_GUN)
        return std::string("Gun");
    if (itemType == ITEMTYPE_ARBALET)
        return std::string("Arbalet");
    if (itemType == ITEMTYPE_SWORD)
        return std::string("Sword");
}

std::string GetMonsterType(MonsterType _monsterType) {
    if (_monsterType == MONSTER_ORC)
        return std::string("Orc");
    if (_monsterType == MONSTER_TROLL)
        return std::string("Troll");
    if (_monsterType == MONSTER_OGRE)
        return std::string("Ogre");
    if (_monsterType == MONSTER_GOBLIN)
        return std::string("Goblin");
    if (_monsterType == MONSTER_SKELETON)
        return std::string("Skeleton");
}

int main(){
    ItemType itemType(ITEMTYPE_GUN);
    MonsterType monsterType(MONSTER_OGRE);
    
    std::cout << "You are carrying " << GetItemType(itemType) << "!\n";
    std::cout << "You see monster " << GetMonsterType(monsterType) << ", carrying " << GetItemType(ITEMTYPE_ARBALET) << "!";
    return 0;
}