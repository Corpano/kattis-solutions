#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Player{
public:
    long guess;
    long numOfEnemies;
};

int mobCount = 0;
vector<Player> playersList;
unordered_set<long> removedPlayers;

void recurseMob(int player){
    if(removedPlayers.count(player) || playersList[player].numOfEnemies > 0)
        return;

    // We found mob
    ++mobCount;

    int mobGuess = playersList[player].guess;
    int mobGuessesGuess = playersList[mobGuess].guess;

    if(!removedPlayers.count(playersList[player].guess)) {
        --playersList[mobGuessesGuess].numOfEnemies;
        removedPlayers.insert(playersList[player].guess);

        recurseMob(mobGuessesGuess);
    }

    removedPlayers.insert(player);
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int n;
        cin >> n;
        playersList.push_back(Player({n-1, 0}));
    }

    for(int i = 0; i < playersList.size(); i++){
        playersList[playersList[i].guess].numOfEnemies = playersList[playersList[i].guess].numOfEnemies + 1;
    }

    for(int i = 0; i < playersList.size(); i++){
        recurseMob(i);
    }

    cout << mobCount + floor(double(n - removedPlayers.size()) / 2.0);
    return 0;
}
