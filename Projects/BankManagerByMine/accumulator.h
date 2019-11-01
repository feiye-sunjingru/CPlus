// accumulator.h
#ifndef _ACCUMULATOR_H_
#define _ACCUMULATOR_H_

class Accumulator{  // 每次对账户的操作都要做一次累加 
	public:
		double getSum(const Date& date) const{
			return sum+lastDate.distance(date)*value;
		}
		
		// 日期，每天的增量 
		Accumulator(const Date& date, double value):lastDate(date),value(value),sum(0){} 
		
		void change(const Date& date, double tmpValue){ // 更新值 
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
		Date lastDate; // 上次修改的日期 
		double value; // 每天的增量 
		double sum; // 上次日期为止的累加总和；如果只是本金，就不用加，sum=0 
};
#endif