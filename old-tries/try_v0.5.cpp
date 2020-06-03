#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class TicTacToe
{
	friend int  checkMate(TicTacToe &table);
	friend void callTable(TicTacToe &table);
	friend void startGame(TicTacToe &table);
	friend void PrintRes(TicTacToe &table,int checkMateRes);
	friend void markTable(TicTacToe &table,int cell);
	public :
		TicTacToe()
		{
			// DEFAULT; 
			cout<<"\nGame Board Created !"<<endl;
			turn = 1;
		}
		TicTacToe operator=(TicTacToe& table)
		{
			return *this;
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
		void analyse();
		void linearCalc();
		void nextTurn()
		{
			turn++;
		}
	    int getTurn()
	    {
	    	return turn;
		}
		string getSquare(int index)
		{
			return square[index];
		}
		void columnCalc();
		void crossCalc();
	private :
		string square[16] = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16"};
		double linearRatio[2]; // [0] -> X's  [1] -> O's
		double columnRatio[2];
		double crossRatio[2];
		int turn;
};
int main()
{
	// MAKE GAME
	int sel,broken = 0,anl;
	char sel1;
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
			cout<<"(1) Yes"<<"\n(2) No"<<"\n> "<<endl;
			cin >> anl;
			if( anl == 1)
			{
				table.analyse();
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
void TicTacToe::analyse()
{ 
	linearCalc();
	columnCalc();
	crossCalc();
	cout<<" Team\t| % Line | % Column | % Cross"<<endl;
	cout<<" ------------------------------------------"<<endl;
	cout<<"| Xx\t|\t "<<100*linearRatio[0]<<"\t|\t "<<100*columnRatio[0]<<"\t|\t "<<100*crossRatio[0]<<"\t|"<<endl;
	cout<<" ------------------------------------------"<<endl;
	cout<<"| Oo\t|\t "<<100*linearRatio[1]<<"\t|\t "<<100*columnRatio[1]<<"\t|\t "<<100*crossRatio[1]<<"\t|"<<endl; 
}
void TicTacToe::crossCalc()
{
	int tempx=0,tempo=0;
	double crossX[2];
	double crossO[2];
	for(int i=0;i<4;i++)
	{
		if( square[(5*i - 5)] == "x" || "X")
		{
			tempx++;
		}
		else if( square[(5*i - 5)] == "o" || "O")
		{
			tempo++;
		}
	}
	crossX[0] = tempx;
	crossO[0] = tempo;
	tempx=0,tempo=0;
	for(int i=0;i<4;i++)
	{
		if( square[(3*i)] == "x" || "X")
		{
			tempx++;
		}
		else if( square[(3*i)] == "o" || "O")
		{
			tempo++;
		}
	}
	crossX[1] = tempx;
	crossO[1] = tempo;
	crossRatio[0] = (crossX[0]/4 + crossX[1]/4)/2;
	crossRatio[1] = (crossO[0]/4 + crossO[1]/4)/2;
}
void TicTacToe::columnCalc()
{
	int tempx=0,tempo=0;
	double columnForX[4];
	double columnForO[4];
	double buffx=0,buffo=0;
	for(int j=0;j<4;j++)
	{
		for(int i=0;i<4;i++)
		{
			if( square[(4*i - 4)] == "x" || "X")
			{
				tempx++;
			}
			else if( square[(4*i - 4)] == "o" || "O")
			{
				tempo++;
			}
		}
		columnForX[j] = tempx;
		columnForO[j] = tempo;
	}
	
	for(int i=0;i<4;i++)
	{
		buffx += columnForX[i]/4; 
		buffo += columnForO[i]/4;
	}
	columnRatio[0] = buffx/4;
	columnRatio[1] = buffo/4;
}
void TicTacToe::linearCalc()
{
	int tempx=0,tempo=0;
	double lineForX[4];
	double lineForO[4];
	double buffx=0,buffo=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if( square[j] == "x" || "X")
			{
				tempx++;
			}
			else if( square[j] == "o" || "O")
			{
				tempo++;
			}
		}	
		lineForX[i] = tempx;
		lineForO[i] = tempo;
	}
	for(int i=0;i<4;i++)
	{
		buffx += lineForX[i]/4; 
		buffo += lineForO[i]/4;
	}
	linearRatio[0] = buffx/4;
	linearRatio[1] = buffo/4;
}
void startGame(TicTacToe &table)
{
	int cell,broken=0;
	char sel1;
	while(!broken)
	{
		callTable(table);
		table.getTurn()>4 ? cout<<"\t\t  Player "<<table.getTurn()%4<<"'s turn"<<endl : cout<<"\t\t  Player "<<table.getTurn()<<"'s turn"<<endl;
		cout<<"\t\t  Select a cell number : ";
		cin>>cell;
		markTable(table,cell);
		if(table.getTurn() >= 4)
		{
			PrintRes(table,checkMate(table));
			if(checkMate(table) >= 0)
			{
				broken = 1;
			}
		}
	}
}
void PrintRes(TicTacToe &table,int checkMateRes)
{
	int team = table.getTurn()%4;
	if(checkMateRes > 0)
	{
		team == 1 || 3 ? cout<<"\t\t TEAM A WON !!!" : cout<<"\t\t TEAM B WON !!!";
	}
	else if(checkMateRes == 0)
	{
		cout<<"\t\t  Game Over !"<<"\n\t\t  It's DRAW !"<<endl;
	}
}
void markTable(TicTacToe &table,int cell)
{

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
	callTable(table);
	table.nextTurn();

}
int checkMate(TicTacToe &table)
{
	TicTacToe tempTable = table;
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
	else if(tempTable.getTurn() == 16)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
void callTable(TicTacToe &table)
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
		cout<<"\t\t| "<< table.square[i]<<" |";
		if (i == 3 || i== 7 || i==11 || i==15)
			{
				cout<<"\n\n\n\n";
			}
	}
}
