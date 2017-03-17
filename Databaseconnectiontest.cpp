#include <iostream>
#include <string>
using namespace std;

#include "libsqlite.hpp"

void insertion(std::string sqliteFile)
{
    try
    {
    sqlite::sqlite db( sqliteFile );
    auto cur = db.get_statement();
    cur->step();
    cur->set_sql( "INSERT INTO Enemies (Unique_id, name, Health, Damage, Type, Armour) values ('12', 'Test', '34', '60', 'Not', '10');" );
     cur->prepare();
     cur->step();
 
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        std::cerr << e.what() << std::endl;
    }
    
    
    
    
}

void update(std::string sqliteFile)
    {
    try
    {
    sqlite::sqlite db( sqliteFile );
    auto cur = db.get_statement();
    cur->step();
    cout << "Run test" << endl;
    cur->set_sql( "update Enemies set Name = 'Test8', Health = 20, Damage = 20, Type = 'True', Armour = 30 where Unique_id = 12;");         
    cout << "Run test = complete" << endl;
    cur->prepare();
    cur->step();

    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        std::cerr << e.what() << std::endl;
    }

    
    
    
    
}

void selection(std::string sqliteFile)
    {
    try
    {
    sqlite::sqlite db( sqliteFile );
    auto cur = db.get_statement();
    cur->step();
        cur->set_sql( "select * from Enemies where Unique_id = '12';");
    cur->prepare();
        cur->step();
        int id = cur ->get_int(0);
    string name = cur ->get_text(1);
        int Health = cur ->get_int(2);
    int Damage = cur ->get_int(3);
        string Type = cur ->get_text(4);
        int armour = cur ->get_int(5);

    cur->prepare();
        cur->step();
        cout << id << " " << name << " " << Health << " " << Damage << " " << Type << " " << armour << endl;

    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        std::cerr << e.what() << std::endl;
    }
    
    
    
}
 void getHealthPickups(std::string sqliteFile)
    {
    try
    {
    sqlite::sqlite db( sqliteFile );
    auto cur = db.get_statement();
    cur->step();
        cur->set_sql( "select * from Loot where Type = 'health';");
    cur->prepare();
       while( cur->step())
       {
           string name = cur ->get_text(1);
           cout << name << endl;
       }
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        std::cerr << e.what() << std::endl;
    }
        
    }



int main()
{
    string sqliteFile = "Gamedatabase.db";
    insertion(sqliteFile);
    update(sqliteFile);
    selection(sqliteFile);
    getHealthPickups(sqliteFile);
    
    
   return 0;
}


