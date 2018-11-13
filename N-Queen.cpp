#include<iostream>
using namespace std;

#define N 4

int board[N][N];
int colcheck[N];      //col check
int d1check[N+3];  
int d2check[N+3];   //principal diagnol

// to print the board
void print()
{
    /*
    Objective: to print the board with positions of queen marked with 1's
    Input : None
    Return Values : None
    */
    
    cout<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<board[i][j]<<"\t";
        }
        cout<<endl;
    }
}

// check the position to place the queen
bool can_place(int row, int col)
{
    
    /*
    Objective: to check for valid positions on board for queen to be placed without voilating the constraint.
    Input : row     : row number 
            col     : colomn number 
    Return Values : True/false
    */
    
    if(colcheck[col]!=0) return false;
    if (d1check[row+col]!=0)  return false;
    if(d2check[row-col+N-1]!=0)return false;
    return true;
}

//solving ........
void solve(int r)       //r=row number
{
    
    /*
    Objective: Solving for each position and placing the queen , calling the print function at end (r==N)
    Input : r   : row number 
    Return Values : None
    */
    
    if(r==N)
   {    print();
        return ;
   }

    for(int c=0;c<N;c++)
    {
        if(can_place(r,c))
            { board[r][c]= 1;

              colcheck[c]=1;
              d1check[r+c]=1;
              d2check[r-c+N-1]=1;

              solve(r+1);               //recursive call to place queen in the next row

              board[r][c]=0;
              colcheck[c]=0;            //folding back if no valid space
              d1check[r+c]=0;           //folding back if no valid space
              d2check[r-c+N-1]=0;       //folding back if no valid space

            }

    }
}

int main()
{
    cout<<"N-Queen's Problem for N="<<N<<endl;
    solve(0); //starts with 0th row (since array begins from 0)
}


