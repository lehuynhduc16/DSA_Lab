#include <bits/stdc++.h>
using namespace std;

bool checkPhone(string fnum){
	if(fnum.length() != 10){
		return false;
	}
	for(int i = 0; i < fnum.length(); i++){
		if(!fnum[i] >= '0' && fnum[i] <= '9'){
			return false;
		}
	}
	return true;
}

int countTime(string ftime, string etime){
	int startTime = 3600*((ftime[0]-'0')*10 + ftime[1]-'0') + 60*((ftime[3]-'0')*10+ftime[4]-'0') + (ftime[6]-'0')*10+ftime[7]-'0';
	int endTime = 3600*((etime[0]-'0')*10 + etime[1]-'0') + 60*((etime[3]-'0')*10+etime[4]-'0') + (etime[6]-'0')*10+etime[7]-'0';
	return endTime-startTime;
}

map<string, int> numberCalls, timeCalls;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	string type;
	int totalCalls = 0;
	int incorrectPhone = 0;
	do{
		cin >> type;
		if(type == "#") continue;
		++totalCalls;
		string fnum, tnum, date, ftime, etime;
		cin >> fnum >> tnum >> date >> ftime >> etime;
		if(!checkPhone(fnum) || !checkPhone(tnum)){
			++incorrectPhone;
		}
		numberCalls[fnum]++;
		timeCalls[fnum] += countTime(ftime, etime);
	}while(type != "#");
	
	do{
		cin >> type;
		string S;
		if(type == "#") break;
		else if(type == "?check_phone_number"){
			if(incorrectPhone == 0) cout << 1 << "\n";
			else cout << "0" << "\n";
		}
		else if(type == "?number_calls_from"){
			cin >> S;
			cout << numberCalls[S] << "\n";
		}
		else if(type == "?number_total_calls"){
			cout << totalCalls << "\n";
		}
		else if(type == "?count_time_calls_from"){
			cin >> S;
			cout << timeCalls[S] << "\n";
		}
	}while(type != "#");
	return 0;
}
