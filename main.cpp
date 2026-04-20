#include <iostream>
#include <exception>
using namespace std;
void check0(int );
void checkFail();
void check1000(int ,int);

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

class range1000:public exception{
	public:
	virtual const char* what() const throw(){
		return "Value out of range (-10000 to 1000)";
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
		check1000(x,y);
		check0(y);
		d=(double) x/y;
		cout<< "The result is " <<d<<endl;
		a=0;
		int i ;
		double* myarray;
		for(i=0;i<100000;i++){
			cout<<"Allocating memory ...."<<i<<endl;
			myarray= new double[5000000000];
		}
	}

	catch(exception& e){
		cout<<e.what()<<endl;
		
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

void check1000(int x,int y){
	range1000 e;
	if (x < -10000 || x > 1000 || y < -10000 || y > 1000) {
			throw e;
        }

}