#include <iostream>
#include <string>

bool checkOctet(std::string part){
  if (part[0] == '0' && part.length() > 1) return false;          // условие с нулями
int number = std::stoi(part);                                 //"строка в целые"
  if (number < 0 || number > 255) return false;                   // максимум и минимум
return true;
}

bool checkIP(std::string adress,int length){
  int i=0;
  std::string part ;
  while( i < length){
    if(adress[i] >='0' && adress[i] <= '9') part += adress[i];     // "нарезка" на октеты
      if(adress[i] == '.') {
         if(!checkOctet(part)) return false;
        part = "";
      }
  i++;
  }
if(!checkOctet(part)) return false;                                // проверка последнего октета
return true;
}

int main(){
std::string ipAdress;
std::cout << "Input please yours IP: ";
std::cin >> ipAdress;

bool norm = true;
  for ( int i = 0; i < ipAdress.length();i++){                    // условие с точками
      if ( ipAdress[0] == '.' 
        || ipAdress[i] == '.' && ipAdress[i+1] == '.' 
        || ipAdress[ipAdress.length() - 1] == '.') {
        norm = false;
        break;
        }
      if ( ipAdress[i] < '.' || ipAdress[i] > '9'                // условие для корректной работы
        || ipAdress[i] == '/'){                                  // в дальнейшем stoi
        norm = false;
        break;
      }  
    } 
if(norm) norm = checkIP(ipAdress,ipAdress.length());
    
std::cout << (norm ? "\tValid" : "\tInvalid") << "\n";      
}