## 程序说明(ISOC++11)
* 2_1.cpp 表现无符号整型的计算 
* 3_3.cpp 的 power(double x, int n)
* 4_2.cpp 使用了拷贝构造函数Point:
	关于函数返回值优化拷贝构造函数可参考：http://blog.sina.com.cn/s/blog_4ab8464c0100kybj.html
	友元函数：模拟反复使用私有成员（考虑到效率，不用get），这里用friend 
* 4_4.cpp 实参复制给形参的过程：从最后一个参数开始传 
* 4_8.cpp 实现了联合体，避免代码冗余和错误 
* 4_9.cpp 实现了枚举类，不同枚举类的属性不能做比较。Cfree增加C++11的支持，参考;https://blog.csdn.net/wallying/article/details/84546533 
* 4_10.cpp 实现了组合类的调用，要注意析构和构造函数的调用
* 6_10.cpp 变量地址作为实参，提高了传递的效率 
* 6_12.cpp 定义了函数指针int(*funcName)(int,int) 
* 6_18.cpp 动态创建多维数组 
* 6_19.cpp 动态数组封装成类 
* 6_22.cpp 浅层复制（空间复制一倍、数据复制一份）。复制的如果是地址，析构了第一个类之后，另外一个指针指向的地方没有对应空间，就会出现一直析构，出现死循环的情况。 
* 6_23.cpp 关于函数返回值是对象的情况，优化拷贝构造函数通过移动构造函数解决 
* 6_25.cpp 访问数组元素，既可以借助下标，也可以利用指针，通常利用下标 
* 7_3.cpp 虚函数使用 
* 8_1.cpp 双目运算符重载 
* 8_2.cpp 单目运算符重载
* 8_3.cpp 运算符重载为非成员函数，friend 
* lab8_1.cpp Point++等运算符重载，注意返回私有变量时不能对应&，这里输出p++直接拆分成p and p++ 
* lab9_1.cpp 函数模板
* lab9_2.cpp 类模板
* lab9_4.cpp 检查i是否能被比它小的质数整除,来判断i是否是质数。存储2~n的质数 
* Node.h 单链表结点的类模板 
* lab9_7.cpp 链表类模板实现 
* lab9_9.cpp 实现计算 3 5 * = 15
* lab9_10~13.cpp 实现队列、栈类模板 
* lab10_1/2.cpp 实现键盘输入，利用容器+迭代器+算法+函数对象，求相反数、求平方 
* 10_3.cpp 迭代器，自定义一个排序。容器vecor~push_back、sort(s.begin(), s.end())、copy(s.begin(), s.end(), result)
* 10_4.cpp 关于随机访问容器deque双端队列，赋值、倒序、相邻元素颠倒、输出
* 10_5.cpp 奇偶排序，随机访问容器vector\deque的操作 
* 10_6.cpp 顺序容器list的操作 
* 10_7.cpp 顺序容器的适配器~栈，实现字符串逆序输出 
* 10_8.cpp 有优先队列的使用，srand 
* 10_9.cpp 关联容器set:upper_bound\lower_bound\insert\begin\end 
* 10_10.cpp 关联容器map:make_pair\find\erase 
* 10_11.cpp 相当于wordcount，涉及函数：isalpha\tolower
* 10_12.cpp 上课时间查询，这里涉及函数：count、equal_range、range.first、range.second 
* 10_13.cpp numeric数值计算头文件：accumulate 累计操作。改进：10_14.cpp、10_15.cpp 
* 10_16.cpp、10_17.cpp 函数对象的使用 
* 10_18.cpp 涉及绑定适配器、组合适配器、函数指针适配器的使用 

## 注意：
* 只有构造函数可以用:初始化
* 对象调用中：实参传递给形参，形参赋值给对象都会调用拷贝构造函数。
* 函数退出之后，会析构一次。最终return 0时把所有定义的对象给析构掉
* 整体的构造函数数量=析构函数的数量 
* static int 有全局寿命，看是否是局部可见 
* 关于引用传递：能保证参数传递中不产生副本，提高传递的效率；且通过const的使用，保证了引用传递的安全性 
* const是要用到类的成员函数上；const变量是要在构造函数的":"后面初始化，不能放到类体 
* 系统的头文件用<>括起来（到安装目录下），自己写的用""括起来（到当前目录找） 
* 在构造函数里，可以指定默认值，但是在外部定义的时候，不能再加，否则编译会出default parameter given for parameter
* 返回局部变量时，返回类型不能是引用
* 函数中，默认值放置在定义的参数列表中而不是声明的位置 
* 模板类中，外部对象需要Node<T>* Node<T>::deleteAfter() 
* 一旦链表类实现了，在main函数中完成相应的功能就比较方便了 
* 队列类的特点就是其元素的操作顺序为先入先出FIFO，用链表实现队列:用链表类的成员函数实现队列类的push和pop成员函数
* 引入基类时，对应的函数也要引入模板参数，LinkedList<T>() 
* s1.splice(iterator position, list<T,Allocator>& x, iterator first, iterator last ) list操作中，在s1的position之后插入x的[first,last)
* s1.splice(iterator position, list<T,Allocator>& x, iterator it) list操作中s1的position后插入x的it位置的数据
* lower_bound():在first和last中的前闭后开区间进行二分查找，返回大于或等于val的第一个元素位置
* upper_bound():函数upper_bound()返回的在前闭后开区间查找的关键字的上界，返回大于val的第一个元素位置
* algorithm:sort、find_if、for_each、mem_fun对象指针、mem_fun_ref对象引用 
 
栈模板：
* 初始化
* 入栈
* 出栈
* 清空栈
* 访问栈顶元素
* 检测栈的状态（满、空） 


 ## 错误信息，增大排错效率 
 * 中文含义
 * 根本原因
 * 解决方法 
 
 ## 常见错误
1.C++ error: 'string' does not name a type
答： 
	using namespace std;
	#include <string> 
2. error: expected template-name before '<' token
答：头文件中没引入所需要的基类 

