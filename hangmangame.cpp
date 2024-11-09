#include<iostream>
#include<cstring>
#include<ctype.h>
#include<vector>
using namespace std;
class hangman{
    private:
    char wordlist[10][15]={{'g','a','d'},{'i','r','u','m','v','a'},{'a','n','a','c','l','e','t'}};
    public:
    char n;
    void userinput(){
        cout<<"\nEnter one character in range(A-Z):";
        cin>>n;
        n=toupper(n);
        char n1[2]={n,'\0'};
        int l=strlen(n1);
        cout<<n1<<l;
        if(((isalpha(n))&&(!isspace(n)))&&(l==1))
        {
            cout<<"keep going";
        }
        else{
            cout<<"Invalid input";
            userinput();
        }
    }
};
int main(){
    hangman wordlist;
    int i;
    for(i=0;i==0;)
    {
        wordlist.userinput();
    }
}