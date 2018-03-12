//
//  main.cpp
//  学生信息管理系统
//
//  Created by Costin on 2018/1/17.
//  Copyright © 2018年 Costin. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

//成员函数定义
// PropertyBuilderByName 用于生成类的成员变量
// 并生成set和get方法
// type 为变量类型
// access_permission 为变量的访问权限(public, priavte, protected)

#define Property(type, name, access_permission)\
access_permission:\
type stu_##name;\
public:\
inline void set##name(type v) {\
stu_##name = v;\
}\
inline type get##name() {\
return stu_##name;\
}\

#include "Student.h"
#include "Teacher.h"

//函数声明
int menu(); // 菜单函数
void saveToFile(vector<Student>& );   //保存文件
void openFromFile(vector<Student>& ); //打开文件



//主函数
int main()
{
    int n=0, i=0, m=0;
    char s;
    string str;
    vector<Student>vec;
    vector<Student>::iterator p;
    openFromFile(vec);  //读取文件内数据放入vector中
    
    for(;;)
    {
        Teacher T;
        switch(menu())
        {
            case 1:
            {
                /*创建（添加）学生信息*/
                cout<<"正在创建学生信息>>>"<<endl;
                m = vec.size();  //读取文件内数据个数
                cout<<"请输入录入学生个数：";
                cin>>n;
                i = i+m; //追加录入
                n = n+m;
                while(i<n)
                {
                    cout<<"您正在录入第"<<i+1<<"个学生的信息:)"<<endl;
                    vec.insert(vec.end(), T.createStudent());  //在vector尾部创建新学生信息
                    i++;
                }
                cout<<"确认信息无误后，保存学生信息请输入y保存数据：";
                cin>>s;
                if(s == 'y' || 'Y')
                   saveToFile(vec);  //保存数据
                break;
            }
            case 2:
            {
                /*浏览学生信息*/
                cout<<"学生信息>>>"<<endl;
                T.viewStudent(vec);
                break;
            }
            case 3:
            {
                /*用学号查询学生信息*/
                cout<<"请输入查询的学生学号：";
                cin>>str;
                T.findWithNo(vec, str);
                break;
            }
            case 4:
            {
                /*用姓名查询学生信息*/
                cout<<"请输入要查询的学生姓名：";
                cin>>str;
                T.findWithName(vec, str);
                break;
            }
            case 5:
            {
                /*修改学生信息*/
                cout<<"请输入修改信息的学生学号：";
                cin>>str;
                T.changeStudent(vec, str);
                saveToFile(vec);
                break;
            }
            case 6:
            {
                /*删除学生信息*/
                cout<<"请输入删除信息的学生学号：";
                cin>>str;
                T.deletStudent(vec, str);
                saveToFile(vec);
                break;
            }
            case 0:
                printf("程序结束，谢谢使用！\n\n");
                return 0;
        }
    }
    return 0;
}

//菜单函数
int menu()
{
    int sn;
    cout<<"\n=====题目三 学生信息管理系统=====\n\n";
    cout<<"1.学生信息录入\n";
    cout<<"2.学生信息浏览\n";
    cout<<"3.按学号查找学生信息\n";
    cout<<"4.按姓名查找学生信息\n";
    cout<<"5.学生信息修改\n";
    cout<<"6.学生信息删除\n";
    printf("0.退出\n");
    printf("请输入 0-6:");
    for(;;)
    {
        cin>>sn;
        if(sn<0||sn>6)
        {
            cout<<"\n输入错误，重选0－6：";
            getchar();
        }
        else
            break;
    }
    return sn;
}

//存储学生信息
void saveToFile(vector<Student>& vec)
{
    int i;
    ofstream outfile("/Users/costin/Desktop/学生信息管理系统/学生信息管理系统/Student.txt");
    for(i=0; i<vec.size(); i++)
    {
        outfile<<vec[i].get_no()<<"\t";
        outfile<<vec[i].get_name()<<"\t";
        outfile<<vec[i].get_age()<<"\t";
        outfile<<vec[i].get_sex()<<"\t";
        outfile<<vec[i].get_birth()<<"\t";
        outfile<<vec[i].get_address()<<"\t";
        outfile<<vec[i].get_tel()<<"\t";
        outfile<<vec[i].get_email()<<"\t";
        outfile<<"\n";
    }
    cout<<"<<<保存成功！"<<endl;
    outfile.close();
}

//从文件读取数据
void openFromFile(vector<Student>& vec)
{
    /*将文件里的数据创建成新对象，然后将对象储存到vector中*/
    int i=0;
    string no;
    Student A;
    ifstream infile("/Users/costin/Desktop/学生信息管理系统/学生信息管理系统/Student.txt");
    if(!infile)
    {
        cout<<"暂无学生信息！！请添加"<<endl;
        return ;
    }
    while(!infile.eof())
    {
        A.Init(infile); //生成对象
        no = A.get_no();
        if(no[0] == '\0')
            break ;
        vec.insert(vec.end(), A); //插入到vector中
        i++;
    }
    vec.pop_back(); //删除多插入的最后一项
    infile.close();
}


