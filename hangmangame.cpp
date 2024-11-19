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
    string n,word;
    char y;
    int results=0,counter=0,x;

    hangman(){
    srand(time(0));
    int g=rand()%wordlist.size();
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
                cout<<w;
            }
            cout<<"\n\nYou have "<<(15-counter)<<" Guess remain?, Good Luck!\n\n";
            results=0;
        }
        else if(results==0){
            if(counter<=15)
            {
            cout<<"\nYou Guessed  not collect!!\n\n\n    ";
            for(auto w:found)
            {
                cout<<w;
            } 
            cout<<"\n\nYou have "<<(15-counter)<<" Guess remain?, Good Luck!\n\n"; 
            }
        }
    }    
    void reset(){
        if(counter==15)
        cout<<"\n\nYou are out of Guess!!!!\n\n";
        cout<<"\n\n Do you want to try again(Y/N):";
        cin>>y;
        if(y=='y'||y=='Y')
        {
            found.clear();
            hangman();
            counter=0;
            results=0;            
        }
    }
};
int main(){
    hangman wlist;
    for(int a=0;a==0;a){
    wlist.userinput();
    wlist.checking();
    wlist.output();
    int p=0,k=0;
        for(auto w:wlist.found)
        {
            if(w!='_')
            k++;
            p++;
        }
        if(k==wlist.word.size()){
            cout<<"\nCongratation!!! You have won the game!!";
            wlist.reset();
        }
        else if(wlist.counter==15)
        {
            wlist.reset();
            if(wlist.y=='n'||wlist.y=='N')
                {
                    cout<<"\n\nThanks for playing the game!!";
                    break;
                }
        }
    }
    return 0;
}

