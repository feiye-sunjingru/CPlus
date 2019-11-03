// 3_4.cpp 
# include <iostream>
using namespace std;

enum GameResult{WIN,LOSE,TIE,CANCEL};

int main3(){
	GameResult result;  // ???????? 
	enum GameResult omit = CANCEL;  // ???????壬?????CANCEL 
	for(int count=WIN; count<=CANCEL; count++){
		result = GameResult(count);
		if(result == omit){
			cout<<"The game was cancelled"<<endl;
		}else{
			cout<<"The game was played";
			if(result==WIN) cout<<"and we won!";
			if(result==LOSE) cout<<"and we lost.";
			cout<<endl;
		}
	}
	return 0;
}