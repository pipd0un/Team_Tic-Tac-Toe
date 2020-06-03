#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class TicTacToe
{
	friend void analyse(TicTacToe& table);
	friend void markTable(TicTacToe& table,int square);
	friend int checkMate(TicTacToe& table);
	friend void startGame(TicTacToe& table);
	public :
		TicTacToe()
		{
			turn =1;
			cout<<"\nGame Board Created"<<endl;
			for (int i=0;i<16;i++)
			{
				square[i] = to_string(i+1); // sets all square's numbers
				sqsign[i] = 1; // sets all squares signable 
			}
		}
		TicTacToe operator=(TicTacToe& table)
		{
			return *this; // This is needed for temp games and its winning calculation
		}
		void instruction()
		{
			cout<<"\nThe Table's signature lineup is as like as : \n";
			cout<<"\t\t.__.\t\t.__.\t\t.__.\t\t.__.\n";
			cout<<"\t\t| 1|\t\t| 2|\t\t| 3|\t\t| 4|\n";
			cout<<"\t\t ** \t\t ** \t\t ** \t\t ** \n";
			cout<<"\t\t.__.\t\t.__.\t\t.__.\t\t.__.\n";
			cout<<"\t\t| 5|\t\t| 6|\t\t| 7|\t\t| 8|\n";
			cout<<"\t\t ** \t\t ** \t\t ** \t\t ** \n";
			cout<<"\t\t.__.\t\t.__.\t\t.__.\t\t.__.\n";
			cout<<"\t\t| 9|\t\t|10|\t\t|11|\t\t|12|\n";
			cout<<"\t\t ** \t\t ** \t\t ** \t\t ** \n";
			cout<<"\t\t.__.\t\t.__.\t\t.__.\t\t.__.\n";
			cout<<"\t\t|13|\t\t|14|\t\t|15|\t\t|16|\n";
			cout<<"\t\t ** \t\t ** \t\t ** \t\t ** \n";
			cout<<"\nSo whenever your turn comes you just should enter the cell number which you choose to mark !\n\n";
		}
		void setSymbol() // it sets symbol of the player that will play 
		{
			if ( turn % 4 == 1)
			{
				symbol = "X";
			}
			else if ( turn % 4 == 2)
			{
				symbol = "O";
			}
			else if ( turn % 4 == 3)
			{
				symbol = "x";
			}
			else if ( turn % 4 == 0)
			{
				symbol = "o";
			}
		}
		string getSymbol() // it returns symbol of the player that will play 
		{
			return symbol;
		}
		void nextTurn() // when a player signs truely it counts the turn
		{
			turn++;
		}
		void callTable() // shows the table of its last status
		{
			system("cls");
		    cout << "\n\n\t\t\t\t     Tic Tac Toe\n\n";
		    cout << "\t\t\t    TEAM-A               TEAM-B"	  << endl;
		    cout << "\t\t\t   Player 1 (X)  ||  Player 2 (O)" << endl;
		    cout << "\t\t\t   Player 3 (x)  ||  Player 4 (o)" << endl<<endl;
		    cout << endl;
			cout<<"\n\n\n";
			for(int i =0;i<16;i++)
			{
				cout<<"\t\t| "<<square[i]<<" |";
				if (i % 4 == 3)
					{
						cout<<"\n\n\n\n";
					}
			}
		}
		string getSquare(int index) // shows the square which player selected
		{
			return square[index-1];
		}
		void sqLock(int sq) // disables square for signature
		{
			sqsign[sq-1] = 0;
		}
		int getTurn() // shows current player's turn
		{
			return turn;
		}
		void sign(int index)  // puts signature , this will be used in markTable()
		{
			square[index-1] = symbol;
		}
		int getSignable(int index); // controls if square is available
		void linearCalc(); // linear ratio of teams signature 
		void columnCalc(); // ''
		void crossCalc();  // ''
	//	void analyse();   // includes xxxCalc() funcs.
	private :
		string square[16];
		int sqsign[16];
		int turn;
		string symbol;
};
void startGame(TicTacToe& table);
int main()
{
	// MAKE GAME
	int sel; // selection temp
	int anl; // answer temp
	int broken = 0; // while loop breaker
	cout<<"Welcome To Team Tic-Tac-Toe game !";
	TicTacToe table;
	while(!broken)
	{
		cout<<"\nEnter the number of selection : ";
		cout<<"\n(1) Instruction";
		cout<<"\n(2) Start";
		cout<<"\n(0) Exit";
		cout<<"\n > ";
		cin>>sel;
		if(sel == 1)
		{
			system("cls");
			table.instruction();
		}
		else if(sel == 2)
		{
			startGame(table);
			cout << "\nDo you want to analysis the table ?"<<endl;
			cout << "(1) Yes" << "\n(2) No" << "\n> ";
			cin >> anl;
			if( anl == 1)
			{
			//	table.analyse();
			//	table.linearCalc();
				analyse(table);
				broken =1;
			}
			else if(anl == 2)
			{
				cout<<"\nSee Ya !"<<endl;
				broken=1;
			}
			
		}
		else if(sel == 0)
		{
			system("cls");
			cout<<"\n\n	See Ya  ...\n\n";
			broken=1;
		}
	}
	system("pause");
	return 0;
}; 
void analyse(TicTacToe& table)
{
	double countx=0;
	double counto=0;
	double crossx[3] = { 0,0,0 };
	double crosso[3] = { 0,0,0 };
	for(int i=1;i<17;i++)
	{
		if ( table.getSquare(i) == "X" || table.getSquare(i) == "x" ) 
		{
			countx++; 
		} 
		else if ( table.getSquare(i) == "O" || table.getSquare(i) == "o" )
		{
			counto++;
		}
	}
	
	for (int i=1;i<17;i+=3)
	{
		if ( table.getSquare(i) == "X" || table.getSquare(i) == "x" )
		{
			crossx[0] ++;
		}
		else if ( table.getSquare(i) == "O" || table.getSquare(i) == "o" )
		{
			crosso[0] ++;
		}
	}
	for ( int i=1;i<17;i+=5 )
	{
		if ( table.getSquare(i) == "X" || table.getSquare(i) == "x" )
		{
			crossx[1] ++;
		}
		else if ( table.getSquare(i) == "O" || table.getSquare(i) == "o" )
		{
			crosso[1] ++;
		}
	}
	crossx[2] = (crossx[0]/8 + crossx[1]/8) / 2; // cross ratio --> x
	crosso[2] = (crosso[0]/8 + crosso[1]/8) / 2; // cross ratio --> o
	cout<<" Team\t| % Line | % Column | % Cross"<<endl;
	cout<<" --------------------------------------------------------"<<endl;
	cout<<"| Xx\t|\t "<<(countx/16)*100<<"\t|\t "<<(countx/16)*100<<"\t|\t "<<crossx[2]*100<<"\t|"<<endl;
	cout<<" --------------------------------------------------------"<<endl;
	cout<<"| Oo\t|\t "<<(counto/16)*100<<"\t|\t "<<(counto/16)*100<<"\t|\t "<<crosso[2]*100<<"\t|"<<endl; 
}
void startGame(TicTacToe& table)
{ 
	int sq; // square number
	char sel1; // selection char 
	int player; // you know what
	int broken=0; // while loop broker
	while(!broken)
	{
		table.callTable(); // shows first screen
		player = table.getTurn()%4;
		switch(player)
		{
			case 1 : cout<<"\t\t  Player 1's turn"<<endl;break;
			case 2 : cout<<"\t\t  Player 2's turn"<<endl;break;
			case 3 : cout<<"\t\t  Player 3's turn"<<endl;break;
			case 0 : cout<<"\t\t  Player 4's turn"<<endl;break;
		}
		cout<<"\t\t  Select a cell number : ";
		cin>>sq;
		table.setSymbol(); // sets players signature symbol
		if(table.getSignable(sq) == 1)
		{
			markTable(table,sq);	// if square is available then signs it
		}
		else if (table.getSignable(sq) == 0)
		{
			cout << "\t\t  This square cant signable ! " << "\n\t\t  Select different square .." << endl;
			system("pause");  // if square is not available warns him/her
		};
		table.callTable();
		if( table.getTurn() >= 7) // controlling starts after 7th turn just because there are any winning possibility after 7th turn
		{
		    int team = table.getTurn()%4;
			if(checkMate(table) == 1)
			{
				if ( team == 2 || team == 0 )
				{
					cout<<"\t\t TEAM A WON !!!";
				}
				else 
				{
					cout<<"\t\t TEAM B WON !!!";
				}
				broken = 1;
			}
			else if(checkMate(table) == -1)
			{
				cout<<"\t\t  Game Over !"<<"\n\t\t  It's DRAW !"<<endl;
				broken = 1;
				system("pause");
			}
		}
	} 
}
TicTacToe::getSignable(int index) // control if it is signable
{
	return sqsign[index-1];
}
void markTable(TicTacToe& table,int square)  // signs a square X,x,O,o if its not signed
{ 
	table.sign(square); // signs it 
	table.sqLock(square); // makes unavailable which it signs
	table.nextTurn(); // then counts turn
}
int checkMate(TicTacToe& table) /// returns winning possibilties or gaming is over
{	
	TicTacToe tempTable = table; // creating temp table makes it easier within making signatures the same
	for(int i =0;i<16;i++)
	{
		if(tempTable.square[i] == "x")
		{
			tempTable.square[i] = "X";
		}
		else if(tempTable.square[i] == "o")
		{
			tempTable.square[i] = "O";
		}
	}
	/// HORIZONTAL WIN
	if(tempTable.square[0] == tempTable.square[1] && tempTable.square[1] == tempTable.square[2] && tempTable.square[2] == tempTable.square[3])
	{
		return 1;
	}
	else if(tempTable.square[4] == tempTable.square[5] && tempTable.square[5] == tempTable.square[6] && tempTable.square[6] == tempTable.square[7])
	{
		return 1;
	}
	else if(tempTable.square[8] == tempTable.square[9] && tempTable.square[9] == tempTable.square[10] && tempTable.square[10] == tempTable.square[11])
	{
		return 1;
	}
	else if(tempTable.square[12] == tempTable.square[13] && tempTable.square[13] == tempTable.square[14] && tempTable.square[14] == tempTable.square[15])
	{
		return 1;
	}
	/// VERTICAL WIN
	else if(tempTable.square[0] == tempTable.square[4] && tempTable.square[4] == tempTable.square[8] && tempTable.square[8] == tempTable.square[12])
	{
		return 1;
	}
	else if(tempTable.square[1] == tempTable.square[5] && tempTable.square[5] == tempTable.square[9] && tempTable.square[9] == tempTable.square[13])
	{
		return 1;
	}
	else if(tempTable.square[2] == tempTable.square[6] && tempTable.square[6] == tempTable.square[10] && tempTable.square[10] == tempTable.square[14])
	{
		return 1;
	}
	else if(tempTable.square[3] == tempTable.square[7] && tempTable.square[7] == tempTable.square[11] && tempTable.square[11] == tempTable.square[15])
	{
		return 1;
	}
	// CROSS WIN
	else if(tempTable.square[0] == tempTable.square[5] && tempTable.square[5] == tempTable.square[10] && tempTable.square[10] == tempTable.square[15])
	{
		return 1;
	}
	else if(tempTable.getTurn() == 17)
	{
		cout << "-1" << endl;
		return -1;
	}
}




