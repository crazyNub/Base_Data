#include "lib.h"

application::application() {}

int application::exec() {
  string inp;
  do {
    cout << "Register new Personal(r)\nShow open data(o)\nShpw close data(c)\n";
    cout << "Input: ";
    cin >> inp;
    switch (inp) {
    case "r": {
      int b = regist_pers();
      if (b)
        return b;
      break;
    }
    case "o": {
      int o = show_open();
      if (o)
        return o;
      break;
    }
    case "c": {
      int c = show_close();
      if (c)
        return c;
      break;
    }
    default:
      cout << "\nError!\n";
    }
    cout << "Do you want to exit (y/n) \n";
    cin >> inp;
  } while (inp != "y");
  return 0;
}

int application::regist_pers() {
  person *human;
  human = new person;
  cout << "Input number: ";
  cin >> human->number;
  cout << "Input salary: ";
  cin >> human->salary;
  cout << "Input passport data: ";
  cin >> human->passport;
  cout << "Input position: ";
  human->position = getline();
  cout << "Input name: ";
  human->name = getline();
  cout << "Input phone: ";
  human->phone = getline();
  mass.push_back(human);
  return 0;
}

int application::show_open() {
  person *human;
  for (vector<person *>::iterator it = mass.begin(); it != mass.end(); it++) {
    human = *it;
    cout << "\n===============================\n";
    cout << "Show number:\n";
    cout << human->number << endl;
    cout << "Show name:\n";
    cout << human->name << endl;
    cout << "Show position:\n";
    cout << human->position << endl;
    cout << "Show phone:\n";
    cout << human->phone << endl;
    cout << "\n===============================\n";
  }
  return 0;
}

int application::show_close() {
  int pop = 0;
  int password;
  while (pop < 3) {
    cout << "Input password:";
    cin >> password;
    if (passord == 12345) {
      for (vector<person *>::iterator it = mass.begin(); it != mass.end();
           it++) {
        human = *it;
        cout << "\n===============================\n";
        cout << "Show salary:\n";
        cout << human->salary << endl;
        cout << "Show passport:\n";
        cout << human->passport << endl;
        cout << "\n===============================\n";
      }
    } else {
      cout << "Wrong password!" pop++;
    }
  }
  return 0;
}
