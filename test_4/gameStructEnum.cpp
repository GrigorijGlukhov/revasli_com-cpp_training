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

struct Monster {
    MonsterType monsterType;
    std::string name;
    int health;
    ItemType itemType;
};

void PrintMonster (Monster monster) {
    std::cout << "This is monster " << GetMonsterType(monster.monsterType) << " named " << monster.name << ". He has " << monster.health << " health points ";
    std::cout << "and holding " << GetItemType(monster.itemType) << " in his hands.\n";
}

int main(){
    Monster orc = {MONSTER_ORC, "Alex", 100, ITEMTYPE_SWORD};
    Monster troll = {MONSTER_TROLL, "Bob", 300, ITEMTYPE_GUN};
    
    PrintMonster(orc);
    PrintMonster(troll);
    return 0;
}