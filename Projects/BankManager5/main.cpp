// main.cpp
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "account.h"
using namespace std;

struct deleter
{
    template<class T>void operator()(T *p)
    {
        delete p;
    }
};
//�������࣬�����洢�˻��б��ʹ�������
class Controller
{
public:
    Controller(const Date &date) :date(date), end(false)
    {
    }
    ~Controller();
    const Date& getDate()const
    {
        return date;
    }
    bool isEnd()const
    {
        return end;
    }
    //ִ��һ��������ظ������Ƿ�ı��˵�ǰ״̬(���Ƿ���Ҫ���浱ǰ����)
    bool runCommand(const string &cmdLine);
private:
    Date date;
    vector<Account*> accounts;       //�˻��б�
    bool end;                        //�û��Ƿ��������˳�����
};
Controller::~Controller()
{
    for_each(accounts.begin(), accounts.end(), deleter());
}
bool Controller::runCommand(const string &cmdLine)
{
    istringstream str(cmdLine);
    char cmd, type;
    int index, day;
    double amount, credit, rate, fee;
    string id, desc;
    Account* account;
    Date date1, date2;
    str >> cmd;
    switch (cmd)
    {
    case 'a':               //�����˻�
        str >> type >> id;
        if (type == 's')
        {
            str >> rate;
            account = new SavingAccount(date, id, rate);
        }
        else
        {
            str >> credit >> rate >> fee;
            account = new CreditAccount(date, id, credit, rate, fee);
        }
        accounts.push_back(account);
        return true;
    case 'd':              //�����ֽ�
        str >> index >> amount;
        getline(str, desc);
        accounts[index]->deposit(date, amount, desc);
        return true;
    case 'w':              //ȡ���ֽ�
        str >> index >> amount;
        getline(str, desc);
        accounts[index]->withdraw(date, amount, desc);
        return true;
    case 's':              //��ѯ���˻���Ϣ
        for (size_t i = 0;i < accounts.size();++i)
        {
            cout << "[" << i << "]";
            accounts[i]->show(cout);
            cout << endl;
        }
        return false;
    case 'c':             //�ı�����
        str >> day;
        if (day < date.getDay())
            cout << "You cannot specify a previous day";
        else if (day > date.getMaxDay())
            cout << "Invalid day";
        else
            date = Date(date.getYear(), date.getMonth(), day);
        return true;
    case 'n':               //�����¸���
        if (date.getMonth() == 12)
            date = Date(date.getYear() + 1, 1, 1);
        else
            date = Date(date.getYear(), date.getMonth() + 1, 1);
        for (vector<Account*>::iterator iter = accounts.begin();iter != accounts.end();++iter)
            (*iter)->settle(date);
        return true;
    case 'q':             //��ѯһ��ʱ���ڵ���Ŀ
        str >> date1 >> date2;
        Account::query(date1, date2);
        return false;
    case 'e':             //�˳�
        end = true;
        return false;
    }
    cout << "Invalid command: " << cmdLine << endl;
    return false;
}
int main()
{
    Date date(2018, 1, 1);         //��ʼ����
    Controller controller(date);
    string cmdLine;
    const char *FILE_NAME = "commands.txt";
    ifstream fileIn(FILE_NAME);      //�Զ�ģʽ���ļ�
    if (fileIn)                //��������򿪣���ִ���ļ��е�ÿһ������
    {
        while (getline(fileIn, cmdLine))
            controller.runCommand(cmdLine);
        fileIn.close();
    }
    ofstream fileOut(FILE_NAME, ios_base::app);        //��׷��ģʽ���ļ�
    cout << "(a)add account  (d)deposit  (w)withdraw  (s)show  (c)change day  (n)next month  (q)query  (e)exit" << endl;
    while (!controller.isEnd())        //�ӱ�׼����������ִ�У�ֱ���˳�
    {
        cout << controller.getDate() << "\tTotal: " << Account::getTotal() << "\tcommand";
        string cmdLine;
        getline(cin, cmdLine);
        if (controller.runCommand(cmdLine))
            fileOut << cmdLine << endl;          //������д���ļ�
    }
    return 0;
}