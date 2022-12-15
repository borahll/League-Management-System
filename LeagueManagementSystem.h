//
//  LeagueManagementSystem.hpp
//  lab2
//
//  Created by Bora Haliloglu on 27.10.2022.
//. 22101852
//. Section 3

#ifndef LeagueManagementSystem_hpp
#define LeagueManagementSystem_hpp
#include <iostream>
#include "Team.hpp"
using namespace std;

class LeagueManagementSystem{
public:
    LeagueManagementSystem();
    ~LeagueManagementSystem();
    void addTeam( const string name, const int year );
    void removeTeam( const string name );
    void addPlayer( const string teamName, const string playerName,
    const int jersey, const int salary );
    void removePlayer( const string teamName, const string playerName );
    void transferPlayer( const string playerName, const string departTeamName, const string arriveTeamName );
    void showAllTeams() const;
    void showTeam( const string name ) const;
    void showPlayer( const string name ) const;
private:
    Team* teams;
    int teamCount;
};
#endif /* LeagueManagementSystem_hpp */
