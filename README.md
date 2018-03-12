# StuInfo-Management
学生信息管理系统

## 功能描述
学生类信息包括：学号，姓名，年龄，性别，出生年月，地址，电话，E-mail学生类功能：
*  学生信息录入（初始化）
*  显示学生信息
*  返回迭代器地址（查找）

老师类功能：
*  学生信息录入功能（学生信息用文件保存）---输入
*  学生信息浏览功能---输出
*  查询、排序功能---算法
	按学号查询
	按姓名查询
*  学生信息的修改
*  学生信息的删除

## 学生类代码
```
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
```

## 教师类代码
```
class Teacher: public Student{
public:
    Student createStudent();  //创建学生信息
    void viewStudent(vector<Student> );   //浏览学生信息
    void findWithNo(vector<Student>, string );   //按学号查找学生信息
    void findWithName(vector<Student>, string ); //按姓名查找学生信息
    void changeStudent(vector<Student>&, string );  //修改学生信息
    void deletStudent(vector<Student>&, string );   //删除学生信息
};
```

---
> 预编译宏命令来自[c++  get与set方法的宏定义实现 - This is bill的专属博客 - CSDN博客](http://blog.csdn.net/Scythe666/article/details/48846761)

#GitHub
