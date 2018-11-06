#include<iostream>
using namespace std;

#define N 4

int board[N][N];
int colcheck[N];
int d1check[N+3];
int d2check[N+3];   //principal diagnol

void print()
{
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

bool isSafe(int row, int col)
{
    if(colcheck[col]!=0) return false;
    if (d1check[row+col]!=0)  return false;
    if(d2check[row-col+N-1]!=0)return false;
    return true;
}


void solve(int r)
{
    if(r==N)
   {    print();
        return ;
   }

    for(int c=0;c<N;c++)
    {
        if(isSafe(r,c))
            { board[r][c]= 1;

              colcheck[c]=1;
              d1check[r+c]=1;
              d2check[r-c+N-1]=1;

              solve(r+1);               //recursive call to place queen in the next row

              board[r][c]=0;
              colcheck[c]=0;            //folding back if no valid space
              d1check[r+c]=0;
              d2check[r-c+N-1]=0;

            }

    }
}

int main()
{
    cout<<"N-Queen's Problem for N="<<N<<endl;
    solve(0);
}


