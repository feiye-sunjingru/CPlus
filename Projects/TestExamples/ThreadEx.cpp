#include "ThreadEx.h"
#include <thread> 
#include <iostream>  
#include <chrono>  

using namespace std;

ThreadEx::ThreadEx()
{
	 thread t1(&ThreadEx::taskForThread,this,"[","]");	
	 thread t2(&ThreadEx::taskForThread,this,"<",">");		 

     //要点：
	 //1、主线程不能先于子线程任务完成，否则子线程任务走不完就拉倒了。
	 //2、主线程中启动子线程后（采用局部对象法），要么join，要么detach。 
	 // 这是因为线程对象在被析构（~thread()）之前必须调用一次join或detach，
	 // 否则运行报错的。
	 //官方英文解释如下：
	 //The trouble you are encountering is a result of the stopThread going out of scope on the stack. 
	 //The C++ standard has the following to say about this:
	 //30.3.1.3 thread destructor [thread.thread.destr] 
	 //~thread();
	 //If joinable() then terminate(), otherwise no effects. 
	 //[ Note: Either implicitly detaching or joining ajoinable() thread in its destructor could result in difficult to debug correctness (for detach) 
	 //or performance (for join) bugs encountered only when an exception is raised. Thus the programmer must ensure that the destructor is never executed 
	 //while the thread is still joinable. — end note ] 
	 //What this means is that you should not let threads go out of scope without first calling either join() ordetatch().
     
	 //----------------------------------------------------------- 
	 //这里的休息模拟主线程干活 
	 //std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	 //主线程启动子线程后调用join方法，确保
	 //子线程和主线程合并，否则运行报错 
	 //但是这样主线程和子线程之间实际就不是并发了
	 //主线程会一直等待，直至子线程运行结束 
	 //另外当调用join函数时，调用线程阻塞等待目标线程终止，然后回收目标线程的资源。 
	 //t1.join();
	 //t2.join(); 
	 //-----------------------------------------------------------
	 
	 
	 
	 //-----------------------------------------------------------
	 //detach方法功能为将子线程分离，交由操作系统处理。
	 //当子线程主函数执行完之后，线程就结束了，运行时库负责清理与该线程相关的资源。  
	 t1.detach();
	 t2.detach(); 	 
	 //这里的休息模拟主线程干活 
	 std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	 //-----------------------------------------------------------
	 
	 
	 cout<<endl<<"main end"<<endl;
}

void ThreadEx::taskForThread(string preFix,string afterFix)
{
	for(int i=0;i<100;i++)
	{
		cout<<preFix<<i<<afterFix;
		//休眠20毫秒
		std::this_thread::sleep_for(std::chrono::milliseconds(20)); 
	}
}