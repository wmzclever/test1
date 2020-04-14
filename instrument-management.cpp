#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

typedef struct LNode* List;
typedef struct DNode            //���ڽṹ
{
    int year;
    int month;
    int day;
}Date;

typedef struct KNode            //�豸��Ϣ�ṹ
{
    char id[20];                //�豸id
    char name[30];              //������
    char type[30];              //�ͺŹ��
    float price;                //����
    char user[30];              //������
    char state[100];            //ʹ��״���ͱ�ע
    Date date;                  //��������
}Message;

struct LNode                    //�豸����
{
    Message k;
    int er;                     //��־λ
    List next;
};

void Insert(List& s,Message t)  //�����豸���
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

void Print(List s)                                //����豸��Ϣ��
{
    List p=s->next;
    cout<<"��ǰ��ȫ����¼����\n"
    <<"����Ϊ���豸��š��������ơ��ͺŹ�񡢵��ۡ��������ڡ������ˡ�ʹ��״���ͱ�ע"<<endl;
    while(p)
    {
        cout<<p->k.id<<" "<<p->k.name<<" "<<p->k.type<<" "<<p->k.price
        <<" "<<p->k.date.year<<"-"<<p->k.date.month<<"-"<<p->k.date.day
        <<" "<<p->k.user<<" "<<p->k.state<<endl;
        p=p->next;
    }
}

void Find(const List s)	                        //����������ѯ�豸
{
    int i,cnt=0;
    List p=s->next;
    int fa=1;
    int cas;
    while(p)						             //!!�������еı�־λΪ0
    {
        p->er=0;
        p=p->next;
    }

    while(1)                                    //��δ��뻹����Ҫ��˼���ģ�ʵ�ֶ�������ѯ��һ�ֱȽ�ԭʼ�ķ�ʽ
    {
        p=s->next;
        cout<<"�����루��ţ������Ժ��ַ�ʽѰ�Ҽ�¼:\n"
        <<"1.�豸���\n"<<"2.��������\n"<<"3.�ͺŹ��\n"<<"4.����\n"
        <<"5.��������\n"<<"6.������\n"<<"7.������ѯ��������"<<endl;
        cin>>i;
        switch (i)
        {
            case 1:							    //�����豸���
                char id[10];
                cout<<"����������ҵ��豸��ţ��Իس�������\n";
                cin>>id;
                while(p)
                {
                    if(!cnt)	                //����ǵ�һ������ֱ��������ر�־λΪ1
                    {
                        if(!strcmp(p->k.id,id))
                        {
                            p->er=1;
                        }
                    }
                    else                        //����������ڲ����㵱ǰ�����ұ�־λΪ1������
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
                cout<<"����������ҵ��������ƣ��Իس�������\n";
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
                cout<<"����������ҵ������ͺţ��Իس�������\n";
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
                cout<<"����������ҵ��������ۣ��Իس�������\n";
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
                cout<<"�����ѯ��ѡ1�����²�ѯѡ2�������ѯѡ3"<<endl;
                cin>>cas;                                                   //�û��������ꡢ�¡��պ��ַ�ʽ��ѯ
                if(cas==1)
                {
                    cout<<"�����빺�����(y)���Իس�������\n";
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
                    cout<<"�����빺���·ݣ��Իس�������\n";
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
                    cout<<"�����빺������(y m d)���Իس�������\n";
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
                    cout<<"��������,error"<<endl;
                }
                break;
            case 6:
                char user[20];
                cout<<"����������ҵ����������ˣ��Իس�������\n";
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
            case 7:				                                //��ѯ������������
                while(p)
                {
                    if(p->er==1)		                        //������������б�־λΪ1�ļ�¼��Ϊ��������
                    {
                        fa=0;		                            //��һ��־λΪ��faΪ0˵���ҵ���ѯ�ļ�¼
                        cout<<p->k.id<<" "<<p->k.name<<" "<<p->k.type<<" "<<p->k.price
                        <<" "<<p->k.date.year<<"-"<<p->k.date.month<<"-"<<p->k.date.day
                        <<" "<<p->k.user<<" "<<p->k.state<<endl;
                    }
                    p=p->next;
                }
                if(fa==1)			                           //fa=1û�з��������ļ�¼
                    cout<<"���ź���û�з��������ļ�¼"<<endl;
                    return;
                    break;
            default:				                           //�û������������󣬽�����ʾ
                    cout<<"��������˳��ü��˵�"<<endl;
       }
        cnt++;
    }
}

void Modify(List s)                                         //�޸��豸��Ϣ
{
    List p=s->next;
    int t;                                                  //��Ϊswitch��ѡ�����
    int flag=1;
    char name[30];
    cout<<"��������Ҫ�ĵ��豸���:";
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
        cout<<"����û�и��豸��"<<endl;
        return;
    }
    cout<<"��ѡ���޸�����:\n"
    <<"1.�豸���\n"<<"2.��������\n"<<"3.����ͺ�\n"<<"4.����\n"
    <<"5.��������\n"<<"6.������\n"<<"7.ʹ���������ע"<<endl;
    cin>>t;
    switch (t)
    {
        case 1:
            cout<<"�������µ��豸���:";
            cin>>p->k.id;
            break;
        case 2:
            cout<<"�������µ��豸����:";
            cin>>p->k.name;
            break;
        case 3:
            cout<<"�������µ��ͺŹ��:";
            cin>>p->k.type;
            break;
        case 4:
            cout<<"�������µĵ���:";
            cin>>p->k.price;
            break;
        case 5:
            cout<<"�������µĹ�������:";
            cin>>p->k.date.year>>p->k.date.month>>p->k.date.day;
            break;
        case 6:
            cout<<"�������µ�������:";
            cin>>p->k.user;
            break;
        case 7:
            cout<<"�������µ�ʹ���������ע:";
            cin>>p->k.state;
            break;
        default:
            cout<<"����û�и�ѡ�"<<endl;
    }
    cout<<"�޸ĺ������¼����:"
    <<p->k.id<<" "<<p->k.name<<" "<<p->k.type<<" "<<p->k.price
    <<" "<<p->k.date.year<<"-"<<p->k.date.month<<"-"<<p->k.date.day
    <<" "<<p->k.user<<" "<<p->k.state<<endl;
}

void Menu()
{
    cout<<"********��ӭʹ���豸����ϵͳ***********\n"
    <<"�������Ӧ���ѡ����\n"
    <<"            1.���ļ��лָ���¼\n"
    <<"            2.��Ӽ�¼\n"
    <<"            3.��ʾ���еļ�¼��Ϣ\n"
    <<"            4.��ѯ�ض��ļ�¼��Ϣ\n"
    <<"            5.�޸��ض���¼\n"
    <<"            6.������ʾ�˵�\n"
    <<"            7.ɾ����¼\n"
    <<"            8.�˳�"
    <<endl;
}

void Relieve(List& head,FILE* fp1)              //���ļ��ж�ȡ������
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

bool Contrast(List s,Message k)                 //�鿴�豸����Ƿ������������
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

void Delete(List s)                            //ɾ���豸���
{
    List p=s->next;
    List pre=s;
    cout<<"������Ҫɾ�����豸��:"<<endl;
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
        cout<<"ɾ��ʧ��"<<endl;
    else
        cout<<"ɾ���ɹ�������Ų���"<<endl;
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
            case 1:				                //���ļ��лָ�����
                char p;
                if(s)
                {				                //���ϵͳ�������ݣ�����ʾ�û��Ƿ��������
                    cout<<"���ڶ���Ḳ��ϵͳ�����м�¼��y/n"<<endl;
                    cin>>p;
                    if(p-'y'==0);
                    else if(p-'n'==0)
                    {
                        cout<<"������������"<<endl;
                        continue;
                    }
                }
                if(!(fp1=fopen("output.txt","r")))
                {
                    cout<<"�ļ�ʧ��"<<endl;
                    exit(0);
                }
                Relieve(s,fp1);
                fclose(fp1);
                cout<<"�ָ��ɹ���������������"<<endl;
                break;
            case 2:				                //��ϵͳ����Ӽ�¼
                int m;
                cout<<"��������Ӽ�����¼"<<endl;
                cin>>m;
                if(!n)
                {
                    cout<<"�൱��û���룬�����ģ�������������"<<endl;
                    continue;
                }
                    cout<<"������("<<m<<"��)�豸��ţ�8λ�������������ơ��ͺŹ�񡢵��ۡ��������ڡ������ˡ�ʹ��״���ͱ�ע(50��)"<<endl;
                for(int i=0;i<m;i++)
                {
                    Message k;
                    cin>>k.id>>k.name>>k.type>>k.price>>k.date.year>>k.date.month>>k.date.day>>k.user>>k.state;
                    if(Contrast(s,k)==false)
                        cout<<"�豸������ظ���error,"<<k.id<<"��������ʧ��"<<endl;
                    else
                        Insert(s,k);
                }
                cout<<"������������"<<endl;
                break;
            case 3:					           //��ʾ���м�¼
                if(!s)
                {
                    cout<<"�б�������Ϣ����������"<<endl;
                    continue;
                }
                Print(s);
                cout<<"�����ɹ���������������"<<endl;
                break;
            case 4:					          //������Ӧ��¼
                if(!s)
                {
                    cout<<"�б�������Ϣ����������"<<endl;
                    continue;
                }
                Find(s);
                cout<<"�����ɹ���������������"<<endl;
                break;
            case 5:			                  //�޸���Ӧ��¼
                if(!s)
                {
                    cout<<"�б�������Ϣ����������"<<endl;
                    continue;
                }
                Modify(s);
                cout<<"�����ɹ���������������"<<endl;
                break;
            case 6:			                //��ʾ�˵�
                Menu();
                break;
            case 7:			                //ɾ����¼
                if(!s)
                {
                    cout<<"ϵͳ�����޼�¼�޷�ɾ��"<<endl;
                    continue;
                }
                Delete(s);
                break;
            case 8:			               //�˳��������ļ�
                if(!s)
                    exit(0);
                else
                {
                    List p=s->next;
                    if(!(fp1=fopen("output.txt","w")))
                    {
                        cout<<"�ļ���ȡʧ��"<<endl;
                        exit(0);
                    }
                    while(p)
                    {
                        fprintf(fp1,"%s %s %s %.2f %d-%d-%d %s %s\n",p->k.id,p->k.name,p->k.type,p->k.price,p->k.date.year,p->k.date.month,p->k.date.day,p->k.user,p->k.state);
                        p=p->next;
                    }
                    fclose(fp1);
                    cout<<"�ļ��Ѿ��ɹ��洢��output.txt�ļ�"<<endl;
                    exit(0);
                }
            default:
                cout<<"�������,��������"<<endl;
        }
    }
    return 0;
}
