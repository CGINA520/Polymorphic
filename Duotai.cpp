//多态案案例（1）:计算器
// #include <iostream>
// #include <string>
// using namespace std;
// //普通实现
// class Calaulator
// {
// public:
//     int getResult(string oper)
//     {
//         if (oper == "+")
//         {
//             return m_num1 + m_num2;
//         }
//         else if (oper == "-")
//         {
//             return m_num1 - m_num2;
//         }
//         else if (oper == "*")
//         {
//             return m_num1 * m_num2;
//         }
//         return 0;
//     }
//     int m_num1;
//     int m_num2;
// };

// void test01()
// {
//     Calaulator c;
//     c.m_num1 = 10;
//     c.m_num2 = 20;
//     cout << c.getResult("+") << endl;
// }

// //使用多态实现计算器
// //抽象类
// class AbstractCalculator
// {
// public:
//     virtual int getResult()
//     {
//         return 0;
//     }
//     int m_num1;
//     int m_num2;
// };
// //加法类
// class AddCalculator : public AbstractCalculator
// {
//     int getResult()
//     {
//         return m_num1 + m_num2;
//     }
// };
// //减法类
// class SubCalculator : public AbstractCalculator
// {
//     int getResult()
//     {
//         return m_num1 - m_num2;
//     }
// };
// //乘法类
// class MulCalculator : public AbstractCalculator
// {
//     int getResult()
//     {
//         return m_num1 * m_num2;
//     }
// };

// void test02()
// {
//     AbstractCalculator *abc = new AddCalculator;
//     abc->m_num1 = 100;
//     abc->m_num2 = 100;
//     cout << abc->getResult() << endl;
//     delete abc;
//     abc = new MulCalculator;
//     abc->m_num1 = 20;
//     abc->m_num2 = 30;
//     cout << abc->getResult() << endl;
//     delete abc;
// }
// int main()
// {
//     test01();
//     test02();
//     system("pause");
//     return 0;
// }

//多态案例（2）:制作饮品
// #include <iostream>
// using namespace std;

// class AbstractDrinking
// {
// public:
//     //煮水
//     virtual void Boil() = 0;
//     //冲泡
//     virtual void Brew() = 0;
//     //倒入杯中
//     virtual void PutIncup() = 0;
//     //加入辅料
//     virtual void PutSomething() = 0;
//     void MakeWork()
//     {
//         Boil();
//         Brew();
//         PutIncup();
//         PutSomething();
//     }
// };
// class Coffe : public AbstractDrinking
// {
// public:
//     //煮水
//     void Boil()
//     {
//         cout << "煮农夫山泉" << endl;
//     }
//     //冲泡
//     void Brew()
//     {
//         cout << "冲泡咖啡" << endl;
//     }
//     //倒入杯中
//     void PutIncup()
//     {
//         cout << "倒入杯中" << endl;
//     }
//     //加入辅料
//     void PutSomething()
//     {
//         cout << "加入糖和牛奶" << endl;
//     }
// };
// class Tea : public AbstractDrinking
// {
// public:
//     //煮水
//     void Boil()
//     {
//         cout << "煮农夫山泉" << endl;
//     }
//     //冲泡
//     void Brew()
//     {
//         cout << "冲泡茶叶" << endl;
//     }
//     //倒入杯中
//     void PutIncup()
//     {
//         cout << "倒入杯中" << endl;
//     }
//     //加入辅料
//     void PutSomething()
//     {
//         cout << "不加辅料" << endl;
//     }
// };
// void DoWork(AbstractDrinking *abs) // AbstractDrinking *abs=new 类名
// {
//     abs->MakeWork();
//     delete abs;
// }
// void test01()
// {
//     DoWork(new Coffe);
//     cout << "-------------------" << endl;
//     DoWork(new Tea);
// }
// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }

//多态案例（3）电脑组装
#include <iostream>
using namespace std;

class Cpu
{
public:
    virtual void calculate() = 0;
};
class VideoCard
{
public:
    virtual void display() = 0;
};
class Memory
{
public:
    virtual void storage() = 0;
};

//电脑类
class Computer
{
public:
    Computer(Cpu *cpu, VideoCard *vc, Memory *mem)
    {
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }
    void dowork()
    {
        m_cpu->calculate();
        m_vc->display();
        m_mem->storage();
    }
    ~Computer()
    {
        if (m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }
        if (m_vc != NULL)
        {
            delete m_vc;
            m_vc = NULL;
        }
        if (m_mem != NULL)
        {
            delete m_mem;
            m_mem = NULL;
        }
    }

private:
    Cpu *m_cpu;
    VideoCard *m_vc;
    Memory *m_mem;
};

//英特尔厂商
class IntelCpu : public Cpu
{
public:
    void calculate()
    {
        cout << "Inter的cpu正在计算中======" << endl;
    }
};
class IntelVideoCard : public VideoCard
{
public:
    void display()
    {
        cout << "Intel的显卡正在显示中======" << endl;
    }
};
class IntelMemory : public Memory
{
public:
    void storage()
    {
        cout << "Intel的内存条正在存储======" << endl;
    }
};

//联想厂商
class LenovoCpu : public Cpu
{
public:
    void calculate()
    {
        cout << "Lenovo的cpu正在计算中======" << endl;
    }
};
class LenovoVideoCard : public VideoCard
{
public:
    void display()
    {
        cout << "Lenovo的显卡正在显示中======" << endl;
    }
};
class LenovoMemory : public Memory
{
public:
    void storage()
    {
        cout << "Lenovo的内存条正在存储======" << endl;
    }
};

void test01()
{
    //第一台电脑零件：
    Cpu *intelcpu = new IntelCpu;
    VideoCard *intelvideocard = new IntelVideoCard;
    Memory *intelmemory = new IntelMemory;
    //第一台电脑：
    Computer *computer1 = new Computer(intelcpu, intelvideocard, intelmemory);
    computer1->dowork();
    delete computer1;
}
void test02()
{
    //第二台电脑零件：
    Cpu *lenovocpu = new LenovoCpu;
    VideoCard *lenovovideocard = new LenovoVideoCard;
    Memory *lenovomemory = new LenovoMemory;
    //第二台电脑：
    Computer *computer2 = new Computer(lenovocpu, lenovovideocard, lenovomemory);
    computer2->dowork();
    delete computer2;
}
void test03()
{
    //第三台电脑：
    Computer *computer3 = new Computer(new LenovoCpu, new IntelVideoCard, new IntelMemory);
    computer3->dowork();
}
int main()
{
    test01();
    cout << "------------------------------------" << endl;
    cout << "------------------------------------" << endl;
    test02();
    cout << "------------------------------------" << endl;
    cout << "------------------------------------" << endl;
    test03();
    system("pause");
    return 0;
}