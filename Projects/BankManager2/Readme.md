## 注意： 
* 可以有const string& 返回值
* 目前利率计算存在逻辑问题 

## 常见错误： 
1. error: invalid initialization of non-const reference of type 'std::__cxx11::string& {aka std::__cxx11::basic_string<char>&}' from an rvalue of type 'std::__cxx11::string {aka std::__cxx11::basic_string<char>}' 
答：函数声明和定义中在该参数的类型前添加const关键字

2. cfree:文件目标不包含任何调试信息，请用debug配置从新构建当前文件
答：https://ask.csdn.net/questions/63667 