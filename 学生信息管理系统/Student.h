//
//  Student.h
//  学生信息管理系统
//
//  Created by Costin on 2018/1/19.
//  Copyright © 2018年 Costin. All rights reserved.
//




//定义学生类
class Student{
    /*生成以下数据成员及其setter,getter*/
    Property(string, _no, private);     //学生学号
    Property(string, _name, private);   //学生姓名
    Property(int, _age, private);       //学生年龄
    Property(char, _sex, private);      //学生性别
    Property(int, _birth, private);     //学生生日
    Property(string, _address, private);//学生住址
    Property(string, _tel, private);    //学生电话
    Property(string, _email, private);  //学生邮件
public:
    Student(){};
    void Init(istream& );   //录入
    void display();   //显示
    vector<Student>::iterator findKey(vector<Student>& , string );  //查找
};


//录入学生信息初始化一个对象
void Student::Init(istream& in)
{
    in>>stu__no>>stu__name>>stu__age>>stu__sex>>stu__birth>>stu__address>>stu__tel>>stu__email;
}

//显示学生信息
void Student::display()
{
    cout<<stu__no<<"   ";
    cout<<stu__name<<"   ";
    cout<<stu__sex<<"   ";
    cout<<stu__age<<"   ";
    cout<<stu__birth<<"   ";
    cout<<stu__address<<"   ";
    cout<<stu__tel<<"   ";
    cout<<stu__email<<"   ";
    cout<<"\n";
}

//根据学号查找vector中对应对象的迭代器地址
vector<Student>::iterator Student::findKey(vector<Student>& vec, string k)
{
    vector<Student>::iterator p;
    for(p=vec.begin(); p!=vec.end() ; p++)
    {
        if(k == p->get_no())
            break;
    }
    return p;
}
