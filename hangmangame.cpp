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
    vector<char> wrongguess;
    string n,word,y="";
    int results=0,counter=0,x,g,c,m;

    hangman(){
    srand(time(0));
    g=rand()%wordlist.size();
    word=wordlist[g];
    x=word.size();
    static int i;
    for(i=0;i<x;i++)
    found.push_back('_');
    cout<<"     You are most Welcome in hangman game!\n";
    cout<<"     \n\nHangman Game tips and procedure: \n    There is a word that is hidden and that word has letters in 27 letters (A-Z).\n    The hangman game is all about to guess the letter in that word,\n    So it's only allowed to insert only one letter! with 15 guesses per word Goodluck!!\n\nGame start now..............\n\n  ";
    cout<<"Choose level you want to play on\n 1.Easy 20 guesses/word \n 2.Medium 15 guesses/word \n 3.Hard 10 guesses/word\n\nEnter your choice:";
    cin>>c;
    m=(c==1)?20:((c==2)?15:10);
    }

    void userinput(){
        cout<<"\nEnter one character in range(A-Z):";
        cin>>n;
        if((n.size()==1&&isalpha(n[0]))&&(!isspace(n[0]))&&(!isdigit(n[0])))
            {
            cout<<"\n";
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
        if(results==0){
                wrongguess.push_back(n[0]);
                counter++;
            }
    }

    void output(){
        if (results==1){
            cout<<"\nYou Guessed collect!!\n\n\n    ";
            for(auto w:found)
            {
                cout<<w<<" ";
            }
            cout<<"\n\nYour incorrect guesses: ";
            for(auto w:wrongguess)
            {
                cout<<w<<" ";
            }
            cout<<"\n\nYou have "<<(m-counter)<<" Guess remain?, Good Luck!\n\n";
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
                cout<<"\nThe correct word was: "<<word;
                reset();
                }
        }
        else if(results==0){
            if(counter<=15)
            {
            cout<<"\nYour guess is not correct!!\n\n\n    ";
            for(auto w:found)
            {
                cout<<w<<" ";
            } 
            cout<<"\n\nYour incorrect guesses:";
            for(auto w:wrongguess)
            {
                cout<<w<<" ";
            }
            cout<<"\n\nYou have "<<(m-counter)<<" Guess remain?, Good Luck!\n\n"; 
            }
        }
    }    
    void reset(){
        if(counter==m){
        cout<<"\n\nYou are out of Guess!!!!\n\n";
        cout<<"\nThe correct word was: "<<word;
        }
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
        y='\0';//initializing
        srand(time(0));
        g=rand()%wordlist.size();
        word=wordlist[g];
        x=word.size();
        found.clear();
        for(int i=0;i<x;i++)
        found.push_back('_');
        cout<<"     You are most Welcome in hangman game!\n";
        cout<<"     \n\nHangman Game tips and procedure: \n    There is a word that is hidden and that word has letters in 27 letters (A-Z).\n    The hangman game is all about to guess the letter in that word,\n    So it's only allowed to insert only one letter! with 15 guesses per word Goodluck!!\n\n    Game start now..............\n\n  ";
        cout<<"Choose level you want to play on\n 1.Easy 20 guesses/word \n 2.Medium 15 guesses/word \n 3.Hard 10 guesses/word\n\nEnter your choice:";
        cin>>c;
        m=(c==1)?20:((c==2)?15:10);
    }
};
int main(){
    hangman wlist;
    for(int a=0;a==0;a)
    {
    wlist.userinput();
    wlist.checking();
    wlist.output();
    if(wlist.y[0]=='n'||wlist.y[0]=='N')
                {
                    cout<<"\n\nThanks for playing the game!!";
                    break;
    }
    if(wlist.counter==wlist.m)
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

