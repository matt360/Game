#pragma once
#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "Defines.h"
#include "Board.h"
#include "GenericPlayer.h"
#include "Player.h"

class Game
{
public:
    Game();
	~Game();

    void Play(const std::vector<GenericPlayer*>& players); //Plays the game of darts
private:
    std::size_t _currentPlayer;
    std::vector<GenericPlayer*> _players;
    Board *_pBoard = new Board;
    GenericPlayer* GetCurrentPlayer();
    GenericPlayer* NextPlayer();
    GenericPlayer* WhoFirst();
    
    void PushNames(uint16_t numPlayers, std::vector<std::string> names);
    uint16_t SetNumPlayers();
        
	int16_t CheckWinningPosition(GenericPlayer* player, Board* board);
    void PlayNineDartFinish();
    void Throw3Darts(GenericPlayer* player, Board* board);
    void CheckBusted(GenericPlayer* player, uint16_t temp);
    void DisplayEndGame(std::size_t winnerIndex);
    
	void DisplayInstructions();
    
    uint16_t _newScore = 501;
    int16_t _temp = 0;
    int16_t _simulateCounter = 0;
    const std::vector<std::string>& _names;
};

//	uint8_t _choice = 0;
//	bool _fail = false;
#endif