#include <iostream>
#include <string>

using namespace std;

// base class for all employees
class employee
{
	public:
		// constructor
		employee(const string& name, const string& ssn) :
               empName(name), empSSN(ssn)
		{}

		virtual ~employee()																						// make destructor virtual so derived classes don't memory leak
		{}

		// output basic employee information
		virtual void displayEmployeeInfo() const																// add virtual to make it dynamically bound to use functions inside called class
		{
			cout << "Name: " << empName << endl;
			cout << "Social Security Number:  " << empSSN << endl;
		}

		// function with this prototype will exist in each derived class
		void payrollCheck() const
		{}

		// this function will have to be implemented by any derived classes
		virtual void myFunction() = 0;																			// = 0 makes it an abstract function where any derived classes have this function


	protected:
		// maintain an employee's name and social
		// security number
		string empName;
		string empSSN;
};


// salaried employee "is an" employee with a monthly salary
class salaryEmployee : public employee
{
   public:
      // initialize Employee attributes and monthly salary
      salaryEmployee(const string& name,
            const string& ssn, double sal):
            employee(name,ssn),salary(sal)
			{}

      // update the monthly salary
      void setSalary(double sal)
      { salary = sal; }

      // call displayEmployeeInfo from base class and add 
		// information about the status (salaried) and weekly salary
		void displayEmployeeInfo() const
      {
         employee::displayEmployeeInfo();
         cout << "Status:   salaried employee" << endl;
         cout << "Salary per week $" << salary << endl;
      }

		// cut a payroll check with the employee name, social security		
		// number in angle brackets, and salary		
		void payrollCheck() const
		{
         cout << "Pay " << empName << " (" << empSSN
				  << ")  $" << salary  << endl;
		}
  
		void myFunction();																						// have to add this function

	private:
      // salary per pay period
      double salary;
};

// hourly employee "is an" employee paid by the hour
class hourlyEmployee : public employee
{
   public:
      // initialize Employee attributes, hourly pay rate
      // and hours worked
      hourlyEmployee(const string& name, const string& ssn, 
				double hp, double hw) : employee(name,ssn), 
				   hourlyPay(hp), hoursWorked(hw)
      {}

      // update the hourly pay and hours worked
      void setHourlyPay(double hp)
      { hourlyPay = hp; }

      void setHoursWorked(double hw)
      { hoursWorked = hw; }


      // call displayEmployeeInfo from base class and output info
		// on hourly rate and scheduled hours
      void displayEmployeeInfo() const
      {
         employee::displayEmployeeInfo();
         cout << "Status:   hourly employee" << endl;
         cout << "Payrate:  $" << hourlyPay << " per hour" << endl;
			cout << "Work schedule (hours per week) " << hoursWorked 
				  << endl;
      }

		void payrollCheck() const
		{
			cout << "Pay " << empName << " (" << empSSN << ")  $" 
				  <<(hourlyPay * hoursWorked)  << endl;
		}

		void myFunction();																						// have to add this function

   private:
      // pay based on hourly pay and hours worked
      double hourlyPay;
      double hoursWorked;
};