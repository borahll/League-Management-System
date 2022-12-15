//
//  LeagueManagementSystem.cpp
//  lab2
//
//  Created by Bora Haliloglu on 27.10.2022.
//  22101852
//. Section 3

#include "LeagueManagementSystem.hpp"
#include <iostream>
#include "Player.hpp"
#include "Team.hpp"
using namespace std;

LeagueManagementSystem::LeagueManagementSystem(){
    teams = nullptr;
    teamCount = 0;
}
LeagueManagementSystem::~LeagueManagementSystem(){
    if(teams != nullptr){
        delete []teams;
    }
}
void LeagueManagementSystem::addTeam(const string name, const int year){
    bool alreadyExists = 0;
    if(teams != nullptr){
        for(int a = 0; a < teamCount; a++){
            if(teams[a].getName() == name){
                alreadyExists = 1;
            }
        }
        if(!alreadyExists){
            teamCount++;
            Team* arr = new Team[teamCount - 1];
            for(int a = 0; a < teamCount - 1; a++){
                arr[a] = teams[a];
            }
            delete []teams;
            teams = new Team[teamCount];
            for(int a = 0; a < teamCount - 1 ; a++){
                teams[a] = arr[a];
            }
            Team tmp(name, year);
            teams[teamCount - 1] = tmp;
            cout << "Added team " << name << endl;
            delete [] arr;
        }
        
        else{
            cout << "Cannot add team. Team " << name << " already exists" << endl;
        }
    }
    else{
        teamCount++;
        teams = new Team[teamCount];
        Team tmp(name, year);
        teams[teamCount-1] = tmp;
        cout << "Added team " << name << endl;
    }
}
void LeagueManagementSystem::removeTeam(const string name){
    bool found = 0;
    int index = -1;
    Team* tmp = new Team[teamCount];
    for(int a = 0; a < teamCount; a++){
        if(teams[a].getName() == name){
            found = 1;
            index = a;
        }
        tmp[a] = teams[a];
    }
    if(!found){
        cout << "Cannot remove team. Team " << name << " does not exist." << endl;
    }
    if(index >= 0){
        delete []teams;
        teams = new Team[teamCount - 1];
        for(int a = 0; a < teamCount - 1; a++){
            teams[a] = tmp[a];
        }
        for(int a = index; a < teamCount - 1; a++){
            teams[a] = tmp[a + 1];
        }
        cout << "Removed team " << name <<"." << endl;
        teamCount--;
    }
    delete []tmp;
}
void LeagueManagementSystem::addPlayer(const string aTeamName, const string aPlayerName, const int aJersey, const int aSalary){
    bool teamfound = 0;
    bool playerExists = 0;
    bool jerseyExists = 0;
    int teamLoc = -1;
    for (int a = 0; a < teamCount; a++){
        if(teams[a].getName() == aTeamName){
            teamfound = 1;
            teamLoc = a;
            if(teams[a].playerExists(aPlayerName)){
                playerExists = 1;
            }
            if(teams[a].jerseyExists(aJersey)){
                jerseyExists = 1;
            }
        }
    }
    if(!teamfound){
        cout << "Team does not exist" << endl;
    }
    else if (playerExists){
        cout << "Player already exists" << endl;
    }
    else if(jerseyExists){
        cout << "Cannot add player. Jersey number " << aJersey << " already exists in team " << aTeamName << "."<< endl;
    }
    else{
        teams[teamLoc].addPlayer(aPlayerName, aJersey, aSalary);
    }
}
void LeagueManagementSystem::removePlayer(const string teamName, const string playerName){
    int teamIndex = -1;
    for(int a = 0; a < teamCount; a++){
        if(teams[a].getName() == teamName){
            teamIndex = a;
        }
    }
    if(teamIndex == -1){
        cout << "Cannot remove player. Team " << teamName << " does not exist." << endl;
    }
    else{
        teams[teamIndex].removePlayer(playerName);
    }
}
void LeagueManagementSystem::transferPlayer(const string playerName, const string departTeamName, const string arriveTeamName){
    int teamIndex = -1;
    int toIndex = -1;
    for(int a = 0; a < teamCount; a++){
        if(teams[a].getName() == departTeamName){
            teamIndex = a;
        }
        if(teams[a].getName() == arriveTeamName){
            toIndex = a;
        }
    }
    if(teamIndex >= 0 && toIndex >= 0){
        if(teams[teamIndex].getPlayer(playerName) != nullptr){
            Player* tmp = teams[teamIndex].getPlayer(playerName);
            //teams[teamIndex].removePlayer(playerName);
            //teams[toIndex].addPlayer(playerName, tmp->getJersey(), tmp->getSalary());
            if(teams[toIndex].jerseyExists(teams[teamIndex].getPlayer(playerName)->getJersey())){
                cout << "Cannot transfer player " << playerName << " to " << teams[toIndex].getName() << " because jersey no " << teams[teamIndex].getPlayer(playerName)->getJersey() << " already exists in team " << teams[toIndex].getName();
            }
            else if(teams[teamIndex].removePlayerV2(playerName) && teams[toIndex].addPlayerV2(playerName, tmp->getJersey(), tmp->getSalary())){
                cout << "transfered player: " << playerName << endl;
            }
        }
        else{
            cout << "Cannot transfer player " << playerName << " because player does not exist" << endl;
        }
    }
    else{
        if(teamIndex == -1 && toIndex == -1){
            cout << "Cannot transfer player. Team " << arriveTeamName << " and " << departTeamName << " does not exist." << endl;
        }
        if(teamIndex == -1 && toIndex >= 0){
            cout << "Cannot transfer player. Team " << departTeamName << " does not exist." << endl;
        }
        if(toIndex == -1 && teamIndex >= 0){
            cout << "Cannot transfer player. Team " << arriveTeamName << " does not exist." << endl;
        }
    }
}
void LeagueManagementSystem::showAllTeams() const{
    cout << "Teams in the League Management System:" << endl;
    if(teamCount == 0){
        cout << "None" << endl; 
    }
    for(int a = 0; a < teamCount; a++){
        cout << teams[a] << endl;
    }
}
void LeagueManagementSystem::showTeam(const string name)const{
    int index = -1;
    for(int a = 0; a < teamCount; a++){
        if(teams[a].getName() == name){
            index = a;
        }
    }
    if(index < 0){
        cout << "Team" << name << " does not exist." << endl;
    }
    else{
        cout << "Team:" << endl;
        cout << teams[index] << endl;
        cout << "Players:" << endl;
        for(int a = 0; a < teams[index].getPlayerCount(); a++){
            cout << *(teams[index].getPlayer(a)) << endl;
        }
    }
}
void LeagueManagementSystem::showPlayer(const string name)const{
    int teamIndex = -1;
    for(int a = 0; a < teamCount; a++){
        if(teams[a].getPlayer(name) != nullptr){
            teamIndex = a;
        }
    }
    if(teamIndex >= 0){
        cout << *(teams[teamIndex].getPlayer(name));
    }
    else{
        cout << "Player " << name << " does not exist."<< endl;
    }
}
