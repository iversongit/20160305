 ///
 /// @file    singletonAutorelease.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-04 23:48:49
 ///
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton{
	public:
		static Singleton * getInstance();
		Singleton();
		~Singleton();
	private:
		class AutoRelease{
			public:
				AutoRelease();
				~AutoRelease();
		};
	private:
		static Singleton * _pInstance;
		static AutoRelease _autorelease;
};

Singleton *	Singleton::_pInstance = NULL;
Singleton::AutoRelease Singleton::_autorelease;

Singleton::Singleton(){
	cout<<"Singleton()"<<endl;
}

Singleton::~Singleton(){
	cout<<"~Singleton()"<<endl;
}

Singleton * Singleton::getInstance(){
	if(_pInstance == NULL){
		_pInstance = new Singleton;
	}

	return _pInstance;
}

Singleton::AutoRelease::AutoRelease(){
	cout<<"AutoRelease()"<<endl;
}

Singleton::AutoRelease::~AutoRelease(){
	cout<<"~AutoRelease()"<<endl;
	if(_pInstance != NULL){
		delete _pInstance;
	}
}

int main(void){
	Singleton *s1 = Singleton::getInstance();
	Singleton *s2 = Singleton::getInstance();
	printf("the address of s1 : %p\n",s1);
	printf("the address of s2 : %p\n",s2);
	return 0;
}
