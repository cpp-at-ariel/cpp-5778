
#include "TicTacToe.h"
#include "Player.h"
#include "Board.h"
#include "Move.h"
#include "Winner.h"

class Loser: public Player {
	public:
		Move play(Board& board) {
			return Move();
		}
};

int main() {
	TicTacToe game(4);       // Initializes a game on a 4x4 board
	Loser loser;             // Creates a player with a lousy strategy
	Winner winner;           // Creates YOUR player, with a winning strategy
	cout << game.run(loser, winner); // returns 0 if the first player wins, 1 if the seccond wins. Hopefully it will print 1 since your player will win.
	cout << game.run(winner, loser); // returns 0 if the first player wins, 1 if the seccond wins. Hopefully it will print 0 since your player will win.
	return 0;
}

