#ifndef LIB_H
#define LIB_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class person {
private:
  int number;      //Номер сотрудника
  string name;     // Ф.И.О open
  string position; // Должность open
  string phone;    // телефон сотрудника open
  int salary;      //Заработная плата close
  int passport;    //Паспортные данные close
public:
};

class application {
public:
  application();
  int exec();
  int regist_pers();
  int show_open();
  int show_close();

private:
  vector<person *> mass;
};

#endif
