#include <iostream>
#include <thread>
 
using namespace std;
 
void my_thread()
{
	puts("hello, world");
}
 
int main13(int argc, char *argv[])
{
	std::thread t(my_thread);
	t.join();
 
	system("pause");
	return 0;
}
