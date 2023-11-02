#include <iostream>
#include <string>
using namespace std;


const double FACULTY_MONTHLY_SALARY = 5000.00; //declaring const global variable for faculty monthly salary
const int STAFF_MONTHLY_HOURS_WORKED = 160; //declaring const global variable for staff max hours worked

enum SEX { MALE, FEMALE};  // create global enum for the gender that has male and female
enum LEVEL { AS, AO, FU }; // create global enum for level that has the 3 available levels
enum DEGREE { MASTERS, PhD }; //create degree enum that contains masters and PhD

struct DATE { // create a struct for date that contains day, month and year
	int Day; //declare the day variable
	int Month; //declare the month variable
	int Year; //eclare the year variable

	DATE(int day, int month, int year) : Day(day), Month(month), Year(year) {} 
	// Define a constructor for the DATE struct that takes three integer parameters (day, month, and year).
	// The constructor initializes the struct's 'Day', 'Month', and 'Year' members with the values passed as arguments.
};

class Employee //create class employee
{
private:
	string FirstName; //declare string first name
	string LastName; //declare string lastname
	string IDNum; // Declare a private string variable to store the employee's ID
	SEX Sex; // Declare a private variable Sex of type SEX
	DATE BirthDate; // Declare a private variable of type DATE to store the employee's birthdate

public:
	Employee(const string &firstName, string lastName, string idNum, SEX sex, DATE birthday)
		: FirstName(firstName), LastName(lastName), IDNum(idNum), Sex(sex), BirthDate(birthday) {}
	// Define a constructor for the Employee class that initializes its private members with the provided values
	Employee() : FirstName(""), LastName(""), IDNum(""), Sex(MALE), BirthDate(DATE(0, 0, 0)) {}
	// Define a default constructor for the Employee class that initializes its private members with default values.

	virtual void putData() const //function does't modify variables so it is const
	{
		// Display employee information.
		cout << "ID Employee number: " << IDNum << endl;
		cout << "Employee name: " << FirstName << " " << LastName << endl;
		cout << "Birth date: " << BirthDate.Day << "/" << BirthDate.Month << "/" << BirthDate.Year << endl;
	}

	void set_first_name(const string &FirstName) { // Set the first name of the employee
		this->FirstName = FirstName;
	}
	void set_last_name(const string &LastName) { // Set the last name of the employee
		this->LastName = LastName;
	}
	void set_id_num(const string &IDNum) { // Set the ID number of the employee
		this->IDNum = IDNum;
	}
	void set_sex(const SEX Sex) { // Set the gender of the employee
		this-> Sex = Sex;
	}
	void set_birthday(const DATE BirthDate) { // Set the birthdate of the employee.
		this->BirthDate = BirthDate;
	}
	

	string getFirstName() const // Get the first name of the employee and return it
	{
		return FirstName;
	}
	string getLastName() const // Get the last name of the employee and retun it
	{
		return LastName;
	}
	string getID() const // Get the ID number of the employee and return it
	{
		return IDNum;
	}
	SEX getGender() const // Get the gender of the employee and rturn it
	{
		return Sex; 
	}
	DATE getBirthDay() const // Get the birthdate of the employee and return it
	{
		return BirthDate;
	}
	virtual double monthlyEarning()const = 0; 
	// Declare a pure virtual function for calculating the monthly earnings of the employee
};

class Staff : public Employee
{
private:
	double HourlyRate; // Declare a private double variable to store the hourly rate for a staff member
public:
	Staff() : Employee("", "", "", MALE, DATE(0, 0, 0)), HourlyRate(0.0) {}
	// Define a default constructor for the Staff class which initializes the Employee base class with default values
	// and sets the hourly rate to 0.0
	Staff(string FirstName, string LastName, string IDNum, SEX Sex, DATE BirthDay, double hourlyRate) :
		Employee(FirstName, LastName, IDNum, Sex, BirthDay), HourlyRate(hourlyRate) {}
	// Define a parameterized constructor for the Staff class which initializes the Employee base class with provided values
	// and sets the hourly rate.

	void setHourlyRate(const double hourlyRate)
	{
		HourlyRate = hourlyRate; // Set the hourly rate for a staff member
	}

	double getHourlyRate() const // Get the hourly rate for a staff member.
	{
		return HourlyRate;
	}
	double monthlyEarning() const // Calculate and return the monthly earning for a staff member, assuming a full-time workload of 160 hours.
	{
		return HourlyRate * STAFF_MONTHLY_HOURS_WORKED;
	}
	virtual void putData() const //it is virtual so that we can override it in class Parttime
	{
		// Display staff member's information, including employee data, employment status, and monthly salary
		Employee::putData(); // Call the base class's putData method to display common employee information
		cout << "Full Time" << endl;
		cout << "Monthly Salary: $" << monthlyEarning() << endl;

	}

};

class Education
{
private:
	DEGREE Degree; // Declare a private variable of type DEGREE to store the degree.
	string Major; // Declare a private string variable to store the major field of study.
	int ResearchNumber; // Declare a private integer variable to store the number of research projects
public:
	Education() : Education(MASTERS, "", 0){}
	// Define a default constructor for the Education class, which initializes the degree to MASTERS, major to an empty string, and researchNumber to 0.
	Education(DEGREE degree, string major, int researchNumber) : Degree(degree), Major(major), ResearchNumber(researchNumber){}
	// Define a parameterized constructor for the Education class that sets the degree, major, and researchNumber based on provided values.

	void setDegree(const DEGREE degree) // Set the education degree level
	{
		Degree = degree;
	}
	void setMajor(const string major) // Set the major field of study
	{
		Major = major;
	}
	void setResearchNumber(const int researchNumber) // Set the number of research projects
	{
		ResearchNumber = researchNumber;
	}

	DEGREE getDegree() const // Get the education degree level of type DEGREE and return it
	{
		return Degree;
	}
	string getMajor() const // Get the major and return it as a string
	{
		return Major;
	}
	int getResearchNumber() const // Get the number of research projects and return it as an integer
	{
		return ResearchNumber;
	}

};


class Faculty : public Employee //class faculty inherites from Employee
{
	Education Edu; // Declare an object of class Education to store the faculty member's education details
	LEVEL Level; // Declare a private variable of type LEVEL to represent the faculty member's level.
public:
	Faculty() : Employee("", "", "", MALE, DATE(0, 0, 0)) , Edu(), Level(AS){}
	// Define a default constructor for the Faculty class. It initializes the Employee base class with default values,
	// and sets the education to default values, and sets the level to Assistant Professor
	Faculty(string FirstName, string LastName, string ID, SEX Sex, DATE BirthDay, LEVEL level, Education education) :
		Employee(FirstName, LastName, ID, Sex, BirthDay), Level(level), Edu(education) {}
	// Define a parameterized constructor for the Faculty class. It initializes the Employee base class with provided values,
	// and sets the level and education based on the provided parameters

	void setter(const LEVEL level) // Set the level of the faculty member
	{
		Level = level;
	}
	LEVEL get_level() const // Get and return the level of the faculty member 
	{
		return Level;
	}
	double monthlyEarning() const // Calculate and return the monthly earning based on the faculty level
	{
		if (Level == AS) //if employee is Assistant professor, return FACULTY_MONTHLY_SALARY
		{
			return FACULTY_MONTHLY_SALARY;
		}
		else if (Level == AO) //if employee is Assosiate professor, return FACULTY_MONTHLY_SALARY*1.2
		{
			return FACULTY_MONTHLY_SALARY * 1.2;
		}
		else if (Level == FU) //if employee is Full professor, return FACULTY_MONTHLY_SALARY*1.4
		{
			return FACULTY_MONTHLY_SALARY * 1.4;
		}
	}
	virtual void putData() const //function does't modify variables so it is const
	{
		// Display faculty member's information, including employee data, level, and monthly salary.
		Employee::putData(); // Call the base class's putData method to display common employee information.
		if (Level == AS)
		{
			cout << "Assistant Professor" << endl; //if level is AS print Assistant Professor 
		}
		else if (Level == AO) //if level is AO print Associate Professor 
		{
			cout << "Associate Professor" << endl;
		}
		else if (Level == FU) //if level is FU print Full Professor 
		{
			cout << "Full Professor" << endl;
		}
		cout << "Monthly Salary: $" << monthlyEarning() << endl; //print and call the Monthly Salary of the faculty employee
	}

};

class Parttime : public Staff
{
private:
	int HoursPerWeek; // Declare a private variable to store the number of hours worked per week by a part-time employee.
public:
	Parttime() : Staff(), HoursPerWeek(0) {}
	// Define a default constructor for the Parttime class. It initializes the Staff base class with default values,
	// and sets the number of hours worked per week to 0.
	Parttime(string FirstName, string LastName, string IDNum, SEX Sex, DATE BirthDay, double HourlyRate,int hoursPerWeek)
		: Staff(FirstName, LastName, IDNum, Sex, BirthDay, HourlyRate), HoursPerWeek(hoursPerWeek) {}
	// Define a parameterized constructor for the Parttime class. It initializes the Staff base class with provided values,
	// and sets the number of hours worked per week based on the provided parameter

	void setHoursPerWeek(const int hoursPerWeek) // Set the number of hours worked per week by a part-time employee.
	{
		HoursPerWeek = hoursPerWeek;
	}
	int getHoursPerWeek() const // Get and return the number of hours worked per week by a part-time employee.
	{
		return HoursPerWeek;
	}
	double monthlyEarning() const // Calculate and return the monthly earning for a part-time employee, based on hourly rate and hours worked per week.
	{
		return getHourlyRate() * HoursPerWeek * 4;
	}
	virtual void putData() const
	{
		// Display part-time employee's information, including employee data, hours worked per month, and monthly salary.
		Employee::putData(); // Call the base class's putData method to display common employee information.
		cout << "Hours worked per month: " << HoursPerWeek << " hours"<< endl;
		cout << "Monthly Salary: $" << monthlyEarning() << endl;
	}
};

int main()
{
	Employee* employee[9]; // Create an array of Employee pointers to hold various employee objects.
	// Initialize the employee array with different types of employees.
	employee[0] = new Staff("Paita", "Allen", "123", MALE, DATE(2, 23, 59), 50.00);
	employee[1] = new Staff("Steven", "Zapata", "456", FEMALE, DATE(7, 12, 64), 35.00);
	employee[2] = new Staff("Enrique", "Rios", "789", MALE, DATE(6, 2, 70), 40.00);
	employee[3] = new Faculty("Anne", "Johnson", "243", FEMALE, DATE(4, 27, 62), FU, Education(PhD, "Engineering", 3));
	employee[4] = new Faculty("William", "Bouris", "791", FEMALE, DATE(3, 14, 75), AO, Education(PhD, "English", 1));
	employee[5] = new Faculty("Christopher", "Andrade", "623", FEMALE, DATE(5, 22, 80), AS, Education(MASTERS, "Physical Education", 0));
	employee[6] = new Parttime("Augusto", "Guzman", "455", FEMALE, DATE(8, 10, 77), 35.00, 30);
	employee[7] = new Parttime("Martin", "Depirro", "678", FEMALE, DATE(9, 15, 87), 30.00, 15);
	employee[8] = new Parttime("Marque", "Aldaco", "945", MALE, DATE(11, 24, 88), 20.00, 35);
	
	cout << "=========== ALL EMPLOYEES DATA ===========" << endl;

	for (int i = 0; i < 9; i++)
	{// Iterate through the employee array and display each employee's data.
		employee[i]->putData(); // if it's a Staff object, call Staff's putData, etc brcaue it is virtual function
		cout << endl;
	}

	// Calculate the total monthly salary for all employees and part-time staff.
	double totalPartTimeSalary = 0.0;
	double totalEmployeeSalary = 0.0;

	for (int i = 0; i < 9; i++) {
		totalEmployeeSalary += employee[i]->monthlyEarning(); // Calculate sum salary for all employee types.
		
		if (dynamic_cast<Parttime*>(employee[i])) {		// Check if the employee is of Parttime type using dynamic_cast.
			totalPartTimeSalary += employee[i]->monthlyEarning(); //calculate sum salary for only parttime employees
		}
	}

	// print the total monthly salary for part-time staff and all employees.
	cout << "Total monthly salary for all part-time staff: $" << totalPartTimeSalary << endl;
	cout << "Total monthly salary for all employees: $" << totalEmployeeSalary << endl;
	
}
