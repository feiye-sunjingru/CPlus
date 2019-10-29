// 4_8.cpp 
# include <iostream>
# include <string> 

using namespace std;

class ExamInfo{
	public:
		ExamInfo(string name, char grade):name(name),mode(GRADE),grade(grade){
		}
		
		ExamInfo(string name, bool pass):name(name),mode(PASS),pass(pass){
		}
		
		ExamInfo(string name, int percent):name(name), mode(PERCENTAGE), percent(percent){
		}
		
		void show();
	
	private:
		string name; // 课程名称
		enum{
			GRADE, PASS, PERCENTAGE
		} mode; // 计分方式
		
		// 使用联合体保存成绩信息，并且输出 
		union{
			char grade; // 等级制的成绩
			bool pass; // 只记是否通过课程
			int percent; // 百分制的成绩 
		};
};

void ExamInfo::show(){
	cout<<name<<":";
	switch(mode){
		case GRADE: cout<<grade; break;
		case PASS: cout<<(pass?"PASS":"FAIL"); break;
		case PERCENTAGE: cout<<percent; break;
	}
	cout<<endl;
} 

int main9(){
	ExamInfo course1("English", 'B');
	ExamInfo course2("Calculus", true);
	ExamInfo course3("C++ Programming", 85);
	course1.show();
	course2.show();
	course3.show();
	return 0;
}
