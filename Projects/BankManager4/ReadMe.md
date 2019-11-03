## 注意
* 郑莉 李超的源代码，参考：https://www.jianshu.com/p/e84382570d3d 

## 常见错误
1. C++ error: 'string' does not name a type
答： using namespace std;
2. error: `cout' was not declared in this scope”
答： 
	#include <iostream>
	using namespace std;
3. c++中"cout"不明确问题
答：将using namespace std; 删除后保存cpp文件，再加上using namespace std;保存cpp文件。