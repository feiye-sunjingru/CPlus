// client.h ������
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
		static char ServerName; // ����������
		static int ClientNum; // ��¼�Ѷ���Ŀͻ�����
};