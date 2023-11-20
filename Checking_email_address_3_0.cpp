#include<iostream>
#include<string>

std::string inFrontOfTheDog = {"'()\":;<>[]"};
std::string afterTheDog = {"/:;<=_>@[\\]^`"};

bool truthful(std::string mail,std::string exeptions,int start,int end,char from, char to)
{
    for(int i=start; i < end; i++){
        for(int j=0; j <= exeptions.length(); j++){
            if ( mail[i] < from || mail[i] > to || mail[i] == exeptions[j]){
                std::cout << "Input error mail["<<i<<"]:"<< mail[i] << "\n";
                return false;
            }
        }
    }
    return true;
}

int main(){
    std::string mail;   
    std::cout << " Input please your mail : ";
    std::cin >> mail;

bool ok = true;  
    bool dog = false;
    int dog_position = 0;
    for (int i = 0; !dog && i < mail.length(); i++){    //находим собаку и заодно проверяем на "концах"
        if( mail[i] == '@'){
            dog = true;
            dog_position = i;
        }
    }
    if(mail[0] == '@'||mail[mail.length()] == '@'||mail[mail.length()-1] == '@'){
        ok = false; 
        std::cout << "Incorrect input @ ! "<<"\n";
    }
    if(!dog){
        ok=false;
        std::cout << "No sign @ ! "<<"\n";
    }

if (ok){
     for ( int i = 0; i < mail.length();i++){      //проверка условия с точками
      if ( mail.length() < 0 || mail[0] == '.' 
        || mail [i] == '.' && mail [i+1] == '.' 
        || mail[mail.length()] == '.') {
        ok = false;
        std::cout << "Incorrect point entry ! "<<"\n";
        }

    if(dog_position > 64 || (mail.length() - (dog_position+1)) > 63){ //условие на максимум знаков
        ok = false;
        std::cout<< "The address is too long ! "<< ok << "\n";
        }

    if(ok) ok = truthful(mail,inFrontOfTheDog,0,dog_position,' ','~');    

    if(ok) ok = truthful(mail,afterTheDog,dog_position+1,mail.length(),',','~');
        }
std::cout << (ok ? "\tYes" : "\tNo") << "\n"; 
}
}