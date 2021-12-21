#include "App.h"

void App::cart()
{
   if (command.empty())
   {
      cout << "Invalid option. Use help cart to see available commands.\n";
   }
   else if (command.front() == "display")
   {
      command.pop();
      displayCart();
   }
   else if (command.front() == "add")
   {
      command.pop();
      addCart();
   }
   else if (command.front() == "edit")
   {
      command.pop();
      editCart();
   }
   else if (command.front() == "remove")
   {
      command.pop();
      removeCart();
   }
   else if (command.front() == "find")
   {
      command.pop();
      findCart();
   }
   else if (command.front() == "assign")
   {
      command.pop();
      assignCart();
   }
   else cout << "Invalid option. Use help cart for more info.\n";
}

void App::displayCart()
{
   int page;
   vector<Cart> carts = airline.getCarts();
   if (carts.size() == 0)
   {
      cout << "No carts to display.\n";
      return;
   }
   vector<vector<string> > table;
   table.push_back({"Id", "Carriages", "Piles", "Pile Size", "Occupation", "Flight"});
   if (command.empty()) page = 0;
   else if (!readNumber(page, command.front()))
   {
      cout << "Page must be a number. Please try again.\n";
      return;
   }
   for (auto & c: carts)
   {
      string flight = to_string(c.getFlight());
      if (flight == "0") flight = "None";
      table.push_back({to_string(c.getId()), to_string(c.getCarriages()),
                       to_string(c.getPiles()), to_string(c.getPileSize()),
                       to_string(c.getOccupation()) + "%", flight});
   }
   displayTable(table, page);

}

void App::addCart()
{
   int id, carriages, piles, pile_size;
   string number;
   vector<string> aux = {"Number of carriages: ", "Number of piles: ", "Number of piles: "};
   vector<int> dimensions(3, 0);
   if (command.empty())
   {
      cout << "Usage:\n  cart add 'id'\n";
      return;
   }
   if (!readNumber(id, command.front()))
   {
      cout << "Invalid id. Please try again.\n";
      return;
   }
   command.pop();
   if (airline.checkCart(id))
   {
      cout << "Cart " << id << " already exists. Maybe you want to try:\n  cart edit 'id'\n";
      return;
   }
   for (int i = 0; i < 3; i++)
   {
      do
      {
         cout << aux[i];
         cin >> number;
         clearStream();
      } while(!readNumber(dimensions[i], number));
   }
   airline.addCart({id, dimensions[0], dimensions[1], dimensions[2]});
}

void App::editCart()
{
   int id, carriages, piles, pile_size;
   string number;
   vector<string> aux = {"Number of carriages: ", "Number of piles: ", "Number of piles: "};
   vector<int> dimensions(3, 0);
   if (command.empty())
   {
      cout << "Usage:\n  cart edit 'id'\n";
      return;
   }
   if (!readNumber(id, command.front()))
   {
      cout << "Invalid id. Please try again.\n";
      return;
   }
   command.pop();
   if (!airline.removeCart(id))
   {
      cout << "Cart " << id << " does not exist. Adding a new one.\n";
   }
   for (int i = 0; i < 3; i++)
   {
      do
      {
         cout << aux[i];
         cin >> number;
         clearStream();
      } while(!readNumber(dimensions[i], number));
   }
   airline.addCart({id, dimensions[0], dimensions[1], dimensions[2]});
}

void App::removeCart()
{
   int id;
   if (command.empty())
   {
      cout << "Usage:\n  cart remove 'id'\n";
      return;
   }
   if (!readNumber(id, command.front()))
   {
      cout << "Invalid id. Please try again.\n";
      return;
   }
   if (airline.removeCart(id))
   {
      cout << "Cart " << id << " was removed.\n";
   }
   else cout << "That cart doesn't exist.\n";
}

void App::findCart()
{
   int id;
   if (command.empty())
   {
      cout << "Usage:\n  cart find 'id'\n";
      return;
   }
   if (!readNumber(id, command.front()))
   {
      cout << "Invalid id. Please try again.\n";
      return;
   }
   if (airline.checkCart(id))
   {
      Cart* cart = airline.findCart(id);
      cout << "Id: " << cart->getId() << "\nCarriages. " << cart->getCarriages();
      cout << "\nNumber of piles: " << cart->getPiles() << "\nBags per pile: ";
      cout << cart->getPileSize() << "\nAssigned flight: ";
      if (cart->getFlight() == 0) cout << "None\n";
      else cout << cart->getFlight() << '\n';
   }
   else cout << "Cart not found.\n";
}

void App::assignCart()
{
   int id, flight_id;
   if (command.empty())
   {
      cout << "Usage:\n  cart assign 'id' 'flight_id'\n";
      return;
   }
   if (!readNumber(id, command.front()))
   {
      cout << "Invalid id. Please try again.\n";
      return;
   }
   if (!airline.checkCart(id))
   {
      cout << "That cart doesn't exist. Use cart display to see available carts.\n";
      return;
   }
   command.pop();
   if (!readNumber(flight_id, command.front()))
   {
      cout << "Invalid id. Please try again.\n";
      return;
   }
   if (!airline.checkFlight(flight_id))
   {
      cout << "That flight doesn't exist. Use flight display to see available flights.\n";
      return;
   }
   Cart* cart = airline.findCart(id);
   if (cart->getFlight() != 0)
   {
      cout << "Cart " << id << " is already assigned to a flight.\n";
   }
   else
   {
      airline.assignCartFlight(id, flight_id);
      cout << "Cart " << id << " was assigned to flight " << flight_id << ".\n";
   }
}