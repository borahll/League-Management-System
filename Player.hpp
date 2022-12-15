//
//  Player.hpp
//  lab2
//
//  Created by Bora Haliloglu on 27.10.2022.
//. 22101852
//  Section 3

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>

#include <iostream>
#include <string>
using namespace std;

class Player{
public:
    Player(string name, int jerseyNo, int salary);
    Player();
    ~Player();
    string getPlayerName();
    int getSalary();
    int getJersey();
    void setName(string name);
    void setSalary(int salary);
    void setJersey(int jersey);
    Player& operator =(const Player&);
private:
    string playerName;
    int salary;
    int jersey;
    
    friend ostream& operator<<(ostream&, Player&);

};

#endif /* Player_hpp */
