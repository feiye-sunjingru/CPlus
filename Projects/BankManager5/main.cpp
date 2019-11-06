#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "account.h"
using namespace std;

struct deleter{ // 能接受任意类中 
	// 重载了圆括号 
    template<class T>void operator()(T *p){
        delete p;
    }
};

//控制器类，用来存储账户列表和处理命令
class Controller{
public:
    Controller(const Date &date) :date(date), end(false){}
    ~Controller();
    const Date& getDate()const{return date;}
    bool isEnd()const{return end;}
    //执行一条命令，返回该命令是否改变了当前状态(即是否需要保存当前命令)
    bool runCommand(const string &cmdLine);
private:
    Date date;
    vector<Account*> accounts;       //账户列表
    bool end;                        //用户是否输入了退出命令
};

Controller::~Controller(){ 
    for_each(accounts.begin(), accounts.end(), deleter());
}

bool Controller::runCommand(const string &cmdLine){
    istringstream str(cmdLine);  // 输入字符串流 
    char cmd, type;
    int index, day;
    double amount, credit, rate, fee;
    string id, desc;
    Account* account;
    Date date1, date2;
    str >> cmd; // 截取字符cmd 
    switch (cmd){
    case 'a': //增加账户
        str >> type >> id;
        if (type == 's'){
            str >> rate;
            account = new SavingAccount(date, id, rate);
        }else{
            str >> credit >> rate >> fee;
            account = new CreditAccount(date, id, credit, rate, fee);
        }
        accounts.push_back(account);
        return true;
    case 'd': //存入现金
        str >> index >> amount;
        getline(str, desc);
        accounts[index]->deposit(date, amount, desc);
        return true;
    case 'w': //取出现金
        str >> index >> amount;
        getline(str, desc);
        accounts[index]->withdraw(date, amount, desc);
        return true;
    case 's': //查询各账户信息
        for (size_t i = 0;i < accounts.size();++i){
            cout << "[" << i << "]";
            accounts[i]->show(cout);
            cout << endl;
        }
        return false;
    case 'c': //改变日期
        str >> day;
        if (day < date.getDay()){
        	cout << "You cannot specify a previous day";
        }else if (day > date.getMaxDay()){
        	cout << "Invalid day";
        }else{
        	date = Date(date.getYear(), date.getMonth(), day);
        }     
        return true;
    case 'n':               //进入下个月
        if (date.getMonth() == 12){
        	date = Date(date.getYear() + 1, 1, 1);
        }else{
        	date = Date(date.getYear(), date.getMonth() + 1, 1);
        }            
        for (vector<Account*>::iterator iter = accounts.begin();iter != accounts.end();++iter){
        	(*iter)->settle(date);
        }   
        return true;
    case 'q':  //查询一段时间内的账目
        str >> date1 >> date2;
        Account::query(date1, date2);
        return false;
    case 'e':             //退出
        end = true;
        return false;
    }
    cout << "Invalid command: " << cmdLine << endl;
    return false;
}

int main(){
    Date date(2018, 1, 1); // 起始日期
    Controller controller(date);
    string cmdLine;
    const char *FILE_NAME = "commands.txt";
    ifstream fileIn(FILE_NAME); // 以读模式打开文件
    if (fileIn){  // 如果正常打开，就执行文件中的每一条命令
        while (getline(fileIn, cmdLine)){
        	controller.runCommand(cmdLine);
        } 
        fileIn.close();
    }
    ofstream fileOut(FILE_NAME, ios_base::app);  // 以追加模式打开文件
    cout << "(a)add account  (d)deposit  (w)withdraw  (s)show  (c)change day  (n)next month  (q)query  (e)exit" << endl;
    while (!controller.isEnd()){  // 从标准输入读入命令并执行，直到退出
        cout << controller.getDate() << "\tTotal: " << Account::getTotal() << "\tcommand";
        string cmdLine;
        getline(cin, cmdLine);
        if (controller.runCommand(cmdLine)){
        	fileOut << cmdLine << endl;          //将命令写入文件
		}             
    }
    return 0;
}