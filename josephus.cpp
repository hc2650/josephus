#include <iostream>
#include <list>
using namespace std;

void josephus(int N, int K){

        list<int> winner;
        for(int j = N; 0 < j; j--)
                winner.push_front(j);
	list<int>::iterator kill = winner.begin();
	
	while(N>2){
		kill=winner.erase(kill);
		if(kill == winner.end()) kill = winner.begin();
		--N;

		for(int k =0; k<K-1; k++){
			++kill;
			if(kill == winner.end()) kill = winner.begin();
		}
	}
	cout<<winner.front()<<" "<<winner.back()<<endl;
}

int main(){

        int i, Test_case, N, K;

	cin>>Test_case;

        for(i =0; i<Test_case; i++){
                cin>>N>>K;
                josephus(N, K);
        }

        return 0;
}

