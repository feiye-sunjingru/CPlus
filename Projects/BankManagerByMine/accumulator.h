// accumulator.h
#ifndef _ACCUMULATOR_H_
#define _ACCUMULATOR_H_

class Accumulator{  // ÿ�ζ��˻��Ĳ�����Ҫ��һ���ۼ� 
	public:
		double getSum(const Date& date) const{
			return sum+lastDate.distance(date)*value;
		}
		
		// ���ڣ�ÿ������� 
		Accumulator(const Date& date, double value):lastDate(date),value(value),sum(0){} 
		
		void change(const Date& date, double tmpValue){ // ����ֵ 
			lastDate = date;
			value = tmpValue;
			sum = getSum(date); 
		}
		
		void reset(const Date& date, double tmpValue){
			lastDate = date; 
			value = tmpValue;
			sum = 0;
		}
		
	private:
		Date lastDate; // �ϴ��޸ĵ����� 
		double value; // ÿ������� 
		double sum; // �ϴ�����Ϊֹ���ۼ��ܺͣ����ֻ�Ǳ��𣬾Ͳ��üӣ�sum=0 
};
#endif