#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <algorithm>
#include <typeinfo>

class Message_Listener;

//Factory_Message_Receiver
class Factory_Message_Receiver
{
public:
    Factory_Message_Receiver() {}
    virtual void senbMessage(std::string) {}
    virtual void registerReceiver(Message_Listener &) {};
    virtual void unregisterReceiver(Message_Listener &,int) {};
    virtual ~Factory_Message_Receiver() {}
};

//INTERFACE
class I_Listener: public std::enable_shared_from_this<Message_Listener>{
public:
    virtual void registerToReceiver(std::weak_ptr<Factory_Message_Receiver>) = 0;
    virtual void unregisterToReceiver(std::weak_ptr<Factory_Message_Receiver>) = 0;
    virtual void update(std::string& ) = 0;
};

//Message_Listener
class Message_Listener : public I_Listener{

private:
    int id;
    static int listenerIDTRacker;
public:
    Message_Listener( int i):id(i){
           std::cout <<"Listener "<< this->id<<" created" << std::endl; 
           listenerIDTRacker++;
    };
    Message_Listener():id(listenerIDTRacker){
           std::cout <<"Listener "<< this->id<<" created" << std::endl; 
           listenerIDTRacker++;
    };
    ~Message_Listener(){
           std::cout <<"Listener "<< this->id<<" destroyed" << std::endl; 
    };
   void registerToReceiver(std::weak_ptr<Factory_Message_Receiver> reg) override { 
        if (!reg.expired()) {
            if(auto tmp = reg.lock()){
                std::cout <<"Listener "<< this->id<<" will register..." << std::endl;
                tmp->registerReceiver((*this));
            }
        }
   }
   void unregisterToReceiver(std::weak_ptr<Factory_Message_Receiver> reg) override { 
        if (!reg.expired()) {
            if(auto tmp = reg.lock()){
                std::cout <<"Listener "<< this->id<<" will unregister from Receiver..." << std::endl;
                tmp->unregisterReceiver((*this), this->id);
            }
        }
   }
    void update(std::string& name) override{
        std::cout<<"Message Listener("<<this->id<<") received: "<<name<<std::endl;
    }
    int getID(){
        return this->id;
    }
};

int Message_Listener::listenerIDTRacker = 1;

//Message_Receiver
class Message_Receiver: public Factory_Message_Receiver{
private:
    std::string name;
    std::string msg;
    std::list<std::weak_ptr<Message_Listener>> intList;

public:
    Message_Receiver( std::string nam):name(nam),msg(""){
        std::cout << this->name<<" created" << std::endl; 
    };
    ~Message_Receiver(){
        std::cout << this->name<<" destroyed" << std::endl; 
    };
    void registerReceiver(Message_Listener& reg) override{ 
        std::cout<<"Register new entry to Listener "<<reg.getID()<<std::endl;
        auto tmp = reg.shared_from_this();
        
        intList.push_back(reg.shared_from_this());
    }
    void unregisterReceiver(Message_Listener& reg, int id_lst) override{ 
        std::cout<<"UnRegister entry: Listener "<<reg.getID()<<std::endl;
        auto iter = std::find_if(intList.begin(), intList.end(), [=](std::weak_ptr<Message_Listener> s) -> bool { return ((s.lock())->getID() == id_lst); });
        if ( iter != intList.end() )
        {
            intList.erase((iter));
        }
    }
    void senbMessage(std::string inputMess) override{
        
        std::cout << this->name<<" sends msg: "<< inputMess << std::endl; 
        for (auto i : intList) {
            if (!i.expired()) {
                if (auto spt = i.lock()) { 
                    spt->update(inputMess);
                }
            }
        }
    }
};

//FACTORYY
class Factory
{
public:
    Factory(){
        std::cout << "Factory created" << std::endl; 
    };
    ~Factory(){
        std::cout << "Factory destroyed" << std::endl; 
    };
    static std::shared_ptr<Factory_Message_Receiver> create( std::string& name)
    {
        if (name.find("Receiver") != std::string::npos) {
            return std::make_shared<Message_Receiver>(name);
        }
        else{
            return nullptr;
        }
    }
};


//----------------------------------MAIN----------------------------------------
int main()
{   
    // Example of Factory/Observer patter with smart Pointers
    {
        // Initialize variables
        std::string name("Receiver_1");
        std::string msg1("Hello World!!!");
        std::string msg2("Goodbye World!!!");
        std::string msg3("No one is listening!!!");

    
        std::shared_ptr<Factory_Message_Receiver> msg_rec(Factory::create(name));
        if(msg_rec == nullptr){
           return -1;
        }
        std::shared_ptr<Message_Listener> msg_lis1(new Message_Listener());
        if(msg_lis1 == nullptr){
           return -1;
        }
        std::shared_ptr<Message_Listener> msg_lis2(new Message_Listener());
        if(msg_lis2 == nullptr){
           return -1;
        }
        std::shared_ptr<Message_Listener> msg_lis3(new Message_Listener());
        if(msg_lis3 == nullptr){
           return -1;
        }
    
        std::weak_ptr<Factory_Message_Receiver> w_msg_rec = msg_rec;
        std::cout<<std::endl;
    
        // Register listeners to Receiver
        msg_lis1->registerToReceiver(w_msg_rec);
    
        msg_lis2->registerToReceiver(w_msg_rec);
        
        msg_lis3->registerToReceiver(w_msg_rec);
    
        std::cout<<std::endl;
    
        // Receivers sends messages
        msg_rec->senbMessage(msg1);
        std::cout<<std::endl;
        
        msg_rec->senbMessage(msg2);
        std::cout<<std::endl;
    
        // UnRegister listeners(1,2) from Receiver
        msg_lis1->unregisterToReceiver(w_msg_rec);
    
        msg_lis2->unregisterToReceiver(w_msg_rec);
        
        std::cout<<std::endl;
    
        // Receivers sends message only to Listener 3
        msg_rec->senbMessage(msg2);
        std::cout<<std::endl;
    
        // UnRegister listeners(3) from Receiver
        msg_lis3->unregisterToReceiver(w_msg_rec);
        std::cout<<std::endl;
        
         // Receivers sends messages
        msg_rec->senbMessage(msg3);
        std::cout<<std::endl;
    }

    // Example of Lamnda inside an std algorithm for a vector
    {
        std::vector<int> vect { 1, 2,3,4,5,44,20,6,55,66,77,4,666};
        int lim = 20;
        std::cout<<"\n\nVector before erase(elements less than : " << lim <<")"<<std::endl;
        for(auto v : vect){
            std::cout<<v<< " ";
        }
        std::cout<<"\n\nVector after erase (elements less than : " << lim <<")"<<std::endl;
        auto iter_er = std::remove_if(vect.begin(), vect.end(),[=](const int& x)->bool { return (x < lim); });
        vect.erase(iter_er, vect.end());
        for(auto v : vect){
            std::cout<<v<< " ";
        }
        std::cout<<std::endl<<std::endl;
    }
    return 0;
}