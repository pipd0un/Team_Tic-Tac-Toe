#include <iostream>
using namespace std;

class TicTacToe
{
	friend int checkMate(TicTacToe &table);
	friend void checkWin(TicTacToe &table,int checkRes);
	friend void callTable(TicTacToe &table);
	friend void markTable(TicTacToe &table,int cell);
	public :
		TicTacToe()
		{
			// DEFAULT;
			cout<<"\nGame Board Created !"<<endl;
			turn = 1;
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
		TicTacToe operator ++(int)
		{
	      TicTacToe temp;
	      temp.turn ++;
	      return temp;
	    }
	    int getTurn()
	    {
	    	return turn;
		}
	private :
		string square[16] = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16"};
		int turn;
};
int main()
{
	// MAKE GAME
	int sel,broken = 0,cell;
	cout<<"Welcome To Team Tic-Tac-Toe game !";
	TicTacToe table;
	
	cout<<"\nEnter the number of selection : ";
	cout<<"\n(1) Instruction";
	cout<<"\n(2) Start";
	cout<<"\n(0) Exit";
	cout<<"\n > ";
	cin>>sel;
	if(sel == 1)
	{
		table.instruction();
	}
	else if(sel == 2)
	{
		while(!broken)
		{
			system("cls");
		    cout << "\n\n\t\t\t\t     Tic Tac Toe\n\n";
		    cout << "\t\t\t    TEAM-A               TEAM-B"	  << endl;
		    cout << "\t\t\t   Player 1 (X)  ||  Player 2 (O)" << endl;
		    cout << "\t\t\t   Player 3 (x)  ||  Player 4 (o)" << endl << endl;
		    cout << endl;
			callTable(table);
			cout<<"Player "<<table.getTurn()%4<<"'s turn"<<endl;
			cout<<"Select a cell number : ";
			cin>>cell;
			markTable(table,cell);
			table++;
			if(table.getTurn() >= 4)
			{
				checkWin(table,checkMate(table));
				checkMate(table) > 0 ? broken = 1 : broken = 0;
			}
		}
		
	}
	else if(sel == 0)
	{
		cout<<"See Ya";
	}
	
	return 0;
};
void checkWin(TicTacToe &table,int checkRes)
{
	int team = table.getTurn()%4;
	checkRes > 0 ? team == 1 || 3 ? cout<<" TEAM A WON !!!" : cout<<" TEAM B WON !!!" : cout<<"Conitnue ...";
}
void markTable(TicTacToe &table,int cell)
{
	cout<<table.getTurn()%4<<endl;
	if(table.getTurn()%4 == 1)
	{
		table.square[cell-1] = "X";
	}
	else if(table.getTurn()%4 == 2)
	{
		table.square[cell-1] = "O";
	}
	else if(table.getTurn()%4 == 3)
	{
		table.square[cell-1] = "x";
	}
	else if(table.getTurn()%4 == 0)
	{
		table.square[cell-1] = "o";
	}
}
int checkMate(TicTacToe &table)
{
	for(int i =0;i<16;i++)
	{
		if(table.square[i] == "x")
		{
			table.square[i] = "X";
		}
		else if(table.square[i] == "o")
		{
			table.square[i] = "O";
		}
	}
	/// HORIZONTAL WIN
	if(table.square[0] == table.square[1] && table.square[1] == table.square[2] && table.square[2] == table.square[3])
	{
		return 1;
	}
	else if(table.square[4] == table.square[5] && table.square[5] == table.square[6] && table.square[6] == table.square[7])
	{
		return 1;
	}
	else if(table.square[8] == table.square[9] && table.square[9] == table.square[10] && table.square[10] == table.square[11])
	{
		return 1;
	}
	else if(table.square[12] == table.square[13] && table.square[13] == table.square[14] && table.square[14] == table.square[15])
	{
		return 1;
	}
	/// VERTICAL WIN
	else if(table.square[0] == table.square[4] && table.square[4] == table.square[8] && table.square[8] == table.square[12])
	{
		return 1;
	}
	else if(table.square[1] == table.square[5] && table.square[5] == table.square[9] && table.square[9] == table.square[13])
	{
		return 1;
	}
	else if(table.square[2] == table.square[6] && table.square[6] == table.square[10] && table.square[10] == table.square[14])
	{
		return 1;
	}
	else if(table.square[3] == table.square[7] && table.square[7] == table.square[11] && table.square[11] == table.square[15])
	{
		return 1;
	}
	// CROSS WIN
	else if(table.square[0] == table.square[5] && table.square[5] == table.square[10] && table.square[10] == table.square[15])
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
void callTable(TicTacToe &table)
{
	cout<<"\n\n\n";
	for(int i =0;i<16;i++)
	{
	//	i < 10 ? cout<<"\t\t| "<< table.square[i]<<" |" : 
		cout<<"\t\t| "<< table.square[i]<<" |";
		if (i == 3 || i== 7 || i==11 || i==15)
			{
				cout<<"\n\n\n\n";
			}
	}
}
