#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <utility>

std::map<int, std::pair<std::string, std::string>> animal_group = {
       {1, {"Cat","Riti"} },
       {2, {"Cat","Jack"} },
       {3, {"Dog","Nick"} },
       {4, {"Fish","Bob"} },
       {5, {"Cat","Flus"} },
       {6, {"Dog","Max"} },
       {7, {"Fish","Gem"} },
       {8, {"Mouse","Flus"} },
       {9, {"Bird","Max"} },
       {10, {"Bird","Chiu"} },
       {11, {"Dog","Jonh"} },
       {12, {"Cat","Hiss"} },
       {13, {"Dog","Nick"} },
       {14, {"Fish","Bob"} },
       {15, {"Cat","Flus"} },
       {16, {"Dog","Peanut"} },
       {17, {"Fish","Nemo"} },
       {18, {"Mouse","Cheese"} },
       {19, {"Mouse","Max"} },
       {20, {"Mouse","Can"} }
};

//-----------------------INTERFACE ANIMAL----------------------------//
class Animal
{
public:
    Animal() {}
    Animal(const Animal&) = delete;
    Animal & operator=(const Animal&) = delete;
    virtual void sound() = 0;
    virtual void move() = 0;
    virtual ~Animal() {}
};

//-----------------------------ANIMALS-------------------------------//
class Cat: public Animal{
private:
    const std::string name;
public:
    static size_t count;
    Cat(const std::string nam):name(nam){
        std::cout << "Cat: " << this->name<<" created" << std::endl;
        count++;
    };
    Cat(const Cat&) = delete;
    Cat & operator=(const Cat&) = delete;
    void sound(){ 
        std::cout << "Cat: " << this->name<<" is mewing" << std::endl; 
    };
    void move(){ 
        std::cout << "Cat: " << this->name<<" is moving fast" << std::endl; 
    };
    ~Cat(){
        std::cout << "Cat: " << this->name<<" destroyed" << std::endl; 
    };
};

class Dog: public Animal{
private:
    const std::string name;
public:
    static size_t count;
    Dog(const std::string nam):name(nam){
        std::cout << "Dog: " << this->name<<" created" << std::endl;
        count++;
    };
    Dog(const Dog&) = delete;
    Dog & operator=(const Dog&) = delete;
    void sound(){ 
        std::cout << "Dog: " << this->name<<" is barking" << std::endl; 
    };
    void move(){ 
        std::cout << "Dog: " << this->name<<" is moving very fast" << std::endl; 
    };
    ~Dog(){
        std::cout << "Dog: " << this->name<<" destroyed" << std::endl; 
   };
};

class Fish: public Animal{
private:
    const std::string name;
public:
    static size_t count;
    Fish(const std::string nam):name(nam){
        std::cout << "Fish: " << this->name<<" created" << std::endl;
        count++;
    };
    Fish(const Fish&) = delete;
    Fish & operator=(const Fish&) = delete;
    void sound(){ 
        std::cout << "Fish: " << this->name<<" do not make sounds" << std::endl; 
    };
    void move(){ 
        std::cout << "Fish: " << this->name<<" is swimming fast" << std::endl; 
    };
    ~Fish(){
        std::cout << "Fish: " << this->name<<" destroyed" << std::endl; 
    };
};

class Bird: public Animal{
private:
    const std::string name;
public:
    static size_t count;
    Bird(const std::string nam):name(nam){
        std::cout << "Bird: " << this->name<<" created" << std::endl;
        count++;
    };
    Bird(const Bird&) = delete;
    Bird & operator=(const Bird&) = delete;
    void sound(){ 
        std::cout << "Bird: " << this->name<<" is singing" << std::endl; 
    };
    void move(){ 
        std::cout << "Bird: " << this->name<<" is flying fast" << std::endl; 
    };
    ~Bird(){
        std::cout << "Bird: " << this->name<<" destroyed" << std::endl; 
    };
};

class Mouse: public Animal{
private:
    const std::string name;
public:
    static size_t count;
    Mouse(const std::string nam):name(nam){
        std::cout << "Mouse: " << this->name<<" created" << std::endl;
        count++;
    };
    Mouse(const Mouse&) = delete;
    Mouse & operator=(const Mouse&) = delete;
    void sound(){ 
        std::cout << "Mouse: " << this->name<<" is scraching" << std::endl; 
    };
     void move(){ 
        std::cout << "Mouse: " << this->name<<" is moving slow" << std::endl; 
    };
    ~Mouse(){
        std::cout << "Mouse: " << this->name<<" destroyed" << std::endl; 
    };
};

//---------------------------FACTORYY--------------------------------//
class Factory
{
public:
    Factory(){
        std::cout << "Animal created" << std::endl; 
    };
    ~Factory(){
        std::cout << "Animal destroyed" << std::endl; 
    };
    static std::shared_ptr<Animal> create(const std::string& animal,const std::string& name)
    {
        if (animal.find("Cat") != std::string::npos) {
            return std::make_shared<Cat>(name);
        }
        else if(animal.find("Dog") != std::string::npos){
            return std::make_shared<Dog>(name);
        }
        else if(animal.find("Bird") != std::string::npos){
            return std::make_shared<Bird>(name);
        }
        else if(animal.find("Fish") != std::string::npos){
            return std::make_shared<Fish>(name);
        }
        else if(animal.find("Mouse") != std::string::npos){
            return std::make_shared<Mouse>(name);
        }
        else{
            return nullptr;
        }
    }
};

//--------------------ANIMAL GROUP FUNCTIONS-------------------------//

void animal_sounds(std::shared_ptr<Animal> anim){
    anim->sound();
}

void animal_move(std::shared_ptr<Animal> anim){
    anim->move();
}

void animal_group_function(std::vector<std::shared_ptr<Animal>> &animal_vect, void(*func)(std::shared_ptr<Animal>)){
    for (auto const& x : animal_vect){
        func(x);
    }
}

size_t Cat::count = 0;
size_t Dog::count = 0;
size_t Fish::count = 0;
size_t Bird::count = 0;
size_t Mouse::count = 0;

//----------------------------------MAIN----------------------------------------//
int main()
{   
    std::vector<std::shared_ptr<Animal>> animal_vect;
    std::shared_ptr<Animal> animal;
    
    for (auto const& x : animal_group)
    {
        animal = (Factory::create( x.second.first, x.second.second));
        if(animal != nullptr){
            animal_vect.push_back(std::move(animal));
        }
        else{
            std::cout << "\nEnd of main not completed...\n" << std::endl; 
            return -1;
        }
    }
    
    std::cout << "\n...Check all animal sounds...\n" << std::endl; 
    animal_group_function(animal_vect,animal_sounds);
    
    std::cout << "\n...Check all animal movements...\n" << std::endl; 
    animal_group_function(animal_vect,animal_move);

    std::cout << "\n...Summary...\n" << std::endl; 
    std::cout << "Cats:  "<<Cat::count<<std::endl;
    std::cout << "Dog:   "<<Dog::count<<std::endl;
    std::cout << "Fish:  "<<Fish::count<<std::endl;
    std::cout << "Bird:  "<<Bird::count<<std::endl;
    std::cout << "Mouse: "<<Mouse::count<<std::endl;
    
    std::cout << "\nEnd of main...\n" << std::endl; 
    return 0;
}