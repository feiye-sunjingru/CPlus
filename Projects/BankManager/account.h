#ifndef __ACCOUNT_H__  // �����ظ����� 
#define __ACCOUNT_H__
#include <string> 
#include "date.h" 
using namespace std;

class SavingsAccount{ // �����˻��� 
	public:
		void record(const Date &date, double amount, const string &desc);  // descΪ������Ŀ����˵������ 
		void error(string msg) const;  // ������� 
	 	double accumulate (const Date& date){
	 		return balance*lastDate.distance(date);
	 	}
		SavingsAccount(const Date &date, string id, double rate);
		const string& getId() {
			return id;
		}
		double getBalance() const{
			return balance;
		}
		double getRate() const{
			return rate;
		}
		void show() const;
		void deposite(const Date& date, double amount, const string& desc);
		void withdraw(const Date& date, double amount, const string& desc);
		void settle(const Date& date);  // �˻����� 
		static double getTotal();
	private:
		string id;  // �˺ţ�������0��ͷ 
		double balance;  // ��� 
		double rate; // ���������� 
		Date lastDate; // �ϴα������ʱ�� 
		double accumulation; // �����ۼ�֮�� 
		static double total;  // ȫ���˻����������˻����ܽ�� 
}; 
#endif
