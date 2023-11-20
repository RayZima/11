#include<iostream>

int encrypt_caesar(int x ,int o_set){
                if(x > '@' && x < '['){
                    x = x - 'A';
                    x = (x + o_set)%26 +'A';         
                }
                if(x > '`' && x < '{' ){    
                    x = x - 'a';
                    x = (x + o_set)%26 + 'a'; 
                }
    return x;
}

int main(){ 
    std::cout << "\n Input plaese your text : ";
    std::string text;
    std::getline(std::cin,text);  
    int offset = 0;
    std::cout << "\n Input please offset : ";
    std::cin >> offset;
    offset %= 26;
    char sign;
    std::cout << "\n Want to encrypt('e') or to decipher('d')  your text? : ";
    std::cin >> sign;

    if( sign =='d' ){
    offset = 26 - offset;
        if (text.length() > 0 && text != " "){
            for (int i = 0; i < text.length(); i++) {
            text[i] = encrypt_caesar(text[i],offset);
            }
        }
        std::cout << "\n Result :\t"<< text << "\n";
    }
    else if( sign == 'e' ){
        if (text.length() > 0 && text != " "){
            for (int i = 0; i < text.length(); i++) {
            text[i] = encrypt_caesar(text[i],offset);
            }
        }
        std::cout << "\n Result :\t"<< text << "\n";
    }
    else std::cout << "\n Incurrect sign !!!";  
}