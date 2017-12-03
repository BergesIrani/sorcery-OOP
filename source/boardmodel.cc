#include "boardmodel.h"
#include "minion.h"
#include "nonplayer.h"
#include "playercontroller.h"
#include "state.h"
#include <iostream>

BoardModel::BoardModel(std::vector<std::string> players, std::vector<std::unique_ptr<std::ifstream>> &data) {
  std::cout << "BoardModel.cc: Players are being initialized in the constructor." << std::endl;
  for (unsigned int i = 0; i < players.size(); ++i) {
    std::cout << "BoardModel.cc: Player " << i << " has been created." << std::endl;
    this->players.emplace_back(std::unique_ptr<PlayerController>(new PlayerController(players[i], data[i], i)));
  }
}

bool BoardModel::isDeckEmpty(int player) {
  return players[player]->getPlayerData().deck.empty();
  }

void BoardModel::updateBoard(std::vector<Event> events) {
  // loop through every non-player in each player's minions, ritual(s)
  // for each card, let it know that the events have occurred
  for (unsigned int i = 0; i < players.size(); ++i) {
      std::cout << "BoardModel.cc: Player " << i << " has been alerted with an event." << std::endl;    
      players[i]->update(events);
  }

}

int BoardModel::getMagic(int player) {
  return players[player]->getPlayerData().magic;
}

void BoardModel::setMagic(int player, int newValue) {
  players[player]->playerModel.magic = newValue;
}

int BoardModel::getHealth(int player) {
  return players[player]->getPlayerData().health;
}

BoardModel::~BoardModel() {
  
}
