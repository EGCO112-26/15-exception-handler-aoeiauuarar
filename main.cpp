#include <iostream>
#include <exception>
using namespace std;
void check0(int );
void checkFail();

class div0:public exception{
	public:
	virtual const char* what() const throw(){
		return "Error divide by zero";
	}
};

class input_fail:public exception{
	public:
	virtual const char* what() const throw(){
		return "Incorrect type entered";
	}
};

int main(){
	int x,y;
	double d;
	int a=1;
do{
	try{

		cout<<"Enter 2 num: ";
		cin>>x>>y;
		checkFail();
		if (x < -10000 || x > 1000 || y < -10000 || y > 1000) {
			throw "Value out of range (-10000 to 1000)";
        }
		check0(y);
		d=(double) x/y;
		cout<< "The result is " <<d<<endl;

		int i ;
		double* myarray;
		for(i=0;i<100000;i++){
			cout<<"Allocating memory ...."<<i<<endl;
			myarray= new double[50000000];
		}
	}

	catch(exception& e){
		cout<<e.what()<<endl;
		a=0;
	}
}while(a);
	return 0;
}

void check0(int x){
	div0 e;
	if(x==0){
		throw e;
	}
}

void checkFail() {
	input_fail e;
    if (cin.fail()) {
		cin.clear();
		cin.ignore(50,'\n');
        throw e;
    }
}