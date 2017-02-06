#include<iostream>
#include<string>
#include<random>
#include<stdio>
#include<ctime>
#include<vector>
using namespace std;

default_random_engine randfuncgen(time(NULL));
uniform_int_distribution<int> number(0, 100);

//prototypes 
void fetchBoard(string board[20][20]);
void drawBoard(string board[20][20], unsigned rows, unsigned columns);

void gameIteration(string board[20][20], unsigned rows, unsigned columns, unsigned & turn);

int main(){

	string name;
	unsigned int _rows=0, _columns=0;
	unsigned int turn=0;
	
	string board[20][20];
	

	printf("Welcome %s\nLet us enjoy TicTacToe\n", name.c_str());;
	_getch();
	cout << "How many rows do you want in the game? ";
	cin >> _rows;
	cout << "How many columns do you want in the game? ";
	cin >> _columns;
	if (_rows* _columns < 6){
		cout << " Creating a game ain't possible;\n";
	}
	else{
		fetchBoard(board);
		drawBoard(board, _rows, _columns);
		gameIteration(board, _rows, _columns ,turn);
	}


	system("PAUSE");
	return 0;
}


void fetchBoard(string board[20][20]){

	for (unsigned i = 0; i < 20; i++){
		for (unsigned j = 0; j < 20; j++){
			board[i][j] = '.';
		}
	}
}
void drawBoard(string board[20][20], unsigned rows, unsigned columns){
	cout << " ";
	for (unsigned k = 0; k < columns; k++){
		if (k == columns - 1){
			cout << "| " << k + 1 << " |";
		}
		else{
			cout << "| " << k + 1 << " ";
		}
	}
	cout << endl;
	for (unsigned i = 0; i <columns; i++){
		cout << "----";
	}

	cout << endl;
	for (unsigned i = 0; i < rows; i++){
		cout << (i+1)%10;
		for (unsigned j = 0; j < columns; j++){
			if (j == columns - 1){
				cout <<  "| " << board[i][j] << " |";
			}
			else{
				cout << "| " << board[i][j] << " ";

			}

		}
		cout << endl;
		for (unsigned i = 0; i <columns; i++){
			cout << "----";
		}

		cout << endl;
	}
}
void addSuspects(string board[20][20],unsigned tactic[20][20], int x, int y, unsigned rows, unsigned columns){
	if (x - 2 >= 0){
		//4
		if (board[y][x - 2] == "."){
			tactic[y][x - 2]++;
		}
		if (y - 2 >= 0){
			//7
			if (board[y - 2][x - 2] == "."){
				tactic[y - 2][x - 2]++;
			}
			//8
			if (board[y - 2][x] == "."){
				tactic[y - 2][x]++;
			}
		}
		if (y + 2 >= 0){
			//1
			if (board[y + 2][x - 2] == "."){
				tactic[y + 2][x - 2]++;
			}
			//2
			if (board[y + 2][x] == "."){
				tactic[y + 2][x]++;
			}
		}
	}
	if (x + 2 < columns){
		//6
		if (board[y][x + 2] == "."){
			tactic[y][x + 2]++;
		}
		if (y + 2 < rows){
			//3
			if (board[y + 2][x + 2] == "."){
				tactic[y + 2][x + 2]++;
			}
		}
		if (y - 2 < rows){
			//9
			if (board[y - 2][x + 2] == "."){
				tactic[y - 2][x + 2]++;
			}
		}
	}
}
void second(string board[20][20], unsigned tactic[20][20], unsigned rows, unsigned columns){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			if (board[i][j] == "O"){
			
				addSuspects(board, tactic, j, i, rows, columns);
			}
		}
	}

}
void AI(string board[20][20], unsigned tactic[20][20], unsigned rows, unsigned columns, unsigned turn){
	
	unsigned defense = 2, attack = 1;
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){

			
			if (board[i][j] != "."){

				//CHECKING 1 MOVE FURTHER, NUMPAD
				
				//7-Key
				if (i - 2 >= 0 && j - 2 >= 0){
					if (board[i][j] == board[i - 1][j - 1]){
						if (board[i - 2][j - 2] == "."){
							if (board[i][j] == "X"){

								tactic[i - 2][j - 2] += attack;
							}
							else
								tactic[i - 2][j - 2] += defense;
						}
					}
					if (board[i][j] == board[i - 2][j - 2]){
						if (board[i - 1][j - 1] == "."){
							if (board[i][j] == "X"){

								tactic[i - 1][j - 1] += attack;
							}
							else
								tactic[i - 1][j - 1] += defense;
						}
					}
				}
				
				//8-Key
				if (i - 2 >= 0){
					if (board[i][j] == board[i - 1][j]){
						if (board[i - 2][j] == "."){
							if (board[i][j] == "X"){

								tactic[i - 2][j] += attack;
							}
							else
								tactic[i - 2][j] += defense;
						}

					}
					if (board[i][j] == board[i - 2][j]){
						if (board[i - 1][j] == "."){
							if (board[i][j] == "X"){

								tactic[i - 1][j] += attack;
							}
							else
								tactic[i - 1][j] += defense;
						}

					}

				}
				

				//9-Key

				if (i - 2 >= 0 && j + 2 < columns){
					if (board[i][j] == board[i - 1][j + 1]){
						if (board[i - 2][j + 2] == "."){
							if (board[i][j] == "X"){

								tactic[i - 2][j + 2] += attack;
							}
							else
								tactic[i - 2][j + 2] += defense;
						}

					}
					if (board[i][j] == board[i - 2][j + 2]){
						if (board[i - 1][j + 1] == "."){
							if (board[i][j] == "X"){

								tactic[i - 1][j + 1] += attack;
							}
							else
								tactic[i - 1][j + 1] += defense;
						}

					}
				}
				
				//4-Key
				if (j - 2 >= 0){
					if (board[i][j] == board[i][j - 1]){
						if (board[i][j - 2] == "."){
							if (board[i][j] == "X"){

								tactic[i][j - 2] += attack;
							}
							else
								tactic[i][j - 2] += defense;
						}
					}
					if (board[i][j] == board[i][j - 2]){
						if (board[i][j - 1] == "."){
							if (board[i][j] == "X"){

								tactic[i][j - 1] += attack;
							}
							else
								tactic[i][j - 1] += defense;
						}
					}
				}

				
				
				//6-Key
				if (j + 2 < columns){
					if (board[i][j] == board[i][j + 1]){
						if (board[i][j + 2] == "."){
							if (board[i][j] == "X"){

								tactic[i][j + 2] += attack;
							}
							else
								tactic[i][j + 2] += defense;
						}

					}
					if (board[i][j] == board[i][j + 2]){
						if (board[i][j + 1] == "."){
							if (board[i][j] == "X"){

								tactic[i][j + 1] += attack;
							}
							else
								tactic[i][j + 1] += defense;
						}

					}
				}
				

				//1-Key
				if (i + 2 < rows && j - 2 >= 0){
					if (board[i][j] == board[i + 1][j - 1]){
						if (board[i + 2][j - 2] == "."){
							if (board[i][j] == "X"){

								tactic[i + 2][j - 2] += attack;
							}
							else
								tactic[i + 2][j - 2] += defense;
						}


					}
					if (board[i][j] == board[i + 2][j - 2]){
						if (board[i + 1][j - 1] == "."){
							if (board[i][j] == "X"){

								tactic[i + 1][j - 1] += attack;
							}
							else
								tactic[i + 1][j - 1] += defense;
						}


					}
				}
				

				//2-Key
				if (i + 2 < rows){
					if (board[i][j] == board[i + 1][j]){
						if (board[i + 2][j] == "."){
							if (board[i][j] == "X"){

								tactic[i + 2][j] += attack;
							}
							else
								tactic[i + 2][j] += defense;

						}
					}
					if (board[i][j] == board[i + 2][j]){
						if (board[i + 1][j] == "."){
							if (board[i][j] == "X"){

								tactic[i + 1][j] += attack;
							}
							else
								tactic[i + 1][j] += defense;

						}
					}
				}
				

				//3
				if (i + 2 < rows && j + 2 < columns){
					if (board[i][j] == board[i + 1][j + 1]){
						if (board[i + 2][j + 2] == "."){
							if (board[i][j] == "X"){
								tactic[i + 2][j + 2] += attack;
							}
							else
								tactic[i + 2][j + 2] += defense;
						}

					}
					if (board[i][j] == board[i + 2][j + 2]){
						if (board[i + 1][j + 1] == "."){
							if (board[i][j] == "X"){
								tactic[i + 1][j + 1] += attack;
							}
							else
								tactic[i + 1][j + 1] += defense;
						}

					}
				}

			}
		}
	}


}
void setPos(string board[20][20],unsigned tactic[20][20], int  &x, int &y, unsigned rows, unsigned columns){

	int posx = 0, posy = 0;
	for (unsigned i = 0; i < 20; i++){
		for (unsigned j = 0; j < 20; j++){
			if (tactic[posy][posx] < tactic[i][j]){
				posx = j;
				posy = i;
			}
		}
	}
	if (tactic[posy][posx] > 0){
		x = posx; 
		y = posy;
	}
	else{
		do{

			x = number(randfuncgen) % columns;
			y = number(randfuncgen) % rows;
		} while (board[y][x] != ".");
	}

	for (unsigned i = 0; i < 20; i++){
		for (unsigned j = 0; j < 20; j++){
			tactic[i][j] = 0;
		}
	}
}

bool gameOver(string Board[20][20], unsigned rows, unsigned columns, unsigned turn, unsigned  turns)
{

	if (turn == turns)
		return true;

	if (turn <5)
		return false;

	unsigned vart = 0;

	for (unsigned i = 0; i<rows; i++)
	{
		for (unsigned j = 0; j< columns; j ++)
		{
			if (vart == 0 && (Board[i][j] == "X" || Board[i][j] == "O"))
			{
				vart++;
				continue;
			}
			if (vart == 1 && (Board[i][j] == "X" || Board[i][j] == "O"))
			{
				vart++;
				continue;
			}
			if (Board[i][j] == "X" || Board[i][j] == "O")
			{
				if (vart == 2 && Board[i][j - 1] == Board[i][j] && Board[i][j] == Board[i][j + 1] && Board[i][j - 2] == Board[i][j] && Board[i][j + 2] == Board[i][j])
					return true;
				else
					vart = 0;
			}
			else
				vart = 0;
		}
		vart = 0;
	}
	//	cout << endl <<"post";
	//	getch();
	//pionowo
	for (unsigned i = 0; i< columns; i += 1)
	{
		vart = 0;
		for (unsigned j = 0; j< rows -1 ; j += 1)
		{
			if (vart == 0 && (Board[j][i] == "X" || Board[j][i] == "O"))
			{
				vart++;
				continue;
			}
			if (vart == 1 && (Board[j][i] == "X" || Board[j][i] == "O"))
			{
				vart++;
				continue;
			}
			if (Board[j][i] == "X" || Board[j][i] == "O")
			{
				if (vart == 2 && Board[j - 1][i] == Board[j][i] && Board[j - 2][i] == Board[j][i] && Board[j][i] == Board[j + 1][i] && Board[j][i] == Board[j + 2][i])
					return true;
				else
					vart = 0;
			}
			else
				vart = 0;
		}
	}
	//	cout << endl <<"pionowo";
	//	getch();
	//prawy skos dol
	unsigned Xposition, Yposition;

	for (unsigned i = 0; i<rows-1; i += 1)
	{
		vart = 0;
		Xposition = 0;
		Yposition = i;
		while (Yposition<rows - 1 && Xposition<columns - 1)
		{
			if (vart == 0 && (Board[Yposition][Xposition] == "X" || Board[Yposition][Xposition] == "O"))
			{
				vart++;
				Yposition += 1;
				Xposition += 1;
				continue;
			}if (vart == 1 && (Board[Yposition][Xposition] == "X" || Board[Yposition][Xposition] == "O"))
			{
				vart++;
				Yposition += 1;
				Xposition += 1;
				continue;
			}
			if (Board[Yposition][Xposition] == "X" || Board[Yposition][Xposition] == "O")
			{
				if (vart == 2 
					&& Board[Yposition - 1][Xposition - 1] == Board[Yposition][Xposition]
					&& Board[Yposition - 2][Xposition - 2] == Board[Yposition][Xposition]
					&& Board[Yposition + 1][Xposition + 1] == Board[Yposition][Xposition]
					&& Board[Yposition + 2][Xposition + 2] == Board[Yposition][Xposition])
					return true;
				else
					vart = 0;
			}
			else
			{
				vart = 0;
				Yposition += 1;
				Xposition += 1;
			}
		}
		vart = 0;
	}
	//	cout << endl << " prawy skos dol";
	//	getch();

	for (unsigned i = 0; i<columns - 2; i += 1)
	{
		vart = 0;
		Yposition = 0;
		Xposition = i;
		while (Yposition<rows - 2 && Xposition<columns - 2)
		{
			if (vart == 0 && (Board[Yposition][Xposition] == "X" || Board[Yposition][Xposition] == "O"))
			{
				vart++;
				Yposition += 1;
				Xposition += 1;
				continue;
			}
			if (vart == 1 && (Board[Yposition][Xposition] == "X" || Board[Yposition][Xposition] == "O"))
			{
				vart++;
				Yposition += 1;
				Xposition += 1;
				continue;
			}
			if (Board[Yposition][Xposition] == "X" || Board[Yposition][Xposition] == "O")
			{
				if (vart == 2
					&& Board[Yposition - 1][Xposition - 1] == Board[Yposition][Xposition]
					&& Board[Yposition - 2][Xposition - 2] == Board[Yposition][Xposition]
					&& Board[Yposition + 1][Xposition + 1] == Board[Yposition][Xposition]
					&& Board[Yposition + 2][Xposition + 2] == Board[Yposition][Xposition])
					return true;
				else
					vart = 0;
			}
			else
			{
				vart = 0;
				Yposition += 1;
				Xposition += 1;
			}
		}
	}

	//	getch();

	for (unsigned i = 0; i<rows - 1; i += 1)
	{
		vart = 0;
		Xposition = rows-1;
		Yposition = i;
		while (Yposition<rows - 1 && Xposition>2)
		{
			if (vart == 0 && (Board[Yposition][Xposition] == "X" || Board[Yposition][Xposition] == "O"))
			{
				vart++;
				Yposition += 1;
				Xposition -= 1;
				continue;
			}if (vart == 1 && (Board[Yposition][Xposition] == "X" || Board[Yposition][Xposition] == "O"))
			{
				vart++;
				Yposition += 1;
				Xposition -= 1;
				continue;
			}
			if (Board[Yposition][Xposition] == "X" || Board[Yposition][Xposition] == "O")
			{
				if (vart == 2 
					&& Board[Yposition - 1][Xposition + 1] == Board[Yposition][Xposition]
					&& Board[Yposition - 2][Xposition + 2] == Board[Yposition][Xposition]
					&& Board[Yposition + 1][Xposition - 1] == Board[Yposition][Xposition]
					&& Board[Yposition + 2][Xposition - 2] == Board[Yposition][Xposition])
					return true;
				else
					vart = 0;
			}
			else
			{
				vart = 0;
				Yposition += 1;
				Xposition -= 1;
			}
		}
	}




	for (unsigned i = rows - 1; i>0; i -= 1)
	{
		vart = 0;
		Yposition = 0;
		Xposition = i;
		while (Yposition<rows - 1 && Xposition<columns - 1)
		{
			if (vart == 0 && (Board[Yposition][Xposition] == "X" || Board[Yposition][Xposition] == "O"))
			{
				vart++;
				Yposition += 1;
				Xposition -= 1;
				continue;
			}
			if (vart == 1 && (Board[Yposition][Xposition] == "X" || Board[Yposition][Xposition] == "O"))
			{
				vart++;
				Yposition += 1;
				Xposition -= 1;
				continue;
			}
			if (Board[Yposition][Xposition] == "X" || Board[Yposition][Xposition] == "O")
			{
				if (vart == 2 
					&& Board[Yposition - 1][Xposition + 1] == Board[Yposition][Xposition]
					&& Board[Yposition - 2][Xposition + 2] == Board[Yposition][Xposition]
					&& Board[Yposition + 1][Xposition - 1] == Board[Yposition][Xposition]
					&& Board[Yposition + 2][Xposition - 2] == Board[Yposition][Xposition])
					return true;
				else
					vart = 0;
			}
			else
			{
				vart = 0;
				Yposition += 1;
				Xposition -= 1;
			}
		}
	}
	//cout << endl << " LEWO SKOS DOL";
	//	getch();

	return false;
}
void gameIteration(string board[20][20], unsigned rows, unsigned columns, unsigned & turn){
	bool good = true;
	vector<string> words;
	unsigned vart = 0; 
	string T = "";

	//fill T to random solve in order to mix it later
	/*for (unsigned i = 0; i < rows*columns; i++){
		if (i % 2 == 0){
			T += "O";
		}
		else{
			T += "X";
		}
	}
	double time = 1;

	for (unsigned i = 2; i < rows*columns; i++)
		time *= i;
	
	printf("w8 Im thinking, It will take about %f seconds", time/10000000);
	permutacje(words, T, 0, rows*columns, vart);

	out(words);
	_getch();*/
	
	int x, y;
	unsigned tactic[20][20], tactic2[200];

	//initialize tactic boards


	for (unsigned i = 0; i < rows*columns; i++){
		tactic2[i] = 0;
	}
	for (unsigned i = 0; i < 20; i++){
		for (unsigned j = 0; j < 20; j++){
			tactic[i][j] = 0;
			
		}
	}
	system("cls");
	drawBoard(board, rows, columns);
	
	while (gameOver(board,rows, columns, turn,rows*columns)==false) {
		
		if (turn % 2 == 0){
			do{

				good = true;
				cout << "\nEnter X coordinate ! :";
				cin >> x;
				if (x<1 || x > columns){
					cout << "\nwrong input !";
					good = false;
					continue;
				}
				cout << "\nEnter Y coordinate ! :";
				cin >> y;
				if (y<1 || y > rows){
					cout << "\nwrong input !";
					good = false;
					continue;
				}
				if (board[y - 1][x - 1] == ".")
					good = true;
				else{
					cout << "\n This place is already taken !"<<endl;
					good = false;
				}
			} while (good == false);

			board[y - 1][x - 1] = "O";

			system("cls");
			drawBoard(board, rows, columns);
			turn++;
		}
		else{
			if (turn == columns * rows)
				break;
			AI(board, tactic, rows, columns, turn);

			setPos(board, tactic, x, y, rows, columns);
			cout << endl << "settinsg at " << x + 1 << " , " << y + 1 << endl;
			_getch();
			board[y][x] = "X";

			turn++;
			system("cls");
			drawBoard(board, rows, columns);
		}
		
		

	}
	cout << "\n GAME IS CONCLUDED!"<<endl;
	

}
