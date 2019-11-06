## 知识点
* 要想知道当月有多少天，可以用命名空间定义+平闰年判断 
* recordMap.lower_bound(begin)查询指定日期范围内的所有账目 
* istringstream str(cmdLine)把命令输入 
* 程序中首先定义了一个结构体struct, 然后以一个函数模板形式重载它的()运算符，这使得()能接受任何类型指针，这样将该结构体的实例传递给for_each算法就可以达到一定区间内的指针执行删除操作的目的
for_each(accounts.begin(), accounts.end(), deleter())
 

## 注意 


## 头文件
* stdexcept：runtime_error 
* algorithm：for_each负责删除所有账户
* utility头文件通过一组函数模板对任意数据类型重载了<=\>\>=\!=运算符，前3个运算符均被转化为对<的调用，最后一个被转换为==的调用
 所以会发现，我们重载了<之后可以用<= 
