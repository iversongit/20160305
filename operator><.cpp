 ///
 /// @file    operator><.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-03 21:54:22
 ///
/*输入>>输出<<的重载*/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

class Complex{
	/*>>和<<运算符只能重载为友元函数形式*/
	/*不能是成员函数，因为它们要求第一个参数
	 *是流类型，流对象不能进行复制
	 */
//	friend ostream & operator <<(ostream &os,const Complex &c1);
//	friend istream & operator >>(istream &is,Complex &c1);
	public:
		Complex(int,int);
		~Complex();
		void print(ostream &) const;
		void scanf(istream &);
	private:
		int _ireal;
		int _imag;
};

Complex::Complex(int ireal=0,int imag=0)
:_ireal(ireal)
,_imag(imag)
{
	cout<<"Complex(int,int)"<<endl;
//	_ireal = ireal;
//	_imag = imag;
}

Complex::~Complex(){
	cout<<"~Complex()"<<endl;	
}

ostream & operator <<(ostream &os,const Complex &c1){
#if 0
	os<<c1._ireal;
	if(c1._imag > 0){
		os<<"+"<<c1._imag<<"i"<<endl;
	}else if(c1._imag < 0){
		os<<"-"<<(-1)*c1._imag<<"i"<<endl;
	}else{
		os<<endl;
	}
#endif
	c1.print(os);
	return os;
}

istream & operator >>(istream &is,Complex &c1){
#if 0
	is>>c1._ireal;
	if(is.get() != '*');
	is>>c1._imag;
#endif
	c1.scanf(is);
	return is;
}

void Complex::print(ostream &os) const{
	os<<_ireal;
	if(_imag > 0){
		os<<"+"<<_imag<<"i"<<endl;
	}else if(_imag < 0){
		os<<"-"<<(-1)*_imag<<"i"<<endl;
	}else{
		os<<endl;
	}
}

void Complex::scanf(istream &is){
	is>>_ireal;
	if(is.get() != '*');
	is>>_imag;
}

int main(void){
	Complex c1(3,4);
	Complex c2(4,-5);
	Complex c3(2,0);
	cin>>c1;
	cout<<c1;
	cin>>c2;
	cout<<c2;
	cin>>c3;
	cout<<c3;
	return 0;
}
