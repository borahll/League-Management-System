//
//  Player.cpp
//  lab2
//
//  Created by Bora Haliloglu on 27.10.2022.
//  22101852
//. Section 3

#include "Player.hpp"

using namespace std;

Player::Player(string name, int jerseyNo, int salary){
    this->playerName = name;
    this->salary = salary;
    this->jersey = jerseyNo;
}
Player::Player(){
    this->playerName = "";
    this->salary = -1;
    this->jersey = -1;
}
Player::~Player(){
    
}
void Player::setName(string name){
    this->playerName = name;
}
void Player::setSalary(int salary){
    this->salary = salary;
}
void Player::setJersey(int no){
    this->jersey = no;
}
string Player::getPlayerName(){
    return this->playerName;
}
int Player::getSalary(){
    return this->salary;
}
int Player::getJersey(){
    return this->jersey;
}
Player& Player::operator=(const Player& right){
    if(&right != this){
        if(this->playerName != right.playerName){
            this->playerName = right.playerName;
        }
        if(this->salary != right.salary){
            this->salary = right.salary;
        }
        
        //if(this->jersey != right.jersey){
            this->jersey = right.jersey;
        //}
    }
    return *this;
}
ostream& operator<<(ostream& o, Player& p){
    o << p.getPlayerName()<< ", jersey " << p.getJersey() << ", " << p.getSalary() << " TL salary"<< endl;
    return o;
}
