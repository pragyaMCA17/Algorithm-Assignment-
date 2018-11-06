#include <iostream>
#include<cstring>
using namespace std;
int n,m,i;
int main()
{

    cout<<" Enter length of sequence : ";
    cin>>n;
    string S[n];
    cout<<"\nInput Sequence S :\n";
    cin.ignore(256,'\n');
    for(i=0 ; i<n ; i++)
    {

        cout<<" S "<<i+1<<" : ";
        getline(cin,S[i]);
    }

    //subsequence enter
    cout<<"\nEnter Subsequence length : ";
    cin>>m;
    string s[m];
    cout<<"\nInput Subsequence s :\n";
    cin.ignore(256,'\n');
    for(i=0 ; i<m ; i++)
    {

        cout<<" s "<<i+1<<" : ";
        getline(cin,s[i]);
    }

    //print sequence and subsequence entered....
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

    int j=0;            // to access subsequence elements
    for(i=0 ; i<n ; i++)
    {
        if(s[j].compare(S[i])==0) // string comparison
           {j++;}
    }

    if(j==m)
    {
        cout<<"\n\nSubsequence is present !!!";
    }
    else if (j==0 || j<m)
       cout<<"\n\nSubsequence is not present !!!";

    return 0;
}



