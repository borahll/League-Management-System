//
//  Team.cpp
//  lab2
//
//  Created by Bora Haliloglu on 27.10.2022.
//. Section 3
//. 22101852

#include "Team.hpp"
#include <iostream>
using namespace std;

Team::Team(string teamName, int year){
    this->teamName = teamName;
    this->year = year;
    this->playerCount = 0;
    this->playerArr = nullptr;
}
Team::Team(){
        this->teamName = "";
        this->year = -1;
        this->playerCount = 0;
        this->playerArr = -1;
}
Team::~Team(){
    if(playerArr != NULL){
        delete []playerArr;
    }
}
string Team::getName(){
    return this->teamName;
}
int Team::getYear(){
    return this->year;
}
int Team::getPlayerCount(){
    return this->playerCount;
}
void Team::getPlayers(){
    if(playerArr != NULL){
        for(int a = 0; a < playerCount; a++){
            cout << playerArr[a].getPlayerName() << endl;
        }
    }
    else{
        cout << " NULL ARRAY" << endl;
    }
}
Player* Team::getPlayer(string Name){
    bool found = 0;
    Player* temp = nullptr;
    if(playerArr != NULL){
        for(int a = 0; a < playerCount; a++){
            if(playerArr[a].getPlayerName() == Name){
                found = 1;
                temp = &playerArr[a];
                return temp;
            }
        }
    }
    return temp;
}
Player* Team::getPlayer(int index){
    Player* temp = nullptr;
    temp = &playerArr[index];
    return temp;
}
void Team::setName(string name){
    this->teamName = name;
}
void Team::setYear(int year){
    this->year = year;
}
Team& Team::operator=(const Team& right){
    if(&right != this){
        if(teamName != right.teamName){
            this->teamName = right.teamName;
        }
        //if(this->playerCount != right.playerCount){
            if(this->playerCount > 0){
                delete []playerArr;
            }
            this->playerCount = right.playerCount;
            if(playerCount > 0){
                playerArr = new Player[playerCount];
            }
            else{
                playerArr = nullptr;
            }
        //}
        for(int a = 0; a < playerCount; a++){
            this->playerArr[a] = right.playerArr[a];
        }
        //if(this->year != right.year){
            this->year = right.year;
        //}
    }
    return *this;
}
ostream& operator<<(ostream& o, Team& t){
    o << t.getName() << ", " << t.getYear() << ", "<< t.playerCount << " players, " <<  t.getTotalSalary() << " total salary" << endl;
    return o;
}
int Team::getTotalSalary(){
    int sal = 0;
    for(int a = 0; a < playerCount; a++){
        sal += playerArr[a].getSalary();
    }
    return sal;
}
bool Team::playerExists(string aPlayerName){
    bool found = 0;
    for(int a = 0; a < playerCount; a++){
        if(playerArr[a].getPlayerName() == aPlayerName){
            found = 1;
        }
    }
    return found;
}
bool Team::jerseyExists(int jerseyNo){
    bool found = 0;
    for(int a = 0; a < playerCount; a++){
        if(playerArr[a].getJersey() == jerseyNo){
            found = 1;
        }
    }
    return found;
}
bool Team::addPlayer(string aName, int jersey, int aSalary){
    if(playerExists(aName)){
        cout << "Cannot add player " << aName << " to the team because it already exists." << endl;
        return 0;
    }
    else{
        if(!jerseyExists(jersey)){
            if(playerCount > 0){
                Player* temp = new Player[playerCount];
                for(int a = 0; a < playerCount; a++){
                    temp[a] = playerArr[a];
                }
                delete []playerArr;
                
                playerArr = new Player[playerCount + 1];
                for(int a = 0; a < playerCount; a++){
                    playerArr[a] = temp[a];
                }
                Player tmp(aName, jersey, aSalary);
                playerArr[playerCount] = tmp;
                playerCount++;
                delete []temp;
                cout << "Added player " << aName << " to the team " << this->getName() << endl;
            }
            else if (playerCount == 0){
                playerArr = new Player[++playerCount];
                Player tmp(aName, jersey, aSalary);
                playerArr[0] = tmp;
                cout << "Added player " << aName << " to the team " << this->getName() << endl;
            }
            return 1;
        }
        else{
            cout << "Cannot add player. Because jersey no " << jersey << " already exists" <<endl;
            return 0;
        }
    }
}
bool Team::addPlayerV2(string aName, int jersey, int aSalary){
    if(playerExists(aName)){
        cout << "Cannot add player " << aName << " to the team because it already exists." << endl;
        return 0;
    }
    else{
        if(!jerseyExists(jersey)){
            if(playerCount > 0){
                Player* temp = new Player[playerCount];
                for(int a = 0; a < playerCount; a++){
                    temp[a] = playerArr[a];
                }
                delete []playerArr;
                
                playerArr = new Player[playerCount + 1];
                for(int a = 0; a < playerCount; a++){
                    playerArr[a] = temp[a];
                }
                Player tmp(aName, jersey, aSalary);
                playerArr[playerCount] = tmp;
                playerCount++;
                delete []temp;
            }
            else if (playerCount == 0){
                playerArr = new Player[++playerCount];
                Player tmp(aName, jersey, aSalary);
                playerArr[0] = tmp;
            }
            return 1;
        }
        else{
            cout << "Cannot add player. Because jersey no " << jersey << " already exists" <<endl;
            return 0;
        }
    }
}
bool Team::removePlayerV2(string playerName){
    bool exists = 0;
    int index = -1;
    for(int a = 0; a < playerCount; a++){
        if(playerArr[a].getPlayerName() == playerName){
            exists = 1;
            index = a;
        }
    }
    if(exists){
        Player* team = new Player[playerCount];
        for(int a = 0; a < playerCount; a++){
            team[a] = playerArr[a];
        }
        delete []playerArr;
        playerArr = new Player[playerCount - 1];
        for(int a = 0; a < index; a++){
            playerArr[a] = team[a];
        }
        for(int a = index; a < playerCount - 1; a++){
            playerArr[a] = team[a + 1];
        }
        playerCount--;
        delete []team;
        return 1;
    }
    else{
        cout << "No such player in the team" << endl;
        return 0;
    }
}

bool Team::removePlayer(string playerName){
    bool exists = 0;
    int index = -1;
    for(int a = 0; a < playerCount; a++){
        if(playerArr[a].getPlayerName() == playerName){
            exists = 1;
            index = a;
        }
    }
    if(exists){
        Player* team = new Player[playerCount];
        for(int a = 0; a < playerCount; a++){
            team[a] = playerArr[a];
        }
        delete []playerArr;
        playerArr = new Player[playerCount - 1];
        for(int a = 0; a < index; a++){
            playerArr[a] = team[a];
        }
        for(int a = index; a < playerCount - 1; a++){
            playerArr[a] = team[a + 1];
        }
        playerCount--;
        delete []team;
        cout << "Removed player " << playerName << " from team " << this->getName() << "." << endl;
        return 1;
    }
    else{
        cout << "No such player in the team" << endl;
        return 0;
    }
}
