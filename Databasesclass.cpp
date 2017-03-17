#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "libsqlite.hpp"
class Databaseconnection
{
    /*This class stores the methods used by the main program to access and interact with the database*/
    public:
    void insertion(std::string sqliteFile, string tablename, string valuestring)
    {
    try
    {
    sqlite::sqlite db( sqliteFile );
    auto cur = db.get_statement();
    cur->step();
    switch(tablename)
    {
   case tablename = "Enemies" :
      cur->set_sql( "INSERT INTO Enemies (Unique_id, name, Health, Damage, Type, Armour) values (" + valuestring + ");" );
      break;
   case tablename = "Inventory"  :
      cur->set_sql( "INSERT INTO Inventory (Unique_id, name, Health, Damage, Type, Armour) values (" + valuestring + ");" );
      break;
   case tablename = "Loot" :
      cur->set_sql( "INSERT INTO Loot (Unique_id, name, Health, Damage, Type, Armour) values (" + valuestring + ");" );
      break;
   case tablename = "Player" :
      cur->set_sql( "INSERT INTO Player (Unique_id, name, Health, Damage, Type, Armour) values (" + valuestring + ");" );
      break;
   case tablename = "Weapons" :
      cur->set_sql( "INSERT INTO Weapons (Unique_id, name, Health, Damage, Type, Armour) values (" + valuestring + ");" );
      break;             
    }
     cur->prepare();
     cur->step();
 
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        std::cerr << e.what() << std::endl;
    }
    }
    /*This is insertion sql statement it has case selection to try and prevent sql injection 
    The syntax for calling this method is class_instance.insertion(sqliteFile,tablename,valuestring);*/
    void update(std::string sqliteFile, string tablename, string updatestring, string unique_id)
    {
    try
    {
    sqlite::sqlite db( sqliteFile );
    auto cur = db.get_statement();
    cur->step();
         
    cur->set_sql( "update Enemies set Name = 'Test8', Health = 20, Damage = 20, Type = 'True', Armour = 30 where Unique_id = 12;"); 
    switch(tablename)
    {
   case tablename = "Enemies" :
      cur->set_sql( "update Enemies set " + updatestring + " where Unique_id = " + unique_id +";");
      break;
   case tablename = "Inventory"  :
      cur->set_sql( "update Inventory set " + updatestring + " where Unique_id = " + unique_id +";");
      break;
   case tablename = "Loot" :
      cur->set_sql( "update Loot set " + updatestring + " where Unique_id = " + unique_id +";");
      break;
   case tablename = "Player" :
      cur->set_sql( "update Player set " + updatestring + " where Unique_id = " + unique_id +";");
      break;
   case tablename = "Weapons" :
      cur->set_sql( "update Weapons set " + updatestring + " where Unique_id = " + unique_id +";");
      break;             
    }
    cur->prepare();
    cur->step();

    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        std::cerr << e.what() << std::endl;
    }    
}
    /*Similar to the insertion statement the update statement uses the case selection to reduce the chance for sql injection
    The syntax for calling this method is class_instance.update(sqliteFile,tablename,updatestring,unique_id);*/
void selection(std::string sqliteFile, string tablename, string wherestring)
    {
    try
    {
    sqlite::sqlite db( sqliteFile );
    auto cur = db.get_statement();
    cur->step();
        cur->set_sql( "select * from " + tablename + " where Unique_id = '" + wherestring + "';");
    cur->prepare();
        cur->step();
    string storage[10];
       switch(tablename)
    {
   case tablename = "Enemies" :
      storage[0] = cur->get_int(0);
      storage[1] = cur->get_text(1);
      storage[2] = cur->get_int(2);
      storage[3] = cur->get_int(3);
      storage[4] = cur->get_text(4);
      storage[5] = cur->get_int(5);
      break;
   case tablename = "Inventory"  :
      storage[0] = cur->get_int(0);
      storage[1] = cur->get_text(1);
      storage[2] = cur->get_text(2);
      storage[3] = cur->get_text(3);
      storage[4] = cur->get_text(4);
      storage[5] = cur->get_text(5);
      storage[6] = cur->get_text(6);
      storage[7] = cur->get_text(7);
      storage[8] = cur->get_text(8);
      storage[9] = cur->get_text(9);
      break;
   case tablename = "Loot" :
      storage[0] = cur->get_int(0);
      storage[1] = cur->get_text(1);
      storage[2] = cur->get_text(2);
      break;
   case tablename = "Player" :
      storage[0] = cur->get_text(0);
      storage[1] = cur->get_int(1);
      storage[2] = cur->get_int(2);
      storage[3] = cur->get_int(3);
      storage[4] = cur->get_int(4);
      break;
   case tablename = "Weapons" :
      storage[0] = cur->get_text(0);
      storage[1] = cur->get_int(1);
      storage[2] = cur->get_text(2);
      storage[3] = cur->get_int(3);
      break;  
        

    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        std::cerr << e.what() << std::endl;
    }
    
    /*This is the selection statement it stores the selected data from the database in a array
    the syntax for calling this code is class_instance.selection(sqliteFile, tablename, wherestring);*/
    
}


}
/*
Databaseconnection connection;
connection.insertion(sqliteFile, tablename, valuestring);
connection.selection(sqliteFile, tablename, wherestring);
connection.update(sqliteFile, tablename, updatestring, unique_id);*/
