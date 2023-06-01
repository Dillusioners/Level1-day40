# include <iostream>
# include <ctime>
# include <string>

// function to draw the board
void drawBoard(int array[3][3]){
	int i, j;

	// iterating through the array and printing all the members
	std::cout << "===============\n";
	for(i = 0; i != 3; i++){
		for(j = 0; j != 3; j++){
			std::cout << "| ";
			if(array[i][j] == 0) std::cout << " ";
			else if(array[i][j] == 1) std::cout << "X";
			else if(array[i][j] == 2) std::cout << "O";
			std::cout << " |";
		}
		std::cout << "\n===============\n";
	}
	std::cout << std::endl;
}

// method to apply input to the program
void applyInput(int array[3][3], int choice, bool run, bool isPlayer){
	// running until proper input isnot provided
	while(run){
		// if user choice is between 1 to 3
		if(choice >= 1 && choice <= 3 && array[0][choice - 1] == 0){
			if(isPlayer) array[0][choice - 1] = 1;
			else array[0][choice - 1] = 2; 
			run = false;
		}

		// if user choice is between 4 to 6
		else if(choice >= 4 && choice <= 6 && array[1][choice - 4] == 0){
			if(isPlayer) array[1][choice - 4] = 1;
			else array[1][choice - 4] = 2;
			run = false;
		}

		// if the user choice is between 7 to 9
		else if(choice >= 6 && choice <= 9 && array[2][choice - 7] == 0){
			if(isPlayer) array[2][choice - 7] = 1;
			else array[2][choice - 7] = 2;
			run = false;
		}

		else{
			// if it is the player, asking for another input
			if(isPlayer){
				std::cout << "\nInvalid Choice! Try Again: ";
				std::cin >> choice;
			}
			// if it the bot, generating a new square
			else choice = (rand() % 9) + 1;
		}
	}
}

// method to check if the player has won or not
bool playerWins(int array[3][3]){
	int i, j, count1 = 0, count2 = 0;
	// checking if the player has won horizontally or vertically
	for(i = 0; i != 3; i++){
		count1 = 0;
		for(j = 0; j != 2; j++){
			if(array[i][j] == array[i][j+1] && array[i][j] != 0) count1++;
		}
		if(count1 == 2) return true;
	}

	// checking if the player has won digonally
	for(i = 0; i != 2; i++){
		if(array[i][j] == array[i+1][j] && array[i][j] != 0) count2++;
	}
	if(count2 == 2) return true;
	return false;
}

// main program starts from here
int main(int argc, char const *argv[]){
	srand(time(NULL));

	// clearing the console and declaring variables
	std::string clear;
    #if defined(_WIN32)
        clear = "cls";
    #else
        clear = "clear";
    #endif

	int game[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	}, choice;
	char wantToPlay;
	bool running, win;

	// prologue text
	std::cout << "\n\n\t\tDillusioners Tic Tac Toe Game\n\n\n" 
			  << "\nInstructions:\n\nYou must enter a value between 1 to 9\nwith which your choice will be placed accordingly\n\n"
			  << "1 is top-left, 7 is the bottom-left, 3 is top-right, 9 is bottom-right\nand rest of the values are arranged accordingly\n\n";

	std::cout << "Do you want to play?(Y/n): ";
	std::cin >> wantToPlay;

	// if the user wants to play
	if(wantToPlay == 'y' or wantToPlay == 'Y') running = true;
	else std::cout << "Alright! Closing the program.";

	// running until someone has won
	while(running){
		// clearing the console
		system(clear.c_str());

		// drawing the board
		drawBoard(game);
		// checking if someone has won or not
		win = playerWins(game);
		if(win){std::cout << "You have won the game!"; return 0;}

		// asking for the user choice
		std::cout << "Enter your choice(1-9): ";
		std::cin >> choice;
		if(choice < 1 || choice > 9) continue;

		// applying the user input
		applyInput(game, choice, running, true);
		// generating a random number and applying the bot choice
		choice = (rand() % 9) + 1;
		applyInput(game, choice, running, false);
	}

	return 0;
}
