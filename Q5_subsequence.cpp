#include <iostream>
#include<cstring>
using namespace std;


int n,m,i;
//n= length of sequence
//m= length of subsequence
//i = counter variable 


int main()
{
    /*
    Objective : To check if the subseqyence entered occurs in sequence inputted in O(m+n) 
    Input : user input of string and substring along with m , n(lengths)
    Return values : None 
    */
    
                //sequence string inputting......
    
    cout<<" Enter length of sequence : ";
    cin>>n;
    string S[n];                            //sequence string
    cout<<"\nInput Sequence S :\n";
    cin.ignore(256,'\n');
    for(i=0 ; i<n ; i++)
    {

        cout<<" S "<<i+1<<" : ";
        getline(cin,S[i]);
    }

                 //subsequence entering.........
    
    cout<<"\nEnter Subsequence length : ";
    cin>>m;
    string s[m];                            //subsequence string 
    cout<<"\nInput Subsequence s :\n";
    cin.ignore(256,'\n');
    for(i=0 ; i<m ; i++)
    {

        cout<<" s "<<i+1<<" : ";
        getline(cin,s[i]);
    }

                 //print sequence and subsequence entered.........
    
    cout<<"\n\nSEQUENCE ENTERED : \n";
    for(i=0;i<n;i++)
    {
        cout<<S[i]<<" , ";
    }
    cout<<"\n\nSUBSEQUENCE ENTERED : \n";
    for(i=0;i<m;i++)
    {
        cout<<s[i]<<" , ";
    }

    
    int j=0;            // to access subsequence elements , j is counter variable
    for(i=0 ; i<n ; i++)
    {
        if(s[j].compare(S[i])==0) // string comparison (0 = if equal)
           {j++;}
    }

    
    if(j==m)            //subsequence completely traversed
    {
        cout<<"\n\nSubsequence is present !!!";
    }
    else if (j==0 || j<m)
       cout<<"\n\nSubsequence is not present !!!";

    return 0;
}



