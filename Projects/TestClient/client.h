// client.h 声明类
#ifndef CLIENT_H_ 
#define CLIENT_H_ 
#endif
class Client{
	public:
		char getServerName(){return Client::ServerName;}
		char getClientNum(){return Client::ClientNum;}
		
		Client();
		~Client();
		void show();
		static void ChangeServerName(char ServerName); 
		
	private:
		static char ServerName; // 服务器名称
		static int ClientNum; // 记录已定义的客户数量
};