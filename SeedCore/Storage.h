#pragma once
#ifndef _STORE
#define _STORE
#include <string>
#include <vector>
// Weapons / Defence Items.
struct Base
{
    std::string ObjectID;
    std::string RealName;
};

struct WAItem : Base
{
    unsigned int PhysicalAttack;
    unsigned int ArteAttack;
    unsigned int PhysicalDef;
    unsigned int ArteDef;
    std::vector<Skill> Skills;  //
    unsigned int Durability;    // Durability
};
struct ISlot
{
    WAItem WA;
    PAItem PA;
    unsigned int count;
};
// TODO
struct Skill
{

};
// Passive Items, Potions etc...
struct PAItem : Base
{

};

struct Player : Base
{
    std::vector<ISlot> Inventory;
    unsigned int MCount;
    std::vector<Skill> Skills;
};
// This might change. Depends on the game itself.
struct Stats
{

};

enum WeaponType
{
    Custom,
    Dropped,
    Purchased,
    Count
};
#endif // !_STORE
