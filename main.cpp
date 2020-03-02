#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;
map<string, string> dic;
map<string, string>::iterator it;
const char* namenumber = "nameandnumber.txt";		//파일 위치
class Phone{
public:
    string name;
    string number;
    int c;
    int fi;

    void Search(){							//Search함수
        ifstream fin(namenumber, ios::in);
        cout << "Please type the name : ";
        getline(cin, name);
        if((c=fin.get())== EOF)
            cout << "None" << endl;
        else
            cout << name << "'s phone number is "<< dic[name] << endl;
    }
    void Save(){							//Save함수
        ofstream fout(namenumber,ios::out| ios::app);
        cout << "Please type the name : ";
        getline(cin, name);
        cout << "Please type the number : ";
        getline(cin, number);
        dic[name] = number;
        cout << "The contact : " << name << ", " << number << " is saved!!!"<< endl;
        fout << name << ",\t";
        fout << dic[name] << endl;
    }

    void Delete(){							//Delete함수
        cout << "Please type the name : ";
        getline(cin, name);
        dic.erase(name);
        ofstream fout2(namenumber, ios::out|ios::trunc);
        for(it = dic.begin(); it != dic.end(); it++){
            fout2 << it->first << ",\t" << it->second << endl;
        }
        cout << "The contact " << name << " is deleted!!!" << endl;
    }

    void ShowAll(){							//ShowAll함수
        ifstream fin(namenumber, ios::in);
        if((c=fin.get()) == EOF)
            cout<<"Nothing"<<endl;
        while((c=fin.get()) != EOF)
            cout << (char)c;
    }
};


int main()
{
    Phone p;
    int n;
    string cpname = " ", cpnumber;
    string com ="", sp;
    ifstream fin(namenumber, ios::in);					//파일에 저장되어있는
    while(fin.peek() != EOF){						//값들을 map에 저장
        if(com == cpname)
            break;
        else{
            com = cpname;
            getline(fin, cpname,',');
            getline(fin, sp, '\t');
            getline(fin, cpnumber);
            dic[cpname] = cpnumber;
        }
    }
    while(1){							//switch문으로 실행
        cout << "Select Function 1:<Search>, 2:<Save>, 3:<Delete>, 4:<ShowAll> or else:<Exit> : ";
        cin >> n;
        cin.ignore(1);
        switch (n) {
        case 1:
            p.Search();
            break;
        case 2:
            p.Save();
            break;
        case 3:
            p.Delete();
            break;
        case 4:
            p.ShowAll();
            break;
        default:
            return 0;
        }
    }
}
