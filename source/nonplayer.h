#ifndef NONPLAYER_H
#define NONPLAYER_H

#include "card.h"
#include "type.h"

class NonPlayer: public Card {
    int cost;
    int owner;
    std::string description;
    Type type;
    virtual void castCard() = 0;
    virtual void castCard(int p, char t = 'r') = 0;
public:
    NonPlayer(std::string &name, int cost, int owner, std::string &&description = "");
    void cast();
    void cast(int p, char t = 'r');
    int getCost();
    void setCost(int cost);
    int getOwner();
    void setOwner(int owner);
    const Type getType() const;
    virtual ~NonPlayer() = 0;
};

#endif
