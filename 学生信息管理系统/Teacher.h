//
//  Teacher.h
//  学生信息管理系统
//
//  Created by Costin on 2018/1/19.
//  Copyright © 2018年 Costin. All rights reserved.
//


//定义老师类
class Teacher: public Student{
public:
    Student createStudent();  //创建学生信息
    void viewStudent(vector<Student> );   //浏览学生信息
    void findWithNo(vector<Student>, string );   //按学号查找学生信息
    void findWithName(vector<Student>, string ); //按姓名查找学生信息
    void changeStudent(vector<Student>&, string );  //修改学生信息
    void deletStudent(vector<Student>&, string );   //删除学生信息
};

//创建学生信息
Student Teacher::createStudent()
{
    string no, name, address, tel, email;
    int age, birth;
    char sex;
    Student A;
    cout<<"\n请输入学生学号(eg:YG1604240210):";
    cin>>no;
    A.set_no(no);
    cout<<"\n请输入学生姓名:";
    cin>>name;
    A.set_name(name);
    cout<<"\n请输入学生性别(m/f):";
    cin>>sex;
    A.set_sex(sex);
    cout<<"\n请输入学生年龄:";
    cin>>age;
    A.set_age(age);
    cout<<"\n请输入学生生日(eg:19981112):";
    cin>>birth;
    A.set_birth(birth);
    cout<<"\n请输入学生家庭住址:";
    cin>>address;
    A.set_address(address);
    cout<<"\n请输入学生联系电话:";
    cin>>tel;
    A.set_tel(tel);
    cout<<"\n请输入学生邮箱地址:";
    cin>>email;
    A.set_email(email);
    return A;
}

//浏览学生信息
void Teacher::viewStudent(vector<Student> vec)
{
    int i;
    cout<<"学号   "<<"姓名   "<<"性别   "<<"年龄   "<<"生日   "<<"家庭住址   "<<"联系电话   "<<"学生邮件地址   "<<endl;
    for(i=0; i<vec.size(); i++)
        vec[i].display();
}

//按学号查找学生信息
void Teacher::findWithNo(vector<Student> vec, string k)
{
    vector<Student>::iterator p;
    p = findKey(vec, k);
    if(p->get_no() == k)
    {
        cout<<"已找到该同学的信息！！"<<endl;
        cout<<"学号   "<<"姓名   "<<"性别   "<<"年龄   "<<"生日   "<<"家庭住址   "<<"联系电话   "<<"学生邮件地址   "<<endl;
        p->display();
    }
    else
    {
        cout<<"未找到该学生信息，请确认后重新输入！！"<<endl;
        return ;
    }
}

//按姓名查找学生信息
void Teacher::findWithName(vector<Student> vec, string k)
{
    vector<Student>::iterator p;
    cout<<"学号         "<<"姓名   "<<"性别   "<<"年龄   "<<"生日   "<<"家庭住址   "<<"联系电话   "<<"学生邮件地址   "<<endl;
    for(p=vec.begin(); p!=vec.end() ; p++)
    {
        if(k == p->get_name())
        {
            p->display();
            cout<<"已找到该同学的信息！！"<<endl;
        }
    }
}

//修改学生信息
void Teacher::changeStudent(vector<Student>& vec, string k)
{
    vector<Student>::iterator p;
    p = findKey(vec, k);
    int n;
    if(p->get_no() == k)
    {
        cout<<"已找到该同学的信息！！"<<endl;
        cout<<"学号   "<<"姓名   "<<"性别   "<<"年龄   "<<"生日   "<<"家庭住址   "<<"联系电话   "<<"学生邮件地址   "<<endl;
        p->display();
        
        cout<<"1.姓名"<<endl;
        cout<<"2.性别"<<endl;
        cout<<"3.年龄"<<endl;
        cout<<"4.生日"<<endl;
        cout<<"5.家庭住址"<<endl;
        cout<<"6.联系电话"<<endl;
        cout<<"7.邮件地址"<<endl;
        cout<<"0.返回上级菜单"<<endl;
        cout<<"\n请选择您要修改的信息："<<endl;
        cin>>n;
        switch(n)
        {
            case 1:
            {
                string name;
                cout<<"请输入修改后的姓名：";
                cin>>name;
                p->set_name(name);
                break;
            }
            case 2:
            {
                char sex;
                cout<<"请输入修改后的性别：";
                cin>>sex;
                p->set_sex(sex);
                break;
            }
            case 3:
            {
                int age;
                cout<<"请输入修改后的年龄：";
                cin>>age;
                p->set_age(age);
                break;
            }
            case 4:
            {
                int birth;
                cout<<"请输入修改后的生日：";
                cin>>birth;
                p->set_birth(birth);
                break;
            }
            case 5:
            {
                string address;
                cout<<"请输入修改后的家庭住址：";
                cin>>address;
                p->set_address(address);
                break;
            }
            case 6:
            {
                string tel;
                cout<<"请输入修改后的电话号码：";
                cin>>tel;
                p->set_tel(tel);
                break;
            }
            case 7:
            {
                string email;
                cout<<"请输入修改后的邮箱";
                cin>>email;
                p->set_email(email);
                break;
            }
        }
    }
    else
    {
        cout<<"未找到该学生信息，请确认后重新输入！！"<<endl;
        return ;
    }
}

//删除学生信息
void Teacher::deletStudent(vector<Student>& vec, string k)
{
    vector<Student>::iterator p;
    p = findKey(vec, k);
    char n;
    if(p->get_no() == k)
    {
        cout<<"已找到该同学的信息！！"<<endl;
        cout<<"学号   "<<"姓名   "<<"性别   "<<"年龄   "<<"生日   "<<"家庭住址   "<<"联系电话   "<<"学生邮件地址   "<<endl;
        p->display();
        cout<<"确认删除？(Y/N)"<<endl;
        cin>>n;
        if(n =='Y'||'y')
            vec.erase(p);
        else
            return ;
    }
    else
    {
        cout<<"未找到该学生信息，请确认后重新输入！！"<<endl;
        return ;
    }
}
