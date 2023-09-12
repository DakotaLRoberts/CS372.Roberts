




#include <iostream>
#include "List.hpp" 
#include "Stack.hpp"
using namespace std;
#include <functional>
template <typename T>
int hotpotato(int players, int passes) {
	Stack<T> player ;

	
	for (int i =players; i >= 1; --i) {
		player.push(i);
	}

	int eliminateplayer ;
	while (!player.empty()) {
	
		for (int i = 0; i < passes - 1; ++i) {
			eliminateplayer = player.front();
			player.pop();
			player .push(eliminatePlayer);
		}
		
		eliminateplayer = player.front();
		cout << "Eliminating player number " << eliminateplayer << "from the game" << endl;
		player.pop();
	}

	return eliminateplayer; 
}

int main() {
	int players, passes;
	cout << "Enter the total number of players: ";
	cin >> players;
	cout << "Enter the number of passes: ";
	cin >> passes;
	int winner = hotpotato <int>(players, passes);
	cout << "The winner is player number" << winner << endl;

	return 0;
}



