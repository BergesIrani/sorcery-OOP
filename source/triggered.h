#ifndef TRIGGERED_H
#define TRIGGERED_H

#include "ability.h"

class Triggered: public Ability {
    Event trigger;
public:
    Triggered(std::string &name, int cost, int owner, std::string &description, Event trigger);
    virtual ~Triggered() = default;
};

class AdderTriggered: public Triggered {
    int attMod;
    int defMod;
    std::string target;
    void updateState(std::vector<Event> &events) override;
    void castCard() override;
    void castCard(int p, char t = 'r') override;
public:
    AdderTriggered(Event trigger, int attMod, int defMod, std::string &target, std::string &description);
    ~AdderTriggered() { }
};

#endif