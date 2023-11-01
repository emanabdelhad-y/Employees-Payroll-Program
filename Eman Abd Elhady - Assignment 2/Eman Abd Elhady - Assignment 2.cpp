#include <iostream>
#include <string>
using namespace std;
//passing strings by refrence? where?
//can i pass by refrence in constructors? 

const double FACULTY_MONTHLY_SALARY = 5000.00;
const int STAFF_MONTHLY_HOURS_WORKED = 160;

enum SEX { MALE, FEMALE}; // MAGIC NUMBERS? NUM.3
enum LEVEL { AS, AO, FU };
enum DEGREE { MASTERS, PhD };

struct DATE {
	int Day;
	int Month;
	int Year;

	DATE(int day, int month, int year) : Day(day), Month(month), Year(year) {}
};

class Employee
{
private:
	string FirstName;
	string LastName;
	string IDNum;
	SEX Sex;		
	DATE BirthDate;

public:
	Employee(string firstName, string lastName, string idNum, SEX sex, DATE birthday)
		: FirstName(firstName), LastName(lastName), IDNum(idNum), Sex(sex), BirthDate(birthday) {}
	Employee() : FirstName(""), LastName(""), IDNum(""), Sex(MALE), BirthDate(DATE(0, 0, 0)) {}

	virtual void putData() const
	{
		cout << "ID Employee number: " << IDNum << endl;
		cout << "Employee name: " << FirstName << " " << LastName << endl;
		cout << "Birth date: " << BirthDate.Day << "/" << BirthDate.Month << "/" << BirthDate.Year << endl;
	}

	void set_first_name(const string &FName) {
		this->FirstName = FName;
	}
	void set_last_name(const string &LName) {
		this->LastName = LName;
	}
	void set_id_num(const string &IDNum) {
		this->IDNum = IDNum;
	}
	void set_sex(const SEX s) {
		Sex = s;
	}
	void set_birthday(const DATE BirthDate) {
		this->BirthDate = BirthDate;
	}
	

	string getFirstName() const
	{
		return FirstName;
	}
	string getLastName() const
	{
		return LastName;
	}
	string getID() const
	{
		return IDNum;
	}
	SEX getGender() const//will return 0 or 1, do i make an if and cout here to get male and female? DO I MAKE IR VOID?
	{
		if (Sex == 0)
		{
			cout << "Male" << endl;
		}
		else if (Sex == 1)
		{
			cout << "Female" << endl;
		}
		return Sex; //must return a value
	}
	DATE getBirthDay() const
	{
		return BirthDate;
	}
	virtual double monthlyEarning() = 0;
};

class Staff : public Employee
{
private:
	double HourlyRate;
public:
	Staff() : Employee("", "", "", MALE, DATE(0, 0, 0)), HourlyRate(0.0) {}
	Staff(string FirstName, string LastName, string IDNum, SEX Sex, DATE BirthDay, double hourlyRate) :
		Employee(FirstName, LastName, IDNum, Sex, BirthDay), HourlyRate(hourlyRate) {}
	
	void setHourlyRate(const double hourlyRate)
	{
		HourlyRate = hourlyRate;
	}

	double getHourlyRate() const
	{
		return HourlyRate;
	}
	double monthlyEarning() 
	{
		return HourlyRate * 160;
	}
	void putData()
	{
		Employee::putData();
		cout << "Full Time" << endl;
		cout << "Monthly Salary: $" << monthlyEarning() << endl;

	}

};

class Education
{
private:
	DEGREE Degree;
	string Major; 
	int ResearchNumber;
public:
	Education() : Education(MASTERS, "", 0){}
	Education(DEGREE degree, string major, int researchNumber) : Degree(degree), Major(major), ResearchNumber(researchNumber){}
	
	void setDegree(const DEGREE degree)
	{
		Degree = degree;
	}
	void setMajor(const string major)
	{
		Major = major;
	}
	void setResearchNumber(const int researchNumber)
	{
		ResearchNumber = researchNumber;
	}

	DEGREE getDegree() const // returns 0, 1. make an if then cout? return void?
	{
		return Degree;
	}
	string getMajor() const
	{
		return Major;
	}
	int getResearchNumber() const
	{
		return ResearchNumber;
	}

};


class Faculty : public Employee
{
	Education Edu;
	LEVEL Level;
public:
	Faculty() : Employee("", "", "", MALE, DATE(0, 0, 0)) , Edu(), Level(AS){}
	Faculty(string FirstName, string LastName, string ID, SEX Sex, DATE BirthDay, LEVEL level, Education education) :
		Employee(FirstName, LastName, ID, Sex, BirthDay), Level(level), Edu(education) {}
	void setter(const LEVEL level)
	{
		Level = level;
	}
	LEVEL get_level() const
	{
		return Level;
	}
	double monthlyEarning() 
	{
		if (Level == AS)
		{
			return FACULTY_MONTHLY_SALARY;
		}
		else if (Level == AO)
		{
			return FACULTY_MONTHLY_SALARY * 1.2;
		}
		else if (Level == FU)
		{
			return FACULTY_MONTHLY_SALARY * 1.4;
		}
	}
	void putData() 
	{
		Employee::putData();
		if (Level == AS)
		{
			cout << "Assistant Professor" << endl;
		}
		else if (Level == AO)
		{
			cout << "Associate Professor" << endl;
		}
		else if (Level == FU)
		{
			cout << "Full Professor" << endl;
		}
		cout << "Monthly Salary: $" << monthlyEarning() << endl;
	}

};

class Parttime : public Staff
{
private:
	int HoursPerWeek;
public:
	Parttime() : Staff(), HoursPerWeek(0) {}
	Parttime(string FirstName, string LastName, string IDNum, SEX Sex, DATE BirthDay, double HourlyRate,int hoursPerWeek)
		: Staff(FirstName, LastName, IDNum, Sex, BirthDay, HourlyRate), HoursPerWeek(hoursPerWeek) {}
	
	void setHoursPerWeek(const int hoursPerWeek)
	{
		HoursPerWeek = hoursPerWeek;
	}
	int getHoursPerWeek() const
	{
		return HoursPerWeek;
	}
	double monthlyEarning()  //const before double is right?
	{
		return getHourlyRate() * HoursPerWeek * 4;
	}
	void putData() 
	{
		Employee::putData();
		cout << "Hours worked per month: " << HoursPerWeek << endl;
		cout << "Monthly Salary: $" << monthlyEarning() << endl;
	}
};

int main()
{
	Employee* emplo[9];
	emplo[0] = new Staff("Paita", "Allen", "123", MALE, DATE(2, 23, 59), 50.00);
	emplo[1] = new Staff("Steven", "Zapata", "456", FEMALE, DATE(7, 12, 64), 35.00);
	emplo[2] = new Staff("Enrique", "Rios", "789", MALE, DATE(6, 2, 70), 40.00);
	emplo[3] = new Faculty("Anne", "Johnson", "243", FEMALE, DATE(4, 27, 62), FU, Education(PhD, "Engineering", 3));
	emplo[4] = new Faculty("William", "Bouris", "791", FEMALE, DATE(3, 14, 75), AO, Education(PhD, "English", 1));
	emplo[5] = new Faculty("Christopher", "Andrade", "623", FEMALE, DATE(5, 22, 80), AS, Education(MASTERS, "Physical Education", 0));
	emplo[6] = new Parttime("Augusto", "Guzman", "455", FEMALE, DATE(8, 10, 77), 35.00, 30);
	emplo[7] = new Parttime("Martin", "Depirro", "678", FEMALE, DATE(9, 15, 87), 30.00, 15);
	emplo[8] = new Parttime("Marque", "Aldaco", "945", MALE, DATE(11, 24, 88), 20.00, 35);

	cout << emplo[0]->getGender() << endl; //******************* remove this when done *************************
	
	cout << "=========== ALL EMPLOYEES DATA ===========" << endl;
	//for (int i = 0; i < 9; i++) {
	//	
	//	if (Staff* staff = dynamic_cast<Staff*>(emplo[i])) { 
	//		// if it's a Staff object, call Staff's putData
	//		staff->putData(); 
	//	}
	//	else if (Faculty* faculty = dynamic_cast< Faculty*>(emplo[i])) {
	//		// If it's a Faculty object, call Faculty's putData
	//		faculty->putData(); 
	//	}
	//	else if (Parttime* parttime = dynamic_cast< Parttime*>(emplo[i])) {
	//		// If it's a Parttime object, call Parttime's putData
	//		parttime->putData(); 
	//	}
	//	cout << endl;
	//}

	for (int i = 0; i < 9; i++)
	{
		Staff* staff = dynamic_cast<Staff*>(emplo[i]);
		Faculty* faculty = dynamic_cast<Faculty*>(emplo[i]);
		Parttime* parttime = dynamic_cast<Parttime*>(emplo[i]);
		if (staff != nullptr) //what is the difference between nullptr and NULL
		{
			staff->putData();
		}
		else if (faculty != nullptr)
		{
			faculty->putData();
		}
		else if (parttime != nullptr)
		{
			parttime->putData();
		}
		cout << endl;
	}

	double totalPartTimeSalary = 0.0;
	double totalEmployeeSalary = 0.0;

	for (int i = 0; i < 9; i++) {
		totalEmployeeSalary += emplo[i]->monthlyEarning();

		if (dynamic_cast<Parttime*>(emplo[i])) {
			totalPartTimeSalary += emplo[i]->monthlyEarning();
		}
	}

	cout << "Total monthly salary for all part-time staff: $" << totalPartTimeSalary << endl;
	cout << "Total monthly salary for all employees: $" << totalEmployeeSalary << endl;
	
}
