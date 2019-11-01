// accumulator.h 
#ifndef _ACCUMULATOR_H_ 
#define _ACCUMULATOR_H_
#include "date.h"

class Accumulator{  // 累加器，按日累加之和 
	public:
		Accumulator(const Date& date, double value):lastDate(date),value(value),sum(0){} 
		double getSum(const Date& date) const{  // 计算sum+按日累加和 
			return sum+value*date.distance(lastDate);
		}
		void change(const Date& date, double tmpvalue){ // 指定日期更改数值 
			lastDate = date;
			value = tmpvalue;
			sum = getSum(date);	
		}
		void reset(const Date& date, double tmpvalue){ // 累加器清0并重新设置日期及初始值 
			lastDate = date;
			value = tmpvalue;
			sum = 0;
		}
		
	private:
		Date lastDate; // 被累加值上次日期 
		double value; // 被累加值当前value，每天的增量 
		double sum;	// 上次日期为止的累加总和 
};

#endif
