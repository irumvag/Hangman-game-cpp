#include<iostream>
#include<cstring>
#include<ctype.h>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include<stdlib.h>
using namespace std;
class hangman{
    public:
    vector<string> wordlist={"kigali","apple", "banana", "cherry", "date", "elderberry"};
    vector<char> found;
    string n,word,y;
    int results=0,counter=0,x,g;

    hangman(){
    srand(time(0));
    g=rand()%wordlist.size();
    word=wordlist[g];
    x=word.size();
    static int i;
    for(i=0;i<x;i++)
    found.push_back('_');
    cout<<"     You are most Welcome in hangman game!\n";
    cout<<"     \n\nHangman Game tips and procedure: \n    There is a word that is hidden and that word has letters in 27 letters (A-Z).\n    The hangman game is all about to guess the letter in that word,\n    So it's only allowed to insert only one letter! with 15 guesses per word Goodluck!!\n\n    Game start now..............\n\n  ";
    }

    void userinput(){
        cout<<"\nEnter one character in range(A-Z):";
        cin>>n;
        if((n.size()==1&&isalpha(n[0]))&&(!isspace(n[0]))&&(!isdigit(n[0])))
            {
            cout<<"\n loading.....\n";
            counter++;
            }
        else 
            {
                cout<<"\nInvalid input! try again?\n\n";
                userinput();
            }
    }

    void checking(){
        cout<<"\nGuess update, you entered: "<<n<<endl;
        for(int i=0;i<word.size();i++)
        {
            if(word[i]==n[0]){
            found[i]=n[0];  
            results=1;          
            }
        }
    }

    void output(){
        if (results==1){
            cout<<"\nYou Guessed collect!!\n\n\n    ";
            for(auto w:found)
            {
                cout<<w<<" ";
            }
            cout<<"\n\nYou have "<<(15-counter)<<" Guess remain?, Good Luck!\n\n";
            results=0;
            int k=0;
            for(auto w:found)
                {
                if(w!='_')
                    k++;
                }
            if(k==word.size())
                {
                cout<<"\nCongratation!!! You have won the game!!";
                reset();
                }
        }
        else if(results==0){
            if(counter<=15)
            {
            cout<<"\nYou Guessed  not collect!!\n\n\n    ";
            for(auto w:found)
            {
                cout<<w<<" ";
            } 
            cout<<"\n\nYou have "<<(15-counter)<<" Guess remain?, Good Luck!\n\n"; 
            }
        }
    }    
    void reset(){
        if(counter==15)
        cout<<"\n\nYou are out of Guess!!!!\n\n";
        cout<<"\n\n Do you want to play again(Y/N):";
        cin>>y;
        if((y.size()==1&&isalpha(y[0]))&&(!isspace(y[0]))&&(!isdigit(y[0]))&&(y[0]=='n'||y[0]=='N')||(y[0]=='y'||y[0]=='Y'))
            {
            if(y[0]=='y'||y[0]=='Y')
            {
            system("clear");
            resetvariable();            
            }
            }
        else 
            {
                cout<<"\nInvalid input! try again?\n\n";
                reset();
            }
    }
    void resetvariable(){
        counter=0;
        y='\0';
        srand(time(0));
        g=rand()%wordlist.size();
        word=wordlist[g];
        x=word.size();
        found.clear();
        for(int i=0;i<x;i++)
        found.push_back('_');
        cout<<"     You are most Welcome in hangman game!\n";
        cout<<"     \n\nHangman Game tips and procedure: \n    There is a word that is hidden and that word has letters in 27 letters (A-Z).\n    The hangman game is all about to guess the letter in that word,\n    So it's only allowed to insert only one letter! with 15 guesses per word Goodluck!!\n\n    Game start now..............\n\n  ";
    }
};
int main(){
    hangman wlist;
    for(int a=0;a==0;a)
    {
    wlist.userinput();
    wlist.checking();
    wlist.output();
    if(wlist.counter==15)
    {
            cout<<"\n\nYou failed the game!!!\n\n";
            wlist.reset();
            if(wlist.y[0]=='n'||wlist.y[0]=='N')
                {
                    cout<<"\n\nThanks for playing the game!!";
                    break;
                }
    }
    }
    return 0;
}

