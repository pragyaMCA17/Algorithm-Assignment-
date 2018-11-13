#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>        //for vector STL
using namespace std;

#define M 20            // number of miles
#define N 4             //number of billboards

int rev[M+1]={};        // initialise revenue array with all 0's
int r[N];               // revenue array
int m[N];               // billboard at miles array
int k=0;                //counter variable


bool can_place(int j)       //j is the mile
{
    
    /*
    Objective: to check if billboard can be found at that mile or not.
    Input : j   : denotes mile 
    Return Value : True/False
    */
    
    if(j==m[k])
        return true;

    return false;

}

//to print billboard positions
void backtrack()
{
     /*
    Objective: to print the final positions selected for billboard from the set of available billboard position set.
    Input : -
    Return Value : None
    */
    
    vector<int> pos;
    for( int i=M ; i>=0; i--)
    {
        if(rev[i]!=rev[i-1])
           {
               pos.push_back(i);
               i=i-5;           // to jump to previous billboard at distance check of 5 mile (given)
           }
    }
    cout<<"\n\nPosition of Billboard will be : \n";
    for(int i=pos.size()-1; i>=0; i--)
    {
        cout<<" Position at mile : " <<pos[i]<<endl;
    }

}

//solving billboard problem
int Billboard()
{
     /*
    Objective: solve for each mjle position .
    Input : None  
    Return Value : final revenue at the end after placing the billboard at optimal positions given the constraint.
    
    APPROACH : rev[i]=max{(rev[i-1],abs(rev[i-6])+r[k])};
    */
    
    for(int i=0;i<=M; i++)
    {
        if (i==0)
            rev[i]=0;

        if(can_place(i))
        {

                rev[i]=std::max(rev[i-1],abs(rev[i-6])+r[k]);           //recurssive condition
                k++;

        }
        else{
            rev[i]=rev[i-1];
        }
    }

    return rev[M];      //revenue generated .
}


int main()
{
    cout<<"**** Billboard Problem ****\n"<<endl;
    cout<<"Miles M ="<<M<<endl;
    cout<<"\nNumber of billboards N= "<<N<<endl;

    //input billboards info ,position and revenue
    for(int b=0;b<N;b++)
    {
        cout<<"\nBillboard position "<<b+1<<" = ";
        cin>>m[b];
        cout<<"Revenue = ";
        cin>>r[b];
    }
    cout<<"\nBillboard valid positions and revenues inserted !!!\n";
    cout<<"Solving....................\n";
    cout<<"\nMaximum revenue is : "<<Billboard();
    backtrack(); // to print the positions of billboard

    return 0;

}
