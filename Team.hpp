//
//  Team.hpp
//  lab2
//
//  Created by Bora Haliloglu on 27.10.2022.
//. 22101852
//. Section 3

#ifndef Team_hpp
#define Team_hpp

#include <stdio.h>

#include <iostream>
#include <string>
#include "Player.hpp"

using namespace std;

class Team{
public:
    Team(string teamName, int year);
    Team();
    ~Team();
    string getName();
    int getYear();
    int getPlayerCount();
    void getPlayers();
    Player* getPlayer(string name);
    Player* getPlayer(int index);
    void setName(string name);
    void setYear(int year);
    bool playerExists(string aPlayerName);
    bool jerseyExists(int jerseyNo);
    Team& operator =(const Team&);
    bool addPlayer(string playerName, int aJersey, int aSalary);
    bool removePlayer(string playerName);
    bool addPlayerV2(string playerName, int aJersey, int aSalary);
    bool removePlayerV2(string playerName);
    int getTotalSalary();
private:
    string teamName;
    int year;
    int playerCount;
    Player* playerArr;
    
    friend ostream& operator<<(ostream&, Team&);
};


#endif /* Team_hpp */

