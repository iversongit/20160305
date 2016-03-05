 ///
 /// @file    string.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-04 23:10:49
 ///

#include <stdio.h>
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
using std::string;

int main(void){
	string s1 = "hello,world";
	string s2 = s1;
	string s3 = s2;

	cout<<"修改前:"<<endl;
	cout<<"sizeof(s1) :"<<sizeof(s1)<<endl;
	printf("s1:  address---> %p\n",s1.c_str());
	cout<<"s1 :"<<s1<<endl;
	cout<<endl;
	cout<<"sizeof(s2) :"<<sizeof(s2)<<endl;
	printf("s2:  address---> %p\n",s2.c_str());
	cout<<"s2 :"<<s2<<endl;
	cout<<endl;
	cout<<"sizeof(s3) :"<<sizeof(s3)<<endl;
	printf("s3:  address---> %p\n",s3.c_str());
	cout<<"s3 :"<<s3<<endl;
	cout<<"-------------------"<<endl;
	cout<<"修改后:"<<endl;
	s3[0] = 'A';
	cout<<"sizeof(s3) :"<<sizeof(s3)<<endl;
	printf("s3:  address---> %p\n",s3.c_str());
	cout<<"s3 :"<<s3<<endl;
	cout<<endl;
	cout<<"sizeof(s1) :"<<sizeof(s1)<<endl;
	printf("s1:  address---> %p\n",s1.c_str());
	cout<<"s1 :"<<s1<<endl;
	cout<<endl;
	cout<<"sizeof(s2) :"<<sizeof(s2)<<endl;
	printf("s2:  address---> %p\n",s2.c_str());
	cout<<"s2 :"<<s2<<endl;
	cout<<endl;
	return 0;	
}
