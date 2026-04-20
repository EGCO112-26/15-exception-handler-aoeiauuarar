#include <iostream>
using namespace std;

void check0(int );

int main(){
	int x,y;
	double d;
	int a=1;
do{
	try{

		int i ;
		double* myarray;
		for(i=0;i<100000;i++){
			cout<<"Allocating memory ...."<<i<<endl;
			myarray= new double[50000000];
		}
		cout<<"Enter 2 num: ";
		cin>>x>>y;
		if(cin.fail()){
			a=0;
			throw 101;
		}
		if(abs(x)>1000 ||abs(y)>1000){
			a=0;
			throw"alue out of range";
		}
		check0(y);
		d=(double) x/y;
		cout<< "The result is " <<d<<endl;
	}
	catch(const char* error){
		cerr<<error<<endl;
	}
	catch(const int x){
		switch(x){
			case 101: cerr<<"Incorrect type entered"<<endl; break;
			case 0: cerr<<"Error divide by zero"<<endl; break;
		}
		
		cin.clear();
		cin.ignore(50,'\n');
	}
	catch(exception &e){
		cout<<e.what()<<endl;
		a=0;
	}
}while(a);
	return 0;
}

void check0(int x){
	if(x==0){
		throw(x);
	}
}
