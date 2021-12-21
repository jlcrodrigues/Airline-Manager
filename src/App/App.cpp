#include "App.h"

App::App(): ITEMS_PER_PAGE(7)
{
   app_run = true;
}

App::App(const string &airports, const string &flights, const string &passengers, const string &planes, const string& carts): ITEMS_PER_PAGE(7)
{
   airline = Airline(airports, flights, passengers, planes, carts);
   app_run = true;
}

void App::run()
{
   cout << "Welcome to Airline Manager. Use help to get started.\n";
   while (app_run)
   {
      cout << ">";
      readCommand();
      processCommand();
   }
}

void App::clearStream() const
{
   cin.clear();
   cin.ignore(INT_MAX, '\n');
}

bool App::readNumber(int& n, const string& s) const
{
   try
   {
      n = stoi(s);
      if (n < 0) return false;
      return true;
   }
   catch (...)
   {
      return false;
   }
}

bool App::readDate(Date &date, const string s) const
{
    try
    {
        if (airline.getDateString(s).length() != 8) return false;
        int c = count(s.begin(), s.end(), '/');
        if (c != 2) return false;
        date.setDay(stoi(airline.getDateString(s).substr(0,2)));
        date.setMonth(stoi(airline.getDateString(s).substr(2,2)));
        date.setYear(stoi(airline.getDateString(s).substr(4, 4)));
        if (!date.checkDate(date)) return false;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool App::readDuration(Date &date, const string s) const
{
    try
    {
        string s2;
        int c = count(s.begin(), s.end(), ':');
        if (c != 1) return false;
        if (s[0] == ':') return false;
        int l = s.length();
        if (s[l-1] == ':') return false;
        int i;
        for (int j  = 0; j < s.length(); j++)
        {
            if (s[j] == ':')
            {
                i = j;
            }
        }
        date.setHour(stoi(s.substr(0, i)));
        date.setMinute(stoi(s.substr(i+1)));
        if (!date.checkDuration(date)) return false;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool App::readTime(Date &date, const string s) const
{
    try
    {
        if (airline.getTimeString(s).length() != 4) return false;
        int c = count(s.begin(), s.end(), ':');
        if (c != 1) return false;
        date.setHour(stoi(airline.getTimeString(s).substr(0,2)));
        date.setMinute(stoi(airline.getTimeString(s).substr(2, 2)));
        if (!date.checkTime(date)) return false;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool App::invalidAirportOrigin(string &aO)
{
    while (1) {
        cout << "Airport " << aO << " doesn't exist.\nYou can use menu to go back.\n";
        cout << "Origin airport id: ";
        cin >> aO;
        clearStream();
        if (aO == "menu")
        {
            return false;
        }
        else if (airline.checkAirport(aO)) return true;
    }
}

bool App::invalidAirportDestination(string &aD)
{
    while (1) {
        cout << "Airport " << aD << " doesn't exist.\nYou can use menu to go back.\n";
        cout << "Destination airport id: ";
        cin >> aD;
        clearStream();
        if (aD == "menu")
        {
            return false;
        }
        if (airline.checkAirport(aD)) return true;
    }
}

void App::invalidDepartureDate(Date &date, string &s) const
{
    while(1)
    {
        cout << "Invalid date. Please try again.\n";
        cout << "Departure date (dd/mm/yyyy): ";
        cin >> s;
        clearStream();
        if (readDate(date, s)) break;
    }
}


void App::invalidDepartureTime(Date &date, string &s) const
{
    while(1)
    {
        cout << "Invalid time. Please try again.\n";
        cout << "Departure time (hh:mm): ";
        cin >> s;
        clearStream();
        if (readTime(date, s)) break;
    }
}

void App::invalidDuration(Date &date, string &s) const
{
    while (1)
    {
        cout << "Invalid time. Please try again.\n";
        cout << "Duration time (hh:mm): ";
        cin >> s;
        clearStream();
        if (readDuration(date, s)) break;
    }
}

bool App::invalidPlane(string &id) const
{
    while (1)
    {
        cout << "Plane " << id << " doesn't exist. Try again.\nYou can use menu to go back.\nPlane id: ";
        cin >> id;
        clearStream();
        if (id == "menu") return false;
        if (airline.checkPlane(id)) return true;
    }
}

vector<int> App::findLength(const vector<vector<string>> &table) const
{
   vector<int> res(table[0].size(), 2);
   for (int i = 0; i < table.size(); i++)
   {
      for (int j = 0; j < table[0].size(); j++)
      {
         if (res[j] < table[i][j].size()) res[j] = table[i][j].size();
      }
   }
   return res;
}

void App::displayTable(vector<vector<string> > table, int page) const
{
   vector<int> length = findLength(table);
   vector<string> header = table[0];
   table.erase(table.begin());
   int n_pages = (table.size() + ITEMS_PER_PAGE - 1) / ITEMS_PER_PAGE - 1;
   page = min(n_pages, page - 1);
   page = max(0, page);
   string barrier = "+";
   for (int & i: length) barrier += string(i + 2, '-') + '+';
   cout << barrier << "\n|";
   for (int i = 0; i < header.size(); i++) cout << " " << left << setw(length[i]) << header[i]<< " |";
   cout << endl << barrier << endl;
   for (int i = page * ITEMS_PER_PAGE; i < table.size() && i < (page + 1) * ITEMS_PER_PAGE; i++)
   {
      cout << "|";
      for (int j = 0; j < table[0].size(); j++)
      {
         cout << " " << left << setw(length[j]) << table[i][j] << " |";
      }
      cout << endl;
   }
   cout << barrier << endl;
   string index = "Page " + to_string(page + 1) + "/" + to_string(n_pages + 1);
   cout << right << setw(barrier.size()) << index << endl;
}

bool App::getOption()
{
   char option = 'a';
   while (option != 'y' && option != 'n')
   {
      cin >> option;
      if (cin.eof())
      {
         app_run = false;
         return false;
      }
      option = tolower(option);
      clearStream();
   }
   if (option == 'y') return true;
   return option != 'n';
}

void App::readCommand()
{
   string w;
   getline(cin, w);
   stringstream word(w);
   queue<string> empty;
   swap(command, empty);
   while (getline(word, w, ' '))
   {
      if (!cin)
      {
         if (cin.eof()) app_run = false;
         else cout << "Something went wrong. Please try again.";
      }
      transform(w.begin(), w.end(), w.begin(), [](unsigned char c){return tolower(c);});
      command.push(w);
   }
}

void App::processCommand()
{
   if (!command.empty())
   {
      if (command.front() == "help")
      {
         command.pop();
         help();
         return;
      }
      if (command.front() == "alias")
      {
         command.pop();
         alias();
         return;
      }
      if (command.front() == "resize")
      {
         command.pop();
         resize();
         return;
      }
      if (command.front() == "about")
      {
         command.pop();
         about();
         return;
      }
      else if (command.front() == "airport" || command.front() == "a")
      {
         command.pop();
         airport();
         return;
      }
      else if (command.front() == "cart" || command.front() == "c")
      {
         command.pop();
         cart();
         return;
      }
      else if (command.front() == "flight" || command.front() == "f")
      {
         command.pop();
         flight();
         return;
      }
      else if (command.front() == "passenger" || command.front() == "pa")
      {
         command.pop();
         passenger();
         return;
      }
      else if (command.front() == "plane" || command.front() == "pl")
      {
         command.pop();
         plane();
         return;
      }
      else if (command.front() == "ticket" || command.front() == "t")
      {
         command.pop();
         ticket();
         return;
      }
      else if (command.front() == "quit" || command.front() == "q")
      {
         quit();
         return;
      }
   }
   cout << "Invalid command. Verify that it is right or use help.\n";
}

void App::alias()
{
   cout << "Save yourself a few key presses by using these shortcuts:\n\n";
   cout << "  airport: a\n  cart: c\n  flight: f\n  passenger: pa\n  plane:  pl\n  ticket: t\n\n";
}

void App::resize()
{
   int size;
   if (command.empty())
   {
      cout << "Usage:\n  resize 'size'";
      return;
   }
   if (!readNumber(size, command.front()))
   {
      cout << "Size must be a number. Please try again.\n";
      return;
   }
   size = max(1, size);
   size = min(30, size);
   ITEMS_PER_PAGE = size;
   cout << "Displays resized to " << size << " units.\n";
}

void App::about()
{
   cout << "This project was made in December of 2021 as part of the Algorithms and Data Structures ";
   cout << "course at FEUP. It was made using C++ and OOP as well as algorithms (binary search, sorting, etc) and ";
   cout << "data structures (stack, queue, bst, etc) approached in class.\n\n";
   cout << "Made by:\n  - Andre Barbosa\n  - Guilherme Almeida\n  - Jose Luis Rodrigues\n\n";
}

void App::quit()
{
    app_run = false;
}
