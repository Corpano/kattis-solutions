#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Player{
public:
    long guess;
    long numOfEnemies;
    bool removed = false;
    int circleType = -1;
};

int mobCount = 0;
vector<Player> playersList;

bool isPlayerRemoved(int player){
    return playersList[player].removed;
}

void removePlayer(int player){
    playersList[player].removed = true;
}

void recurseMob(int player){
    if(isPlayerRemoved(player) || playersList[player].numOfEnemies > 0)
        return;

    // We found mob
    ++mobCount;

    int mobGuess = playersList[player].guess;
    int mobGuessesGuess = playersList[mobGuess].guess;

    if(!isPlayerRemoved(playersList[player].guess)) {
        --playersList[mobGuessesGuess].numOfEnemies;
        removePlayer(playersList[player].guess);

        recurseMob(mobGuessesGuess);
    }

    removePlayer(player);
}

// Finds all circular groups and updates types of players
map<int, int> circularPlayerGroups;
void recurseCircle(int player, int circleType){
    if(playersList[player].circleType == -1 && !isPlayerRemoved(player)){
        playersList[player].circleType = circleType;

        if(circularPlayerGroups.count(circleType)){
            ++circularPlayerGroups[circleType];
        }else{
            circularPlayerGroups[circleType] = 1;
        }

        recurseCircle(playersList[player].guess, circleType);
    }
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

    // Takes care of remaining "circular" connected nodes in graph
    int currCircleType = 0;
    for(int i = 0; i < playersList.size(); i++){
        if(!isPlayerRemoved(i))
        {
            recurseCircle(i, currCircleType);
            ++currCircleType;
        }
    }
    int extraMobs = 0;
    for(auto c : circularPlayerGroups){
        extraMobs += floor(c.second / 2.0);
    }

    cout << mobCount + extraMobs;
    return 0;
}
