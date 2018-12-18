//
//  main.cpp
//  test2
//
//  Created by 魏云飞 on 2017/10/17.
//  Copyright © 2017年 魏云飞. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;
class employee{
    private:
        static employee *top;
        static employee *ground;
        static employee *now;
        static size_t Number;
        static size_t AllMoney;
        employee *next=nullptr;
        employee *head=nullptr;
        size_t number;
        string name;
        size_t money;
        char sex;
    public:
        employee(string a,size_t b,char c){
            if(top==nullptr){
                top=(employee*)malloc(sizeof(employee));
                ground=(employee*)malloc(sizeof(employee));
                now=(employee*)malloc(sizeof(employee));
                top=this;
                ground=this;
                Number=1;
            }
            ground->next=(employee*)malloc(sizeof(employee));
            next=this;
            head=ground;
            ground=this;
            name=a;
            money=b;
            sex=c;
            AllMoney+=b;
            number=Number;
            Number++;
            cout<<"构建成功"<<endl;
        };
        ~employee(){
            if(ground==this){
                if(head!=nullptr){
                    ground=head;
                }
                else{
                    delete this;
                }
            }
            if(top==this){
                if(next==nullptr){
                    delete this;
                }
                else{
                    top=next;
                }
            }
            if(head!=nullptr){
                    head->next=next;
                }
            if(next!=nullptr){
                next->head=head;
            }
            free(next);
            free(head);
            free(now);
            delete next;
            delete head;
            now=nullptr;
        }
        employee(const employee &mi){
            name=mi.name;
            money=mi.money;
            sex=mi.sex;
            if(mi.head!=nullptr){
                head=(employee*)malloc(sizeof(employee));
                *head=*mi.head;
            }
            if(mi.next!=nullptr){
                next=(employee*)malloc(sizeof(employee));
                *next=*mi.next;
            }
        }
        static void Search(size_t a){
            now=(employee*)malloc(sizeof(employee));
            *now=*top;
            for(;now!=nullptr;){
                if(now->number==a){
                    cout<<"雇员姓名："<<now->name<<endl<<"雇员薪酬："<<now->money<<endl<<"雇员性别"<<now->sex<<endl;
                    cout<<"查找完成"<<endl;
                    now=nullptr;
                    return;
                }
                else{
                    now=now->next;
                }
            }
            cout<<"不存在该编号"<<endl;
            now=nullptr;
        }
         static void Delete(size_t a){
            now=(employee*)malloc(sizeof(employee));
            *now=*top;
            for(;now!=nullptr;){
                if(now->number==a){
                    delete now;
                    cout<<"删除完成"<<endl;
                    now=nullptr;
                    return;
                }
                else{
                    now=now->next;
                }
            }
            cout<<"不存在该编号"<<endl;
            now=nullptr;
        }
/*        static bool Search_ground_nullptr(){
            if(ground==nullptr){
                return false;
            }
            else{
                return true;
            }
        }
        static employee Ground_return(){
            return *ground;
        }*/
        friend void Get_all();
};

void Get_all(){
    cout<<"总薪酬为"<<employee::AllMoney<<endl;
}

int main(){
    size_t a;
    size_t b;
    string c;
    char d;
    cout<<"输入你想要执行的操作"<<endl;
    cout<<"1.增加雇员"<<endl;
    cout<<"2.删除雇员"<<endl;
    cout<<"3.查找雇员"<<endl;
    cout<<"4.检视当前总薪酬"<<endl;
    cout<<"5.结束程序"<<endl;
    for(;;){
        cout<<"请输入:"<<endl;
        cin>>a;
        switch(a){
            case 1:
                cout<<"输入新建雇员的姓名，薪酬，性别"<<endl;
                cin>>c;
                cin>>b;
                cin>>d;
                employee *x=new employee(c,b,d);
                break;
            case 2:
                cout<<"输入要删除的雇员编号："<<endl;
                cin>>b;
                employee::Delete(b);
                break;
            case 3:
                cout<<"输入要查找雇员编号:"<<endl;
                cin>>b;
                employee::Search(b);
                break;
            case 4:
                Get_all();
                break;
            case 5:
                exit(0);
            default:
                cout<<"指令无效"<<endl;
        }
    }
}
