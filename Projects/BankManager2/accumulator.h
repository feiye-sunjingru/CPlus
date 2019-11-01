// accumulator.h 
#ifndef _ACCUMULATOR_H_ 
#define _ACCUMULATOR_H_
#include "date.h"

class Accumulator{  // �ۼ����������ۼ�֮�� 
	public:
		Accumulator(const Date& date, double value):lastDate(date),value(value),sum(0){} 
		double getSum(const Date& date) const{  // ����sum+�����ۼӺ� 
			return sum+value*date.distance(lastDate);
		}
		void change(const Date& date, double tmpvalue){ // ָ�����ڸ�����ֵ 
			lastDate = date;
			value = tmpvalue;
			sum = getSum(date);	
		}
		void reset(const Date& date, double tmpvalue){ // �ۼ�����0�������������ڼ���ʼֵ 
			lastDate = date;
			value = tmpvalue;
			sum = 0;
		}
		
	private:
		Date lastDate; // ���ۼ�ֵ�ϴ����� 
		double value; // ���ۼ�ֵ��ǰvalue��ÿ������� 
		double sum;	// �ϴ�����Ϊֹ���ۼ��ܺ� 
};

#endif
