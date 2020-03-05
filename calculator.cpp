#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{

  while(1){

  cout << "? ";
  char number1[10];
  cin >> number1;
  if(strcmp(number1,"quit")==0)
  {
      break;
  }
  int num1 = atoi(number1);

  char symbol;
  cin >> symbol;

  char number2[10];
  cin.getline(number2,100,'\n');
  int num2 = atoi(number2);

  int result = 0;

  if(symbol=='+')
  {
      result = num1 + num2;
      cout << num1 << " " <<symbol << " "<< num2 << " "<< "=" << " " << result << endl;
  }
  else if(symbol=='-')
  {
      result = num1 - num2;
      cout << num1 << " " <<symbol << " "<< num2 << " "<< "=" << " " << result << endl;
  }
  else if(symbol=='*')
  {
      result = num1 * num2;
      cout << num1 << " " <<symbol << " "<< num2 << " "<< "=" << " " << result << endl;
  }
  else if(symbol=='/')
  {
      result = num1 / num2;
      cout << num1 << " " <<symbol << " "<< num2 << " "<< "=" << " " << result << endl;
  }
  else if(symbol=='%')
  {
      result = num1 % num2;
     cout << num1 << " " <<symbol << " "<< num2 << " "<< "=" << " " << result << endl;
  }
  else
  {
      cout << "symbol is not correct" << endl;
  }
    }
}
