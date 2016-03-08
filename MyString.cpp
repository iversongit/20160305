 ///
 /// @file    MyString.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-05 00:31:04
 ///
#include <string.h>
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

class String{
	private:
		class CharProxy{
			public:
				CharProxy(String &theString,int index)
				:_theString(theString)
				,_index(index)
				{
					cout<<"CharProxy()"<<endl;
				}

				char & operator=(const char& ch){
					cout<<"CharProxy::operator=(const char&)"<<endl;
					if(_index>=0 && _index<_theString.size()){
						if(_theString._str[_theString.size() + 1]==1){
							_theString._str[_index] = ch;
							return _theString._str[_index];
						}else{
							--_theString._str[_theString.size() + 1];
							char *temp = _theString._str;
							_theString._str = new char[_theString.size() + 2];
							strcpy(_theString._str,temp);
							_theString._str[_theString.size() + 1] = 1;
							_theString._str[_index] = ch;
							return _theString._str[_index];
						}
					}else{
						static char nullchar = '\0';
						cout<<"下标越界"<<endl;
						return nullchar;
					}				

				}

				operator char(){
					cout<<"CharProxy::operator char()"<<endl;
					return _theString._str[_index];
				}
			private:
				String & _theString;
				int _index;

		};
	public:
		String();
		String(const char *);
		String(const String &);
		String & operator =(const String &);
		~String();
		CharProxy operator[](int);
	//	char & operator[](int);
		int size();
		void print();
		int use_count();
		const char * c_str() const;
	private:
		char * _str;
};

String::String()
:_str(new char[2])
{
	cout<<"String()"<<endl;
	_str[1] = 1;
}

String::String(const char *str){
	cout<<"String(const char *str)"<<endl;
	int len = strlen(str);
	_str = new char[len + 2];
	strcpy(_str,str);
	_str[len + 1] = 1;
}

String::String(const String &rhs)
:_str(rhs._str)
{
	cout<<"String(const String &rhs)"<<endl;
	++_str[size()+1];
}

String & String::operator =(const String &rhs){
	cout<<"operator =(const String &rhs)"<<endl;
	if(&rhs == this){
		return *this;
	}
	
	if(--_str[size()+1] == 0)
		delete[] _str;

	_str = rhs._str;
	++_str[size() + 1];
	return *this;
}

String::~String(){
	cout<<"~String()"<<endl;
	if(--_str[size() + 1] == 0){
		delete[] _str;
	}
}

void String::print(){
	cout<<_str<<endl;
}

int String::size(){
	return strlen(_str);
}

int String::use_count(){
	return _str[size() + 1];
}

const char * String::c_str() const{
	return _str;
}

String::CharProxy String::operator[](int idx){
	return CharProxy(*this,idx);
}
#if 0
char & String::operator [](int index){
	if(index>=0 && index<size()){
		if(_str[size() + 1]==1)
			return _str[index];
		else{
			--_str[size() + 1];
			char *temp = _str;
			_str = new char[size() + 2];
			strcpy(_str,temp);
			_str[size() + 1] = 1;
			return _str[index];
		}
	}else{
		static char nullchar = '\0';
		cout<<"下标越界"<<endl;
		return nullchar;
	}
}
#endif

int main(){
	String s1 = "how are you";
	String s2 = s1;
	String s3;
	s3 =s2;
	cout<<"s1's use_count: "<<s1.use_count()<<endl;
	cout<<"s2's use_count: "<<s2.use_count()<<endl;
	cout<<"s3's use_count: "<<s3.use_count()<<endl;
	printf("s1 address: %p\n",s1.c_str());
	printf("s2 address: %p\n",s2.c_str());
	printf("s3 address: %p\n",s3.c_str());
	cout<<"s1--> ";
	s1.print();
	cout<<"s2--> ";
	s2.print();
	cout<<"s3--> ";
	s3.print();

	cout<<"-------------------------------"<<endl;
	cout<<"修改s3之后的各项结果为："<<endl;
	s3[0] = 'H';
	cout<<"s3--> ";
	s3.print();	
	printf("s3 address: %p\n",s3.c_str());
	cout<<"s3's use_count: "<<s3.use_count()<<endl;
	cout<<endl;
	cout<<"s1's use_count: "<<s1.use_count()<<endl;
	cout<<"s2's use_count: "<<s2.use_count()<<endl;
	printf("s1 address: %p\n",s1.c_str());
	printf("s2 address: %p\n",s2.c_str());
	cout<<"s1--> ";
	s1.print();
	cout<<"s2--> ";
	s2.print();
	cout<<"-------------------------------"<<endl;
	cout<<"执行读操作: "<<endl;
	cout<<s2[0]<<endl;
	cout<<"s1's use_count: "<<s1.use_count()<<endl;
	cout<<"s2's use_count: "<<s2.use_count()<<endl;
	printf("s1 address: %p\n",s1.c_str());
	printf("s2 address: %p\n",s2.c_str());
	cout<<"s1--> ";
	s1.print();
	cout<<"s2--> ";
	s2.print();
	cout<<endl;
	s3.print();	
	printf("s3 address: %p\n",s3.c_str());
	cout<<"s3's use_count: "<<s3.use_count()<<endl;
	cout<<endl;

	return 0;
}
