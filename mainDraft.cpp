//------------------------------------------------------------------------------
// SECJ1023- Programming Technique II | Semester 2, 2021/2022
// Project Interim Submission
// Section 7 Group 5
// LUQMAN HAKIM BIN MD SAID A21EC0050
// MUHAMMAD TAUFIQ BIN JURIMI A21EC0095
// NURFAZLIN BINTI MAT TAMIDI A21EC0119
// NURKHAIRUNNADIYA BINTI AHMADI A21EC0217
// Admin username = admin0
// Admin password = pt2
// Deliveryman plate number = UTM5050
//------------------------------------------------------------------------------

#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;
#define MENU_MAX 20

class RestaurantOwner;
class Customer;
class Order;
class Dish;
class Menu;
class DeliveryMan;
class Payment;

class RestaurantOwner
{
private:
	string restaurantName, username, password;

public:
	RestaurantOwner()
	{
		restaurantName = "W3sternz";
		username = "admin0";			//admin username
		password = "pt2";				//admin password
	}
	RestaurantOwner(string rn, string un, string p)
	{
		restaurantName = rn;
		username = un;
		password = p;
	}
	void setrestaurantName(string rn) { restaurantName = rn; }
	void setusername(string un) { username = un; }
	void setpassword(string p) { password = p; }
	string getrestaurantName() const { return restaurantName; }
	string getusername() const { return username; }
	string getpassword() const { return password; }
	void create()
	{
		cin.ignore();
		cout << "+------------------------------------+" << endl;
		cout << "+  Create Restaurant Owner's Account +" << endl;
		cout << "+------------------------------------+" << endl;
		cout << setfill(' ') << setw(20) << left << "Enter restaurant name : ";
		getline(cin, restaurantName);
		cout << setfill(' ') << setw(20) << left << "Enter your username : ";
		getline(cin, username);
		cout << setfill(' ') << setw(20) << left << "Enter your password : ";
		getline(cin, password);
	}
	void update()
	{
		cout << "+------------------------------------+" << endl;
		cout << "+     Restaurant Owner's Account     +" << endl;
		cout << "+------------------------------------+" << endl;
		cout << setfill(' ') << setw(20) << left << "Restaurant name : " << restaurantName << endl;
		cout << setfill(' ') << setw(20) << left << "Username : " << username << endl;
		cout << setfill(' ') << setw(20) << left << "Password : " << password << endl;
	}
};

// association
class Customer
{
private:
	string customerName;
	string username;
	string password;
	string address;

public:
	Customer()
	{
		customerName = "";
		username = "";
		password = "";
		address = "";
	}
	Customer(string cn, string un, string p, string a)
	{
		customerName = cn;
		username = un;
		password = p;
		address = a;
	}
	string history[10];
	int pastOrder = 0;
  string cusReview, cusDate;
	string getcustomerName() const { return customerName; }
	string getusername() const { return username; }
	string getpassword() const { return password; }
	string getaddress() const { return address; }
	void setcustomerName(string cn) { customerName = cn; }
	void setusername(string un) { username = un; }
	void setpassword(string p) { password = p; }
	void setaddress(string a) { address = a; }
	void create()
	{
		system("cls");

		cin.ignore();
		cout << "+------------------------------------+" << endl;
		cout << "+     Create  Customer's Account     +" << endl;
		cout << "+------------------------------------+" << endl;
		cout << endl;
		cout << setw(20) << left << "Enter your username : ";
		getline(cin, username);
		cout << setw(20) << left << "Enter your password : ";
		getline(cin, password);
		cout << setw(20) << left << "Enter your location address : ";
		getline(cin, address);
		cout << setw(20) << left << "Enter your name [eg: Luqman] : ";
		getline(cin, customerName);
	}
	void update()
	{
		cout << "+------------------------------------+" << endl;
		cout << "+          Customer's Account        +" << endl;
		cout << "+------------------------------------+" << endl;
		cout << setfill(' ') << setw(20) << left << "Customer name : " << customerName << endl;
		cout << setfill(' ') << setw(20) << left << "Username : " << username << endl;
		cout << setfill(' ') << setw(20) << left << "Password : " << password << endl;
		cout << setfill(' ') << setw(20) << left << "Address : " << address << endl;
	}
	void historylist()
	{
		cout << "+------------------------------------+" << endl;
		cout << "+          Your Order History        +" << endl;
		cout << "+------------------------------------+" << endl;
		for (int i = 0; i < pastOrder; i++)
			if (pastOrder > 0)
				cout << i + 1 << ". " << history[i] << endl;
	}
	
	void review(string d, string r) // tengok yang ini
	{
		cusDate = d;
		cusReview = r;
		cout << "Order Date: " << cusDate << " - Review: " << cusReview << endl;
	}
	void review() // tengok yang ini
	{
		cout << "Order Date: " << cusDate << " - Review: " << cusReview << endl;
	}
};

// composition
// parent class:Customer class
class Order
{
private:
	string date;
	string cart;
	Customer c1;

public:
	Order()
	{
		date = "";
		cart = "";
	}
	Order(string date1, string cart1, string cn, string un, string p, string a) : c1(cn, un, p, a)
	{
		cart = cart1;
		date = date1;
	}
	Order(string date1, string cart1)
	{
		date = date1;
		cart = cart1;
	}
	string getdate() const { return date; }
	string getcart() const { return cart; }
	void setdate(string d) { date = d; }
	void setcart(string c) { cart = c; }
	void update()
	{
		system("cls");
		cout << "+------------------------------------+" << endl;
		cout << "+           Customer's Order         +" << endl;
		cout << "+------------------------------------+" << endl;
		cout << setfill(' ') << setw(20) << left << "Customer's Name : " << c1.getcustomerName() << endl;
		cout << setfill(' ') << setw(20) << left << "Address : " << c1.getaddress() << endl;
		cout << setfill(' ') << setw(20) << left << "Date : " << date << endl;
		cout << setfill(' ') << setw(20) << left << "Cart : " << cart << endl;
	}
};

class Dish
{
private:
	Order o;
	string category;
	string foodname;
	double foodprice;

public:
	Dish(string f, double p, string cat) : o("", "")
	{
		foodname = f;
		foodprice = p;
		category = cat;
	};
	Dish(string f, double p, string cat, string _d, string _c) : o(_d, _c)
	{
		category = cat;
		foodname = f;
		foodprice = p;
	}

	void setFoodName(string n)
	{
		foodname = n;
	}
	void setFoodPrice(double p)
	{
		foodprice = p;
	}
	void setCategory(string c)
	{
		category = c;
	}
	void update()
	{
		cout << setfill(' ') << setw(20) << left << "Dish : " << foodname << ", Price: " << foodprice << ", Category: " << category << endl;
	}
	string getFoodName() const
	{
		return foodname;
	}
	double getFoodPrice() const
	{
		return foodprice;
	}
	string getCategory() const
	{
		return category;
	}
	double operator+(const double right)
	{
		return this->foodprice + right;
	}
};

class Menu
{
private:
	string description;
	string listoffood[MENU_MAX];
	Dish *d;

public:
	Menu(string desc, Dish dishes[], int N)
	{
		description = desc;
		for (int i = 0; i < N; i++)
			listoffood[i] = dishes[i].getFoodName();

		d = dishes;
	}
	void setDescription(string desc)
	{
		description = desc;
	}
	void setListOfFood(Dish d[], int i)
	{
		listoffood[i] = d[i].getFoodName();
	}
	string getDescription() const
	{
		return description;
	}
	string getListOfFood(int i) const
	{
		return listoffood[i];
	}
	void update(Dish dishes[], int N)
	{
		cout << "+----------------------------------------------+" << endl;
		cout << "+------------------   MENU:   -----------------+" << endl;
		cout << "+----------------------------------------------+" << endl;
		for (int i = 0; i < N; i++)
		{
			cout<<left;
			cout << i + 1 << ". " <<setw(10)
				 << "Dish : " << dishes[i].getFoodName() << setw(10)<< ", Price: " << dishes[i].getFoodPrice() << setw(10)<< ", Category: " << dishes[i].getCategory() << endl;
		}
	}
};

class DeliveryMan
{
private:
	Order o;
  string dName, tvehicle, mvehicle, nvehicle, dreview[10];
public:
	
	DeliveryMan()
	{
		dName = "Ali";
		tvehicle = "Motorcycle"; // type
		mvehicle = "Honda EX5";	 // model
		nvehicle = "UTM5050";	 				// ! Deliveryman initial plat no
		for (int i = 0; i < 10; i++)
			dreview[i] = "";
	}
	DeliveryMan(string dn, string v, string m, string n, string dp, string r[]) : o()
	{
		dName = dn;	  // deliveryman name or username
		tvehicle = v; // deliveryman vehicle details; type
		mvehicle = m; // model,
		nvehicle = n; // plat no
		for (int i = 0; i < 10; i++)
			dreview[i] = r[i];
	}
  string requiredDelivery[10];
	string getName() const { return dName; }
	string getVehicle() const { return tvehicle; }
	string getModel() const { return mvehicle; }
	string getNoPlat() const { return nvehicle; }
	string getReview(int I) const { return dreview[I]; }
	void setName(string dn) { dName = dn; }
	void setVehicle(string v) { tvehicle = v; }
	void setModel(string m) { mvehicle = m; }
	void setNoPlat(string n) { nvehicle = n; }
	void setReview(string r, int I) { dreview[I] = r[I]; }
	void update()
	{
		cout << "1. "
			 << "Name : " << dName << "\nVehicle Type: " << tvehicle << "\nVehicle Model: " << mvehicle << "\nVehicle Plat Number: " << nvehicle << endl;
	}
	void review(string r, int N)
	{
		dreview[N] = r;
	}
	void review(Customer cus[])
	{
		for (int i = 0; i < 10; i++)
		{
			cout << i + 1 << ". " << dName << " - Customer Name: " << cus[i].getcustomerName() << " - Review: " << dreview[i] << endl;
		}
	}
	
};


class Payment
{
protected:
	string cardNum;
	DeliveryMan d;
	double price;
	string paymentId;

public:
	Payment() {}
	Payment(double pc, string pId, string cNum) : d()	// Composition
	{
		price = pc;
		paymentId = pId;
		cardNum = cNum;
	}
	void setPrice(double pc) { price = pc; }
	void setPaymentId(string pId) { paymentId = pId; }
};

void intro()
{
	cout << "Group member     : MUHAMMAD TAUFIQ BIN JURIMI" << endl;
	cout << "                 : LUQMAN HAKIM BIN MD SAID" << endl;
	cout << "                 : NURKHAIRUNNADIYA BINTI AHMADI" << endl;
	cout << "                 : NURFAZLIN BINTI MAT TAMIDI" << endl;
	cout << "\n\n";
}

void customerOption()
{
	cout << setfill(' ') << setw(20) << left << "\n1. View menu list" << endl;
	cout << setfill(' ') << setw(20) << left << "2. Order dish" << endl;
	cout << setfill(' ') << setw(20) << left << "3. View your cart" << endl;
	cout << setfill(' ') << setw(20) << left << "4. History and Review" << endl;
	cout << setfill(' ') << setw(20) << left << "5. View your account details" << endl;
	cout << setfill(' ') << setw(20) << left << "6. Edit your account details" << endl;
	cout << setfill(' ') << setw(20) << left << "7. Logout and exit" << endl;
}

int main()
{
	RestaurantOwner admin;
	DeliveryMan d;
	Dish dishes[16] = {
		Dish("Chicken Burger", 3.50, "Main dish, Non-Vegan, Halal"),
		Dish("Beef Burger", 3.50, "Main dish, Non-vegan, Halal"),
		Dish("Macaroni & Cheese", 5.00, "Main dish, Non-Vegan, Halal"),
		Dish("Spaghetti Carbonara", 5.00, "Main dish, Non-Vegan, Halal"),
		Dish("Spaghetti Aglio Olio", 5.00, "Main dish, Non-vegan, Halal"),
		Dish("Tofu Spinach Lasagna", 6.00, "Main dish, Vegan, Halal"),
		Dish("Special W3sternz Steak", 10.00, "Main dish, Non-vegan, Halal"),
		Dish("Special W3sternz Beef Ribs", 12.00, "Main dish, Non-Vegan, Halal"),
		Dish("Salad", 3.00, "Side Dish, Vegan, Halal"),
		Dish("Cheeesy Fried Potato Wedges", 4.00, "Side Dish, Vegan, Halal"),
		Dish("Dairy free Vanilla Ice Cream", 2.00, "Dessert, Vegan, Halal"),
		Dish("Special caramel Chocolate Ice Cream", 4, "Dessert, Non-Vegan, Halal"),
		Dish("Chardonnay Wine", 10.00, "Drink, Vegan, NON-HALAL"),
		Dish("Sprite", 2.00, "Drink, Vegan, Halal"),
		Dish("Ice Chocolate", 4.00, "Drink, Non-Vegan, Halal"),
		Dish("Ice Lemon Tea", 2.00, "Drink, Vegan, Halal")};
	Menu restaurantMenu("We prepare special and lazat western food", dishes, 16); // Aggregation
	Customer cus[10];
	Order myOrder;
	Order *orderPtr;

	int choice = 0, isCustomerSignedIn = 0, customerlist = 0, successfulLogin = 0, customers = 0;
	intro();
	do
	{

		cout
			<< "+--------------------------------------------+" << endl;
		cout << "+                    HOLA!                   +" << endl;
		cout << "+            WELCOME TO " << admin.getrestaurantName();
		cout << "             +" << endl;
		cout << "+          (powered by AyuhOrder!!!)         +" << endl;
		cout << "+               Option, choose               +" << endl;
		cout << "+--------------------------------------------+" << endl;

		cout << setfill(' ') << setw(20) << left << "1. Restaurant owner" << endl;
		cout << setfill(' ') << setw(20) << left << "2. Customer" << endl;
		cout << setfill(' ') << setw(20) << left << "3. Deliveryman" << endl;
		cout << setfill(' ') << setw(20) << left << "4. Exit" << endl;

		cin >> choice;
		int choiceadmin = 1, choicecustomer = 1, choicecustomer1 = 1;
		switch (choice)
		{
		case 1: // Restaurant Owner
		{
		L1:
			system("cls");
			string owner_name, owner_pass;
			cout << "+--------------------------------------------+" << endl;
			cout << "+----- Please Insert Username & Password ----+" << endl;
			cout << "+--------------------------------------------+" << endl;
			cout << "Username: ";
			cin >> owner_name;
			cout << "Password: ";
			cin >> owner_pass;
			while (choiceadmin)
			{

				int choice_admin = 1;
				if (owner_name == admin.getusername() && owner_pass == admin.getpassword())
				{
					system("cls");
					cout << "+----------------------------------------------+" << endl;
					cout << "+------- HI, WELCOME TO YOUR RESTAURANT -------+" << endl;
					cout << "+----------------------------------------------+" << endl;
					cout << "+------ Please CHOOSE what you want to do -----+" << endl;
					cout << "+----------------------------------------------+" << endl;
					cout << setfill(' ') << setw(20) << left << "\n1. Edit Menu" << endl;
					cout << setfill(' ') << setw(20) << left << "2. Create Employee Account" << endl;
					cout << setfill(' ') << setw(20) << left << "3. Review" << endl;
					cout << setfill(' ') << setw(20) << left << "0. Logout and Exit" << endl;
					cin >> choice_admin;

					switch (choice_admin)
					{
					case 1:
					{
						int dishNum, menu_edit = 1;
						while (menu_edit)
						{
							system("cls");
							restaurantMenu.update(dishes, 16);
							cout << "+------------------------------------------------------+" << endl;
							cout << "+----- Please CHOOSE which dish you want to change ----+" << endl;
							cout << "+------------------------------------------------------+" << endl;
							string dish_name, category;
							double dish_price;
							cout << "\nDish Number: ";
							cin >> dishNum;
							cin.ignore();
							cout << "\nInsert New Dish Name: ";
							getline(cin, dish_name);
							cout << "\nInsert New Dish Price (Enter number [ex: 5.00]): ";
							cin >> dish_price;
							cin.ignore();
							cout << "\nInsert New Dish Category: ";
							getline(cin, category);
							dishes[dishNum - 1] = Dish(dish_name, dish_price, category);

							system("cls");
							cout << "+----------------------------------------------+" << endl;
							cout << "+------------------   MENU:   -----------------+" << endl;
							cout << "+----------------------------------------------+" << endl;
							for (int i = 0; i < 16; i++)
							{
								cout << i + 1 << ". "
									 << "Dish : " << dishes[i].getFoodName() << ", Price: " << dishes[i].getFoodPrice() << ", Category: " << dishes[i].getCategory() << endl;
							}

							cout << "+----------------------------------------------+" << endl;
							cout << setfill(' ') << setw(20) << left << "\n1. Re-Edit" << endl;
							cout << setfill(' ') << setw(20) << left << "0. Exit" << endl;
							cin >> menu_edit;

							while (menu_edit != 1 && menu_edit != 0)
							{
								cout << "Please, enter a legitimate number" << endl;
								cout << "+----------------------------------------------+" << endl;
								cout << setfill(' ') << setw(20) << left << "\n1. Re-Edit" << endl;
								cout << setfill(' ') << setw(20) << left << "0. Exit" << endl;
								cin >> menu_edit;
							}
						}
						break;
					}
					case 2:
					{
						system("cls");
						int employee_choice, employee_acc = 1;
						while (employee_acc)
						{
							cout << "+----------------------------------------------+" << endl;
							cout << "+------------- EMPLOYEES ACCOUNT --------------+" << endl;
							cout << "+----------------------------------------------+" << endl;
							cout << setfill(' ') << setw(20) << left << "\n1. Sign up a new employee account" << endl;
							cout << setfill(' ') << setw(20) << left << "2. List of Employees" << endl;
							cout << setfill(' ') << setw(20) << left << "0. Exit" << endl;
							cin >> employee_choice;

							switch (employee_choice)
							{
							case 1:
							{
								cin.ignore();
								string dname, vtype, vmodel, vplat;
								system("cls");
								cout << "+----------------------------------------------+" << endl;
								cout << "+------- EMPLOYEES ACCOUNT REGISTRATION -------+" << endl;
								cout << "+----------------------------------------------+" << endl;
								cout << "\nInsert New Deliveryman Name: ";
								getline(cin, dname);
								d.setName(dname);
								cout << "\nInsert Vehicle Type: ";
								getline(cin, vtype);
								d.setVehicle(vtype);
								cout << "\nInsert Vehicle Model: ";
								getline(cin, vmodel);
								d.setModel(vmodel);
								cout << "\nInsert Vehicle Plat Number: ";
								getline(cin, vplat);
								d.setNoPlat(vplat);

								cout << "Registration successful.\nPress enter to go back to employees account menu" << endl;
								system("PAUSE");
								system("cls");
								break;
							}
							case 2:
							{
								system("cls");
								cout << "+----------------------------------------------+" << endl;
								cout << "+------------- LIST OF EMPLOYEES --------------+" << endl;
								cout << "+----------------------------------------------+" << endl;
								cout << "1. "
									 << "Name : " << d.getName() << ", Vehicle Type: " << d.getVehicle() << ", Vehicle Model: " << d.getModel() << ", Vehicle Plat Number: " << d.getNoPlat() << endl;
								cout << "\nPress any key to go back to employees account menu" << endl;
								system("PAUSE");
								system("cls");
								break;
							}
							case 0:
								employee_acc = 0;
								break;

							default:
								system("cls");
								cout << "Please, enter a legitimate number" << endl;
								break;
							}
						}
						break;
					}
					case 3:
					{
						system("cls");
						int review_choice, review_list = 1;
						while (review_list)
						{
							cout << "+----------------------------------------------+" << endl;
							cout << "+-------------- LIST OF REVIEWS ---------------+" << endl;
							cout << "+----------------------------------------------+" << endl;
							cout << setfill(' ') << setw(20) << left << "\n1. Customers Review" << endl;
							cout << setfill(' ') << setw(20) << left << "2. Deliveryman Review" << endl;
							cout << setfill(' ') << setw(20) << left << "0. Exit" << endl;
							cin >> review_choice;

							switch (review_choice)
							{
							case 1:
							{
								system("cls");
								cout << "+----------------------------------------------+" << endl;
								cout << "+--------- LIST OF CUSTOMERS REVIEWS ----------+" << endl;
								cout << "+----------------------------------------------+" << endl;
								for (int i = 0; i < 10; i++)
								{
									string r;
									cus[i].review();
								}
								system("PAUSE");
								system("cls");
								break;
							}

							case 2:
							{
								system("cls");
								cout << "+----------------------------------------------+" << endl;
								cout << "+------- LIST OF DELIVERYMANS REVIEWS ---------+" << endl;
								cout << "+----------------------------------------------+" << endl;
								string rev;
								d.review(cus);
								system("PAUSE");
								system("cls");
								break;
							}

							case 0:
								review_list = 0;
								break;

							default:
								system("cls");
								cout << "Please, enter a legitimate number" << endl;
								break;
							}
						}

						break;
					}
					case 0:
						choiceadmin = 0;
						break;

					default:
						cout << "Please, enter a legitimate number" << endl;
						system("pause");
						break;
					}
				}
				else
				{
					system("cls");
					cout << "+----------------------------------------------+" << endl;
					cout << "+---------------- WARNING!!! ------------------+" << endl;
					cout << "+----------------------------------------------+" << endl;
					cout << "+------ WRONG USERNAME & PASSWORD INSERT ------+" << endl;
					cout << "+----------------------------------------------+" << endl;
					cout << setfill(' ') << setw(20) << left << "\n1. Re-enter Username & Password" << endl;
					cout << setfill(' ') << setw(20) << left << "0. Exit" << endl;
					int adminacc;
					cin >> adminacc;
					switch (adminacc)
					{
						case 1:
							goto L1;
						break;

						case 0:
							choiceadmin = 0;
						break;

						default:
							cout << "Please enter a legitimate number" << endl;
							cout << "Press any key to re-enter Username & Password" << endl;
							system("PAUSE");
							goto L1;
						break;
					}	
					
				}
			}
			break;
		}

		case 2: // customer
		{
			int choicecustomer, customerIndex;
			do
			{
				cin.ignore();
				system("cls");
				cout << "+----------------------------------------------+" << endl;
				cout << "+------- HI, WELCOME TO OUR RESTAURANT --------+" << endl;
				cout << "+----------------------------------------------+" << endl;
				cout << "+------- Please SIGN UP if you are new --------+" << endl;
				cout << "+----------------------------------------------+" << endl;
				cout << "+--- SIGN IN if you already have an account ---+" << endl;
				cout << "+----------------------------------------------+" << endl;
				cout << setfill(' ') << setw(20) << left << "\n1. Sign up a new account" << endl;
				cout << setfill(' ') << setw(20) << left << "2. Sign in" << endl;
				cout << setfill(' ') << setw(20) << left << "3. Exit" << endl;
				cin >> choicecustomer;
				string tempCart = "", tempDate = "";
				double tempPrice = 0;
				switch (choicecustomer)
				{
				case 1:
					cus[customers].create();
					customers++;
					cout << "Thank you, registration successful.\nPress enter to proceed and sign in with your brand new account" << endl;
					break;
				case 2:
					if (successfulLogin == 0)
					{
						string cusUsername, cusPassword;
						system("cls");
						cout << "+----------------------------------------------+" << endl;
						cout << "+   You can proceed logging in your account    +" << endl;
						cout << "+----------------------------------------------+" << endl;
						cin.ignore();
						cout << "\nPlease enter your username: ";
						getline(cin, cusUsername);
						cout << "\nPlease enter your password: ";
						getline(cin, cusPassword);
            
						for (int i = 0; i < 10; i++)
						{
							if ((cusUsername == cus[i].getusername()) && cusPassword == cus[i].getpassword() && cusUsername != "" && cusPassword != "")
							{
								successfulLogin = 1;
								customerIndex = i;
							}
						}
						if (successfulLogin == 0)
							cout << "\nWrong Username or Password, press enter to go back" << endl;
					}
					if (successfulLogin == 1)
					{
						system("cls");
						do
						{
							system("cls");
							cout << "\n+----------------------------------------------+" << endl;
							cout << "+------------------ WELCOME -------------------+" << endl;
							cout << "+------------ Choose any option :D ------------+" << endl;
							cout << "+----------------------------------------------+" << endl;
							customerOption();
							cin >> choicecustomer1;
							switch (choicecustomer1)
							{
							case 1:
								system("cls");
								restaurantMenu.update(dishes, 16);
								system("PAUSE");
								break; // view menu
							case 2:
							{
								tempPrice = 0;
								tempCart = "";
                int dishAmount;
								system("cls");
								restaurantMenu.update(dishes, 16);
                
								cout << "\nHow many dishes you want to order?: ";
								cin >> dishAmount;
								int foodOrder[dishAmount];
								cin.ignore();
                
								cout << "Enter your preferred delivery time, example: 12:00am, 15 June 22: ";
								getline(cin, tempDate);
								myOrder.setdate(tempDate);
								system("cls");
								restaurantMenu.update(dishes, 16);
                
								cout << "\nEnter your order (key in number according to menu above)" << endl;
								for (int i = 0; i < dishAmount; i++)
								{
									cin >> foodOrder[i];
									tempCart.append(restaurantMenu.getListOfFood(foodOrder[i] - 1) + ",");
								}
								for (int i = 0; i < dishAmount; i++)
								{
									myOrder.setcart(restaurantMenu.getListOfFood(foodOrder[i] - 1));
									tempPrice = dishes[foodOrder[i] - 1] + tempPrice; // Operator overloading (dishes are an array of object)
								}
								cout << "Thank you for your order. You can proceed to your cart for purchase purposes" << endl;
								system("PAUSE");
								break;
							} // order
							case 3:
							{
								if (tempPrice != 0)
								{
									Order finalOrder(tempDate, tempCart, cus[customerIndex].getcustomerName(), cus[customerIndex].getusername(), cus[customerIndex].getpassword(), cus[customerIndex].getaddress()); //composition
									orderPtr = &finalOrder;
									system("cls");
									orderPtr->update();
									cout << "\n*---  Your Cart : \n"
										 << tempCart << " ---*" << endl;
									cout << "\n*--- Total Price : RM" << tempPrice << " ---*" << endl;
									cout << "Enter 1 to proceed to payment, and any key to go back" << endl;
									int paymentIndex;
									cin >> paymentIndex;
									if (paymentIndex == 1)
									{
                    string cardnum, cardcvv;
                    system("cls");
										cout << "+--------------------------------------------+" << endl;
										cout << "+     Enter your credit card information     +" << endl;
										cout << "+--------------------------------------------+" << endl;
										cout << "\nEnter 16 digits card number: ";
										cin >> cardnum;
										cout << "Enter 3 digit cvv number (back of your card): ";
										cin >> cardcvv;
                    
										Payment creditcard(tempPrice, cardnum, cardcvv);
										system("cls");
										cout << "+--------------------------------------------+" << endl;
										cout << "+  THANK YOU, YOUR ORDER WILL BE DELIVERED   +" << endl;
										cout << "+    ACCORDING TO THE TIME/DATE PROVIDED     +" << endl;
										cout << "+--------------------------------------------+" << endl;
										d.requiredDelivery[customerIndex] = "Date: " + tempDate + " | Location: " + cus[customerIndex].getaddress() + " | Order:" + tempCart;
										cus[customerIndex].pastOrder++;
										cus[customerIndex].history[cus[customerIndex].pastOrder - 1] = tempCart;
										tempPrice = 0;
										system("PAUSE");
									}
									else
									{
										break;
									}
								}
								else if (tempPrice <= 0)
								{
									cout << "Please order something first" << endl;
									system("PAUSE");
								}
								break;
							}
							case 4: // history
								if (cus[customerIndex].pastOrder == 0)
								{
									cout << "No past order, buy something first :D" << endl;
									system("PAUSE");
								}
								else
								{
									cus[customerIndex].historylist();
									string r;
									cin.ignore();
									cout << "\nEnter your review for past order: ";
									getline(cin, r);
									cus[customerIndex].review(myOrder.getdate(), r);
									system("PAUSE");
								}
								break;
								// view account details
							case 5:
							{
								system("cls");
								cus[customerIndex].update();
								system("PAUSE");
								break;
							}
								// edit account details
							case 6:
								system("cls");
								int choicechange;
								cout << "+----------------------------------------------+" << endl;
								cout << "+---------- EDIT MY ACCOUNT DETAILS -----------+" << endl;
								cout << "+----------------------------------------------+" << endl;
								cout << "+---- CHOOSE THE OPTION YOU WANT TO EDIT ------+" << endl;
								cout << "+----------------------------------------------+" << endl;
								cout << setfill(' ') << setw(20) << left << "\n1. Change my name" << endl;
								cout << setfill(' ') << setw(20) << left << "2. Change my username" << endl;
								cout << setfill(' ') << setw(20) << left << "3. Change my password" << endl;
								cout << setfill(' ') << setw(20) << left << "4. Change my address" << endl;
								cin >> choicechange;
								switch (choicechange)
								{
								case 1:
								{
									string newcusname;
									cout << "My name: " << cus[customerIndex].getcustomerName() << endl;
									cout << "Type your new name: ";
									getline(cin, newcusname);
									while (newcusname == cus[customerIndex].getcustomerName())
									{
										cout << "Cannot enter the same name! Try Again" << endl;
										cout << "Type your new name: ";
										getline(cin, newcusname);
									}
									cus[customerIndex].setcustomerName(newcusname);
									break;
								}
								case 2:
								{
									string newcususername;
									cout << "My username: " << cus[customerIndex].getusername() << endl;
									cout << "Type your new username: ";
									getline(cin, newcususername);
									while (newcususername == cus[customerIndex].getusername())
									{

										cout << "Cannot enter the same username! Try Again" << endl;
										cout << "Type your new username: ";
										getline(cin, newcususername);
									}
									cus[customerIndex].setusername(newcususername);
									break;
								}
								case 3:
								{
									string newcuspassword;
									cout << "My Password: " << cus[customerIndex].getpassword() << endl;
									cout << "Type your new password: ";
									getline(cin, newcuspassword);
									while (newcuspassword == cus[customerIndex].getpassword())
									{

										cout << "Cannot enter the same password! Try Again" << endl;
										cout << "Type your new password: ";
										getline(cin, newcuspassword);
									}
									cus[customerIndex].setpassword(newcuspassword);
									break;
								}
								case 4:
								{
									string newcusaddress;
									cout << "My address: " << cus[customerIndex].getaddress() << endl;
									cout << "Type your new address: ";
									getline(cin, newcusaddress);
									while (newcusaddress == cus[customerIndex].getaddress())
									{
										cout << "Cannot enter the same address! Try Again" << endl;
										cout << "Type your new address: ";
										getline(cin, newcusaddress);
									}
									cus[customerIndex].setaddress(newcusaddress);
									break;
								}
								default:
									break;
								}
							case 7:
								successfulLogin = 0; // exit
								break;
							default:
								break;
							}
						} while (choicecustomer1 != 7);
					}

					break;
				case 3:

					break;
				}
			} while (choicecustomer != 3);
			break;
		}
		case 3: // Deliveryman(sign-in/choose order/pending order/delivery/review customer)
		{
			int choicedelivery = 1, orderChoice;
			string reviewEmployee, reviewCustomer;
			string delivery_name, delivery_pass, tempPlate;
			system("cls");
			cout << "+--------------------------------------------+" << endl;
			cout << "+          DELIVERY MAN VERIFICATION         +" << endl;
			cout << "+--------------------------------------------+" << endl;
			cout << "Enter your plate number for verification purposes: ";
			cin.ignore();
			getline(cin, tempPlate);
			if (tempPlate != d.getNoPlat())
			{
				cout << "WRONG, you will be send to main menu" << endl;
				system("PAUSE");
				system("cls");
				break;
			}
			system("cls");
			cout << "+--------------------------------------------+" << endl;
			cout << "+                WELCOME " << d.getName() << "            +" << endl;
			cout << "+                DELIVERY ACCOUNT            +" << endl;
			cout << "+--------------------------------------------+" << endl;
			d.update(); // shows deliveryman acc setup by admin
			system("PAUSE");
			system("cls");
			if (d.requiredDelivery[0] == "" && d.requiredDelivery[1] == "" && d.requiredDelivery[2] == "" && d.requiredDelivery[3] == "" && d.requiredDelivery[4] == "" &&
				d.requiredDelivery[5] == "" && d.requiredDelivery[6] == "" && d.requiredDelivery[7] == "" && d.requiredDelivery[8] == "" && d.requiredDelivery[9] == "")
			{
				cout << "+--------------------------------------------+" << endl;
				cout << "+                NO ORDER YET                +" << endl;
				cout << "+--------------------------------------------+" << endl;
				system("PAUSE");
				break;
			} // deliveryman can see customer's order
			else
			{
				cout << "+--------------------------------------------+" << endl;
				cout << "+          PLEASE FULFILL THIS ORDER         +" << endl;
				cout << "+--------------------------------------------+" << endl;
				for (int i = 0; i < 10; i++)
				{
					cout << i + 1 << ". " << d.requiredDelivery[i] << endl;
				}
				cout << "Enter your order choice to fulfill, according to number list above: ";
				cin >> orderChoice;
				d.requiredDelivery[orderChoice - 1] = "";
			}
			system("cls");

			while (choicedelivery)
			{
				system("cls");
				cout << "+--------------------------------------------+" << endl;
				cout << "+                DELIVERY STATUS             +" << endl;
				cout << "+--------------------------------------------+" << endl;
				cout << setfill(' ') << setw(20) << left << "Please choose your delivery status :" << endl;
				cout << setfill(' ') << setw(20) << left << "1. Order Pending" << endl;
				cout << setfill(' ') << setw(20) << left << "2. Order Processed(kitchen)" << endl;
				cout << setfill(' ') << setw(20) << left << "3. Ready to Pickup" << endl;
				cout << setfill(' ') << setw(20) << left << "4. Review" << endl;
				cout << setfill(' ') << setw(20) << left << "0. Exit" << endl;
				cin >> choicedelivery;

				// delivery status determine by deliveryMan

				system("cls");
				switch (choicedelivery)
				{
				case 1: // order pending status
					cout << "+--------------------------------------------+" << endl;
					cout << "+                 ORDER PENDING              +" << endl;
					cout << "+--------------------------------------------+" << endl;
					cout << setfill(' ') << setw(20) << left << "Please deliver the order within the time estimated" << endl;
					cout << setfill(' ') << setw(20) << left << "If failed to do so,a penalty will be given" << endl;
					system("PAUSE");
					break;

				case 2: // order processed status
					cout << "+--------------------------------------------+" << endl;
					cout << "+                ORDER PROCESSED             +" << endl;
					cout << "+--------------------------------------------+" << endl;
					cout << setfill(' ') << setw(20) << left << "The food is in processing by the kitchen crew" << endl;
					cout << setfill(' ') << setw(20) << left << "Please wait patiently" << endl;
					system("PAUSE");
					break;

				case 3: // order pickup status
					cout << "+--------------------------------------------+" << endl;
					cout << "+                READY TO PICKUP             +" << endl;
					cout << "+--------------------------------------------+" << endl;
					cout << setfill(' ') << setw(20) << left << "Order delivered successfully" << endl;
					cout << setfill(' ') << setw(20) << left << "Thanks,keep up with your good job :)" << endl;
					system("PAUSE");
					break;
				case 4:
				{
					// deliveryMan review their customer
					int i = 0;
					string name, cname, date, _review, r;
					system("cls");
					cout << "+--------------------------------------------+" << endl;
					cout << "+                    REVIEW                  +" << endl;
					cout << "+--------------------------------------------+" << endl;
					cin.ignore();
					cout << "Please enter your review for this order: ";
					getline(cin, r);
					d.review(r, orderChoice - 1);
					break;
				}
				case 0:
					break;
				default:
					cout << setfill(' ') << setw(20) << left << "Please enter a legitimate number \n"
						 << endl;
						system("PAUSE");
					break;
				}
			}
			break;
		}
		case 4:
			system("cls");
			cout << "+--------------------------------------------+" << endl;
			cout << "+                    MERCI                   +" << endl;
			cout << "+                 SEE U AGAIN                +" << endl;
			cout << "+--------------------------------------------+" << endl;
			system("PAUSE");
			break;

		default:
			cout << "Please enter a legitimate number \n"
				 << endl;
				 system("PAUSE");
			break;
		}

		system("cls");
	} while (choice != 4);

	
	return 0;
}