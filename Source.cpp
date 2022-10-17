#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;


/*-----Creating Main Class Of Admin Module-----*/
class Admin
{
	/*-----Protected Data Members So We Can Inherit Them During Inheritance-----*/
protected:

	string First_Name;
	string Last_Name;
	string Department_Name;
	string Department_Name_Choice;
	string Teacher_ID;
	string Student_ID;
	string Student_Batch;
	string Blood_Group;
	string Fee_Status;
	string Fee_Status_Choice;
	string Marks;
	string User_Name;
	string User_Name_File;
	string Password;
	string Password_File;
	string Registration_Date;
	string Gender;
	string Gender_Choice;
	string Contact_Number;
	string Qualification;
	string Adress;
	string Salary;
	string Student_Roll_No;

	int Day, Date, Month;
	int Teacher_STD;
	int Student_STD;
	int Enrolled_Students;
	int Enrolled_Teachers;

	/*-----Ofstream & Ifstream Objects For Read & Write Data From File-----*/

	ofstream write;
	ifstream read;

	ofstream Enrolled_Sudents_Write;
	ifstream Enrolled_Sudents_Read;

	ofstream Enrolled_Teachers_Write;
	ifstream Enrolled_Teachers_Read;

	ofstream Student_ID_Write;
	ifstream Student_ID_Read;

	ofstream Teacher_ID_Write;
	ifstream Teacher_ID_Read;

public:
	/*-----Constructor To Initialize Data Members With Default Values-----*/
	Admin()
	{
		Teacher_STD = 1000;
		Student_STD = 1000;
		Enrolled_Students = 0;
		Enrolled_Teachers = 0;
		Day = 0;
		Date = 0;
		Month = 0;
		First_Name = "";
		Last_Name = "";
		Department_Name = "";
		Department_Name_Choice = "";
		Teacher_ID = "";
		Student_ID = "";
		Student_Batch = "";
		Blood_Group = "";
		Fee_Status = "";
		Fee_Status_Choice = "";
		Marks = "";
		User_Name = "";
		User_Name_File = "";
		Password = "";
		Password_File = "";
		Registration_Date = "";
		Gender = "";
		Gender_Choice = "";
		Contact_Number = "";
		Qualification = "";
		Adress = "";
		Salary = "";
		Student_Roll_No = "";
	}

	/*-----Destructor-----*/

	virtual ~Admin()
	{
		cout << "\t\t\t+==========================================================+" << endl;
		cout << "\t\t\t|-----------------|  Software Designed By    |-------------|" << endl;
		cout << "\t\t\t|-----------------|  Dawood Usman 20F-0298   |-------------|" << endl;
		cout << "\t\t\t|-----------------| Sheraaz Mehboob 20F-0266 |-------------|" << endl;
		cout << "\t\t\t+==========================================================+\n" << endl;
		system("pause");
	}

	/*-----Virtual Functions-----*/

	virtual void Sign_In_Admin() {}
	virtual void Add_New_Teacher() {}
	virtual void Add_New_Student() {}
	virtual void Edit_Student_Detail() {}
	virtual void Edit_Teacher_Detail() {}
	virtual void View_All_Students() {}
	virtual void View_All_Teachers() {}

};

/*-----Sign-In Class To Perform Sign-In Function-----*/

class Sign_in_Admin : public Admin
{
public:

	/*Overriding The Sign-In Function To Perform Sign-In Function-----*/

	void Sign_In_Admin()override
	{
		system("cls");

		/*-----Open File In Which Admin Credientials Are Saved-----*/

		read.open("Admin_Credentials.txt");

		/*-----Read Admin Credientials Form File-----*/

		getline(read, User_Name_File);
		getline(read, Password_File);

		/*-----Match Admin Credientials With Input-----*/

		while (true)
		{
			cout << "+==========================================================+" << endl;
			cout << "|----------------| Sign-In To Your Account |---------------|" << endl;
			cout << "+==========================================================+\n" << endl;

			cout << "\t\t Enter Your User Name :  ";
			cin >> User_Name;
			cout << "\t\t Enter Your Password  :  ";
			cin >> Password;
			if (User_Name == User_Name_File && Password == Password_File)
			{
				break;
			}
			else
			{
				/*-----Keep On Taking Input Until Admin Credientials Are Not Correct-----*/

				cout << "\n\t\tYour Credentials Are Not Correct :( " << endl;
				cout << "\t\t          Try Again !               \n" << endl;

				cout << endl;
				system("pause");
				system("cls");
			}
		}

		/*-----Close Admin Credientials File-----*/

		read.close();
	}
};

/*-----Add class To Add Teacher & Student Into Flex System-----*/

class Add : public Admin
{
private:
	int Enrolled_Teachers_File;
	int Enrolled_Students_File;
	int Teacher_ID_File[5];
public:

	Add()
	{
		Enrolled_Teachers_File = 0;
		Enrolled_Students_File = 0;
		for (int i = 0; i < 5; i++)
		{
			Teacher_ID_File[i] = 0;
		}
	}

	/*-----Add Teacher Function To Add Teacher Into Flex System-----*/

	void Add_New_Teacher()override
	{
		system("cls");
		cout << "+==========================================================+" << endl;
		cout << "|--------------------| Add New Teacher |-------------------|" << endl;
		cout << "+==========================================================+\n" << endl;

		cout << "\t Enter First Name         :   ";
		cin >> First_Name;
		cout << "\t Enter Last Name          :   ";
		cin >> Last_Name;
		cout << "\t Total Departments Name        " << endl;
		cout << " \t 1- Computer Science" << endl;
		cout << " \t 2- Electrical Engineering" << endl;
		cout << " \t 3- Software Engineering" << endl;
		cout << " \t 4- Business" << endl;
		cout << " \t 5- Social Sciences" << endl;

		/*-----Infinite Loop To Handle The Wrong Input Problem-----*/

		while (true)
		{
			cout << "\t Enter Department Name    :   ";
			cin >> Department_Name_Choice;

			if (Department_Name_Choice == "1")
			{
				Department_Name = "Computer Science";
				Teacher_ID = "CS-";
				break;
			}
			else if (Department_Name_Choice == "2")
			{
				Department_Name = "Electrical Engineering";
				Teacher_ID = "EE-";
				break;
			}
			else if (Department_Name_Choice == "3")
			{
				Department_Name = "Software Engineering";
				Teacher_ID = "SE-";
				break;
			}
			else if (Department_Name_Choice == "4")
			{
				Department_Name = "Business";
				Teacher_ID = "B-";
				break;
			}
			else if (Department_Name_Choice == "5")
			{
				Department_Name = "Social Sciences";
				Teacher_ID = "SS-";
				break;
			}
		}

		/*-----Open Teacher ID File In Which Teachers IDs For Each Department Are Stored-----*/

		read.open("Teacher_ID.txt");

		/*-----Read Teacher IDs For Each Department & Store Them Into Integer Array-----*/

		for (int i = 0; i < 5; i++)
		{
			read >> Teacher_ID_File[i];
		}

		/*-----Close Teacher ID File-----*/

		read.close();

		/*-----Open Teacher ID File-----*/

		read.open("Teacher_ID.txt");

		/*-----Increment Value For Specific Department Given By User-----*/

		for (int i = 0; i < 5; i++)
		{
			if (Teacher_ID == "CS-")
			{
				Teacher_ID_File[0] = Teacher_ID_File[0] + 1;
				Teacher_STD = Teacher_ID_File[0];
				break;
			}
			else if (Teacher_ID == "EE-")
			{
				Teacher_ID_File[1] = Teacher_ID_File[1] + 1;
				Teacher_STD = Teacher_ID_File[1];
				break;
			}
			else if (Teacher_ID == "SE-")
			{
				Teacher_ID_File[2] = Teacher_ID_File[2] + 1;
				Teacher_STD = Teacher_ID_File[2];
				break;
			}
			else if (Teacher_ID == "B-")
			{
				Teacher_ID_File[3] = Teacher_ID_File[3] + 1;
				Teacher_STD = Teacher_ID_File[3];
				break;
			}
			else if (Teacher_ID == "SS-")
			{
				Teacher_ID_File[4] = Teacher_ID_File[4] + 1;
				Teacher_STD = Teacher_ID_File[4];
				break;
			}
		}

		/*-----Close Teacher ID File-----*/

		read.close();

		/*-----Open Teacher File-----*/

		write.open("Teacher_ID.txt");

		/*-----Write or Update That Updated Value In Array Into File-----*/

		for (int i = 0; i < 5; i++)
		{
			write << Teacher_ID_File[i] << endl;
		}

		/*-----Close Teacher ID File-----*/

		write.close();

		cout << "\t Teacher ID               :   " << Teacher_ID << Teacher_STD << endl;
		cout << "\t Enter User Name          :   ";
		cin >> User_Name;
		cout << "\t Enter Password           :   ";
		cin >> Password;
		cout << "\t Enter Registeration Date " << endl;
		cout << "\t Enter Date               :   ";
		cin >> Day;
		cout << "\t Enter Month              :   ";
		cin >> Date;
		cout << "\t Enter Year               :   ";
		cin >> Month;
		cout << "\t Genders:                   " << endl;
		cout << " \t 1- Male" << endl;
		cout << " \t 2- Female" << endl;

		/*-----Infinite Loop To Handle The Wrong Input Problem-----*/

		while (true)
		{
			cout << "\t Enter Gender             :   ";
			cin >> Gender_Choice;

			if (Gender_Choice == "1")
			{
				Gender = "Male";
				break;
			}
			else if (Gender_Choice == "2")
			{
				Gender = "Female";
				break;
			}
		}

		cout << "\t Enter Contact Number     :   ";
		cin >> Contact_Number;
		cout << "\t Enter Qualification      :   ";
		cin >> Qualification;
		cout << "\t Enter Adress             :   ";
		cin.ignore();
		getline(cin, Adress);
		cout << "\t Enter Salary             :   ";
		cin >> Salary;

		/*-----Open & Append Teacher File To Save The Previous Data As Well-----*/

		write.open("Teacher.txt", ios::app);

		/*-----Write All The Teacher Data Into File-----*/

		write << First_Name << endl;
		write << Last_Name << endl;
		write << Department_Name << endl;
		write << Teacher_ID << Teacher_STD << endl;
		write << User_Name << endl;
		write << Password << endl;
		write << Day << "/" << Date << "/" << Month << endl;
		write << Gender << endl;
		write << Contact_Number << endl;
		write << Qualification << endl;
		write << Adress << endl;
		write << Salary << endl;

		/*-----Open Enrolled Teacher File-----*/

		Enrolled_Teachers_Read.open("Enrolled_Teachers.txt");

		/*-----If File Is Not Open, It'll Create File And Write 1 In File-----*/

		if (!Enrolled_Teachers_Read.is_open())
		{
			Enrolled_Teachers_Write.open("Enrolled_Teachers.txt");
			Enrolled_Teachers_Write << 1;
			Enrolled_Teachers_Write.close();
		}

		/*-----If File Is Already Created Then Read The Enrolled Number From File & Again Store It With Plus 1-----*/

		else
		{
			Enrolled_Teachers_Read >> Enrolled_Teachers_File;
			Enrolled_Teachers = Enrolled_Teachers_File + 1;
			Enrolled_Teachers_Write.open("Enrolled_Teachers.txt");
			Enrolled_Teachers_Write << Enrolled_Teachers;
		}

		/*-----Close All Opened Files-----*/

		Enrolled_Teachers_Read.close();
		Enrolled_Teachers_Write.close();
		write.close();

		/*-----Write Teacher Credientials Into File-----*/

		write.open("Teacher_Credientials.txt", ios::app);
		write << Teacher_ID << Teacher_STD << endl;
		write << Password << endl;
		write.close();

		cout << "\n-> Your New Teacher Has Been Added Successfully :) " << endl;
		cout << endl;
		system("pause");

	}

	/*-----Add Student Function To Add Student Into Flex System-----*/

	void Add_New_Student()override
	{
		system("cls");
		cout << "+==========================================================+" << endl;
		cout << "|--------------------| Add New Student |-------------------|" << endl;
		cout << "+==========================================================+\n" << endl;

		cout << "\t Enter First Name        :   ";
		cin >> First_Name;
		cout << "\t Enter Last Name         :   ";
		cin >> Last_Name;
		cout << "\t Total Departments Name " << endl;
		cout << " \t 1- Computer Science" << endl;
		cout << " \t 2- Electrical Engineering" << endl;
		cout << " \t 3- Software Engineering" << endl;
		cout << " \t 4- Business" << endl;
		cout << " \t 5- Social Sciences" << endl;

		/*-----Infinite Loop To Handle The Wrong Input Problem-----*/

		while (true)
		{
			cout << "\t Enter Department Name   :   ";
			cin >> Department_Name_Choice;

			if (Department_Name_Choice == "1")
			{
				Department_Name = "Computer Science";
				break;
			}
			else if (Department_Name_Choice == "2")
			{
				Department_Name = "Electrical Engineering";
				break;
			}
			else if (Department_Name_Choice == "3")
			{
				Department_Name = "Software Engineering";
				break;
			}
			else if (Department_Name_Choice == "4")
			{
				Department_Name = "Business";
				break;
			}
			else if (Department_Name_Choice == "5")
			{
				Department_Name = "Social Sciences";
				break;
			}
		}

		/*-----Open Student ID File-----*/

		Student_ID_Read.open("Student_ID.txt");

		/*-----Read Student ID From File & Make Increment Of One In This-----*/

		Student_ID_Read >> Student_STD;
		Student_STD = Student_STD + 1;

		/*-----Close Student ID File-----*/

		Student_ID_Read.close();

		cout << "\t Student ID              :   " << "20F-" << Student_STD << endl;

		/*-----Open Student ID File-----*/

		Student_ID_Write.open("Student_ID.txt");

		/*-----Write Updated Value Of Student ID Into File-----*/

		Student_ID_Write << Student_STD;

		/*-----Close Student ID File-----*/

		Student_ID_Write.close();

		cout << "\t Enter Registeration Date   " << endl;
		cout << " \t Enter Date              :   ";
		cin >> Day;
		cout << " \t Enter Month             :   ";
		cin >> Date;
		cout << " \t Enter Year              :   ";
		cin >> Month;
		cout << "\t Genders  " << endl;
		cout << " \t 1- Male" << endl;
		cout << " \t 2- Female" << endl;

		/*-----Infinite Loop To Handle The Wrong Input Problem-----*/

		while (true)
		{
			cout << "\t Enter Gender            :   ";
			cin >> Gender_Choice;

			if (Gender_Choice == "1")
			{
				Gender = "Male";
				break;
			}
			else if (Gender_Choice == "2")
			{
				Gender = "Female";
				break;
			}
		}

		cout << "\t Enter User Name         :   ";
		cin >> User_Name;
		cout << "\t Enter Password          :   ";
		cin >> Password;
		cout << "\t Enter Contact Number    :   ";
		cin >> Contact_Number;
		cout << "\t Enter Blood Group       :   ";
		cin >> Blood_Group;
		cout << "\t Enter Adress            :   ";
		cin.ignore();
		getline(cin, Adress);
		cout << "\t Fee Status " << endl;
		cout << " \t 1- Paid " << endl;
		cout << " \t 2- Not Paid " << endl;

		/*-----Infinite Loop To Handle The Wrong Input Problem-----*/

		while (true)
		{
			cout << "\t Enter Fee Status        :   ";
			cin >> Fee_Status_Choice;

			if (Fee_Status_Choice == "1")
			{
				Fee_Status = "Paid";
				break;
			}
			else if (Fee_Status_Choice == "2")
			{
				Fee_Status = "Not Paid";
				break;
			}
		}

		cout << "\t Enter Qualification     :   ";
		cin >> Qualification;
		cout << "\t Enter Marks             :   ";
		cin >> Marks;

		/*-----Open Student File With Append Mode So It Can Store Previous Data As Well-----*/

		write.open("Student.txt", ios::app);

		/*-----Write All The Student Data Into File-----*/

		write << First_Name << endl;
		write << Last_Name << endl;
		write << Department_Name << endl;
		write << "20F-" << Student_STD << endl;
		write << Day << "/" << Date << "/" << Month << endl;
		write << Gender << endl;
		write << User_Name << endl;
		write << Password << endl;
		write << Contact_Number << endl;
		write << Blood_Group << endl;
		write << Adress << endl;
		write << Fee_Status << endl;
		write << Qualification << endl;
		write << Marks << endl;

		/*-----Open Enrolled Students File-----*/

		Enrolled_Sudents_Read.open("Enrolled_Students.txt");

		/*-----If File Is Not Open, It'll Create File And Write 1 In File-----*/

		if (!Enrolled_Sudents_Read.is_open())
		{
			Enrolled_Sudents_Write.open("Enrolled_Students.txt");
			Enrolled_Sudents_Write << 1;
			Enrolled_Sudents_Write.close();
		}

		/*-----If File Is Already Created Then Read The Enrolled Number From File & Again Store It With Plus 1-----*/

		else
		{
			Enrolled_Sudents_Read >> Enrolled_Students_File;
			Enrolled_Students = Enrolled_Students_File + 1;

			Enrolled_Sudents_Read.close();

			Enrolled_Sudents_Write.open("Enrolled_Students.txt");
			Enrolled_Sudents_Write << Enrolled_Students;
		}

		/*-----Close All Opened Files-----*/

		Enrolled_Sudents_Write.close();
		write.close();

		/*-----Write Student Credientials Into File-----*/

		write.open("Student_Credientials.txt", ios::app);
		write << "20F-" << Student_STD << endl;
		write << Password << endl;
		write.close();

		cout << "\n-> Your New Student Has Been Added Successfully :) " << endl;
		cout << endl;
		system("pause");
	}
};

/*-----Edit class To Edit Teacher & Student Data Into Flex System-----*/

class Edit : public Admin
{
private:
	int Student_Index;
	int Teacher_Index;

	string Student_Edit_Choice;
	string Teacher_Edit_Choice;

	string Student_Roll_Number;
	string Student_Roll_Number_File;
	int Enrolled_Students_File;
	bool Roll_Number_Check = false;

	int Enrolled_Teachers_File;
	string Teacher_ID_Number;
	string Teacher_ID_Number_File;
	bool Teacher_ID_Number_Check = false;

public:

	Edit()
	{
		Student_Index = 0;
		Teacher_Index = 0;

		Student_Edit_Choice = "";
		Teacher_Edit_Choice = "";

		Student_Roll_Number = "";
		Student_Roll_Number_File = "";
		Enrolled_Students_File = 0;

		Enrolled_Teachers_File = 0;
		Teacher_ID_Number = "";
		Teacher_ID_Number_File = "";
	}

	/*-----Function To Edit Student Detail-----*/

	void Edit_Student_Detail()override
	{
		system("cls");

	Again:
		cout << "+==========================================================+" << endl;
		cout << "|------------------| Edit Student Details|-----------------|" << endl;
		cout << "+==========================================================+\n" << endl;

		cout << "Enter Student's Roll Number : ";
		cin >> Student_Roll_Number;

		/*-----Open Student File-----*/

		read.open("Student.txt");

		/*-----Loop Will Execute Till End Of File-----*/

		while (!read.eof())
		{
			read >> Student_Roll_Number_File;
			if (Student_Roll_Number == Student_Roll_Number_File)
			{
				Roll_Number_Check = true;
				break;
			}
		}

		if (Roll_Number_Check == false)
		{
			cout << "\n-> No Student Of This ID Has Registered :( " << endl;
			cout << "                Try Again !                  " << endl;

			cout << endl;
			system("pause");
			system("cls");
			read.close();
			goto Again;
		}

		/*-----Close Student File-----*/

		read.close();

		/*-----Open Student File-----*/

		read.open("Student.txt");

		/*-----Open Enrolled Student File-----*/

		Enrolled_Sudents_Read.open("Enrolled_Students.txt");

		/*-----Read Number Of Enrolled Students From File-----*/

		Enrolled_Sudents_Read >> Enrolled_Students_File;

		/*-----Creating 2D-Dynamic Array As We've To Define A Length Of First Index At Run-Time-----*/

		string** Student_Data = new string * [Enrolled_Students_File];
		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			/*-----Here We Defined Length Of 14 As We Have 14 Enteries Of Each Student Data In File-----*/
			Student_Data[i] = new string[14];
		}

		/*-----Read All Students Data From File & Store That In 2D-Dynamic Array-----*/

		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				getline(read, Student_Data[i][j]);
			}
		}

		/*-----Finding The Index Of The Student By His/Her Roll Number-----*/

		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			if (Student_Data[i][3] == Student_Roll_Number)
			{
				Student_Index = i;
				break;
			}
		}

		/*-----Giving The Option To User That Which Data He Want To Edit-----*/

		while (true)
		{

			cout << "\n1) Edit First Name  " << endl;
			cout << "2) Edit Last Name   " << endl;
			cout << "3) Edit Fee Status  " << endl;
			cout << "4) Edit Adress      " << endl;
			cout << "5) Edit Contact Number " << endl;
			cout << "6) Go Back " << endl;

			cout << "\n-> Enter Your Choice : ";
			cin >> Student_Edit_Choice;

			if (Student_Edit_Choice == "1")
			{
				cout << "\nEnter First Name : ";
				cin >> Student_Data[Student_Index][0];
			}
			else if (Student_Edit_Choice == "2")
			{
				cout << "\nEnter Last Name : ";
				cin >> Student_Data[Student_Index][1];
			}
			else if (Student_Edit_Choice == "3")
			{
				cout << "\nFee Status : " << endl;
				cout << " 1- Paid " << endl;
				cout << " 2- Not Paid " << endl;
				cout << "Enter Fee Status : ";
				cin >> Fee_Status_Choice;
				if (Fee_Status_Choice == "1")
				{
					Student_Data[Student_Index][11] = "Paid";
				}
				else if (Fee_Status_Choice == "2")
				{
					Student_Data[Student_Index][11] = "Not Paid";
				}
			}
			else if (Student_Edit_Choice == "4")
			{
				cout << "\nEnter Adress : ";
				cin.ignore();
				getline(cin, Student_Data[Student_Index][10]);
			}
			else if (Student_Edit_Choice == "5")
			{
				cout << "\nEnter Contact Number : ";
				cin >> Student_Data[Student_Index][8];
			}
			else if (Student_Edit_Choice == "6")
			{
				break;
			}

			cout << endl;
			system("pause");
			system("cls");

			cout << "+==========================================================+" << endl;
			cout << "|------------------| Edit Student Details|-----------------|" << endl;
			cout << "+==========================================================+\n" << endl;
		}

		/*-----Open Student File-----*/

		write.open("Student.txt");

		/*-----Write All The Updated Data From Array Into Student File-----*/

		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				write << Student_Data[i][j] << endl;
			}
			cout << endl;
		}

		/*-----Close All The Opened Files-----*/

		write.close();
		read.close();
		Enrolled_Sudents_Read.close();

		cout << "\n-> Your Student Data Has Been Updated Successfully :) " << endl;
		cout << endl;
		system("pause");
	}

	/*-----Function To Edit Teacher Detail-----*/

	void Edit_Teacher_Detail() override
	{
		system("cls");

	Again:
		cout << "+==========================================================+" << endl;
		cout << "|------------------| Edit Teacher Details|-----------------|" << endl;
		cout << "+==========================================================+\n" << endl;

		cout << "Enter Teacher's ID Number : ";
		cin >> Teacher_ID_Number;

		/*-----Open Teacher File-----*/

		read.open("Teacher.txt");

		/*-----Loop Will Execute Till End Of File-----*/

		while (!read.eof())
		{
			read >> Teacher_ID_Number_File;
			if (Teacher_ID_Number == Teacher_ID_Number_File)
			{
				Teacher_ID_Number_Check = true;
				break;
			}
		}

		if (Teacher_ID_Number_Check == false)
		{
			cout << "\n-> No Teacher Of This ID Has Registered :( " << endl;
			cout << "                Try Again !                  " << endl;

			cout << endl;
			system("pause");
			system("cls");
			read.close();
			goto Again;
		}

		/*-----Close Teacher File-----*/

		read.close();

		/*-----Open Teacher File-----*/

		read.open("Teacher.txt");

		/*-----Open Enrolled Teacher File-----*/

		Enrolled_Teachers_Read.open("Enrolled_Teachers.txt");

		/*-----Read Number Of Enrolled Teachers From File-----*/

		Enrolled_Teachers_Read >> Enrolled_Teachers_File;

		/*-----Creating 2D-Dynamic Array As We've To Define A Length Of First Index At Run-Time-----*/

		string** Teacher_Data = new string * [Enrolled_Teachers_File];
		for (int i = 0; i < Enrolled_Teachers_File; i++)
		{
			/*-----Here We Defined Length Of 14 As We Have 12 Enteries Of Each Student Data In File-----*/
			Teacher_Data[i] = new string[12];
		}

		/*-----Read All Teachers Data From File & Store That In 2D-Dynamic Array-----*/

		for (int i = 0; i < Enrolled_Teachers_File; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				getline(read, Teacher_Data[i][j]);
			}
		}

		/*-----Finding The Index Of The Teacher By His/Her ID Number-----*/

		for (int i = 0; i < Enrolled_Teachers_File; i++)
		{
			if (Teacher_Data[i][3] == Teacher_ID_Number)
			{
				Teacher_Index = i;
				break;
			}
		}

		/*-----Giving The Option To User That Which Data He Want To Edit-----*/

		while (true)
		{
			cout << "\n1) Edit Adress" << endl;
			cout << "2) Edit Contact Number " << endl;
			cout << "3) Edit Qualification " << endl;
			cout << "4) Edit Salary " << endl;
			cout << "5) Go Back " << endl;

			cout << "\n -> Enter Your Choice : ";
			cin >> Teacher_Edit_Choice;

			if (Teacher_Edit_Choice == "1")
			{
				cout << "\nEnter Adress : ";
				cin.ignore();
				getline(cin, Teacher_Data[Teacher_Index][10]);
			}
			else if (Teacher_Edit_Choice == "2")
			{
				cout << "\nEnter Contact Number : ";
				cin >> Teacher_Data[Teacher_Index][8];
			}
			else if (Teacher_Edit_Choice == "3")
			{

				cout << "\nEnter Qualification : ";
				cin >> Teacher_Data[Teacher_Index][9];
			}
			else if (Teacher_Edit_Choice == "4")
			{
				cout << "\nEnter Salary : ";
				cin >> Teacher_Data[Teacher_Index][11];
			}
			else if (Teacher_Edit_Choice == "5")
			{
				break;
			}

			cout << endl;
			system("pause");
			system("cls");

			cout << "+==========================================================+" << endl;
			cout << "|------------------| Edit Teacher Details|-----------------|" << endl;
			cout << "+==========================================================+\n" << endl;
		}

		/*-----Open Teacher File-----*/

		write.open("Teacher.txt");

		/*-----Write All Updated Teacher Data From 2D-Array Into File-----*/

		for (int i = 0; i < Enrolled_Teachers_File; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				write << Teacher_Data[i][j] << endl;
			}
			cout << endl;
		}

		/*-----Close All The Opened Files-----*/

		write.close();
		Enrolled_Teachers_Read.close();
		read.close();

		cout << "\n-> Your Teacher Data Has Been Updated Successfully :) " << endl;
		cout << endl;
		system("pause");
	}
};

/*-----View class To View Teachers & Students Data-----*/

class View : public Admin
{
private:
	int Enrolled_Students_File;
	int Enrolled_Teachers_File;
public:

	View()
	{
		Enrolled_Students_File = 0;
		Enrolled_Teachers_File = 0;
	}

	void View_All_Students()override
	{
		system("cls");

		cout << "+==========================================================+" << endl;
		cout << "|----------------| View All Students Data |----------------|" << endl;
		cout << "+==========================================================+\n" << endl;

		/*-----Open Student File-----*/

		read.open("Student.txt");

		/*-----Open Enrolled Students File-----*/

		Enrolled_Sudents_Read.open("Enrolled_Students.txt");

		/*-----Read Enrolled Students From File-----*/

		Enrolled_Sudents_Read >> Enrolled_Students_File;

		/*-----Creating 2D-Dynamic Array As We've To Define A Length Of First Index At Run-Time-----*/

		string** Student_Data = new string * [Enrolled_Students_File];
		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			/*-----Here We Defined Length Of 14 As We Have 12 Enteries Of Each Student Data In File-----*/
			Student_Data[i] = new string[14];
		}

		/*-----Read All Students Data From File & Store That In 2D-Dynamic Array-----*/

		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				getline(read, Student_Data[i][j]);
			}
		}

		/*-----Dislpay Asked Data Of Student-----*/

		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			cout << "----------| Student " << i + 1 << " Data |----------\n" << endl;
			cout << "Student ID      :  " << Student_Data[i][3] << endl;
			cout << "Student Name    :  " << Student_Data[i][0] << " " << Student_Data[i][1] << endl;
			cout << "Department Name :  " << Student_Data[i][2] << endl;
			cout << "Gender          :  " << Student_Data[i][5] << endl;
			cout << "Contact Number  :  " << Student_Data[i][8] << endl;
			cout << "Blood Group     :  " << Student_Data[i][9] << endl;
			cout << "Adress          :  " << Student_Data[i][10] << endl;
			cout << "Fee Status      :  " << Student_Data[i][11] << endl;
			cout << endl;
		}

		/*-----Close All Opened File-----*/

		read.close();
		Enrolled_Sudents_Read.close();

		cout << "\n-> Here Is The Data Of All Students :) " << endl;
		cout << endl;
		system("pause");
	}

	void View_All_Teachers()override
	{
		system("cls");

		cout << "+==========================================================+" << endl;
		cout << "|----------------| View All Teachers Data |----------------|" << endl;
		cout << "+==========================================================+\n" << endl;

		/*-----Open Teachers File-----*/

		read.open("Teacher.txt");

		/*-----Open Enrolled Teachers File-----*/

		Enrolled_Teachers_Read.open("Enrolled_Teachers.txt");

		/*-----Read Enrolled Teachers From File-----*/

		Enrolled_Teachers_Read >> Enrolled_Teachers_File;

		/*-----Creating 2D-Dynamic Array As We've To Define A Length Of First Index At Run-Time-----*/

		string** Teacher_Data = new string * [Enrolled_Teachers_File];
		for (int i = 0; i < Enrolled_Teachers_File; i++)
		{
			/*-----Here We Defined Length Of 14 As We Have 12 Enteries Of Each Student Data In File-----*/
			Teacher_Data[i] = new string[12];
		}

		/*-----Read All Teachers Data From File & Store That In 2D-Dynamic Array-----*/

		for (int i = 0; i < Enrolled_Teachers_File; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				getline(read, Teacher_Data[i][j]);
			}
		}

		/*-----Dislpay Asked Data Of Teachers-----*/

		for (int i = 0; i < Enrolled_Teachers_File; i++)
		{
			cout << "----------| Teacher " << i + 1 << " Data |----------\n" << endl;
			cout << "Teacher Name   :  " << Teacher_Data[i][0] << " " << Teacher_Data[i][1] << endl;
			cout << "Gender         :  " << Teacher_Data[i][7] << endl;
			cout << "Qualification  :  " << Teacher_Data[i][9] << endl;
			cout << "Contact Number :  " << Teacher_Data[i][8] << endl;
			cout << "User Name      :  " << Teacher_Data[i][4] << endl;
			cout << endl;
		}

		/*-----Close All Opened File-----*/

		read.close();
		Enrolled_Teachers_Read.close();

		cout << "\n-> Here Is The Data Of All Teachers :) " << endl;
		cout << endl;
		system("pause");
	}
};

/*-----Teacher Module Main Class-----*/

class Teacher : public Admin
{
public:

	Teacher() {}
	~Teacher() {}

	/*-----Virtual Functions-----*/

	virtual void Sign_In_Teacher() {}
	virtual void Teacher_Time_Table() {}
	virtual void Assign_Marks() {}
	virtual void Assign_Grades() {}
	virtual void Marking_Attendence() {}
};

/*-----Sign In Teacher Class For Teacher To Sign In Into Flex-----*/

class Sign_in_Teacher : public Teacher
{
private:
	bool Teacher_ID_Check = false;
	string Teacher_Department;
	char First_Letter;
	char Second_Letter;
public:

	/*-----Constructor-----*/

	Sign_in_Teacher()
	{
		Teacher_Department = "";
		First_Letter = '\0';
		Second_Letter = '\0';
	}

	/*-----Sign In Teacher Function For Teacher To Sign In Into Flex-----*/

	void Sign_In_Teacher()override
	{
		system("cls");

	Again:
		cout << "+==========================================================+" << endl;
		cout << "|----------------| Sign-In To Your Account |---------------|" << endl;
		cout << "+==========================================================+\n" << endl;


		cout << "\t\t Enter Your ID        :  ";
		cin >> User_Name;
		cout << "\t\t Enter Your Password  :  ";
		cin >> Password;

		/*-----Open File In Which Teacher Credientials Are Saved-----*/

		read.open("Teacher_Credientials.txt");

		/*-----Read Teacher Credientials Form File-----*/
		while (!read.eof())
		{

			read >> User_Name_File;
			read >> Password_File;

			/*-----Match Teacher Credientials With Input-----*/

			if (User_Name == User_Name_File && Password == Password_File)
			{
				Teacher_ID_Check = true;
				write.open("Teacher_IDs_For_Assignments.txt");
				write << User_Name;
				write.close();
				break;
			}
		}

		if (Teacher_ID_Check == false)
		{
			cout << "\n\t\tYour Credentials Are Not Correct :( " << endl;
			cout << "\t\t          Try Again !               \n" << endl;

			read.close();
			cout << endl;
			system("pause");
			system("cls");
			goto Again;
		}

		/*-----Close Teacher Credientials File-----*/

		read.close();

		/*-----Store 1st Two Letters Of Teacher Id To Check Department-----*/

		First_Letter = User_Name[0];
		Second_Letter = User_Name[1];

		if (First_Letter == 'C' && Second_Letter == 'S')
		{
			Teacher_Department = "Computer Science";

		}
		else if (First_Letter == 'E' && Second_Letter == 'E')
		{
			Teacher_Department = "Electrical Engineering";
		}
		else if (First_Letter == 'S' && Second_Letter == 'E')
		{
			Teacher_Department = "Software Engineering";
		}
		else if (First_Letter == 'B')
		{
			Teacher_Department = "Business";
		}
		else if (First_Letter == 'S' && Second_Letter == 'S')
		{
			Teacher_Department = "Social Sciences";
		}

		/*-----Open Teacher Department File-----*/

		write.open("Teacher_Department.txt");

		/*-----Write Teacher Department In File-----*/

		write << Teacher_Department << endl;
		
		/*-----Close The File-----*/

		write.close();

	}

};

/*-----Teacher Time Table Class To Display TimeTable-----*/

class Teachers_Time_Table : public Teacher
{
private:
	bool Teacher_ID_Checks = false;
	char First_Letter;
	char Second_Letter;

public:

	/*-----Constructor-----*/

	Teachers_Time_Table()
	{
		First_Letter = '\0';
		Second_Letter = '\0';
	}

	/*-----Function To Check Teacher ID For Validation-----*/

	void Check_ID_TT()
	{
		system("cls");

	Again:
		cout << "+==========================================================================+" << endl;
		cout << "|--------------------------| Teacher Time Table |--------------------------|" << endl;
		cout << "+==========================================================================+" << endl;

		cout << "\n\t\t    Enter Your ID   :   ";
		cin >> User_Name;

		/*-----Open File In Which Teacher Credientials Are Saved-----*/

		read.open("Teacher_Credientials.txt");

		/*-----Read Teacher Credientials Form File-----*/
		while (!read.eof())
		{
			read >> User_Name_File;

			/*-----Match Teacher Credientials With Input-----*/

			if (User_Name == User_Name_File)
			{
				Teacher_ID_Checks = true;
				break;
			}
		}

		if (Teacher_ID_Checks == false)
		{
			cout << "\n\t\tYour Credentials Are Not Correct :( " << endl;
			cout << "\t\t          Try Again !               \n" << endl;

			read.close();
			cout << endl;
			system("pause");
			system("cls");
			goto Again;
		}

		/*-----Close Teacher Credientials File-----*/

		read.close();

	}

	/*-----Function To Shuffle The Subjects In Time Table-----*/

	void Shuffle_Subjects(string Lectures[10])
	{
		for (int i = 0; i < (10 - 1); i++)
		{
			int r = i + (rand() % (10 - i));
			srand(time(0));
			string temp = Lectures[i];
			Lectures[i] = Lectures[r];
			Lectures[r] = temp;
		}
	}

	/*-----Teacher Time Table Main Function-----*/

	void Teacher_Time_Table()override
	{
		Check_ID_TT();

		/*-----Get First Two Characters Of ID To Check The Department-----*/

		First_Letter = User_Name[0];
		Second_Letter = User_Name[1];

		/*-----Assign Subjects To Every Teacher According To His Department-----*/

		if (First_Letter == 'C' && Second_Letter == 'S')
		{
			string Lectures[10] = { "PF","  " , "DS", "  " , "DB", "  ", "OS","  ", "AI", "  " };
			Shuffle_Subjects(Lectures);
			Time_Table_Display(Lectures);
		}
		else if (First_Letter == 'E' && Second_Letter == 'E')
		{
			string Lectures[10] = { "EL","  " , "CS", "  " , "MI", "  ", "ET","  ", "PQ", "  " };
			Shuffle_Subjects(Lectures);
			Time_Table_Display(Lectures);
		}
		else if (First_Letter == 'S' && Second_Letter == 'E')
		{
			string Lectures[10] = { "PF","  " , "DS", "  " , "DB", "  ", "OS","  ", "AI", "  " };
			Shuffle_Subjects(Lectures);
			Time_Table_Display(Lectures);
		}
		else if (First_Letter == 'B')
		{
			string Lectures[10] = { "FA","  " , "SM", "  " , "HM", "  ", "OB","  ", "EC", "  " };
			Shuffle_Subjects(Lectures);
			Time_Table_Display(Lectures);
		}
		else if (First_Letter == 'S' && Second_Letter == 'S')
		{
			string Lectures[10] = { "PS","  " , "BE", "  " , "AH", "  ", "RT","  ", "MS", "  " };
			Shuffle_Subjects(Lectures);
			Time_Table_Display(Lectures);
		}
	}

	/*-----Teacher Time Table Function To Display TimeTable-----*/

	void Time_Table_Display(string Lectures[10])
	{
		system("cls");

		cout << "\t\t+==========================================================================+" << endl;
		cout << "\t\t|--------------------------| Teacher Time Table |--------------------------|" << endl;
		cout << "\t\t|==========================================================================|" << endl;
		cout << "\t\t|  Time Slot  |  Monday  |  Tuesday  |  Wednesday  |  Thursday  |  Friday  |" << endl;
		cout << "\t\t|--------------------------------------------------------------------------|" << endl;
		cout << "\t\t| 08:00-09:00 |    " << Lectures[0] << "    |     " << Lectures[9] << "    |      " << Lectures[8] << "     |      " << Lectures[2] << "    |    " << Lectures[6] << "    |" << endl;
		cout << "\t\t| 09:00-10:00 |    " << Lectures[1] << "    |     " << Lectures[8] << "    |      " << Lectures[6] << "     |      " << Lectures[0] << "    |    " << Lectures[5] << "    |" << endl;
		cout << "\t\t| 10:00-11:00 |    " << Lectures[2] << "    |     " << Lectures[7] << "    |      " << Lectures[4] << "     |      " << Lectures[4] << "    |    " << Lectures[7] << "    |" << endl;
		cout << "\t\t| 11:00-12:00 |    " << Lectures[3] << "    |     " << Lectures[6] << "    |      " << Lectures[2] << "     |      " << Lectures[2] << "    |    " << Lectures[4] << "    |" << endl;
		cout << "\t\t| 12:00-01:00 |    " << Lectures[4] << "    |     " << Lectures[5] << "    |      " << Lectures[0] << "     |      " << Lectures[6] << "    |    " << Lectures[8] << "    |" << endl;
		cout << "\t\t| 01:00-02:00 |    " << Lectures[5] << "    |     " << Lectures[4] << "    |      " << Lectures[1] << "     |      " << Lectures[8] << "    |    " << Lectures[3] << "    |" << endl;
		cout << "\t\t| 02:00-03:00 |    " << Lectures[6] << "    |     " << Lectures[3] << "    |      " << Lectures[3] << "     |      " << Lectures[7] << "    |    " << Lectures[1] << "    |" << endl;
		cout << "\t\t| 03:00-04:00 |    " << Lectures[7] << "    |     " << Lectures[2] << "    |      " << Lectures[5] << "     |      " << Lectures[5] << "    |    " << Lectures[2] << "    |" << endl;
		cout << "\t\t| 04:00-05:00 |    " << Lectures[8] << "    |     " << Lectures[1] << "    |      " << Lectures[7] << "     |      " << Lectures[3] << "    |    " << Lectures[9] << "    |" << endl;
		cout << "\t\t| 05:00-06:00 |    " << Lectures[9] << "    |     " << Lectures[0] << "    |      " << Lectures[9] << "     |      " << Lectures[1] << "    |    " << Lectures[0] << "    |" << endl;
		cout << "\t\t+==========================================================================+" << endl;

		cout << "\n\t\t\t  -> Here Is The Weekly TimeTable Of Teacher " << User_Name << " :) " << endl;
		cout << endl;
		system("pause");
	}
};

/*-----Assign Marks Class To Assign Marks To Students-----*/

class Assign_marks : public Teacher
{
private:
	string Student_ID_File;
	string Student_Roll_Number;
	string Student_Roll_Number_File;
	int Enrolled_Students_File;
	bool Roll_Number_Check = false;
	string Student_Department;
	string Teacher_Department;
	string File_Course[4];
public:

	/*-----Constructor-----*/

	Assign_marks()
	{
		Student_ID_File = "";
		Student_Roll_Number = "";
		Student_Roll_Number_File = "";
		Student_Department = "";
		Enrolled_Students_File = 0;
		Teacher_Department = "";
	}

	/*-----Function To Assign Marks-----*/

	void Assign_Marks()override
	{
		system("cls");

	Again:
		cout << "+==========================================================+" << endl;
		cout << "|---------------------| Assign Marks |---------------------|" << endl;
		cout << "+==========================================================+\n" << endl;

		cout << "Enter Student's Roll Number : ";
		cin >> Student_Roll_Number;

		/*-----Open Student File-----*/

		read.open("Student.txt");

		/*-----Loop Will Execute Till End Of File-----*/

		while (!read.eof())
		{
			read >> Student_Roll_Number_File;
			if (Student_Roll_Number == Student_Roll_Number_File)
			{
				Roll_Number_Check = true;
				break;
			}
		}

		if (Roll_Number_Check == false)
		{
			cout << "\n-> No Student Of This ID Has Registered :( " << endl;
			cout << "                Try Again !                  " << endl;

			cout << endl;
			system("pause");
			system("cls");
			read.close();
			goto Again;
		}
		read.close();

		/*-----Open Student File-----*/

		read.open("Student.txt");

		/*-----Open Enrolled Students File-----*/

		Enrolled_Sudents_Read.open("Enrolled_Students.txt");

		/*-----Read Enrolled Students From File-----*/

		Enrolled_Sudents_Read >> Enrolled_Students_File;

		/*-----Creating 2D-Dynamic Array As We've To Define A Length Of First Index At Run-Time-----*/

		string** Student_Data = new string * [Enrolled_Students_File];
		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			/*-----Here We Defined Length Of 14 As We Have 12 Enteries Of Each Student Data In File-----*/
			Student_Data[i] = new string[14];
		}

		/*-----Read All Students Data From File & Store That In 2D-Dynamic Array-----*/

		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				getline(read, Student_Data[i][j]);
			}
		}

		/*----Get The Student Department-----*/

		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			if (Student_Data[i][3] == Student_Roll_Number)
			{
				Student_Department = Student_Data[i][2];
			}
		}

		read.close();
		Enrolled_Sudents_Read.close();

		read.open("Teacher_Department.txt");
		getline(read, Teacher_Department);

		/*-----Checking Whether Student & Teacher Departments Are Same Or Not-----*/

		if (Student_Department != Teacher_Department)
		{
			cout << "\n This Student Is From Other Department " << endl;
			cout << "       You Cannot Assign Marks !       " << endl;

			read.close();
			cout << endl;
			system("pause");
			system("cls");
			goto Again;

		}

		/*-----If Same Then Program Will Proceed-----*/

		else if (Student_Department == Teacher_Department)
		{
			read.close();
			ifstream Course_read("Student_Registered_Courses.txt");

			while (!Course_read.eof())
			{
				Course_read >> Student_ID_File;

				/*-----Store All Students Registered Courses In Array-----*/

				if (Student_ID_File == Student_Roll_Number)
				{
					for (int i = 0; i < 4; i++)
					{
						getline(Course_read, File_Course[i]);
					}
					break;
				}
			}

			Course_read.close();

			bool Marks_Check = false;
			string Student_Id;
			string Assign_Marks_Choice;
			string Marks;
			string Course_Marks[3] = { "-", "-", "-" };
			string Subject_Marks_File;
			bool Subject_Check = false;

			while (true)
			{
				system("cls");

				cout << "+==========================================================+" << endl;
				cout << "|---------------------| Assign Marks |---------------------|" << endl;
				cout << "+==========================================================+\n" << endl;

				/*-----Show Student His/Her Registered Courses-----*/

				cout << "Student's Registerd Courses \n" << endl;
				cout << "1- " << File_Course[1] << endl;
				cout << "2- " << File_Course[2] << endl;
				cout << "3- " << File_Course[3] << endl;
				cout << "4- Assign Marks Done" << endl;

				cout << "\nEnter Course You Want To Assign Marks : ";
				cin >> Assign_Marks_Choice;

				/*-----Check If Student Has Already Registered His/Her Courses Or Not-----*/

				read.open("Student_Marks.txt");
				while (!read.eof())
				{
					read >> Student_Id;
					if (Student_Id == Student_Roll_Number)
					{
						Marks_Check = true;
						read.close();
						break;
					}
				}
			
				if (Marks_Check == true)
				{
					cout << "\nYou Have Already Assigned Marks To This Student !\n" << endl;
					read.close();
					system("pause");
					break;
				}
				
				/*-----If Not Then Register Courses-----*/

				else if (Marks_Check == false)
				{
					if (Assign_Marks_Choice == "1")
					{
						cout << "\nEnter Marks Of " << File_Course[1] << " : ";
						cin >> Marks;
						Course_Marks[0] = Marks;
						cout << "\n-> You've Just Assigned " << File_Course[1] << " Marks :) " << endl;
					}
					else if (Assign_Marks_Choice == "2")
					{
						cout << "\nEnter Marks Of " << File_Course[1] << " : ";
						cin >> Marks;
						Course_Marks[1] = Marks;
						cout << "\n-> You've Just Assigned " << File_Course[2] << " Marks :) " << endl;
					}
					else if (Assign_Marks_Choice == "3")
					{
						cout << "\nEnter Marks Of " << File_Course[1] << " : ";
						cin >> Marks;
						Course_Marks[2] = Marks;
						cout << "\n-> You've Just Assigned " << File_Course[3] << " Marks :) " << endl;
					}
					else if (Assign_Marks_Choice == "4")
					{
						break;
					}

					cout << endl;
					system("pause");
					system("cls");

					system("pause");

					/*-----Write All Assigned Marks Into File-----*/

					ofstream Write_Marks("Student_Marks.txt", ios::app);

					Write_Marks << Student_Roll_Number << endl;
					Write_Marks << File_Course[1] << endl;
					Write_Marks << Course_Marks[0] << endl;
					Write_Marks << File_Course[2] << endl;
					Write_Marks << Course_Marks[1] << endl;
					Write_Marks << File_Course[3] << endl;
					Write_Marks << Course_Marks[2] << endl;

					Write_Marks.close();

					system("pause");

					cout << endl;
					read.close();
				}
			}
		}

	}
};

/*-----Assign Grades Class To Assign Grades To Students-----*/

class Assign_grades : public Teacher
{
private:
	string Student_ID_File;
	string Student_Roll_Number;
	string Student_Roll_Number_File;
	int Enrolled_Students_File;
	bool Roll_Number_Check = false;
	string Student_Department;
	string Teacher_Department;
	string File_Course[4];
public:

	/*-----Constructor-----*/

	Assign_grades()
	{
		Student_ID_File = "";
		Student_Roll_Number = "";
		Student_Roll_Number_File = "";
		Student_Department = "";
		Enrolled_Students_File = 0;
		Teacher_Department = "";
	}

	/*-----Function To Assign Grades To Students-----*/

	void Assign_Grades()override
	{
		system("cls");
	Again:
		cout << "+==========================================================+" << endl;
		cout << "|--------------------| Assign Grades |---------------------|" << endl;
		cout << "+==========================================================+\n" << endl;

		cout << "Enter Student's Roll Number : ";
		cin >> Student_Roll_Number;

		/*-----Open Student File-----*/

		read.open("Student.txt");

		/*-----Loop Will Execute Till End Of File-----*/

		while (!read.eof())
		{
			read >> Student_Roll_Number_File;
			if (Student_Roll_Number == Student_Roll_Number_File)
			{
				Roll_Number_Check = true;
				break;
			}
		}

		if (Roll_Number_Check == false)
		{
			cout << "\n-> No Student Of This ID Has Registered :( " << endl;
			cout << "                Try Again !                  " << endl;

			cout << endl;
			system("pause");
			system("cls");
			read.close();
			goto Again;
		}
		read.close();

		/*-----Open Student File-----*/

		read.open("Student.txt");

		/*-----Open Enrolled Students File-----*/

		Enrolled_Sudents_Read.open("Enrolled_Students.txt");

		/*-----Read Enrolled Students From File-----*/

		Enrolled_Sudents_Read >> Enrolled_Students_File;

		/*-----Creating 2D-Dynamic Array As We've To Define A Length Of First Index At Run-Time-----*/

		string** Student_Data = new string * [Enrolled_Students_File];
		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			/*-----Here We Defined Length Of 14 As We Have 12 Enteries Of Each Student Data In File-----*/
			Student_Data[i] = new string[14];
		}

		/*-----Read All Students Data From File & Store That In 2D-Dynamic Array-----*/

		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				getline(read, Student_Data[i][j]);
			}
		}

		/*----Get The Student Department-----*/

		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			if (Student_Data[i][3] == Student_Roll_Number)
			{
				Student_Department = Student_Data[i][2];
			}
		}

		read.close();
		Enrolled_Sudents_Read.close();

		read.open("Teacher_Department.txt");
		getline(read, Teacher_Department);

		/*-----Checking Whether Student & Teacher Departments Are Same Or Not-----*/

		if (Student_Department != Teacher_Department)
		{
			cout << "\n This Student Is From Other Department " << endl;
			cout << "       You Cannot Assign Marks !       " << endl;

			read.close();
			cout << endl;
			system("pause");
			system("cls");
			goto Again;

		}

		/*-----If Same Then Program Will Proceed-----*/

		else if (Student_Department == Teacher_Department)
		{
			read.close();
			ifstream Course_read("Student_Registered_Courses.txt");

			while (!Course_read.eof())
			{
				Course_read >> Student_ID_File;

				if (Student_ID_File == Student_Roll_Number)
				{
					for (int i = 0; i < 4; i++)
					{
						getline(Course_read, File_Course[i]);
					}
					break;
				}
			}

			Course_read.close();

			bool Marks_Check = false;
			string Student_Id;
			string Assign_Grades_Choice;
			string Grade;
			string Course_Grades[3] = { "-", "-", "-" };

			while (true)
			{
				system("cls");

				cout << "+==========================================================+" << endl;
				cout << "|--------------------| Assign Grades |---------------------|" << endl;
				cout << "+==========================================================+\n" << endl;

				/*-----Show Student His/Her Registered Courses-----*/

				cout << "Student's Registerd Courses \n" << endl;
				cout << "1- " << File_Course[1] << endl;
				cout << "2- " << File_Course[2] << endl;
				cout << "3- " << File_Course[3] << endl;
				cout << "4- Assign Grades Done" << endl;

				cout << "\nEnter Course You Want To Assign Grades : ";
				cin >> Assign_Grades_Choice;

				read.open("Student_Grades.txt");
				while (!read.eof())
				{
					read >> Student_Id;

					/*-----Check If Student Has Already Registered His/Her Courses Or Not-----*/

					if (Student_Id == Student_Roll_Number)
					{
						Marks_Check = true;
						read.close();
						break;
					}
				}

				if (Marks_Check == true)
				{
					cout << "\nYou Have Already Assigned Grades To This Student !\n" << endl;
					system("pause");
					break;
				}

				/*-----Check If Student Has Not Registered Then Program Will Proceed-----*/

				else if (Marks_Check == false)
				{
					if (Assign_Grades_Choice == "1")
					{
						cout << "\nAssign Grade Of " << File_Course[1] << " : ";
						cin >> Grade;
						Course_Grades[0] = Grade;
						cout << "\n-> You've Just Assigned " << File_Course[1] << " Grades :) " << endl;
					}
					else if (Assign_Grades_Choice == "2")
					{
						cout << "\nAssign Grade Of " << File_Course[1] << " : ";
						cin >> Grade;
						Course_Grades[1] = Grade;
						cout << "\n-> You've Just Assigned " << File_Course[2] << " Grades :) " << endl;
					}
					else if (Assign_Grades_Choice == "3")
					{
						cout << "\nAssign Grade Of " << File_Course[1] << " : ";
						cin >> Marks;
						Course_Grades[2] = Grade;
						cout << "\n-> You've Just Assigned " << File_Course[3] << " Grades :) " << endl;
					}
					else if (Assign_Grades_Choice == "4")
					{
						break;
					}

					cout << endl;
					system("pause");
					system("cls");

					system("pause");

					/*-----Write All Assigned Grades Into File-----*/

					ofstream Write_Grades("Student_Grades.txt", ios::app);

					Write_Grades << Student_Roll_Number << endl;
					Write_Grades << File_Course[1] << endl;
					Write_Grades << Course_Grades[0] << endl;
					Write_Grades << File_Course[2] << endl;
					Write_Grades << Course_Grades[1] << endl;
					Write_Grades << File_Course[3] << endl;
					Write_Grades << Course_Grades[2] << endl;

					Write_Grades.close();

					cout << endl;
					read.close();
					system("pause");
				}
			}
		}
	}

};

/*-----Marking Attendence Class To Mark Attendence Of Students-----*/

class Marking_attendence : public Teacher
{
private:
	string Lecture_No;
	string Date;
	string Month;
	string Year;
	string Full_Date;
	string Duration;
	char Presence;
	string Student_Department;
	string Student_Roll_Number;
	string Student_Roll_Number_File;
	string Teacher_Department;
	int Enrolled_Students_File;
	string Student_ID_File;
	string File_Course[4];
	bool Roll_Number_Check = false;
public:

	/*-----Constructor-----*/

	Marking_attendence()
	{
		Lecture_No = "";
		Date = "";
		Month = "";
		Year = "";
		Full_Date = "";
		Duration = "";
		Presence = '\0';
	}

	/*-----Function To Mark Attendence Of All Students-----*/

	void Marking_Attendence()override
	{
		system("cls");

		Again:
		cout << "+===========================================================+" << endl;
		cout << "|---------------------| Mark Attendence |-------------------|" << endl;
		cout << "+===========================================================+\n" << endl;

		cout << "Enter Student's Roll Number : ";
		cin >> Student_Roll_Number;

		/*-----Open Student File-----*/

		read.open("Student.txt");

		/*-----Loop Will Execute Till End Of File-----*/

		while (!read.eof())
		{
			read >> Student_Roll_Number_File;
			if (Student_Roll_Number == Student_Roll_Number_File)
			{
				Roll_Number_Check = true;
				break;
			}
		}

		if (Roll_Number_Check == false)
		{
			cout << "\n-> No Student Of This ID Has Registered :( " << endl;
			cout << "                Try Again !                  " << endl;

			cout << endl;
			system("pause");
			system("cls");
			read.close();
			goto Again;
		}
		read.close();

		/*-----Open Student File-----*/

		read.open("Student.txt");

		/*-----Open Enrolled Students File-----*/

		Enrolled_Sudents_Read.open("Enrolled_Students.txt");

		/*-----Read Enrolled Students From File-----*/

		Enrolled_Sudents_Read >> Enrolled_Students_File;

		/*-----Creating 2D-Dynamic Array As We've To Define A Length Of First Index At Run-Time-----*/

		string** Student_Data = new string * [Enrolled_Students_File];
		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			/*-----Here We Defined Length Of 14 As We Have 12 Enteries Of Each Student Data In File-----*/
			Student_Data[i] = new string[14];
		}

		/*-----Read All Students Data From File & Store That In 2D-Dynamic Array-----*/

		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				getline(read, Student_Data[i][j]);
			}
		}

		/*----Get The Student Department-----*/

		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			if (Student_Data[i][3] == Student_Roll_Number)
			{
				Student_Department = Student_Data[i][2];
			}
		}

		read.close();
		Enrolled_Sudents_Read.close();

		read.open("Teacher_Department.txt");
		getline(read, Teacher_Department);

		/*----Check Student & Teacher Departments-----*/

		if (Student_Department != Teacher_Department)
		{
			cout << "\n This Student Is From Other Department " << endl;
			cout << "       You Cannot Mark Attendence !       " << endl;

			read.close();
			cout << endl;
			system("pause");
			system("cls");
			goto Again;

		}

		/*-----If Departments Are Same Then Program Will Proceed-----*/

		else if (Student_Department == Teacher_Department)
		{
			read.close();

			ifstream Course_read("Student_Registered_Courses.txt");

			while (!Course_read.eof())
			{
				Course_read >> Student_ID_File;

				if (Student_ID_File == Student_Roll_Number)
				{
					for (int i = 0; i < 4; i++)
					{
						getline(Course_read, File_Course[i]);
					}
					break;
				}
			}

			Course_read.close();

			while (true)
			{
				system("cls");

				cout << "+==========================================================+" << endl;
				cout << "|--------------------| Mark Attendence |-------------------|" << endl;
				cout << "+==========================================================+\n" << endl;

				/*-----Show Students His/Her Registered Courses-----*/

				cout << "Student's Registerd Courses \n" << endl;
				cout << "1- " << File_Course[1] << endl;
				cout << "2- " << File_Course[2] << endl;
				cout << "3- " << File_Course[3] << endl;
				cout << "4- Assign Grades Done" << endl;

				string Marked_Subject;
				string Mark_Attendence_Choice;
				string Student_Id;
				bool Marks_Check = false;

				cout << "\nEnter Course You Want To Mark Attendence : ";
				cin >> Mark_Attendence_Choice;

				/*-----Check Wether Student Attendence Has Already Marked-----*/

				read.open("Student_Attendence.txt");
				while (!read.eof())
				{
					read >> Student_Id;
					if (Student_Id == Student_Roll_Number)
					{
						Marks_Check = true;
						read.close();
						break;
					}
				}

				if (Marks_Check == true)
				{
					cout << "\nYou Have Already Marked Present Of This Student !\n" << endl;
					system("pause");
					break;
				}

				/*-----If Not Then Write Attendence Into The File-----*/

				else if (Marks_Check == false)
				{

					if (Mark_Attendence_Choice == "1")
					{
						while (true)
						{
							cout << "\nMark Presence Of " << File_Course[1] << " : ";
							cin >> Presence;
							if (Presence == 'A' || Presence == 'P')
							{
								break;
							}
						}
						ofstream Write_Attendence("Student_Attendence.txt", ios::app);
						Write_Attendence << File_Course[1] << endl;
						Write_Attendence.close();
						Marked_Subject = File_Course[1];
					}
					else if (Mark_Attendence_Choice == "2")
					{
						while (true)
						{
							cout << "\nMark Presence Of " << File_Course[2] << " : ";
							cin >> Presence;
							if (Presence == 'A' || Presence == 'P')
							{
								break;
							}
						}
						ofstream Write_Attendence("Student_Attendence.txt", ios::app);
						Write_Attendence << File_Course[2] << endl;
						Write_Attendence.close();
						Marked_Subject = File_Course[2];
					}
					else if (Mark_Attendence_Choice == "3")
					{
						while (true)
						{
							cout << "\nMark Presence Of " << File_Course[3] << " : ";
							cin >> Presence;
							if (Presence == 'A' || Presence == 'P')
							{
								break;
							}
						}
						ofstream Write_Attendence("Student_Attendence.txt", ios::app);
						Write_Attendence << File_Course[3] << endl;
						Write_Attendence.close();
						Marked_Subject = File_Course[3];
					}
					else if (Mark_Attendence_Choice == "4")
					{
						break;
					}

					cout << endl;
					cout << "Enter Lecture Number      :  ";
					cin >> Lecture_No;
					cout << "Enter Day Of Lecture      :  ";
					cin >> Date;
					cout << "Enter Month Of Lecture    :  ";
					cin >> Month;
					cout << "Enter Year Of Lecture     :  ";
					cin >> Year;
					cout << "Enter Hours Of Lecture    :  ";
					cin >> Duration;

					cout << "\n-> You've Just Marked " << Marked_Subject << " Presence :) " << endl;

					/*-----Write Attendence Into The File-----*/

					ofstream Write_Attendence("Student_Attendence.txt", ios::app);

					Write_Attendence << Student_Roll_Number << endl;
					Write_Attendence << Date << "-" << Month << "-" << Year << endl;
					Write_Attendence << Lecture_No << endl;
					Write_Attendence << Duration << endl;
					Write_Attendence << Presence << endl;

					Write_Attendence.close();

					cout << endl;
					system("pause");
					system("cls");
				}
			}
		}

		read.close();
	}

};

/*-----Student Main Class-----*/

class Student : public Admin
{
public:

	/*-----Virtual Functions-----*/

	virtual void Sign_In_Student() {}
	virtual void View_Attendence() {}
	virtual void View_Marks() {}
	virtual void View_Grades() {}
	virtual void Register_Course() {}
	virtual void View_Registered_Course() {}
	virtual void View_Fee_Status() {}
};

/*-----Sign In Class To Get Student Sign in Into Flex-----*/

class Sign_in_Student : public Student
{
private:
	bool Student_ID_Check = false;
public:

	/*-----Sign In Function To Get Student Sign in Into Flex-----*/

	void Sign_In_Student()override
	{
		system("cls");

	Again:
		cout << "+==========================================================+" << endl;
		cout << "|----------------| Sign-In To Your Account |---------------|" << endl;
		cout << "+==========================================================+\n" << endl;

		cout << "\t\t Enter Your ID        :  ";
		cin >> Student_ID;
		cout << "\t\t Enter Your Password  :  ";
		cin >> Password;

		/*-----Open File In Which Student Credientials Are Saved-----*/

		read.open("Student_Credientials.txt");

		/*-----Read Student Credientials Form File-----*/
		while (!read.eof())
		{

			read >> User_Name_File;
			read >> Password_File;

			/*-----Match Student Credientials With Input-----*/

			if (Student_ID == User_Name_File && Password == Password_File)
			{
				Student_ID_Check = true;
				write.open("Student_ID_For_Course_Registration.txt");
				write << Student_ID;
				write.close();
				break;
			}
		}

		if (Student_ID_Check == false)
		{
			cout << "\n\t\tYour Credentials Are Not Correct :( " << endl;
			cout << "\t\t          Try Again !               \n" << endl;

			read.close();
			cout << endl;
			system("pause");
			system("cls");
			goto Again;
		}

		/*-----Close Student Credientials File-----*/

		read.close();
	}
};

/*-----class View_Attendence To View Attence Of Student-----*/

class View_attendence : public Student
{
private:
	string Student_ID_File;
	string Lecture_Name_File;
	string Lecture_No;
	string Date;
	string Month;
	string Year;
	string Duration;
	string Presence;
	string File_Attendence[3];
	string File_Course[4];
	string View_Presence_Choice;
	string Course_For_Searching;
	string Date_File;
	string Full_Date;

public:

	/*-----Constructor-----*/

	View_attendence()
	{
		Student_ID_File = "";
		Lecture_Name_File = "";
		Lecture_No = "";
		Date = "";
		Month = "";
		Year = "";
		Duration = "";
		Presence = "";
		View_Presence_Choice = "";
		Course_For_Searching = "";
		Date_File = "";
		Full_Date = "";
	}

	/*-----View_Attendence Function To View Attence Of Student-----*/

	void View_Attendence()override
	{

		read.open("Student_ID_For_Course_Registration.txt");
		read >> Student_ID;
		read.close();

		ifstream Course_read("Student_Registered_Courses.txt");

		/*-----Storing Student's All Registered Courses In Array-----*/

		while (!Course_read.eof())
		{
			Course_read >> Student_ID_File;

			if (Student_ID_File == Student_ID)
			{
				for (int i = 0; i < 4; i++)
				{
					getline(Course_read, File_Course[i]);
				}
				break;
			}
		}

		Course_read.close();

		while (true)
		{
			system("cls");
			cout << "+============================================================+" << endl;
			cout << "|---------------------| View Attendence |--------------------|" << endl;
			cout << "+============================================================+" << endl;

			/*-----Display Student's All Registered Courses-----*/

			cout << "\nStudent's Registerd Courses \n" << endl;
			cout << "1- " << File_Course[1] << endl;
			cout << "2- " << File_Course[2] << endl;
			cout << "3- " << File_Course[3] << endl;
			cout << "4- View Attendence Done" << endl;

			cout << "\nEnter Course You Want To See Presence : ";
			cin >> View_Presence_Choice;

			/*-----Check Presence Of All Registered Courses-----*/

			if (View_Presence_Choice == "1")
			{
				Course_For_Searching = File_Course[1];
			}
			else if (View_Presence_Choice == "2")
			{
				Course_For_Searching = File_Course[2];
			}
			else if (View_Presence_Choice == "3")
			{
				Course_For_Searching = File_Course[3];
			}
			else if (View_Presence_Choice == "4")
			{
				break;
			}

			cout << "Enter Date  : ";
			cin >> Date;
			cout << "Enter Month : ";
			cin >> Month;
			cout << "Enter Year  : ";
			cin >> Year;
			Full_Date = Date + "-" + Month + "-" + Year;

			read.open("Student_Attendence.txt");

			bool attendence_check = false;
			while (!read.eof())
			{
				getline (read,Lecture_Name_File);
				read >> Student_ID_File;
				read >> Date_File;

				if (Lecture_Name_File == Course_For_Searching && Student_ID_File == Student_ID && Date_File == Full_Date)
				{
					attendence_check = true;
					for (int i = 0; i < 3; i++)
					{
						read >> File_Attendence[i];
					}
					break;
				}
			}


			read.close();

			if (attendence_check == true)
			{
				cout << endl;
				cout << "+============================================================+" << endl;
				cout << "|---------------------| View Attendence |--------------------|" << endl;
				cout << "|============================================================|" << endl;
				cout << "|  Lecture No  |     Date      |   Duration   |   Presence   |" << endl;
				cout << "|------------------------------------------------------------|" << endl;
				cout << "|      " << File_Attendence[0] << "       |  " << Date_File << "   |       " << File_Attendence[1] << "      |       " << File_Attendence[2] << "      |" << endl;
				cout << "+============================================================+" << endl;

				cout << "\n -> Here Is Your Presence Of " << Lecture_Name_File << " On " << Date_File << ":)" << endl;

			}
			else if (attendence_check == false)
			{
				cout << "\n-> Your Attendence Has Not Been Marked Yet :(" << endl;
			}

			cout << endl;
			system("pause");
		}
	}
};

/*-----Class View_Marks To View Marks Of Student-----*/

class View_marks : public Student
{
private:
	string Student_ID_File;
	string File_Course[4];
public:

	View_marks()
	{
		Student_ID_File = "";
	}

	void View_Marks()
	{
		system("cls");
		cout << "+==========================================================+" << endl;
		cout << "|-----------------------| View Marks |---------------------|" << endl;
		cout << "+==========================================================+\n" << endl;

		read.open("Student_ID_For_Course_Registration.txt");
		read >> Student_ID;
		read.close();

		read.open("Student_Registered_Courses.txt");

		/*-----Storing Student's All Registered Courses In Array-----*/

		while (!read.eof())
		{
			read >> Student_ID_File;

			if (Student_ID_File == Student_ID)
			{
				for (int i = 0; i < 4; i++)
				{
					getline(read, File_Course[i]);
				}
				break;
			}
		}

		read.close();

		string Student_Marks[7];
		read.open("Student_Marks.txt");

		/*-----Storing Student's Marks In Array-----*/

		while (!read.eof())
		{
			read >> Student_ID_File;

			if (Student_ID_File == Student_ID)
			{
				for (int i = 0; i < 7; i++)
				{
					getline(read, Student_Marks[i]);
				}
				break;
			}
		}
		read.close();

		string Course_Name_Choice;
		while (true)
		{
			system("cls");
			cout << "+==========================================================+" << endl;
			cout << "|-----------------------| View Marks |---------------------|" << endl;
			cout << "+==========================================================+\n" << endl;

			/*-----Display Student's All Registered Courses-----*/

			cout << "Your Registered Courses :\n" << endl;
			cout << "1- " << File_Course[1] << endl;
			cout << "2- " << File_Course[2] << endl;
			cout << "3- " << File_Course[3] << endl;
			cout << "4- View Marks Done" << endl;
			cout << endl;

			cout << "Enter Course Name : ";
			cin >> Course_Name_Choice;

			if (Course_Name_Choice == "1")
			{
				cout << File_Course[1] << " : " << Student_Marks[2] << endl;
			}
			else if (Course_Name_Choice == "2")
			{
				cout << File_Course[2] << " : " << Student_Marks[4] << endl;
			}
			else if (Course_Name_Choice == "3")
			{
				cout << File_Course[3] << " : " << Student_Marks[6] << endl;
			}
			else if (Course_Name_Choice == "4")
			{
				break;
			}

			cout << endl;
			system("pause");
			system("cls");
		}


		system("pause");
	}
};

/*-----Class View Grades To View Students Grade-----*/

class View_grades : public Student
{
private:
	string Student_ID_File;
	string File_Course[4];
public:

	/*-----Constructor-----*/

	View_grades()
	{
		Student_ID_File = "";
	}

	/*-----Function View Grades To View Students Grade-----*/

	void View_Grades()override
	{
		system("cls");
		cout << "+==========================================================+" << endl;
		cout << "|----------------------| View Grades |---------------------|" << endl;
		cout << "+==========================================================+\n" << endl;

		read.open("Student_ID_For_Course_Registration.txt");
		read >> Student_ID;
		read.close();

		read.open("Student_Registered_Courses.txt");

		/*-----Storing Student's All Registered Courses In Array-----*/

		while (!read.eof())
		{
			read >> Student_ID_File;

			if (Student_ID_File == Student_ID)
			{
				for (int i = 0; i < 4; i++)
				{
					getline(read, File_Course[i]);
				}
				break;
			}
		}

		read.close();

		string Student_Grades[7];
		read.open("Student_Grades.txt");

		/*-----Storing Student's Grades In Array-----*/

		while (!read.eof())
		{
			read >> Student_ID_File;

			if (Student_ID_File == Student_ID)
			{
				for (int i = 0; i < 7; i++)
				{
					getline(read, Student_Grades[i]);
				}
				break;
			}
		}
		read.close();

		string Course_Name_Choice;
		while (true)
		{
			system("cls");
			cout << "+==========================================================+" << endl;
			cout << "|----------------------| View Grades |---------------------|" << endl;
			cout << "+==========================================================+\n" << endl;

			/*-----Display Student's All Registered Courses-----*/

			cout << "Your Registered Courses :\n" << endl;
			cout << "1- " << File_Course[1] << endl;
			cout << "2- " << File_Course[2] << endl;
			cout << "3- " << File_Course[3] << endl;
			cout << "4- View Grades Done" << endl;
			cout << endl;

			cout << "Enter Course Name : ";
			cin >> Course_Name_Choice;

			if (Course_Name_Choice == "1")
			{
				cout << File_Course[1] << " : " << Student_Grades[2] << endl;
			}
			else if (Course_Name_Choice == "2")
			{
				cout << File_Course[2] << " : " << Student_Grades[4] << endl;
			}
			else if (Course_Name_Choice == "3")
			{
				cout << File_Course[3] << " : " << Student_Grades[6] << endl;
			}
			else if (Course_Name_Choice == "4")
			{
				break;
			}

			cout << endl;
			system("pause");
			system("cls");
		}


		system("pause");
	}
};

/*-----Class For Regiter & View Register Courses-----*/

class View_Registered_Courses : public Student
{
private:
	int Enrolled_Students_File;
	string Student_Department;
	string Student_ID_File;
public:

	/*-----Constructor-----*/

	View_Registered_Courses()
	{
		Enrolled_Students_File = 0;
		Student_ID_File = "";
		Student_Department = "";
	}

	/*-----Function To Register Courses-----*/

	void Register_Course()override
	{
		system("cls");
		cout << "+==========================================================+" << endl;
		cout << "|-----------------| Register Your Courses |----------------|" << endl;
		cout << "+==========================================================+\n" << endl;

		read.open("Student_ID_For_Course_Registration.txt");
		read >> Student_ID;
		read.close();

		/*-----Open Student File-----*/

		read.open("Student.txt");

		/*-----Open Enrolled Students File-----*/

		Enrolled_Sudents_Read.open("Enrolled_Students.txt");

		/*-----Read Enrolled Students From File-----*/

		Enrolled_Sudents_Read >> Enrolled_Students_File;

		/*-----Creating 2D-Dynamic Array As We've To Define A Length Of First Index At Run-Time-----*/

		string** Student_Data = new string * [Enrolled_Students_File];
		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			/*-----Here We Defined Length Of 14 As We Have 12 Enteries Of Each Student Data In File-----*/
			Student_Data[i] = new string[14];
		}

		/*-----Read All Students Data From File & Store That In 2D-Dynamic Array-----*/

		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				getline(read, Student_Data[i][j]);
			}
		}

		/*----Get The Student Department-----*/

		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			if (Student_Data[i][3] == Student_ID)
			{
				Student_Department = Student_Data[i][2];
			}
		}

		/*-----Offer Subjects According To Department-----*/

		if (Student_Department == "Computer Science")
		{
			string Courses[5] = { "Programming Fundamentals","Object Oriented Programming","Data Structures","Data Base","Operating System" };
			Show_Course(Courses);
		}
		else if (Student_Department == "Electrical Engineering")
		{
			string Courses[5] = { "Digital Electronics","System Design","Motor Control","Analogue Electrics","Electromagnetic Fields" };
			Show_Course(Courses);
		}
		else if (Student_Department == "Software Engineering")
		{
			string Courses[5] = { "Programming Fundamentals","Object Oriented Programming","Data Structures","Data Base","Operating System" };
			Show_Course(Courses);
		}
		else if (Student_Department == "Business")
		{
			string Courses[5] = { "Management Studies","Finance","Accounting","Marketing","Advertisement" };
			Show_Course(Courses);
		}
		else if (Student_Department == "Social Sciences")
		{
			string Courses[5] = { "History","Geography"," Political Structures ","Political Science"," Economics" };
			Show_Course(Courses);
		}
		read.close();
		Enrolled_Sudents_Read.close();
	}

	/*-----Function To ShoW Courses-----*/

	void Show_Course(string Courses[5])
	{
		string Courses_Choice;
		string Registered_Courses[3];
		string Student_Id;
		bool Marks_Check = false;

	Again:
		cout << "-------| Choose Any 3 Courses You Want To Register |------- \n" << endl;

		cout << "1-" << Courses[0] << endl;
		cout << "2-" << Courses[1] << endl;
		cout << "3-" << Courses[2] << endl;
		cout << "4-" << Courses[3] << endl;
		cout << "5-" << Courses[4] << endl;

		int course_count = 0;

		cout << endl;
		while (true)
		{
			cout << "Select Course " << course_count + 1 << " : ";
			cin >> Courses_Choice;

			ifstream Course_read("Student_Registered_Courses.txt");

			/*-----Check Wether Student Has Already Regitered Courses-----*/

			while (!Course_read.eof())
			{
				Course_read >> Student_Id;
				if (Student_Id == Student_ID)
				{
					Marks_Check = true;
					Course_read.close();
					break;
				}
			}

			if (Marks_Check == true)
			{
				cout << "\nYou Have Already Registered Your Courses !\n" << endl;
				system("pause");
				break;
			}

			/*-----Choose 3 Courses Out Of 5-----*/

			else if (Marks_Check == false)
			{
				if (Courses_Choice == "1")
				{
					Registered_Courses[course_count] = Courses[0];
					course_count = course_count + 1;
				}
				else if (Courses_Choice == "2")
				{
					Registered_Courses[course_count] = Courses[1];
					course_count = course_count + 1;
				}
				else if (Courses_Choice == "3")
				{
					Registered_Courses[course_count] = Courses[2];
					course_count = course_count + 1;
				}
				else if (Courses_Choice == "4")
				{
					Registered_Courses[course_count] = Courses[3];
					course_count = course_count + 1;
				}
				else if (Courses_Choice == "5")
				{
					Registered_Courses[course_count] = Courses[4];
					course_count = course_count + 1;
				}
				if (course_count == 3)
				{
					break;
				}
				Course_read.close();
			}
		}

		if (Marks_Check == false)
		{
			/*-----Make Sure All Courses Are Different-----*/

			bool course_check = true;
			if (Registered_Courses[0] == Registered_Courses[1] ||
				Registered_Courses[1] == Registered_Courses[2] ||
				Registered_Courses[2] == Registered_Courses[0])
			{
				course_check = false;
			}

			if (course_check == false)
			{
				cout << "\nYou Cannot Register Same Course Multiple Times :( " << endl;
				cout << "              Register Again !                  \n" << endl;

				cout << endl;
				system("pause");
				system("cls");
				goto Again;
			}
			else if (course_check == true)
			{

				cout << "\n----| You Have Registered Following Courses |----\n" << endl;
				cout << "1-" << Registered_Courses[0] << endl;
				cout << "2-" << Registered_Courses[1] << endl;
				cout << "3-" << Registered_Courses[2] << endl;

			}

			write.open("Student_Registered_Courses.txt", ios::app);

			/*-----Write Courses Into File-----*/

			write << Student_ID << endl;
			for (int i = 0; i < 3; i++)
			{
				write << Registered_Courses[i] << endl;
			}
			write.close();

			system("pause");
		}
		else
			system("pause");
	}

	/*-----Function To View Registered Courses-----*/

	void View_Registered_Course()override
	{
		string File_Course[4];

		system("cls");
		cout << "+==========================================================+" << endl;
		cout << "|----------------| View Registered Courses |---------------|" << endl;
		cout << "+==========================================================+\n" << endl;

		read.open("Student_ID_For_Course_Registration.txt");
		read >> Student_ID;
		read.close();

		read.open("Student_Registered_Courses.txt");

		/*-----Store Courses Into Array-----*/

		while (!read.eof())
		{
			read >> Student_ID_File;

			if (Student_ID_File == Student_ID)
			{
				for (int i = 0; i < 4; i++)
				{
					getline(read, File_Course[i]);
				}
				break;
			}
		}

		/*-----Showing Registered Courses-----*/

		read.close();
		cout << "Your Registered Courses :\n" << endl;
		cout << "1- " << File_Course[1] << endl;
		cout << "2- " << File_Course[2] << endl;
		cout << "3- " << File_Course[3] << endl;
		cout << endl;

		system("pause");
	}
};

class View_fee_Status : public Student
{
private:
	int Amount;
	int Enrolled_Students_File;
	string Generated_On;
	string Due_Date;
	string Fee_Status;
public:

	View_fee_Status()
	{
		Enrolled_Students_File = 0;
		Amount = 150000;
		Generated_On = "10-Mar-2021";
		Due_Date = "31-Mar-2021";
		Fee_Status = "";
	}

	void View_Fee_Status()override
	{
		system("cls");
		cout << "+==================================================================+" << endl;
		cout << "|------------------------| View Fee Status |-----------------------|" << endl;
		cout << "+==================================================================+\n" << endl;

		read.open("Student_ID_For_Course_Registration.txt");
		read >> Student_ID;
		read.close();

		/*-----Open Student File-----*/

		read.open("Student.txt");

		/*-----Open Enrolled Students File-----*/

		Enrolled_Sudents_Read.open("Enrolled_Students.txt");

		/*-----Read Enrolled Students From File-----*/

		Enrolled_Sudents_Read >> Enrolled_Students_File;

		/*-----Creating 2D-Dynamic Array As We've To Define A Length Of First Index At Run-Time-----*/

		string** Student_Data = new string * [Enrolled_Students_File];
		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			/*-----Here We Defined Length Of 14 As We Have 12 Enteries Of Each Student Data In File-----*/
			Student_Data[i] = new string[14];
		}

		/*-----Read All Students Data From File & Store That In 2D-Dynamic Array-----*/

		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				getline(read, Student_Data[i][j]);
			}
		}

		/*----Get The Student Fee Status-----*/

		for (int i = 0; i < Enrolled_Students_File; i++)
		{
			if (Student_Data[i][3] == Student_ID)
			{
				Fee_Status = Student_Data[i][11];
			}
		}


		cout << "+==================================================================+" << endl;
		cout << "|  Roll.No  |  Amount  |  Generated On  |   Due Date    |  Status  |" << endl;
		cout << "|==================================================================|" << endl;
		cout << "|  " << Student_ID << " |  " << Amount << "  |  " << Generated_On << "   |  " << Due_Date << "  |   " << Fee_Status << "   |  " << endl;
		cout << "+==================================================================+" << endl;

		cout << "\n-> Here Is Your Fee Status :) \n" << endl;
		system("pause");
	}

};

/*---Function To Display Main Menu-----*/

void Main_Menu()
{
	system("cls");
	cout << "+==========================================================+" << endl;
	cout << "|-----------| Welcome To Flex Management System |----------|" << endl;
	cout << "|==========================================================|" << endl;
	cout << "|                 1) Admin Flex Portal                     |" << endl;
	cout << "|                 2) Teacher Flex Portal                   |" << endl;
	cout << "|                 3) Student Flex Portal                   |" << endl;
	cout << "|                 4) Exit Your Program                     |" << endl;
	cout << "+==========================================================+" << endl;
}

/*---Function To Display Admin Menu-----*/

void Admin_Menu()
{
	system("cls");
	cout << "+==========================================================+" << endl;
	cout << "|------------------| Admin Flex Portal |-------------------|" << endl;
	cout << "|==========================================================|" << endl;
	cout << "|                 1)   Add New Teacher                     |" << endl;
	cout << "|                 2)   Add New Student                     |" << endl;
	cout << "|                 3) Edit Teacher Details                  |" << endl;
	cout << "|                 4) Edit Student Details                  |" << endl;
	cout << "|                 5) View Teacher Details                  |" << endl;
	cout << "|                 6) View Student Details                  |" << endl;
	cout << "|                 7) Log out From Account                  |" << endl;
	cout << "+==========================================================+" << endl;
}

/*---Function To Display Teacher Menu-----*/

void Teacher_Menu()
{
	system("cls");
	cout << "+==========================================================+" << endl;
	cout << "|-----------------| Teacher Flex Portal |------------------|" << endl;
	cout << "|==========================================================|" << endl;
	cout << "|                 1) Display Time Table                    |" << endl;
	cout << "|                 2)    Assign Marks                       |" << endl;
	cout << "|                 3)    Assign Grades                      |" << endl;
	cout << "|                 4)   Mark Attendence                     |" << endl;
	cout << "|                 5) Log out From Account                  |" << endl;
	cout << "+==========================================================+" << endl;
}

/*---Function To Display Student Menu-----*/

void Student_Menu()
{
	system("cls");
	cout << "+==========================================================+" << endl;
	cout << "|-----------------| Student Flex Portal |------------------|" << endl;
	cout << "|==========================================================|" << endl;
	cout << "|                 1)     View Marks                        |" << endl;
	cout << "|                 2)     View Grades                       |" << endl;
	cout << "|                 3)   View Fee Status                     |" << endl;
	cout << "|                 4)   View Attendence                     |" << endl;
	cout << "|                 5)   Register Course                     |" << endl;
	cout << "|                 6) View Register Course                  |" << endl;
	cout << "|                 7) Log out From Account                  |" << endl;
	cout << "+==========================================================+" << endl;
}

/*---Main Function-----*/

int main()
{
	system("color 0a");

	/*-----Creating Pointer Objects Of 3 Main Module Classes-----*/

	Admin* admin = NULL;
	Teacher* teacher = NULL;
	Student* student = NULL;

	string Main_Menu_Choice;
	string Admin_Menu_Choice;
	string Teacher_Menu_Choice;
	string Student_Menu_Choice;

	while (true)
	{
		Main_Menu();
		cout << "\n\t\t --> Enter Your Choice : ";
		cin >> Main_Menu_Choice;

		/*-----Admin Module-----*/

		if (Main_Menu_Choice == "1")
		{
			admin = new Sign_in_Admin();
			admin->Sign_In_Admin();

			while (true)
			{
				Admin_Menu();
				cout << "\n\t\t --> Enter Your Choice : ";
				cin >> Admin_Menu_Choice;

				if (Admin_Menu_Choice == "1")
				{
					admin = new Add();
					admin->Add_New_Teacher();
				}
				else if (Admin_Menu_Choice == "2")
				{
					admin = new Add();
					admin->Add_New_Student();
				}
				else if (Admin_Menu_Choice == "3")
				{
					admin = new Edit();
					admin->Edit_Teacher_Detail();
				}
				else if (Admin_Menu_Choice == "4")
				{
					admin = new Edit();
					admin->Edit_Student_Detail();
				}
				else if (Admin_Menu_Choice == "5")
				{
					admin = new View();
					admin->View_All_Teachers();
				}
				else if (Admin_Menu_Choice == "6")
				{
					admin = new View();
					admin->View_All_Students();
				}
				else if (Admin_Menu_Choice == "7")
				{
					break;
				}
			}
	    }

		/*-----Teacher Module-----*/

		else if (Main_Menu_Choice == "2")
		{
			teacher = new Sign_in_Teacher();
			teacher->Sign_In_Teacher();

			while (true)
			{
				Teacher_Menu();
				cout << "\n Enter Your Choice : ";
				cin >> Teacher_Menu_Choice;

				if (Teacher_Menu_Choice == "1")
				{
					teacher = new Teachers_Time_Table();
					teacher->Teacher_Time_Table();
				}
				else if (Teacher_Menu_Choice == "2")
				{
					teacher = new Assign_marks();
					teacher->Assign_Marks();
				}
				else if (Teacher_Menu_Choice == "3")
				{
					teacher = new Assign_grades();
					teacher->Assign_Grades();
				}
				else if (Teacher_Menu_Choice == "4")
				{
					teacher = new Marking_attendence();
					teacher->Marking_Attendence();

				}
				else if (Teacher_Menu_Choice == "5")
				{
					break;
				}
			}
		}

		/*-----Student Module-----*/

		else if (Main_Menu_Choice == "3")
		{
			student = new Sign_in_Student();
			student->Sign_In_Student();

			while (true)
			{
				Student_Menu();
				cout << "\n Enter Your Choice : ";
				cin >> Student_Menu_Choice;


				if (Student_Menu_Choice == "1")
				{
					student = new View_marks();
					student->View_Marks();
				}
				else if (Student_Menu_Choice == "2")
				{
					student = new View_grades();
					student->View_Grades();
				}
				else if (Student_Menu_Choice == "3")
				{
					student = new View_fee_Status();
					student->View_Fee_Status();
				}
				else if (Student_Menu_Choice == "4")
				{
					student = new View_attendence();
					student->View_Attendence();
				}
				else if (Student_Menu_Choice == "5")
				{
					student = new View_Registered_Courses();
					student->Register_Course();
				}
				else if (Student_Menu_Choice == "6")
				{
					student = new View_Registered_Courses();
					student->View_Registered_Course();
				}
				else if (Student_Menu_Choice == "7")
				{
					break;
				}
			}
		}

		/*-----Exit Flex Management System-----*/

		else if (Main_Menu_Choice == "4")
		{
			break;
		}

	}

	cout << endl;
	system("pause");
	return 0;
}