

#include<iostream>
using namespace std;

class Racional{
	int num, denom;
	public:
		Racional(int n, int d): num(n), denom(d){};
		int VerNum(){ return num; };
		int VerDenom(){ return denom; };
		
		Racional operator+(const Racional& num2){
			return Racional((this->num + num2.num), (this->denom, num2.denom));
		}
		
		Racional operator*(const Racional num){
			return Racional((num.num * this->num), (num.denom * this->denom));
		}


		Racional operator++(){
      this->num = num+denom;
      return *this;
		}

		Racional operator++(int){
			this->num = this->num + this->denom;
			return *this;
		}

};

int main(){

	Racional n1(3, 5), n2(3, 5), n3(0, 1);
	// n3 = n1+ n2;
	// n3 = n1 * n2;
	// n3++;
	cout << n3.VerNum() << endl;
	cout << n3.VerDenom() << endl;


	return 0;
}