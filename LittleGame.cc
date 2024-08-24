#include <bits/stdc++.h>
using namespace std;

class world{
private:
    static string home_kind[];
public:
    bool illegal_home(string home);    
};

bool world::illegal_home(string home){
    string tmp = home;
    for(int i = 0; i<4; i++){
        if(tmp == home_kind[i]){
            return false;
        }
    }
    cout<<"你家的星球不在星球列表中，不要耍我，請選擇你家的星球"<<endl;
    system("pause");
    return true;
};

string world::home_kind[] = {"Earth", "Mars", "Moon", "Pluto"};

class person{             //virtual class for inheritance，don't need to create object of this class，no constructor
protected:
    string name;
    string home;
    int height;
    int weight;
    int intelligence;
    bool illegal_name(string name);         //only allow English name，so we can use parent's member function to check
    virtual void do_height() = 0;
    virtual void do_weight() = 0;
    virtual void do_intelligence() = 0;
    bool found(person*);
public:
    virtual void input(string) = 0;         //pure virtual function for do more detail for different person on  different planet
    void print_person();                    //print the same information for different person on different planet (for one person)
    virtual void print_data() = 0;          //print all information for different person on different planet (for all person)
    virtual void remove() = 0;              //remove the person on different planet (for one person)
    virtual void sort_yourself() = 0;       //sort the person on different planet by elements (for all person)
    string get_name();                     //get the name of the person on different planet (for one person)
    string get_home();                     //get the home of the person on different planet (for one person)
    int get_height();                      //get the height of the person on different planet (for one person)
    int get_weight();                      //get the weight of the person on different planet (for one person)
    int get_intelligence();                //get the intelligence of the person on different planet (for one person)
    virtual int get_rank(person*, char, int) = 0;   //get the rank of the person on different planet by elements (for one person)
};

string person::get_name(){
    return this->name;
}


string person::get_home(){
    return this->home;
}

int person::get_height(){
    return this->height;
}

int person::get_weight(){
    return this->weight;
}

int person::get_intelligence(){
    return this->intelligence;
}

bool person::found(person* p){
    cout<<endl;
    p->print_person();
    char choice{0};
    cout<<"你確定是他？(y/n) : ";
    do{
        cin>>choice;
        if(choice == 'y'){
            return true;
        }
        else if(choice == 'n'){
            return false;
        }
        else{
            cout<<"請輸入小寫 : ";
        }
    }while(1);
}

void person::print_person(){
    cout << "Person Information:" << endl;
    cout << "Name:              " << this->name << endl;
    cout << "Home:              " << this->home << endl;
    cout << "Height:            " << this->height << endl;
    cout << "Weight:            " << this->weight << endl;
    cout << "Intelligence:      " << this->intelligence << endl;
}

bool person::illegal_name(string name){
    for(int i=0; i<name.size(); i++){
        if((name[i] < 'a' || name[i] > 'z') && (name[i] < 'A' || name[i] > 'Z') && (name[i] != ' ')){
            return true;
        }
    }
    return false;
}

class Earth_person:public person{
private:
    static vector<Earth_person> earth_people;
    void do_height();
    void do_weight();
    void do_intelligence();
public:
    Earth_person(string name = "", string home = "", int height = 0, int weight = 0, int intelligence = 0);
    void input(string);
    void print_data();
    void remove();
    void sort_yourself();
    Earth_person(const Earth_person&);
    Earth_person& operator=(const Earth_person&);
    int get_size();
    int get_rank(person*, char, int);
};

int Earth_person::get_rank(person* you, char detail, int choice_three){
    int E_rank{0};
    if(choice_three == 1){
        for(int i = 0; i<earth_people.size(); i++){
            if((earth_people[i].get_height()) > (you->get_height())){
                E_rank++;
                if(detail == 'y'){
                    this->earth_people[i].print_person();
                    cout<<endl;
                }
            }
        }
    }
    else if(choice_three == 2){
        for(int i = 0; i<earth_people.size(); i++){
            if(earth_people[i].get_weight() > you->get_weight()){
                E_rank++;
                if(detail == 'y'){
                    this->earth_people[i].print_person();
                    cout<<endl;
                }
            }
        }
    }
    else if(choice_three == 3){
        for(int i = 0; i<i<earth_people.size(); i++){
            if(earth_people[i].get_intelligence() > you->get_intelligence()){
                E_rank++;
                if(detail == 'y'){
                    this->earth_people[i].print_person();
                    cout<<endl;
                }
            }
        }
    }
    return E_rank;
}

int Earth_person::get_size(){
    return earth_people.size();
}

Earth_person::Earth_person(const Earth_person& other){
    this->name = other.name;
    this->home = other.home;
    this->height = other.height;
    this->weight = other.weight;
    this->intelligence = other.intelligence;
}

Earth_person& Earth_person::operator=(const Earth_person& other){
    this->name = other.name;
    this->home = other.home;
    this->height = other.height;
    this->weight = other.weight;
    this->intelligence = other.intelligence;
    return *this;
}

void Earth_person::do_height(){
    for(int i = 0; i<earth_people.size()-1; i++){
        for(int j = (i+1); j<earth_people.size(); j++){
            if(earth_people[i].height > earth_people[j].height){
                Earth_person temp = earth_people[i];                //copy constructor
                earth_people[i] = earth_people[j];                  //operator=
                earth_people[j] = temp;                             //operator=
            }            
        }
    }
}


void Earth_person::do_weight(){
    for(int i = 0; i<earth_people.size()-1; i++){
        for(int j = (i+1); j<earth_people.size(); j++){
            if(earth_people[i].weight > earth_people[j].weight){
                Earth_person temp = earth_people[i];                //copy constructor
                earth_people[i] = earth_people[j];
                earth_people[j] = temp;
            }            
        }
    }
}

void Earth_person::do_intelligence(){
    for(int i = 0; i<earth_people.size()-1; i++){
        for(int j = (i+1); j<earth_people.size(); j++){
            if(earth_people[i].intelligence > earth_people[j].intelligence){
                Earth_person temp = earth_people[i];                //copy constructor
                earth_people[i] = earth_people[j];                  //operator=
                earth_people[j] = temp;                             //operator=
            }            
        }
    }
}

void Earth_person::sort_yourself(){
    int which{0}; 
    cout<<"1. Height"<<endl;
    cout<<"2. Weight"<<endl;
    cout<<"3. Intelligence"<<endl;
    cout<<"Which one do you want to sort by? (請輸入數字): ";
    cin>>which;
    if(which == 1){
        this->do_height();
    }
    else if(which == 2){
        this->do_weight();
    }
    else if(which == 3){
        this->do_intelligence();
    }
    else{
        cout<<"Invalid input"<<endl;
        system("pause");
        return;
    }
    cout<<"Sorted by "<<which<<endl;
    for(int i=0; i<earth_people.size(); i++){
        earth_people[i].print_person();
        cout<<endl;
    }
}

void Earth_person::remove(){
    string search = "\0";
    getline(cin, search);
    for(int i=0; i<earth_people.size(); i++){
        if(earth_people[i].name == search){
            bool flag = found(&earth_people[i]);
            if(flag){
                earth_people.erase(earth_people.begin()+i);
                cout<<"Person "<<search<<" has been removed from the Earth planet"<<endl;
                system("pause");
                return;
            }
            continue;
        }
    }
    cout<<"Person "<<search<<" not found in the Earth planet"<<endl;
}

vector<Earth_person> Earth_person::earth_people = {
    {"Alice", "Earth", 170, 70, 150}, 
    {"Bob", "Earth", 160, 60, 140},
    {"Charlie", "Earth", 180, 80, 160},
    {"David", "Earth", 175, 75, 155},
    {"Eve", "Earth", 165, 65, 135},
    {"Frank", "Earth", 185, 85, 175},
    {"Grace", "Earth", 160, 60, 130},
    {"Herry", "Earth", 170, 70, 140},
    {"Ivy", "Earth", 175, 75, 155},
    {"John", "Earth", 180, 80, 160}
};

void Earth_person::print_data(){
    if(earth_people.empty()){
        cout<<"Earth planet is empty"<<endl;
        return;
    }
    for(int i=0; i<earth_people.size(); i++){
        earth_people[i].print_person();
        cout<<endl;
    }
}

Earth_person::Earth_person(string name, string home, int height, int weight, int intelligence){
    this->name = name;
    this->home = home;
    this->height = height;
    this->weight = weight;
    this->intelligence = intelligence;
}

void Earth_person::input(string planet){
    string name = "";
    do{
        cout<<"Enter name (Only For English Name) :";
        getline(cin, name);
    }while(this->illegal_name(name));
    this->name = name;

    this->home = planet;

    int height;
    do{
        cout<<"Enter height (1~200 cm): ";
        cin>>height;
    }while(height <= 0 || height > 200);
    this->height = height;

    int weight;
    do{
        cout<<"Enter weight (1~100 kg): ";
        cin>>weight;
    }while(weight <= 0 || weight > 100);
    this->weight = weight;

    int intelligence;
    do{
        cout<<"Enter intelligence (1~180): ";
        cin>>intelligence;
    }while(intelligence <= 0 || intelligence > 180);
    this->intelligence = intelligence;
    earth_people.push_back(*this);
}

class Mars_person:public person{
private:
    static vector<Mars_person> mars_people;
    void do_height();
    void do_weight();
    void do_intelligence();
public:
    Mars_person(string name = "", string home = "", int height = 0, int weight = 0, int intelligence = 0);
    void input(string);
    void print_data();
    void remove();
    void sort_yourself();
    Mars_person(const Mars_person&);
    Mars_person& operator=(const Mars_person&);
    int get_size();
    int get_rank(person*, char, int);
};

int Mars_person::get_rank(person* you, char detail, int choice_three){
    int M_rank{0};
    if(choice_three == 1){
        for(int i = 0; i<mars_people.size(); i++){
            if((mars_people[i].get_height()) > (you->get_height())){
                M_rank++;
                if(detail == 'y'){
                    mars_people[i].print_person();
                    cout<<endl;
                }
            }
        }
    }
    else if(choice_three == 2){
        for(int i = 0; i<mars_people.size(); i++){
            if(mars_people[i].get_weight() > you->get_weight()){
                M_rank++;
                if(detail == 'y'){
                    mars_people[i].print_person();
                    cout<<endl;
                }
            }
        }
    }
    else if(choice_three == 3){
        for(int i = 0; i<mars_people.size(); i++){
            if(mars_people[i].get_intelligence() > you->get_intelligence()){
                M_rank++;
                if(detail == 'y'){
                    mars_people[i].print_person();
                    cout<<endl;
                }
            }
        }
    }
    return M_rank;
}

int Mars_person::get_size(){
    return mars_people.size();
}

Mars_person::Mars_person(const Mars_person& other){
    this->name = other.name;
    this->home = other.home;
    this->height = other.height;
    this->weight = other.weight;
    this->intelligence = other.intelligence;
}

Mars_person& Mars_person::operator=(const Mars_person& other){
    this->name = other.name;
    this->home = other.home;
    this->height = other.height;
    this->weight = other.weight;
    this->intelligence = other.intelligence;
    return *this;
}

void Mars_person::do_height(){
    for(int i = 0; i<mars_people.size()-1; i++){
        for(int j = (i+1); j<mars_people.size(); j++){
            if(mars_people[i].height > mars_people[j].height){
                Mars_person temp = mars_people[i];                //copy constructor
                mars_people[i] = mars_people[j];
                mars_people[j] = temp;
            }            
        }
    }
}


void Mars_person::do_weight(){
    for(int i = 0; i<mars_people.size()-1; i++){
        for(int j = (i+1); j<mars_people.size(); j++){
            if(mars_people[i].weight > mars_people[j].weight){
                Mars_person temp = mars_people[i];                //copy constructor
                mars_people[i] = mars_people[j];
                mars_people[j] = temp;
            }            
        }
    }
}

void Mars_person::do_intelligence(){
    for(int i = 0; i<mars_people.size()-1; i++){
        for(int j = (i+1); j<mars_people.size(); j++){
            if(mars_people[i].intelligence > mars_people[j].intelligence){
                Mars_person temp = mars_people[i];                //copy constructor
                mars_people[i] = mars_people[j];
                mars_people[j] = temp;
            }            
        }
    }
}

void Mars_person::sort_yourself(){
    int which{0}; 
    cout<<"1. Height"<<endl;
    cout<<"2. Weight"<<endl;
    cout<<"3. Intelligence"<<endl;
    cout<<"Which one do you want to sort by? (請輸入數字): ";
    cin>>which;
    if(which == 1){
        this->do_height();
    }
    else if(which == 2){
        this->do_weight();
    }
    else if(which == 3){
        this->do_intelligence();
    }
    else{
        cout<<"Invalid input"<<endl;
        system("pause");
        return;
    }
    cout<<"Sorted by "<<which<<endl;
    for(int i=0; i<mars_people.size(); i++){
        mars_people[i].print_person();
        cout<<endl;
    }
}

void Mars_person::remove(){
    string search = "\0";
    getline(cin, search);
    for(int i=0; i<mars_people.size(); i++){
        if(mars_people[i].name == search){
            bool flag = found(&mars_people[i]);
            if(flag){
                mars_people.erase(mars_people.begin()+i);
                cout<<"Person "<<search<<" has been removed from the Mars planet"<<endl;
                system("pause");
                return;
            }
            continue;
        }
    }
    cout<<"Person "<<search<<" not found in the Moon planet"<<endl;
}

void Mars_person::print_data(){
    if(mars_people.empty()){
        cout<<"Mars planet is empty"<<endl;
        return;
    }
    for(int i=0; i<mars_people.size(); i++){
        mars_people[i].print_person();
        cout<<endl;
    }
}

vector<Mars_person> Mars_person::mars_people = {
    {"Abigail", "Mars", 80, 33, 130},
    {"Brian", "Mars", 70, 12, 140},
    {"Colin", "Mars", 60, 27, 150},
    {"Daniel", "Mars", 75, 31, 145},
    {"Emily", "Mars", 65, 19, 135},
    {"Flora", "Mars", 15, 17, 165},
    {"Garfield", "Mars", 36, 28, 120},
    {"Harriet", "Mars", 67, 29, 130},
    {"Isabella", "Mars", 76, 3, 145},
    {"Jim", "Mars", 64, 39, 160}
};

Mars_person::Mars_person(string name, string home, int height, int weight, int intelligence){
    this->name = name;
    this->home = home;
    this->height = height;
    this->weight = weight;
    this->intelligence = intelligence;
}

void Mars_person::input(string planet){
    string name;
    do{
        cout<<"Enter name (Only For English Name) :";
        getline(cin, name);
    }while(this->illegal_name(name));
    this->name = name;

    this->home = planet;

    int height;
    do{
        cout<<"Enter height (1~80 cm): ";
        cin>>height;
    }while(height <= 0 || height > 80);
    this->height = height;

    int weight;
    do{
        cout<<"Enter weight (1~40 kg): ";
        cin>>weight;
    }while(weight <= 0 || weight > 40);
    this->weight = weight;

    int intelligence;
    do{
        cout<<"Enter intelligence (1~200): ";
        cin>>intelligence;
    }while(intelligence <= 0 || intelligence > 200);
    this->intelligence = intelligence;
    mars_people.push_back(*this);
}


class Moon_person:public person{
private:
    static vector<Moon_person> moon_people;
    void do_height();
    void do_weight();
    void do_intelligence();
public:
    Moon_person(string name = "", string home = "", int height = 0, int weight = 0, int intelligence = 0);
    void input(string);
    void print_data();
    void remove();
    void sort_yourself();
    Moon_person(const Moon_person&);
    Moon_person& operator=(const Moon_person&);
    int get_size();
    int get_rank(person*, char, int);
};

int Moon_person::get_rank(person* you, char detail, int choice_three){
    int Mo_rank{0};
    if(choice_three == 1){
        for(int i = 0; i<moon_people.size(); i++){
            if((moon_people[i].get_height()) > (you->get_height())){
                Mo_rank++;
                if(detail == 'y'){
                    moon_people[i].print_person();
                    cout<<endl;
                }
            }
        }
    }
    else if(choice_three == 2){
        for(int i = 0; i<moon_people.size(); i++){
            if(moon_people[i].get_weight() > you->get_weight()){
                Mo_rank++;
                if(detail == 'y'){
                    moon_people[i].print_person();
                    cout<<endl;
                }
            }
        }
    }
    else if(choice_three == 3){
        for(int i = 0; i<moon_people.size(); i++){
            if(moon_people[i].get_intelligence() > you->get_intelligence()){
                Mo_rank++;
                if(detail == 'y'){
                    moon_people[i].print_person();
                    cout<<endl;
                }
            }
        }
    }
    return Mo_rank;
}

int Moon_person::get_size(){
    return moon_people.size();
}

Moon_person::Moon_person(const Moon_person& other){
    this->name = other.name;
    this->home = other.home;
    this->height = other.height;
    this->weight = other.weight;
    this->intelligence = other.intelligence;
}

Moon_person& Moon_person::operator=(const Moon_person& other){
    this->name = other.name;
    this->home = other.home;
    this->height = other.height;
    this->weight = other.weight;
    this->intelligence = other.intelligence;
    return *this;
}

void Moon_person::do_height(){
    for(int i = 0; i<moon_people.size()-1; i++){
        for(int j = (i+1); j<moon_people.size(); j++){
            if(moon_people[i].height > moon_people[j].height){
                Moon_person temp = moon_people[i];                //copy constructor
                moon_people[i] = moon_people[j];
                moon_people[j] = temp;
            }
        }
    }
}


void Moon_person::do_weight(){
    for(int i = 0; i<moon_people.size()-1; i++){
        for(int j = (i+1); j<moon_people.size(); j++){
            if(moon_people[i].weight > moon_people[j].weight){
                Moon_person temp = moon_people[i];                //copy constructor
                moon_people[i] = moon_people[j];
                moon_people[j] = temp;
            }            
        }
    }
}

void Moon_person::do_intelligence(){
    for(int i = 0; i<moon_people.size()-1; i++){
        for(int j = (i+1); j<moon_people.size(); j++){
            if(moon_people[i].intelligence > moon_people[j].intelligence){
                Moon_person temp = moon_people[i];                //copy constructor
                moon_people[i] = moon_people[j];
                moon_people[j] = temp;
            }            
        }
    }
}

void Moon_person::sort_yourself(){
    int which{0}; 
    cout<<"1. Height"<<endl;
    cout<<"2. Weight"<<endl;
    cout<<"3. Intelligence"<<endl;
    cout<<"Which one do you want to sort by? (請輸入數字): ";
    cin>>which;
    if(which == 1){
        this->do_height();
    }
    else if(which == 2){
        this->do_weight();
    }
    else if(which == 3){
        this->do_intelligence();
    }
    else{
        cout<<"Invalid input"<<endl;
        system("pause");
        return;
    }
    cout<<"Sorted by "<<which<<endl;
    for(int i=0; i<moon_people.size(); i++){
        moon_people[i].print_person();
        cout<<endl;
    }
}

void Moon_person::remove(){
    string search = "\0";
    getline(cin, search);
    for(int i=0; i<moon_people.size(); i++){
        if(moon_people[i].name == search){
            bool flag = found(&moon_people[i]);
            if(flag){
                moon_people.erase(moon_people.begin()+i);
                cout<<"Person "<<search<<" has been removed from the Moon planet"<<endl;
                system("pause");
                return;
            }
            continue;
        }
    }
    cout<<"Person "<<search<<" not found in the Moon planet"<<endl;
}

vector<Moon_person> Moon_person::moon_people = {
    {"Alex", "Moon", 150, 50, 220},
    {"Bruce", "Moon", 66, 60, 130},
    {"Carol", "Moon", 75, 30, 140},
    {"Drew", "Moon", 124, 35, 245},
    {"Ethan", "Moon", 135, 45, 135},
    {"Fletcher", "Moon", 145, 15, 165},
    {"Gabriel", "Moon", 110, 22, 120},
    {"Hannah", "Moon", 126, 37, 230},
    {"Iqbal", "Moon", 144, 42, 145},
    {"Jimmy", "Moon", 137, 19, 160}
};

void Moon_person::print_data(){
    if(moon_people.empty()){
        cout<<"Moon planet is empty"<<endl;
        return;
    }
    for(int i=0; i<moon_people.size(); i++){
        moon_people[i].print_person();
        cout<<endl;
    }
}

Moon_person::Moon_person(string name, string home, int height, int weight, int intelligence){
    this->name = name;
    this->home = home;
    this->height = height;
    this->weight = weight;
    this->intelligence = intelligence;
}

void Moon_person::input(string planet){
    string name;
    do{
        cout<<"Enter name (Only For English Name) :";
        getline(cin, name);
    }while(this->illegal_name(name));
    this->name = name;

    this->home = planet;

    int height;
    do{
        cout<<"Enter height (1~150 cm): ";
        cin>>height;
    }while(height <= 0 || height > 150);
    this->height = height;

    int weight;
    do{
        cout<<"Enter weight (1~60 kg): ";
        cin>>weight;
    }while(weight <= 0 || weight > 60);
    this->weight = weight;

    int intelligence;
    do{
        cout<<"Enter intelligence (1~250): ";
        cin>>intelligence;
    }while(intelligence <= 0 || intelligence > 250);
    this->intelligence = intelligence;
    moon_people.push_back(*this);
}

class Pluto_person:public person{
private:
    static vector<Pluto_person> pluto_people;
    void do_height();
    void do_weight();
    void do_intelligence();
public:
    Pluto_person(string name = "", string home = "", int height = 0, int weight = 0, int intelligence = 0);
    void input(string);
    void print_data();
    void remove();
    void sort_yourself();
    Pluto_person(const Pluto_person&);
    Pluto_person& operator=(const Pluto_person&);
    int get_size();
    int get_rank(person*, char, int);
};

int Pluto_person::get_rank(person* you, char detail, int choice_three){
    int P_rank{0};
    if(choice_three == 1){
        for(int i = 0; i<pluto_people.size(); i++){
            if((pluto_people[i].get_height()) > (you->get_height())){
                P_rank++;
                if(detail == 'y'){
                    pluto_people[i].print_person();
                    cout<<endl;
                }
            }
        }
    }
    else if(choice_three == 2){
        for(int i = 0; i<pluto_people.size(); i++){
            if(pluto_people[i].get_weight() > you->get_weight()){
                P_rank++;
                if(detail == 'y'){
                    pluto_people[i].print_person();
                    cout<<endl;
                }
            }
        }
    }
    else if(choice_three == 3){
        for(int i = 0; i<pluto_people.size(); i++){
            if(pluto_people[i].get_intelligence() >you->get_intelligence()){
                P_rank++;
                if(detail == 'y'){
                    pluto_people[i].print_person();
                    cout<<endl;
                }
            }
        }
    }
    return P_rank;
}

int Pluto_person::get_size(){
    return pluto_people.size();
}

Pluto_person::Pluto_person(const Pluto_person& other){
    this->name = other.name;
    this->home = other.home;
    this->height = other.height;
    this->weight = other.weight;
    this->intelligence = other.intelligence;
}

Pluto_person& Pluto_person::operator=(const Pluto_person& other){
    this->name = other.name;
    this->home = other.home;
    this->height = other.height;
    this->weight = other.weight;
    this->intelligence = other.intelligence;
    return *this;
}

void Pluto_person::do_height(){
    for(int i = 0; i<pluto_people.size()-1; i++){
        for(int j = (i+1); j<pluto_people.size(); j++){
            if(pluto_people[i].height > pluto_people[j].height){
                Pluto_person temp = pluto_people[i];                //copy constructor
                pluto_people[i] = pluto_people[j];
                pluto_people[j] = temp;
            }  
        }
    }
}


void Pluto_person::do_weight(){
    for(int i = 0; i<pluto_people.size()-1; i++){
        for(int j = (i+1); j<pluto_people.size(); j++){
            if(pluto_people[i].weight > pluto_people[j].weight){
                Pluto_person temp = pluto_people[i];                //copy constructor
                pluto_people[i] = pluto_people[j];
                pluto_people[j] = temp;
            }            
        }
    }
}

void Pluto_person::do_intelligence(){
    for(int i = 0; i<pluto_people.size()-1; i++){
        for(int j = (i+1); j<pluto_people.size(); j++){
            if(pluto_people[i].intelligence > pluto_people[j].intelligence){
                Pluto_person temp = pluto_people[i];                //copy constructor
                pluto_people[i] = pluto_people[j];
                pluto_people[j] = temp;
            }            
        }
    }
}

void Pluto_person::sort_yourself(){
    int which{0}; 
    cout<<"1. Height"<<endl;
    cout<<"2. Weight"<<endl;
    cout<<"3. Intelligence"<<endl;
    cout<<"Which one do you want to sort by? (請輸入數字): ";
    cin>>which;
    if(which == 1){
        this->do_height();
    }
    else if(which == 2){
        this->do_weight();
    }
    else if(which == 3){
        this->do_intelligence();
    }
    else{
        cout<<"Invalid input"<<endl;
        system("pause");
        return;
    }
    cout<<"Sorted by "<<which<<endl;
    for(int i=0; i<pluto_people.size(); i++){
        pluto_people[i].print_person();
        cout<<endl;
    }
}

void Pluto_person::remove(){
    string search = "\0";
    getline(cin, search);
    for(int i=0; i<pluto_people.size(); i++){
        if(pluto_people[i].name == search){
            bool flag = found(&pluto_people[i]);
            if(flag){
                pluto_people.erase(pluto_people.begin()+i);
                cout<<"Person "<<search<<" has been removed from the Pluto planet"<<endl;
                system("pause");
                return;
            }
            continue;
        }
    }
    cout<<"Person "<<search<<" not found in the Pluto planet"<<endl;
}

void Pluto_person::print_data(){
    if(pluto_people.empty()){
        cout<<"Pluto planet is empty"<<endl;
        return;
    }
    for(int i=0; i<pluto_people.size(); i++){
        pluto_people[i].print_person();
        cout<<endl;
    }
}

vector<Pluto_person> Pluto_person::pluto_people = {
    {"Amy", "Pluto", 90, 44, 110},
    {"Brad", "Pluto", 100, 50, 120},
    {"Coco", "Pluto", 80, 43, 130},
    {"Dva", "Pluto", 55, 36, 235},
    {"Emma", "Pluto", 65, 23, 125},
    {"Furie", "Pluto", 75, 14, 245},
    {"Gasgas", "Pluto", 60, 47, 190},
    {"Hsieh", "Pluto", 72, 33, 220},
    {"Iusse", "Pluto", 95, 27, 135},
    {"Johnny", "Pluto", 88, 26, 245}
};

Pluto_person::Pluto_person(string name, string home, int height, int weight, int intelligence){
    this->name = name;
    this->home = home;
    this->height = height; 
    this->weight = weight;
    this->intelligence = intelligence;
}

void Pluto_person::input(string planet){
    string name;
    do{
        cout<<"Enter name (Only For English Name) :";
        getline(cin, name);
    }while(this->illegal_name(name));
    this->name = name;

    this->home = planet;

    int height;
    do{
        cout<<"Enter height (1~100 cm): ";
        cin>>height;
    }while(height <= 0 || height > 100);
    this->height = height;

    int weight;
    do{
        cout<<"Enter weight (1~50 kg): ";
        cin>>weight;
    }while(weight <= 0 || weight > 50);
    this->weight = weight;

    int intelligence;
    do{
        cout<<"Enter intelligence (1~300): ";
        cin>>intelligence;
    }while(intelligence <= 0 || intelligence > 300);
    this->intelligence = intelligence;
    pluto_people.push_back(*this);
}


class galgame{
protected:
    string name;
    int level;
    int exp;
    int hp;
    int mp;
    int atk;
    bool check(string name);
public:
    virtual void input() = 0;
    void print_info();
    virtual void print_game() = 0;
    virtual void setmp(int) = 0;
    string get_name();
    int get_level();
    int get_exp();
    int get_hp();
    int get_mp();
    int get_atk();
};

string galgame::get_name(){
    return this->name;
}

int galgame::get_level(){
    return this->level;
}

int galgame::get_exp(){
    return this->exp;
}


int galgame::get_hp(){
    return this->hp;
}

int galgame::get_mp(){
    return this->mp;
}

int galgame::get_atk(){
    return this->atk;
}

void galgame::print_info(){
    cout<<"Name:       "<<this->name<<endl;
    cout<<"Level:      "<<this->level<<endl;
    cout<<"Experience: "<<this->exp<<endl;
    cout<<"HP:         "<<this->hp<<endl;
    cout<<"MP:         "<<this->mp<<endl;
    cout<<"Attack:     "<<this->atk<<endl;
}

bool galgame::check(string name){
    for(int i=0; i<name.size(); i++){
        if((name[i] < 'a' || name[i] > 'z') && (name[i] < 'A' || name[i] > 'Z') && (name[i] != ' ')){
            return true;
        }
    }
    return false;
}

class monster:public galgame{
private:
    static vector<monster> monsters;
public:
    void input();
    monster(string name = "", int level = 0, int exp = 0, int hp = 0, int mp = 0, int atk = 0);
    void print_game();
    monster(const monster&);
    monster& operator=(const monster&);
    monster select();
    int hurt(int, int);
    void remove();
    void rewrite(int, int, monster&);
    void setmp(int);
};

void monster::setmp(int mp){
    this->mp = mp;
}

void monster::rewrite(int level, int exp, monster& winner){
    for(int i = 0; i<monsters.size(); i++){
        if(this->get_name() == monsters[i].name){
            if(monsters[i].level < level){
                monsters[i].level = level;
            }
            monsters[i].exp += exp;
            monsters[i].hp = winner.hp;
            monsters[i].mp = winner.mp;
            monsters[i].atk = winner.atk;
        }
    }
}

void monster::remove(){
    if(this->monsters.empty()){
        cout<<"怪物被殺光了..."<<endl;
        return;
    }
    for(int i = 0; i<monsters.size(); i++){
        if(this->get_name() == monsters[i].name){
            monsters.erase(monsters.begin()+i);
        }
    }
}

int monster::hurt(int damage, int mp){
    int new_damage = damage*(mp*0.1);
    this->hp -= new_damage;
    if(this->hp <= 0){
        this->hp = 0;
        cout<<"怪物被殺了"<<endl;
    }
    else{
        cout<<"怪物受到了"<<new_damage<<"點傷害"<<endl;
    }
    return (mp*0.9);
}

monster monster:: select(){
    if(monsters.empty()){
        cout<<"怪物已經死光了呦"<<endl;
        system("pause");
        return monster();
    }
    string name = "";
    do{
        this->print_game();
        cout<<"請選擇你要面對的怪物 (輸入名字): ";
        cin.ignore();
        getline(cin, name);
        for(int i=0; i<monsters.size(); i++){
            if(monsters[i].name == name){
                monsters[i].print_info();
                char select_choice;
                do{
                    cout<<"請問是否指名此怪物 (y/n): ";
                    cin>>select_choice;
                    if(select_choice == 'y' || select_choice == 'n') break;
                    cout<<"輸入小寫 y 或 n"<<endl;
                    system("pause");
                }while(1);
                if(select_choice == 'y'){
                    return monsters[i];
                }
            }
        }
        cout<<"你沒有這個怪物"<<endl;
    }while(true);
}

monster::monster(const monster& other){
    this->name = other.name;
    this->level = other.level;
    this->exp = other.exp;
    this->hp = other.hp;
    this->mp = other.mp;
    this->atk = other.atk;
}

monster& monster::operator=(const monster& other){
    this->name = other.name;
    this->level = other.level;
    this->exp = other.exp;
    this->hp = other.hp;
    this->mp = other.mp;
    this->atk = other.atk;
    return *this;
}

vector<monster> monster::monsters{
    {"Goblin", 60, 10, 100000, 50, 10},
    {"Orc", 35, 20, 200000, 100, 20},
    {"Troll", 45, 30, 300000, 150, 30}
};

void monster::print_game(){
    if(monsters.empty()){
        cout<<"怪物被打光囉"<<endl;
        return;
    }
    for(int i=0; i<monsters.size(); i++){
        monsters[i].print_info();
        cout<<endl;
    }
}

monster::monster(string name, int level, int exp, int hp, int mp, int atk){
    this->name = name;
    this->level = level;
    this->exp = exp;
    this->hp = hp;
    this->mp = mp;
    this->atk = atk;
}

void monster::input(){
    string name = "";
    do{
        cout<<"Enter name (Only For English Name) :";
        cin.ignore();
        getline(cin, name);
    }while(this->check(name));
    this->name = name;

    int level;
    do{
        cout<<"Enter level (1~200): ";
        cin>>level;
    }while(level <= 0 || level > 200);
    this->level = level;

    int exp;
    do{
        cout<<"Enter experience (1~10000): ";
        cin>>exp;
    }while(exp <= 0 || exp > 10000);
    this->exp = exp;

    int hp;
    do{
        cout<<"Enter hp (1~100000): ";
        cin>>hp;
    }while(hp <= 0 || hp > 100000);
    this->hp = hp;

    int mp;
    do{
        cout<<"Enter mp (1~10000): ";
        cin>>mp;
    }while(mp <= 0 || mp > 10000);
    this->mp = mp;

    int atk;
    do{
        cout<<"Enter attack (1~10000): ";
        cin>>atk;
    }while(atk <= 0 || atk > 10000);
    this->atk = atk;
    monsters.push_back(*this);
}

class player:public galgame{
private:
    static vector<player> players;
public:
    void input();
    player(string name = "", int level = 0, int exp = 0, int hp = 0, int mp = 0, int atk = 0);
    void print_game();
    player(const player&);
    player& operator=(const player&);
    player select();
    int hurt(int, int);
    void remove();
    void rewrite(int, int, player&);
    void setmp(int);
};

void player::setmp(int mp){
    this->mp = mp;
}

void player::rewrite(int level, int exp, player& winner){
    for(int i = 0; i<players.size(); i++){
        if(this->get_name() == players[i].name){
            if(players[i].level < level){
                players[i].level = level;
            }
            players[i].exp += exp;
            players[i].hp = winner.hp;
            players[i].mp = winner.mp;
            players[i].atk = winner.atk;
        }
    }
}

void player::remove(){
    if(this->players.empty()){
        cout<<"沒有人可以移出了"<<endl;
        return;
    }
    for(int i = 0; i<players.size(); i++){
        if(this->get_name() == players[i].name){
            players.erase(players.begin()+i);
        }
    }
}

int player::hurt(int damage, int mp){
    int new_damage = damage*(mp*0.1);
    this->hp -= new_damage;
    if(this->hp <= 0){
        this->hp = 0;
        cout<<"你被殺了"<<endl;
    }
    else{
        cout<<"你受到了"<<new_damage<<"點傷害"<<endl;
    }
    return (mp*0.9);
}

player player:: select(){
    if(players.empty()){
        cout<<"人都死光了啦"<<endl;
        system("pause");
        return player();
    }
    cin.ignore();
    string name = "";
    do{
        this->print_game();
        cout<<"請選擇你的角色 (輸入名字): ";
        getline(cin, name);
        for(int i=0; i<players.size(); i++){
            if(players[i].name == name){
                players[i].print_info();
                char select_choice;
                do{
                    cout<<"請問是否指名此角色 (y/n): ";
                    cin>>select_choice;
                    if(select_choice == 'y' || select_choice == 'n') break;
                    cout<<"輸入小寫 y 或 n"<<endl;
                    system("pause");
                }while(1);
                if(select_choice == 'y'){
                    return players[i];
                }
            }
        }
        cout<<"你沒有這個角色"<<endl;
    }while(true);
}

player::player(const player& other){
    this->name = other.name;
    this->level = other.level;
    this->exp = other.exp;
    this->hp = other.hp;
    this->mp = other.mp;
    this->atk = other.atk;
}

player& player::operator=(const player& other){
    this->name = other.name;
    this->level = other.level;
    this->exp = other.exp;
    this->hp = other.hp;
    this->mp = other.mp;
    this->atk = other.atk;
    return *this;
}

void player::print_game(){
    if(players.empty()){
        cout<<"請造點人出來"<<endl;
        return;
    }
    for(int i = 0; i<players.size(); i++){
        players[i].print_info();
        cout<<endl;
    }
}

vector<player> player::players{
    {"Hibino Kafka", 10, 1500, 100, 96, 9999},
    {"Satoru Gojo", 15, 30, 50, 70, 500},
};

player::player(string name, int level, int exp, int hp, int mp, int atk){
    this->name = name;
    this->level = level;
    this->exp = exp;
    this->hp = hp;
    this->mp = mp;
    this->atk = atk;
}

void player::input(){
    string name = "";
    do{
        cout<<"Enter name (Only For English Name) :";
        cin.ignore();
        getline(cin, name);
    }while(this->check(name));
    this->name = name;

    int level;
    do{
        cout<<"Enter level (1~100): ";
        cin>>level;
    }while(level <= 0 || level > 100);
    this->level = level;

    int exp;
    do{
        cout<<"Enter experience (1~5000): ";
        cin>>exp;
    }while(exp <= 0 || exp > 5000);
    this->exp = exp;

    int hp;
    do{
        cout<<"Enter hp (1~100000): ";
        cin>>hp;
    }while(hp <= 0 || hp > 100000);
    this->hp = hp;

    int mp;
    do{
        cout<<"Enter mp (1~100000): ";
        cin>>mp;
    }while(mp <= 0 || mp > 100000);
    this->mp = mp;

    int atk;
    do{
        cout<<"Enter attack (1~10000): ";
        cin>>atk;
    }while(atk <= 0 || atk > 10000);
    this->atk = atk;
    players.push_back(*this);
}

class maze{
protected:
    string gender;
    int record_die_life;
    char player_now;                                                                 // player's identity
    char footprint;                                                                  // footprint of the maze
    int life;
    static const int move_x[4];
    static const int move_y[4];
    int pos_x;                                                                       // player's position
    int pos_y;                                                                       // player's position   
    int end_point_x;                                                                 // end point's position
    int end_point_y;                                                                 // end point's position
    static vector<vector<char>> maze_map;
    static vector<vector<char>> ans_maze_map;
    int pick_num(int down = 0, int range = 0);
    void generate_maze(int size = 1);
    bool is_dir(char);
    void print_maze(bool);
    void eat(int x, int y, char c = 'Q');
    bool solve(int, int);
    bool light_up;
    void event();
    int meet_event;
    static vector<string> event_list;
public:
};

vector<string>maze::event_list{
    {"dragon"}, {"free"}, {"life"}, {"footprint"}, {"player_now"}, {"monster_week"}, {"clear"}, {"gamble_horse"}
};

void maze::event(){
    random_shuffle(event_list.begin(), event_list.end());
    int space{0}, cnt{0};
    for(int i=1;i<maze_map.size()-1;i++){
        for(int j=1;j<maze_map[i].size()-1;j++){
            if(maze_map[i][j] == ' '){
                space++;
            }
        }
    }
    while(space){
        if(cnt >= event_list.size()) break;
        int row = 0;
        int col = 0;      
        do{
            row = this->pick_num(1, maze_map.size()-2);
            col = this->pick_num(1, maze_map.size()-2);
        }while(maze_map[row][col] != ' ');
        maze_map[row][col] = 'M';
        space--;
        cnt++;
    }
}

vector<vector<char>> maze::ans_maze_map;
const int maze::move_x[4] = {0, 1, 0, -1};
const int maze::move_y[4] = {-1, 0, 1, 0};

bool maze::solve(int x, int y) {
    bool flag = true;
    if((x <= 0) || (y <= 0) || (x >= ans_maze_map.size()-1) || (y >= ans_maze_map[0].size()-1) || (ans_maze_map[x][y] == '#') || (ans_maze_map[x][y] == '*')){
        return true;
    }
    // cout<<x<<" "<<y<<" OK"<<endl;
    if((x == end_point_x)&&(y == (end_point_y-1))){
        ans_maze_map[x][y] = '*';
        return false;
    }
    ans_maze_map[x][y] = '*';
    for(int i=0;i<4;i++){
        int nx = x + move_x[i];
        int ny = y + move_y[i];
        flag = solve(nx, ny);
        if(!flag){
            return false;
        }
    }
    ans_maze_map[x][y] = ' ';
    return true;
}

void maze::eat(int x, int y, char c){
    maze_map[x][y] = ' ';
    vector<int> new_dir = {0, 1, 2, 3};
    random_shuffle(new_dir.begin(), new_dir.end());
    for(int i=0;i<4;i++){
        int dir = new_dir[i];
        int nx = x + move_x[dir]*2;
        int ny = y + move_y[dir]*2;
        if(nx > 0 && ny > 0 && nx < maze_map.size()-1 && ny < maze_map[0].size()-1 && maze_map[nx][ny] == '#' ){
            maze_map[x + move_x[dir]][y + move_y[dir]] = ' ';
            eat(nx, ny, c);
        }
    }
}

bool maze::is_dir(char c){
    if((c != 'w') && (c != 'a') && (c != 's') && (c != 'd')){
        cout<<endl<<"請輸入小寫英文字母呦"<<endl;
        return false;
    }
    return true;
}

void maze::print_maze(bool light_up){
    if(this->life <= 0){
        this->player_now = 'X';
        this->maze_map[this->pos_x][this->pos_y] = this->player_now;
    }
    cout<<endl<<"Your Life : "<<this->life<<endl<<endl;
    for(int i=0;i<maze_map.size();i++){
        for(int j=0;j<maze_map[i].size();j++){

            if(light_up == false){
                if(( abs(i - (this->pos_x)) <= 1 ) && ( abs(j - (this->pos_y)) <= 1 )) cout<<maze_map[i][j];
                else cout<<'-';
            }
            else{
                cout<<maze_map[i][j];
            }
        }
        cout<<endl;
    }
}

vector<vector<char>> maze::maze_map;

void maze::generate_maze(int size){
    int first_hole = 0;
    this->maze_map.clear();
    // cout<<"Generating maze of size "<<endl;
    for(int i=0;i<size;i++){
        vector<char> row;
        for(int j=0;j<size;j++){
            row.push_back('#');
        }
        maze_map.push_back(row);
    }
    first_hole = this->pick_num(1, size-2);
    // cout<<"First hole at ("<<first_hole<<",0)"<<endl;
    this->maze_map[first_hole][0] = ' ';
    eat(first_hole, 1, this->player_now);
    this->maze_map[first_hole][1] = this->player_now;   
    int end_hole = 0;
    do{
        end_hole = this->pick_num(1, size-2);
    }while(((this->maze_map[end_hole][this->maze_map.size()-2]) != ' ') && (maze_map[end_hole][this->maze_map.size()-2] != this->player_now));
    
    // cout<<"End hole at ("<<end_hole<<","<<size-1<<")"<<endl;
    maze_map[end_hole][size-1] = '+';
    this->end_point_x = end_hole;
    this->end_point_y = size-1;
    this->meet_event = 0;
    this->event();
}


int maze::pick_num(int down, int range){
    return (static_cast<int>(rand()%range)+down);
}

class maze_player: public maze{
private:
    string name;
    int age;
    int height;
    int weight;
    char move(char parent_now = ' ');
    bool if_win();
    bool move_ok(int dir);
    bool judge();
    bool die();
    void print_player_info();
    void Event(int);
    static vector<string> end_game;
    void end_game_print();
public:
    void play_maze();
    maze_player();
};

void maze_player::end_game_print(){
    cout<<"以下是您本次遊玩過程中所獲得的稱號"<<endl<<endl;
    for(int i=0;i<end_game.size();i++){
        cout<<i+1<<". "<<end_game[i]<<endl;
    }
    cout<<endl<<"恭喜您獲得了共 "<<end_game.size()<<" 個稱號"<<endl;
}

vector<string> maze_player::end_game;

void maze_player::Event(int n_move){
    int nx = this->pos_x + move_x[n_move];
    int ny = this->pos_y + move_y[n_move];
    if(this->maze_map[nx][ny] != 'M') return;
    string WhichEvent = event_list[this->meet_event];
    
    if(WhichEvent == "dragon"){
        int minus_height{0};
        cout<<endl<<"非常不幸...你遭遇了強敵 遠古巨龍 "<<endl;
        system("pause");
        if(this->height > 150){
            cout<<"你長太高了，被恐龍看到了"<<endl;
            int hei_choice{0};
            do{                
                cout<<"1.呼叫多拉A夢"<<endl;
                cout<<"2.使用催眠術"<<endl;
                cout<<"3.Explosion"<<endl;
                cout<<"您的選擇是 (1~3): ";
                cin>>hei_choice;
                if(hei_choice == 1 || hei_choice == 2 || hei_choice == 3) break;
                cout<<"請看好輸入"<<endl;
                system("pause");
            }while(1);
            if(hei_choice == 1){
                if(this->name == "Nobi Nobita"){
                    cout<<"多拉A夢使用隱形斗篷"<<endl;
                    cout<<"您找到龍的逆麟並刺殺了牠"<<endl;
                    cout<<"偶遇 森西 料理龍肉料理"<<endl;
                    int dragon_meat{0};
                    do{
                        cout<<"是否吃下肚 (1~2) : ";
                        cin>>dragon_meat;
                        if(dragon_meat == 1 || dragon_meat == 2) break;
                        cout<<"請看好輸入"<<endl;
                        system("pause");
                    }while(1);
                    if(dragon_meat == 1){
                        cout<<"你吃下了肚"<<endl;
                        this->end_game.push_back("美食評鑑家");
                    }
                    else{
                        cout<<"你放棄了美食"<<endl;
                        this->end_game.push_back("不識高等美食的獵人");
                    }
                }
                else{
                    cout<<"多拉A夢只陪在大雄身邊"<<endl;
                    cout<<"小提示：如果有下輩子，你也可以叫（大雄）"<<endl;
                    cout<<"你與遠古巨龍苦戰300回合，損失 30% 血量"<<endl;
                    this->end_game.push_back("我獨自屠龍");
                    int tmp = this->life;
                    this->life *=  0.7;
                    this->record_die_life += (tmp - this->life);
                    system("pause");
                }
            }
            else if(hei_choice == 2){
                cout<<"這種東西輪的到你學？"<<endl;
                this->life = 0;
                cout<<"您為巨龍飽餐一頓"<<endl;
                this->end_game.push_back("在地美食");
                system("pause");
            }
            else if(hei_choice == 3){
                cout<<"我が名はめぐみん。紅魔族随一の魔法の使い手にして、爆裂魔法を操りし者。我が力、見るがいい！エクスプロージョン！"<<endl;
                cout<<"巨龍被爆裂魔法一發入魂，連渣都不剩了"<<endl;
                cout<<"您失去了精力，睡了半天"<<endl;
                this->light_up = !this->light_up;
                this->end_game.push_back("一發戰士");
                system("pause");
            }
        }
        else{
            cout<<"您矮到連視力1.0的巨龍都看不見"<<endl;
            this->end_game.push_back("矮子的生存之道");
            cout<<"巨龍朝入口飛去"<<endl;
            system("pause");
        }
    }
    else if(WhichEvent == "free"){
        cout<<endl<<"你侵犯到了身為上司的瑪奇瑪"<<endl;
        cout<<"身為下屬，她指定您要像條狗絕對的服從"<<endl;
        int free_choice{0};
        do{
            cout<<"1.旺旺旺"<<endl;
            cout<<"2.你才是狗"<<endl;
            cout<<"您的選擇是 (1~2): ";
            cin>>free_choice;
            if(free_choice == 1 || free_choice == 2) break;
            cout<<"請看好輸入"<<endl;
            system("pause");
        }while(1);
        if(free_choice == 1){
            cout<<"您在合適的時機反殺了敵人"<<endl;
            cout<<"作為向慾望效忠的狗 你將 槍枝惡魔 做成料理享用"<<endl;
            this->end_game.push_back("醬汁燒肉");
            system("pause");
        }
        else if(free_choice == 2){
            cout<<"您選擇以弱小的身軀迎戰 槍枝惡魔 "<<endl;
            cout<<"啪 你沒了"<<endl;
            this->end_game.push_back("渺小的弱者");
            this->life = 0;
            system("pause");
        }
    }
    else if(WhichEvent == "life"){
        cout<<endl<<"巧遇水神大人"<<endl;
        int life_choice{0};
        do{
            cout<<"1.是"<<endl;
            cout<<"2.否"<<endl;
            cout<<"是否向偉大的 阿克西斯教 低頭 (1、2) : ";
            cin>>life_choice;
            if(life_choice == 1 || life_choice == 2) break;
            cout<<"請看好輸入"<<endl;
            system("pause");
        }while(1);
        if(life_choice == 1){
            int new_life{0};
            do{
                cout<<"請輸入你希望的生命值 (數字 1~10000) :";
                cin>>new_life;
                if(new_life >= 1 && new_life <= 10000) break;
                cout<<"請輸入合理的數字"<<endl;
                system("pause");
            }while(1);
            new_life = this->pick_num(0, new_life);
            this->life += new_life;
            cout<<"從偉大的 水之女神 獲得了 "<<new_life<<" 生命值"<<endl;
            this->end_game.push_back("不可靠的保佑");
            system("pause");
        }
        else if(life_choice == 2){
            cout<<"淘氣的 阿庫雅 懲罰了你"<<endl;
            int new_life{0};
            do{
                cout<<"請輸入你希望的生命值 (數字 1~100) :";
                cin>>new_life;
                if(new_life >= 1 && new_life <= 100) break;
                cout<<"接受懲罰吧!!"<<endl;
                system("pause");
            }while(1);
            do{
                new_life = this->pick_num(0, new_life);
            }while(new_life >= this->life);
            this->life = new_life;
            cout<<"非常遺憾...你只剩下了 "<<this->life<<" 的生命值"<<endl;
            this->end_game.push_back("抵死不從的堅持");
            system("pause");
        }
    }
    else if(WhichEvent == "footprint"){
        if(this->weight > 70){
            int footprint_choice{0};
            do{
                cout<<"您的胖使迷宮失去往日的安寧"<<endl;
                cout<<"以下是 WorldGym 教練的建議"<<endl;
                cout<<"1. 抓舉 230 kg 的槓鈴"<<endl;
                cout<<"2. 挺舉 270 kg 的槓鈴"<<endl;
                cout<<"3. 花 9.5s 完成 100m 短跑"<<endl;
                cout<<"4. 花 1:59:40s 完成一場馬拉松"<<endl;
                cout<<"您的選擇是 (1~4) : ";
                cin>>footprint_choice;
                if(footprint_choice >= 1 || footprint_choice <= 4) break;
                cout<<"請看好輸入"<<endl;
                system("pause");
            }while(1);
            if(footprint_choice == 1){
                cout<<"世界抓舉紀錄 : 拉沙·塔拉哈澤 也才 225 kg"<<endl;
            }
            else if(footprint_choice == 2){
                cout<<"世界挺舉紀錄 : 拉沙·塔拉哈澤 也才 267 kg"<<endl;
            }
            else if(footprint_choice == 3){
                cout<<"世界短跑紀錄 : 斐迪南·奧曼亞拉·姆魯瓦 也才 9.77s"<<endl;
            }
            else if(footprint_choice == 4){
                cout<<"世界馬拉松紀錄 : 埃利烏德·基普喬蓋 也才 1:59:40.2"<<endl;
            }
            cout<<"你的欺騙換來拳拳到肉的關照"<<endl;
            this->life--;
            this->record_die_life++;
            system("pause");
            this->end_game.push_back("欺騙教練的胖子");
        }
        else{
            cout<<"您的存在並沒有造成迷宮的困擾"<<endl;
            this->end_game.push_back("好好先生");
            system("pause");
        }
    }
    else if(WhichEvent == "player_now"){
        this->end_game.push_back("逆天改命");
        cout<<endl<<"您獲得了逆天改命的機會"<<endl;
        int life{0};
        do{
            cout<<"請輸入你希望的生命值 (數字 1~100) :";
            cin>>life;
            if(life >= 1 && life <= 100) break;
            cout<<"請珍惜機會"<<endl;
            system("pause");
        }while(1);
        if(this->life >= 100){
            this->life += life;
        }
        else{
            this->life = life;        
        }
        int gender;
        do{
            cout<<"請選擇性別 (1.男 2.女) : ";
            cin>>gender;
            if(gender == 1 || gender == 2) break;
            cout<<"請珍惜機會"<<endl;
            system("pause");
        }while(1);
        if(gender == 1){
            this->gender = "Man";
        }
        else{
            this->gender = "Woman";
        }
        cout<<"請重新輸入名字 (Only English And Numbers And Space): ";
        string name;
        cin.ignore();
        getline(cin, name);
        this->name = name;
        cout<<"請輸入年齡 (1~100) : ";
        int age;
        do{
            cin>>age;
            if(age >= 1 && age <= 100) break;
            cout<<"請珍惜機會"<<endl;
            system("pause");
        }while(1);
        this->age = age;
        int height;
        do{
            cout<<"請輸入身高 (1~200) : ";
            cin>>height;
            if(height >= 1 && height <= 200) break;
            cout<<"請珍惜機會"<<endl;
            system("pause");
        }while(1);
        this->height = height;
        int weight;
        do{
            cout<<"請輸入體重 (1~150) : ";
            cin>>weight;
            if(weight >= 1 && weight <= 150) break;
            cout<<"請珍惜機會"<<endl;
            system("pause");
        }while(1);
        this->weight = weight;
        cout<<endl<<"恭喜您獲得了新的身分"<<endl;
        this->print_player_info();
        system("pause");
    }
    else if(WhichEvent == "monster_week"){
        cout<<" : 我是邪惡組織的幹部"<<endl;
        cout<<" : 我的任務是觀察並毀滅可惡的地球人"<<endl;
        cout<<" : 但是今天是休假"<<endl;
        int choice_monweek;
        do{
            cout<<"1. 觀察熊貓"<<endl;
            cout<<"2. 日常光故便利店店員"<<endl;
            cout<<"請輸入你的選擇 (1~2) : ";
            cin>>choice_monweek;
            if(choice_monweek == 1 || choice_monweek == 2) break;
            cout<<"請看清楚輸入"<<endl;
        }while(1);
        if(choice_monweek == 1){
            cout<<"就這樣...世界又又獲得了一天的平靜"<<endl;
            this->end_game.push_back("治癒小日子");
        }
        else{
            cout<<"熊貓肉包賣完了？"<<endl;
            int sale{0};
            do{
                cout<<"1. 是"<<endl;
                cout<<"2. 否"<<endl;
                cout<<"是否承認還有肉包 (1、2) : ";
                cin>>sale;
                if(sale == 1 || sale == 2) break;
                cout<<"輸入1、2"<<endl;
                system("pause");
            }while(1);
            if(sale == 2){
                cout<<"你欺騙了壞人先生"<<endl;
                this->end_game.push_back("可惡的地球人");
            }
            else{
                cout<<"什麼事都沒發生，又是和平的一天"<<endl;
                this->end_game.push_back("地球拯救者");
            }
        }
    }
    else if(WhichEvent == "clear"){
        cout<<endl<<"上天恩賜你一項技能"<<endl;
        int skill_choice{0};
        do{
            cout<<"1.Unjustice"<<endl;
            cout<<"2.I Am ATOMIC"<<endl;
            cout<<"您的選擇是 (1~2): ";
            cin>>skill_choice;
            if(skill_choice == 1 || skill_choice == 2) break;
            cout<<"請選好技能"<<endl;
            system("pause");
        }while(1);
        if(skill_choice == 1){
            this->maze_map[this->pos_x][this->pos_y] = this->footprint;
            this->maze_map[this->end_point_x][this->end_point_y] = this->player_now;
            cout<<"你使用了 Unjustice 技能"<<endl;
            cout<<"能力：直達終點"<<endl;
            system("pause");
            this->end_game.push_back("不正義的勝利");
        }
        else if(skill_choice == 2){
            cout<<"你使用巨大的力量，清除了所有障礙"<<endl;
            for(int i=1;i<maze_map.size()-1;i++){
                for(int j=1;j<maze_map.size()-1;j++){
                    maze_map[i][j] = ' ';
                }
            }
            this->end_game.push_back("真不愧是暗影大人!!");
            system("pause");
        }
        
    }
    else if(WhichEvent == "gamble_horse"){
        vector<string> sor{"特別週","無聲鈴路","東海帝皇","青雲天空","富士奇石","小栗帽","大樹快車","草上飛","黃金船","目白麥昆"};
        cout<<"在不起眼的角落發現正在舉行一場賽馬"<<endl;
        cout<<"你決定與蹲在角落的 傑哥 來場豪賭"<<endl;
        int horse_choice{0};
        do{
            cout<<" 1. 特別週"<<endl;
            cout<<" 2. 無聲鈴路"<<endl;
            cout<<" 3. 東海帝皇"<<endl;
            cout<<" 4. 青雲天空"<<endl;
            cout<<" 5. 富士奇石"<<endl;
            cout<<" 6. 小栗帽"<<endl;
            cout<<" 7. 大樹快車"<<endl;
            cout<<" 8. 草上飛"<<endl;
            cout<<" 9. 黃金船"<<endl;
            cout<<"10. 目白麥昆"<<endl;
            cout<<"請下注你看好的馬 : ";
            cin>>horse_choice;
            if((horse_choice >= 1) && (horse_choice <= 10)) break;
            cout<<"請好好選擇"<<endl;
            system("pause");
        }while(1);
        int ja = 0;
        do{
            ja = this->pick_num(0, 10);
        }while(ja == horse_choice);
        vector<pair<string, int>> cmp;
        cmp.push_back(make_pair(sor[horse_choice-1], this->pick_num(5, 15)));
        cmp.push_back(make_pair(sor[ja], this->pick_num(5, 15)));
        cout<<endl;
        for(int i = 0; i<2; i++){
            cout<<cmp[i].first<<" 花了 "<<cmp[i].second<<" 秒 "<<"完成 100 米衝刺比賽"<<endl;
        }
        if(cmp[0].second > cmp[1].second){
            cout<<"吼由...輸了啦"<<endl;
            this->end_game.push_back("不被幸運女神眷顧的雖神");
            if(this->gender == "Man"){
                if(this->age >= 18){
                    cout<<"身體不錯喔~挺結實的"<<endl;
                    cout<<"你被 傑哥 強制燈大人了"<<endl;
                    system("pause");
                    this->end_game.push_back("不划算的賭博");
                }
                else{
                    cout<<"傑哥 看不上你"<<endl;
                    cout<<"你平安的告別了 傑哥"<<endl;
                    this->end_game.push_back("平淡的賭博");
                }
            }
            else if(this->gender == "Woman"){
                cout<<"お嬢様, it's time to go to bed"<<endl;
                cout<<"또 핸드폰 하는 거예요"<<endl;
                cout<<"늦게 자면 고운 피부가 다 무너진다구요"<<endl;
                cout<<"最後の警告です"<<endl;
                cout<<"지금 잠에 들지 않으면"<<endl;
                cout<<"우린 춤을 출 거예요"<<endl;
                cout<<"야레야레, 못 말리는 아가씨"<<endl;
                cout<<"야레야레"<<endl;
                cout<<"못 말리는 아가씨"<<endl;
                cout<<"야레야레"<<endl;
                cout<<"못 말리는 아가씨"<<endl;
                cout<<"또 핸드폰 하는 거예요"<<endl;
                this->end_game.push_back("晚安大小姐");
                system("pause");
            }
        }
        else if(cmp[0].second < cmp[1].second){
            cout<<"你成功地從 傑哥 手中獲得了勝利 "<<endl;
            this->end_game.push_back("賭狗的快樂");
        }
    }

    this->meet_event++;
}

void maze_player::print_player_info(){
    cout<<endl<<"Player Info:"<<endl<<endl;
    cout<<"Name   : "<<this->name<<endl;
    cout<<"Gender : "<<this->gender<<endl;
    cout<<"Age    : "<<this->age<<" years"<<endl;
    cout<<"Height : "<<this->height<<" cm"<<endl;
    cout<<"Weight : "<<this->weight<<" kg"<<endl;
    cout<<"Life   : "<<this->life<<endl;
    if(this->end_game.size() > 0){
        cout<<endl;
        cout<<"以下為目前獲得稱號 : "<<endl;
        for(string x : this->end_game) cout<<x<<endl;
        cout<<endl;
    }
}

bool maze_player::die(){
    if(this->life > 0) return false;
    cout<<endl<<"你已經成功的完成了拙劣的表演"<<endl;
    char choice;
    do{
        cout<<"是否要重玩一次？(y/n) : ";
        cin>>choice;
        if(choice == 'y'){
            this->end_game_print();
            this->end_game.clear();
            maze_player* new_player = nullptr;
            new_player = new maze_player();
            *this = *new_player;
            delete new_player;
            this->play_maze();
            return false;
        }
        else if(choice == 'n'){
            cout<<"沒有勇氣的傢伙"<<endl;
            return true;
        }    
        else{
            cout<<"請輸入y或n"<<endl;
            system("pause");
        }
    }while(choice!= 'y' && choice!= 'n');
    return false;                       //滿足return 而已，這對function不造成任何功能上的影響
}

bool maze_player::judge(){
    cout<<"現在，你還想重新挑戰嗎？(y/n) : ";
    char choice;
    do{
        cin>>choice;
        if(choice == 'y'){
            this->play_maze();
            return true;
        }
        else if(choice == 'n'){
            cout<<"感謝遊玩"<<endl;
            return false;
        }    
        else{
            cout<<"請輸入y或n"<<endl;
            system("pause");
        }
    }while(1);
}


bool maze_player::if_win(){
    if(this->maze_map[this->end_point_x][this->end_point_y] == this->player_now){
        cout<<"恭喜你通關了"<<endl;
        this->end_game_print();
        this->end_game.clear();
        system("pause");
        return this->judge();
    }
    return false;
}

char maze_player::move(char player_now){
    cout<<"Enter direction (w,a,s,d): ";
    char direction;
    do{
        cin>>direction;
        if(direction != 'w' && direction != 'a' && direction !='s' && direction != 'd'){
            cin.ignore();
            continue;
        }
    }while(!is_dir(direction));
    bool flag = false;
    if(direction == 'w'){
        if(move_ok(3)){
            this->Event(3);
            this->maze_map[this->pos_x][this->pos_y] = this->footprint;
            if(maze_map[this->pos_x-1][this->pos_y] == this->player_now) return 'w';
            this->pos_x += move_x[3];
            this->pos_y += move_y[3];
            flag = true;
        }
    }
    else if(direction == 'a'){
        if(move_ok(0)){
            this->Event(0);
            this->maze_map[this->pos_x][this->pos_y] = this->footprint;
            if(maze_map[this->pos_x-1][this->pos_y] == this->player_now) return 'a';
            this->pos_x += move_x[0];
            this->pos_y += move_y[0];
            flag = true;
        }
    }
    else if(direction == 's'){
        if(move_ok(1)){
            this->Event(1);
            this->maze_map[this->pos_x][this->pos_y] = this->footprint;
            if(maze_map[this->pos_x-1][this->pos_y] == this->player_now) return 's';
            this->pos_x += move_x[1];
            this->pos_y += move_y[1];
            flag = true;
        }
    }
    else{                   //d
        if(move_ok(2)){
            this->Event(2);
            this->maze_map[this->pos_x][this->pos_y] = this->footprint;
            if(maze_map[this->pos_x-1][this->pos_y] == this->player_now) return 'd';
            this->pos_x += move_x[2];
            this->pos_y += move_y[2];
            flag = true;
        }
    }
    if(flag){
        this->maze_map[this->pos_x][this->pos_y] = player_now;
    }
    return direction;
}

bool maze_player::move_ok(int dir){
    if((this->maze_map[this->pos_x+this->move_x[dir]][this->pos_y+this->move_y[dir]]) == '+'){
        return true;
    }
    else if((this->pos_x+this->move_x[dir] <=0) || (this->pos_x+move_x[dir] >=(maze_map.size()-1)) || (this->pos_y+move_y[dir] <=0) || (this->pos_y+move_y[dir] >= maze_map[0].size()-1) || (maze_map[this->pos_x+this->move_x[dir]][this->pos_y+this->move_y[dir]] == '#')){
        cout<<"看起來你選擇了錯誤的方向"<<endl;
        cout<<"作為懲罰：生命減一"<<endl;
        this->life--;
        this->record_die_life++;
        system("pause");
        return false;
    }
    return true;
}

maze_player::maze_player(){              //玩家建構子
    cout<<endl<<"歡迎來到迷宮世界"<<endl;
    cout<<"在這裡，你將尋找 '+' 以獲得我的財寶"<<endl;
    cout<<"去吧!!我把一切都留在那裡了"<<endl;
    cout<<"在此迷宮， '#' 為邊界， '*' 為解答路徑， '-' 為隱藏表示， 'M' 為隨機事件"<<endl;
    system("pause");
    int life;
    do{
        cout<<"請輸入你期望的生命值 (數字 1~100) :";
        cin>>life;
    }while(life < 1 || life > 100);
    this->life = this->pick_num(1, life);
    this->record_die_life = this->life;

    if(this->life == life){
        cout<<endl<<"幸運如你~得到了最高的期望 "<<this->life<<" 的生命值"<<endl;
        system("pause");
    }
    else{
        cout<<endl<<"非常遺憾...您的祈禱不夠虔誠，只獲得了 "<<this->life<<" 的生命值"<<endl;
        system("pause");
    }
    int gender;
    do{
        cout<<"請選擇性別 (1.男 2.女) : ";
        cin>>gender;
        if(gender == 1){
            this->gender = "Man";
            break;
        }
        else if(gender == 2){
            this->gender = "Woman";
            break;
        }
        cout<<"請輸入1或2"<<endl;
        system("pause");
    }while(1);
    cout<<endl<<"請輸入勇者名字 (Only English And Numbers And Space): ";
    string name;
    cin.ignore();
    getline(cin, name);
    this->name = name;

    int age;
    do{
        cout<<"請輸入勇者年齡 (1~100) : ";
        cin>>age;
        if(age < 1){
            cout<<"禁止異世界轉生"<<endl;
            system("pause");
        }
        else if(age > 100){
            cout<<"您已經到了該退休的年紀了"<<endl;
            system("pause");
        }
    }while(age < 1 || age > 100);
    this->age = age;

    int height;
    do{
        cout<<"請輸入勇者身高 (1~200) : ";
        cin>>height;
        if(height < 1){
            cout<<"侏儒都比你高"<<endl;
            system("pause");
        }
        else if(height > 200){
            cout<<"怎麼還沒睡醒"<<endl;
            system("pause");
        }
    }while(height < 1 || height > 200);
    this->height = height;

    int weight;
    do{
        cout<<"請輸入勇者體重 (1~150) : ";
        cin>>weight;
        if(weight < 1){
            cout<<"嬰兒都比你重"<<endl;
            system("pause");
        }
        else if(weight > 150){
            cout<<"出門用吊車的人怎麼擠進迷宮入口"<<endl;
            system("pause");
        }
    }while(weight<1 || weight>150);
    this->weight = weight;
    this->print_player_info();
    cout<<endl<<"After Reading, ";
    system("pause");
    cout<<endl;
}

void maze_player::play_maze(){
    char player_now = 'Q';
    do{
        cout<<endl<<"請輸入代表你的符號 (only one char) : ";
        cin>>player_now;
        if(player_now == '#'){
            cout<<endl<<"不可以跟牆壁是一樣的符號喔"<<endl;
            system("pause");
        }
        else if(player_now == '*'){
            cout<<endl<<"不能和解答路徑的符號相同喔"<<endl;
            system("pause");
        }
        else if(player_now == '-'){
            cout<<endl<<"不可以跟關燈一樣的符號喔"<<endl;
            system("pause");
        }
        else if(player_now == 'M'){
            cout<<endl<<"不可以跟隨機事件一樣的符號喔"<<endl;
            system("pause");
        }
        else break;
    }while(1);
    this->player_now = player_now;

    char back = ' ';
    do{
        cout<<"請輸入移動後的軌跡符號 : ";
        cin>>back;
        if(back == '#'){
            cout<<endl<<"不可以跟牆壁是一樣的符號喔"<<endl;
            system("pause");
        }
        else if(back == '*'){
            cout<<endl<<"不能和解答路徑的符號相同喔"<<endl;
            system("pause");
        }
        else if(back == this->player_now){
            cout<<endl<<"不能和玩家的符號相同喔"<<endl;
            system("pause");
        }
        else if(back == '-'){
            cout<<endl<<"不可以跟關燈一樣的符號喔"<<endl;
            system("pause");
        }
        else if(back == 'M'){
            cout<<endl<<"不可以跟隨機事件一樣的符號喔"<<endl;
            system("pause");
        }
    }while((back == '#') || (back == '*') || (back == this->player_now) || (back == '-') || (back == 'M'));
    this->footprint = back;
    
    int size;
    do{
        cout<<endl<<"請輸入 '奇數' 大小的地圖 : ";
        cin>>size;
        if(size == 1){
            cout<<"勇者不可以這麼沒有挑戰心"<<endl;
            system("pause");
        }
        else if(size%2 == 0){
            cout<<"地圖大小必須為奇數"<<endl;
            system("pause");
        }
    }while((size%2 == 0) || (size < 3));
    generate_maze(size);
    for(int i=0;i<maze_map.size();i++){
        for(int j=0;j<maze_map[i].size();j++){
            if(maze_map[i][j] == this->player_now){
                this->pos_x = i;
                this->pos_y = j;
            }
        }
    }
    do{
        cout<<"是否要亮燈？(y/n) : ";
        char choice;
        cin>>choice;
        if(choice == 'y'){
            this->light_up = true;
            break;
        }
        else if(choice == 'n'){
            this->light_up = false;
            break;
        }
        else{
            cout<<"請輸入y或n"<<endl;
            system("pause");
        }
    }while(1); 
    cout<<"這是世界為你打造的地獄"<<endl;
    this->print_maze(light_up);
    do{
        int choice;
        cout<<endl<<endl<<"你有以下選擇："<<endl;
        cout<<"1. 移動"<<endl;
        cout<<"2. 看解答"<<endl;
        cout<<"3. 玩燈"<<endl;
        cout<<"4. 查看個人資訊"<<endl;
        cout<<"5. 離開"<<endl;
        cout<<"你的選擇是 (1~5) : ";
        cin>>choice;
        if(choice == 1){
            char choice_move;
            do{
                cout<<"是否選擇連續移動？(y/n) : ";
                cin>>choice_move;
                if(choice_move == 'y' || choice_move == 'n')break;
                else{
                    cout<<"請輸入y或n"<<endl;
                    system("pause");
                }
            }while(1);
            if(choice_move == 'y'){
                int count{0};
                do{
                    cout<<"請輸入移動次數 (1~20) : ";
                    cin>>count;
                    if(count>=1 && count<=20)break;
                    else{
                        cout<<"請輸入1~20"<<endl;
                        system("pause");
                    }
                }while(1);
                for(int i=0;i<count;i++){
                    if((this->maze_map[this->end_point_x][this->end_point_y] == player_now) || (this->life <= 0)) break;
                    this->move(player_now);
                    print_maze(this->light_up);
                }
            }
            else{
                this->move(player_now);
                print_maze(this->light_up);
            }
        }
        else if(choice == 2){
            if(maze_map.empty()){
                cout<<"請生成地圖"<<endl;
                system("pause");
            }
            else{
                this->ans_maze_map = this->maze_map;
                this->solve(this->pos_x, this->pos_y);
                ans_maze_map[this->pos_x][this->pos_y] = player_now;
                for(int i=0;i<ans_maze_map.size();i++){
                    for(int j=0;j<ans_maze_map[i].size();j++){
                        if((maze_map[i][j] == this->footprint) && (ans_maze_map[i][j] == '*')){
                            ans_maze_map[i][j] = '*';
                        }
                        else if((maze_map[i][j] == this->footprint) && (ans_maze_map[i][j] == ' ')){
                            ans_maze_map[i][j] = this->footprint;
                        }
                    }
                }
                if(this->ans_maze_map[this->end_point_x][this->end_point_y-1] != this->player_now){
                    this->ans_maze_map[this->end_point_x][this->end_point_y-1] = '>';
                }
                this->maze_map = this->ans_maze_map;
                this->print_maze(this->light_up);
            }
        }
        else if(choice == 3){
            this->light_up = !this->light_up;
            if(this->light_up) cout<<"你已為世界帶來燈光"<<endl;
            else cout<<"來吧!渾沌的世界"<<endl;
            this->print_maze(this->light_up);
            system("pause");
        }
        else if(choice == 4){
            this->print_player_info();
            system("pause");
        }
        else if(choice == 5){
            cout<<"感謝您的遊玩"<<endl;
            system("pause");
            return;
        }
        else{
            cout<<"請輸入1,2,3,4,5"<<endl;
            cout<<"下次遊戲請注意"<<endl;
            cout<<"如果你輸入的是字元~請中斷遊戲"<<endl;
            system("pause");
        }
        bool winner_choice = this->if_win();
        if((winner_choice == false) && (maze_map[this->end_point_x][this->end_point_y] == player_now)) break;
        if(this->die()) break;
    }while(1);
}

class game{
private:
    void copy();
    person* add();
    galgame* attack(int, player&, monster&);
    void fight(player&, monster&);
    bool havefun(person*);
    bool rpg();
    void total_rank(person*);
public:
    void play();
};

void game::total_rank(person* you){
    int choice_three{0}; 
    do{
        cout<<"1. height"<<endl;
        cout<<"2. weight"<<endl;
        cout<<"3. intelligence"<<endl;
        cout<<"你想看哪個的排名？ (1~3) : ";             //get_name get_intell get_weight get_height
        cin>>choice_three;
        if(choice_three >= 1 && choice_three <= 3) break;
        cout<<endl<<"請輸入 1~3"<<endl;
        system("pause");
    }while(1);

    char detail;
    do{
        cout<<"想看看細部資訊嗎？ (y/n) : ";
        cin>>detail;
        if((detail == 'y') || (detail == 'n')) break;
        cout<<endl<<"請輸入 y 或 n"<<endl;
        system("pause");
    }while(1);

    cout<<endl<<"以下是你要的資訊："<<endl;
    int E_rank{0}, M_rank{0}, Mo_rank{0}, P_rank{0};
    person* view_total = nullptr;
    view_total = new Earth_person();
    E_rank = view_total->get_rank(you, detail, choice_three);
    if(E_rank == 0){
        cout<<"你已經治霸了地球"<<endl;
    }    
    cout<<endl<<"在地球上，你是第: "<<E_rank+1<<" 名"<<endl;
    cout<<"After reading, ";
    system("pause");
    delete view_total;
    cout<<endl;

    view_total = new Mars_person();
    M_rank = view_total->get_rank(you, detail, choice_three); 
    if(M_rank == 0){
        cout<<"你已經治霸了火星"<<endl;
    }
    cout<<endl<<"在火星上，你是第: "<<M_rank+1<<" 名"<<endl;
    cout<<"After reading, ";
    system("pause");
    delete view_total;
    cout<<endl;

    view_total = new Moon_person();
    Mo_rank = view_total->get_rank(you, detail, choice_three); 
    if(Mo_rank == 0){
        cout<<"你已經治霸了月球"<<endl;
    }
    cout<<endl<<"在月球上，你是第: "<<Mo_rank+1<<" 名"<<endl;
    cout<<"After reading, ";
    system("pause");
    delete view_total;
    cout<<endl;

    view_total = new Pluto_person();
    P_rank = view_total->get_rank(you, detail, choice_three); 
    if(P_rank == 0){
        cout<<"你已經治霸了冥王星"<<endl;
    }
    cout<<endl<<"在冥王星上，你是第: "<<P_rank+1<<" 名"<<endl;
    cout<<"After reading, ";
    system("pause");
    delete view_total;
    
    cout<<endl<<"在世界看上，你是第: "<<E_rank+M_rank+Mo_rank+P_rank+1<<" 名"<<endl;
    system("pause");
}

void game::copy(){
    const static string author{"林承羿"};
    const static string otherName{"Leisure Hermit"};
    const static string student_id{"01257027"};
    cout<<endl<<"此遊戲由 "<<otherName<<" 製作"<<endl;
    cout<<endl<<"After reading the information, ";
    system("pause");
    cout<<endl;
}

void game::fight(player& fighter, monster& enemy){
    cout<<"你開始戰鬥"<<endl;
    player pytmp = fighter;
    monster eytmp = enemy;
    int who_first{0};
    galgame* winner = nullptr;
    if(fighter.get_level()>enemy.get_level()){
        cout<<"等即為角色較高， 角色 先攻"<<endl;
        who_first = 1;
        winner = attack(1, fighter, enemy);
    }
    else{
        cout<<"怪物等級較高， 怪物 先攻"<<endl;
        who_first = 0;
        winner = attack(0, fighter, enemy);
    }
    if(winner->get_name() == fighter.get_name()){
        cout<<endl<<"你好帥氣呀~既然這麼能打~再打十個"<<endl;
        cout<<"現在這是你新的資訊"<<endl<<endl;
        enemy.remove();             //被幹死了
        fighter.rewrite(eytmp.get_level(), eytmp.get_exp(), fighter);     //貪婪，吸收別人
        winner->print_info();
        system("pause");
    }
    else{
        cout<<endl<<"你死了...一刻都沒為 "<<pytmp.get_name()<<" 感到哀悼，下一個趕來的是哪個小丑呢"<<endl;
        cout<<"這是經過你微弱攻擊後的怪獸"<<endl<<endl;
        fighter.remove();
        enemy.rewrite(pytmp.get_level(), pytmp.get_exp(), enemy);
        winner->print_info();
        system("pause");
    }
}

galgame* game:: attack(int who_first, player& attacker, monster& enemy){
    while(attacker.get_hp() > 0 && enemy.get_hp() > 0){  //我先
        if(who_first == 1){
            int atk_mp = enemy.hurt(attacker.get_atk(), attacker.get_mp());
            attacker.setmp(atk_mp);
        }
        else{                                              //他先
            int eny_mp = attacker.hurt(enemy.get_atk(), enemy.get_mp());
            enemy.setmp(eny_mp);
        }
        who_first = !who_first;
    }
    if(attacker.get_hp() > 0){
        return &attacker;
    }
    else{
        return &enemy;
    }
}

person* game::add(){
    world wld;
    string planet = "";
    do{
        cout<<endl<<"請選擇你的星球(Put The Name Of The Planet)："<<endl;
        cout<<"是 名稱 請打字"<<endl<<endl;
        cout<<"1. Earth"<<endl;
        cout<<"2. Mars"<<endl;
        cout<<"3. Moon"<<endl;
        cout<<"4. Pluto"<<endl;
        cout<<"Your Planet: ";
        getline(cin, planet);   
    }while(wld.illegal_home(planet));

    person* you = nullptr;

    if(planet == "Earth"){
        you = new Earth_person();
    }
    else if(planet == "Mars"){
        you = new Mars_person();
    }
    else if(planet == "Moon"){
        you = new Moon_person();
    }
    else if(planet == "Pluto"){
        you = new Pluto_person();
    }

    you->input(planet);
    // you->print_data();                               //印出所在星球的所有人資訊，debug用
    cout<<endl<<"你的身分如下："<<endl;
    you->print_person();    
    return you;
}

bool game::rpg(){
    galgame* you = nullptr;
    int choice{0};
    cout<<endl<<"歡迎來到弱肉強食的世界"<<endl;
    cout<<"1. 增加角色"<<endl;
    cout<<"2. 增加怪物"<<endl;
    cout<<"3. 進入戰鬥"<<endl;
    cout<<"4. 印出全部內容"<<endl;
    cout<<"5. 離開遊戲"<<endl;
    cout<<"Your Choice（輸入數字）: ";
    cin>>choice;
    if(choice == 1){
        you  = new player();
        you->input();
        cout<<"你創造的角色如下："<<endl;
        you->print_info();
        delete you;                                  //釋放記憶體
        return true;
    }
    else if(choice == 2){
        you = new monster();
        you->input();
        cout<<"你創造的怪物如下："<<endl;
        you->print_info();
        delete you;                                  //釋放記憶體
        return true;
    }
    else if(choice == 3){
        player fighter;
        fighter = fighter.select();
        // fighter.print_info();                         //debug用
        if(fighter.get_name() == ""){
            return true;
        }

        cout<<"選擇你的對手"<<endl;
        monster enemy;
        enemy = enemy.select();
        if(enemy.get_name() == ""){
            return true;
        }
        // enemy.print_info();                           //debug用
        fight(fighter, enemy);
        return true;
    }
    else if(choice == 4){
        galgame* view = nullptr;
        view = new player();
        cout<<endl<<"Player populations: "<<endl;
        view->print_game();
        delete view;                                  //釋放記憶體
        cout<<"After reading, ";
        system("pause");

        view = new monster();
        cout<<"Monster populations: "<<endl;
        view->print_game();
        delete view;                                  //釋放記憶體
        cout<<"After reading, ";
        system("pause");
        return true;
    }
    else if(choice == 5){
        cout<<endl<<"感謝遊玩"<<endl;
        system("pause");
        return false;
    }
    else{
        cout<<"請看好輸入"<<endl;
        system("pause");
        return true;
    }
}

bool game:: havefun(person* you){
    cout<<endl<<"你好，我是神奇世界的小助手，請問你有什麼想問的？"<<endl;
    int choice{0};
    cout<<"1. 增加人數"<<endl;
    cout<<"2. 刪除人數"<<endl;
    cout<<"3. 印出所有人資訊"<<endl;
    cout<<"4. 排序"<<endl;
    cout<<"5. 世界排名"<<endl;
    cout<<"6. 退出"<<endl;
    cout<<"Your Choice: ";
    cin>>choice;
    if(choice == 1){
        cin.ignore();
        add();
        return true;
    }
    else if(choice == 2){
        person* del = nullptr;
        cout<<"想從哪裡移除 (輸入星球名稱): "<<endl;
        cout<<"是 名稱 名字 請打字"<<endl<<endl;
        cout<<"1. Earth"<<endl;
        cout<<"2. Mars"<<endl;
        cout<<"3. Moon"<<endl;
        cout<<"4. Pluto"<<endl;
        cout<<"Your Choice Planet: ";
        string where = "";
        cin.ignore();
        world *view = new world();
        do{
            getline(cin, where);
            if(where == "Earth"){
                del = new Earth_person();
            }
            else if(where == "Mars"){
                del = new Mars_person();
            }
            else if(where == "Moon"){
                del = new Moon_person();
            }
            else if(where == "Pluto"){
                del = new Pluto_person();
            }
        }while(view->illegal_home(where));

        cout<<"想除掉誰 (輸入名字)：";
        del->remove();
        delete del;                                  //釋放記憶體
        delete view;                                  //釋放記憶體
        return true;
    }
    else if(choice == 3){
        person* view = nullptr;
        cout<<"Earth populations: "<<endl;
        view = new Earth_person();
        view->print_data();
        delete view;                                 //釋放記憶體   
        cout<<"After reading, ";
        system("pause");

        cout<<"Mars populations: "<<endl;
        view = new Mars_person();
        view->print_data();
        delete view;                                  //釋放記憶體
        cout<<"After reading, ";
        system("pause");

        cout<<"Moon populations: "<<endl;
        view = new Moon_person();
        view->print_data();
        delete view;                                  //釋放記憶體
        cout<<"After reading, ";
        system("pause");

        cout<<"Pluto populations: "<<endl;
        view = new Pluto_person();
        view->print_data();
        delete view;                                  //釋放記憶體
        cout<<"After reading, ";
        system("pause");

        return true;
    }

    else if(choice == 4){
        cout<<endl<<"選擇要排序的星球 (輸入星球名稱): "<<endl;
        cout<<"是 名稱 請打字"<<endl<<endl;
        cout<<"1. Earth"<<endl;
        cout<<"2. Mars"<<endl;
        cout<<"3. Moon"<<endl;
        cout<<"4. Pluto"<<endl;
        cout<<"Your Choice Planet: ";
        string where = "";
        person* sor = nullptr;
        cin.ignore();
        world *view = new world();
        do{
            getline(cin, where);
            if(where == "Earth"){
                sor = new Earth_person();
            }
            else if(where == "Mars"){
                sor = new Mars_person();
            }
            else if(where == "Moon"){
                sor = new Moon_person();
            }
            else if(where == "Pluto"){
                sor = new Pluto_person();
            }
        }while(view->illegal_home(where));
        cout<<endl;
        sor->sort_yourself();
        delete view;                                  //釋放記憶體
        return true;
    }
    else if(choice == 5){
        if(you == nullptr){
            cout<<"所以你怎麼就不創身分呢？"<<endl;
            cout<<"請回吧"<<endl;
            system("pause");
            return true;
        }
        this->total_rank(you);
        return true;
    }
    else if(choice == 6){
        cout<<endl<<"感謝您的參與"<<endl;
        system("pause");
        return false;
    }
    else{
        cout<<endl<<"請不要調皮"<<endl;
        system("pause");
        return true;
    }
}


void game::play(){
    this->copy();
    int game_num{0};
    do{
        again:
        cout<<"你想玩什麼遊戲？(輸入數字): "<<endl;
        cout<<"1. 角色扮演"<<endl;
        cout<<"2. 單機RPG"<<endl;
        cout<<"3. 勇者迷宮"<<endl;
        cout<<"4. 離開"<<endl;
        cout<<"Your Choice: ";
        cin>>game_num;
        if(game_num == 1){
            cout<<endl<<"歡迎來到神奇世界："<<endl;
            cout<<"至第一次來到這裡的你"<<endl;
            person* you = nullptr;
            char new_info;
            do{
                cout<<endl<<"你想要自己的身分嗎？(y/n): ";
                cin>>new_info;
                if(new_info == 'y'){
                    cin.ignore();
                    you = add();                                 //輸入身分資訊，載入世界資訊
                    break;
                }
                else if(new_info == 'n'){
                    cout<<"您不能參與 世界排序"<<endl;
                    break;
                }
                else{
                    cout<<"請輸入小寫呦~"<<endl;
                    system("pause");
                }
            }while(1);


            system("pause");                                     //給你確認資訊

            bool flag = true;
            do{
                flag = havefun(you);
            }while(flag);
        }

        else if(game_num == 2){
            bool flag = true;
            do{
                flag = this->rpg();
            }while(flag);
        }
        else if(game_num == 3){
            maze_player player;
            player.play_maze();
        }
        else if(game_num == 4){
            cout<<"您已完成遊戲體驗"<<endl;
            system("pause");
            break;
        }
        else{
            cout<<"請不要調皮"<<endl;
            system("pause");
            goto again;
        }
    }while(1);
}

int main(void){
    system("chcp 65001");                                //設定編碼為UTF-8
    srand((unsigned) time (NULL));

    game PlayForAllNight;
    PlayForAllNight.play();

    return 0;
}