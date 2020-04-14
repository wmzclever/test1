#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

typedef struct LNode* List;
typedef struct DNode            //日期结构
{
    int year;
    int month;
    int day;
}Date;

typedef struct KNode            //设备信息结构
{
    char id[20];                //设备id
    char name[30];              //仪器名
    char type[30];              //型号规格
    float price;                //单价
    char user[30];              //领用人
    char state[100];            //使用状况和备注
    Date date;                  //购入日期
}Message;

struct LNode                    //设备链表
{
    Message k;
    int er;                     //标志位
    List next;
};

void Insert(List& s,Message t)  //插入设备结点
{
    List p,q;
    if(s==NULL)
    {
        s=new struct LNode;
        s->next=NULL;
        p=s;
        q=new struct LNode;
        q->er=0;
        q->k=t;
        q->next=NULL;
        p->next=q;
    }
    else
    {
        p=s;
        while(p->next)
            p=p->next;
        q=new struct LNode;
        q->k=t;
        q->next=NULL;
        p->next=q;
    }
}

void Print(List s)                                //输出设备信息表
{
    List p=s->next;
    cout<<"当前的全部记录如下\n"
    <<"依次为：设备编号、仪器名称、型号规格、单价、购入日期、领用人、使用状况和备注"<<endl;
    while(p)
    {
        cout<<p->k.id<<" "<<p->k.name<<" "<<p->k.type<<" "<<p->k.price
        <<" "<<p->k.date.year<<"-"<<p->k.date.month<<"-"<<p->k.date.day
        <<" "<<p->k.user<<" "<<p->k.state<<endl;
        p=p->next;
    }
}

void Find(const List s)	                        //多重条件查询设备
{
    int i,cnt=0;
    List p=s->next;
    int fa=1;
    int cas;
    while(p)						             //!!令链表中的标志位为0
    {
        p->er=0;
        p=p->next;
    }

    while(1)                                    //这段代码还是需要点思考的，实现多条件查询的一种比较原始的方式
    {
        p=s->next;
        cout<<"请输入（序号）您想以何种方式寻找记录:\n"
        <<"1.设备编号\n"<<"2.仪器名称\n"<<"3.型号规格\n"<<"4.单价\n"
        <<"5.购入日期\n"<<"6.领用人\n"<<"7.结束查询并输出结果"<<endl;
        cin>>i;
        switch (i)
        {
            case 1:							    //查找设备编号
                char id[10];
                cout<<"请输入想查找的设备编号，以回车结束：\n";
                cin>>id;
                while(p)
                {
                    if(!cnt)	                //如果是第一次找则直接设置相关标志位为1
                    {
                        if(!strcmp(p->k.id,id))
                        {
                            p->er=1;
                        }
                    }
                    else                        //否则如果对于不满足当前条件且标志位为1的清零
                    {
                        if(strcmp(p->k.id,id)&&(p->er==1))
                        {
                            p->er=0;
                        }
                    }
                    p=p->next;
                }
                break;
            case 2:
                char name[20];
                cout<<"请输入想查找的仪器名称，以回车结束：\n";
                cin>>name;
                while(p)
                {
                    if(!cnt)
                    {
                        if(!strcmp(p->k.name,name))
                        {
                            p->er=1;
                        }
                    }
                    else
                    {
                        if(strcmp(p->k.name,name)&&(p->er==1))
                        {
                            p->er=0;
                        }
                    }
                    p=p->next;
                }
                break;
            case 3:
                char type[10];
                cout<<"请输入想查找的仪器型号，以回车结束：\n";
                cin>>type;
                while(p)
                {
                    if(!cnt)
                    {
                        if(!strcmp(p->k.type,type))
                        {
                            p->er=1;
                        }
                    }
                    else
                    {
                        if(strcmp(p->k.type,type)&&(p->er==1))
                        {
                            p->er=0;
                        }
                    }
                    p=p->next;
                }
                break;
            case 4:
                float price;
                cout<<"请输入想查找的仪器单价，以回车结束：\n";
                cin>>price;
                while(p)
                {
                    if(!cnt)
                    {
                        if(p->k.price==price)
                        {
                            p->er=1;
                        }
                    }
                    else
                    {
                        if((p->k.price!=price)&&(p->er==1))
                        {
                            p->er=0;
                        }
                    }
                    p=p->next;
                }
                break;
            case 5:
                Date s;
                cout<<"按年查询请选1，按月查询选2，按天查询选3"<<endl;
                cin>>cas;                                                   //用户输入以年、月、日何种方式查询
                if(cas==1)
                {
                    cout<<"请输入购入年份(y)，以回车结束：\n";
                    cin>>s.year;
                    while(p)
                    {
                        if(!cnt)
                        {
                            if(p->k.date.year==s.year)
                            {
                                p->er=1;
                            }
                        }
                        else
                        {
                            if((p->k.date.year!=s.year)&&(p->er==1))
                            {
                                p->er=0;
                            }
                        }
                        p=p->next;
                    }
                }
                else if(cas==2)
                {
                    cout<<"请输入购入月份，以回车结束：\n";
                    cin>>s.month;
                    while(p)
                    {
                        if(!cnt)
                        {
                            if(p->k.date.month==s.month)
                            {
                                p->er=1;
                            }
                        }
                        else
                        {
                            if((p->k.date.month!=s.month)&&(p->er==1))
                            {
                                p->er=0;
                            }
                        }
                        p=p->next;
                    }
                }
                else if(cas==3)
                {
                    cout<<"请输入购入日期(y m d)，以回车结束：\n";
                    cin>>s.day;
                    while(p)
                    {
                        if(!cnt)
                        {
                            if(p->k.date.day==s.day)
                            {
                                p->er=1;
                            }
                        }
                        else
                        {
                            if((p->k.date.day!=s.day)&&(p->er==1))
                            {
                                p->er=0;
                            }
                        }
                        p=p->next;
                    }
                }
                else
                {
                    cout<<"输入有误,error"<<endl;
                }
                break;
            case 6:
                char user[20];
                cout<<"请输入想查找的仪器领用人，以回车结束：\n";
                cin>>user;
                while(p)
                {
                    if(!cnt)
                    {
                        if(!strcmp(p->k.user,user))
                        {
                            p->er=1;
                        }
                    }
                    else
                    {
                        if(strcmp(p->k.user,user)&&(p->er==1))
                        {
                            p->er=0;
                        }
                    }
                    p=p->next;
                }
                break;
            case 7:				                                //查询结束并输出结果
                while(p)
                {
                    if(p->er==1)		                        //输出所有链表中标志位为1的记录即为最终所求
                    {
                        fa=0;		                            //另一标志位为，fa为0说明找到查询的记录
                        cout<<p->k.id<<" "<<p->k.name<<" "<<p->k.type<<" "<<p->k.price
                        <<" "<<p->k.date.year<<"-"<<p->k.date.month<<"-"<<p->k.date.day
                        <<" "<<p->k.user<<" "<<p->k.state<<endl;
                    }
                    p=p->next;
                }
                if(fa==1)			                           //fa=1没有符合条件的记录
                    cout<<"很遗憾，没有符合条件的记录"<<endl;
                    return;
                    break;
            default:				                           //用户功能输入有误，进行提示
                    cout<<"输入错误，退出该级菜单"<<endl;
       }
        cnt++;
    }
}

void Modify(List s)                                         //修改设备信息
{
    List p=s->next;
    int t;                                                  //作为switch的选择序号
    int flag=1;
    char name[30];
    cout<<"请输入想要改的设备编号:";
    cin>>name;
    while(p)
    {
        if(!strcmp(name,p->k.id))
        {
            flag=0;
            break;
        }
        p=p->next;
    }
    if(flag)
    {
        cout<<"错误，没有该设备！"<<endl;
        return;
    }
    cout<<"请选择修改内容:\n"
    <<"1.设备编号\n"<<"2.仪器名称\n"<<"3.规格型号\n"<<"4.单价\n"
    <<"5.购入日期\n"<<"6.领用人\n"<<"7.使用情况及备注"<<endl;
    cin>>t;
    switch (t)
    {
        case 1:
            cout<<"请输入新的设备编号:";
            cin>>p->k.id;
            break;
        case 2:
            cout<<"请输入新的设备名称:";
            cin>>p->k.name;
            break;
        case 3:
            cout<<"请输入新的型号规格:";
            cin>>p->k.type;
            break;
        case 4:
            cout<<"请输入新的单价:";
            cin>>p->k.price;
            break;
        case 5:
            cout<<"请输入新的购入日期:";
            cin>>p->k.date.year>>p->k.date.month>>p->k.date.day;
            break;
        case 6:
            cout<<"请输入新的领用人:";
            cin>>p->k.user;
            break;
        case 7:
            cout<<"请输入新的使用情况及备注:";
            cin>>p->k.state;
            break;
        default:
            cout<<"错误，没有该选项！"<<endl;
    }
    cout<<"修改后该条记录如下:"
    <<p->k.id<<" "<<p->k.name<<" "<<p->k.type<<" "<<p->k.price
    <<" "<<p->k.date.year<<"-"<<p->k.date.month<<"-"<<p->k.date.day
    <<" "<<p->k.user<<" "<<p->k.state<<endl;
}

void Menu()
{
    cout<<"********欢迎使用设备管理系统***********\n"
    <<"请根据相应序号选择功能\n"
    <<"            1.从文件中恢复记录\n"
    <<"            2.添加记录\n"
    <<"            3.显示所有的记录信息\n"
    <<"            4.查询特定的记录信息\n"
    <<"            5.修改特定记录\n"
    <<"            6.重新显示菜单\n"
    <<"            7.删除记录\n"
    <<"            8.退出"
    <<endl;
}

void Relieve(List& head,FILE* fp1)              //从文件中读取表并覆盖
{
    head=new struct LNode;
    List q=head;
    List p;
    while(!feof(fp1))
    {
        p=new struct LNode;
        p->next=NULL;
        q->next=p;
        fscanf(fp1,"%s %s %s %f %d-%d-%d %s %s\n",p->k.id,p->k.name,p->k.type,&p->k.price,&p->k.date.year,&p->k.date.month,&p->k.date.day,p->k.user,p->k.state);
        q=p;
    }
}

bool Contrast(List s,Message k)                 //查看设备结点是否存在于链表中
{
    bool temp=true;
    List p=s;
    while(p)
    {
        if(!strcmp(p->k.id,k.id))
            temp=false;
        p=p->next;
    }
    return temp;
}

void Delete(List s)                            //删除设备结点
{
    List p=s->next;
    List pre=s;
    cout<<"请输入要删除的设备号:"<<endl;
    int flag=0;
    char name[30];
    cin>>name;
    while(p)
    {
        if(!strcmp(name,p->k.id))
        {
            flag=1;
            List q=p;
            pre->next=p->next;
            p=p->next;
            delete q;
            continue;
        }
        pre=p;
        p=p->next;
    }
    if(!flag)
        cout<<"删除失败"<<endl;
    else
        cout<<"删除成功，请接着操作"<<endl;
}

int main()
{
    List s=NULL;
    int n;
    FILE *fp1;
    Menu();
    while(1)
    {
        cin>>n;
        switch (n)
        {
            case 1:				                //从文件中恢复数据
                char p;
                if(s)
                {				                //如果系统已有数据，则提示用户是否继续操作
                    cout<<"现在读入会覆盖系统中所有记录，y/n"<<endl;
                    cin>>p;
                    if(p-'y'==0);
                    else if(p-'n'==0)
                    {
                        cout<<"请接着输入序号"<<endl;
                        continue;
                    }
                }
                if(!(fp1=fopen("output.txt","r")))
                {
                    cout<<"文件失败"<<endl;
                    exit(0);
                }
                Relieve(s,fp1);
                fclose(fp1);
                cout<<"恢复成功，请接着输入序号"<<endl;
                break;
            case 2:				                //向系统中添加记录
                int m;
                cout<<"请输入添加几条记录"<<endl;
                cin>>m;
                if(!n)
                {
                    cout<<"相当于没插入，很无聊，请接着输入序号"<<endl;
                    continue;
                }
                cout<<"请输入("<<m<<"条)设备编号（8位数）、仪器名称、型号规格、单价、购入日期、领用人、使用状况和备注(50字)"<<endl;
                for(int i=0;i<m;i++)
                {
                    Message k;
                    cin>>k.id>>k.name>>k.type>>k.price>>k.date.year>>k.date.month>>k.date.day>>k.user>>k.state;
                    if(Contrast(s,k)==false)
                        cout<<"设备编号有重复，error,"<<k.id<<"该条插入失败"<<endl;
                    else
                        Insert(s,k);
                }
                cout<<"请接着输入序号"<<endl;
                break;
            case 3:					           //显示所有记录
                if(!s)
                {
                    cout<<"列表中无信息，请先输入"<<endl;
                    continue;
                }
                Print(s);
                cout<<"操作成功，请接着输入序号"<<endl;
                break;
            case 4:					          //查找相应记录
                if(!s)
                {
                    cout<<"列表中无信息，请先输入"<<endl;
                    continue;
                }
                Find(s);
                cout<<"操作成功，请接着输入序号"<<endl;
                break;
            case 5:			                  //修改相应记录
                if(!s)
                {
                    cout<<"列表中无信息，请先输入"<<endl;
                    continue;
                }
                Modify(s);
                cout<<"操作成功，请接着输入序号"<<endl;
                break;
            case 6:			                //显示菜单
                Menu();
                break;
            case 7:			                //删除记录
                if(!s)
                {
                    cout<<"系统中暂无记录无法删除"<<endl;
                    continue;
                }
                Delete(s);
                break;
            case 8:			               //退出并保存文件
                if(!s)
                    exit(0);
                else
                {
                    List p=s->next;
                    if(!(fp1=fopen("output.txt","w")))
                    {
                        cout<<"文件存取失败"<<endl;
                        exit(0);
                    }
                    while(p)
                    {
                        fprintf(fp1,"%s %s %s %.2f %d-%d-%d %s %s\n",p->k.id,p->k.name,p->k.type,p->k.price,p->k.date.year,p->k.date.month,p->k.date.day,p->k.user,p->k.state);
                        p=p->next;
                    }
                    fclose(fp1);
                    cout<<"文件已经成功存储到output.txt文件"<<endl;
                    exit(0);
                }
            default:
                cout<<"输入错误,重新输入"<<endl;
        }
    }
    return 0;
}
