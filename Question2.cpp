#include "Question2.h"
#include<iostream>
using namespace std;

//////////////////////////////////////APPLICATIONMANAGER//////////////////////////////////////////////////

//====================constructor============================

ApplicationManager::ApplicationManager(Storage* storage, RAM* ram) {
	this->storage = storage;
	this->ram = ram;

	fileExplorer = new FileExplorer(storage);    // creating four objects
	recycleBin = new RecycleBin(storage);
	calculator = new Calculator();
	settings = new Settings();

	storage->saveFile(File("FileExplorer", "app", 20));   //manually saving the files to storage
	storage->saveFile(File("RecycleBin", "app", 10));     //sizes are from test cases files
	storage->saveFile(File("Calculator", "app", 15));
	storage->saveFile(File("Settings", "app", 5));
}

//==========================functions==========================

bool ApplicationManager::launchApp(const char* appName) {

	//finding the named app


	//for file explorer
	bool found1 = true;
	int i1 = 0;

	const char* target1 = "FileExplorer";

	while (appName[i1] != '\0' && target1[i1] != '\0') {

		if (appName[i1] != target1[i1]) {
			found1 = false;
			break;
		}
		i1++;
	}
	if (appName[i1] != '\0' || target1[i1] != '\0') found1 = false;  //if length not equal then not same

	if (found1) {

		if (fileExplorer->isRunning == true) return true;

		if (ram->allocate(50) == true) {  //checking for sufficient space
			fileExplorer->isRunning = true;
			return true;
		}
	}

	//for recycle bin
	bool found2 = true;
	int i2 = 0;

	const char* target2 = "RecycleBin";

	while (appName[i2] != '\0' && target2[i2] != '\0') {

		if (appName[i2] != target2[i2]) {
			found2 = false;
			break;
		}
		i2++;
	}

	if (appName[i2] != '\0' || target2[i2] != '\0') found2 = false;  //if length not equal then not same

	if (found2) {

		if (recycleBin->isRunning == true) return true;

		if (ram->allocate(30) == true) {  //checking for sufficient space
			recycleBin->isRunning = true;
			return true;
		}
	}

	//for calculator
	bool found3 = true;
	int i3 = 0;

	const char* target3 = "Calculator";

	while (appName[i3] != '\0' && target3[i3] != '\0') {

		if (appName[i3] != target3[i3]) {
			found3 = false;
			break;
		}
		i3++;
	}

	if (appName[i3] != '\0' || target3[i3] != '\0') found3 = false;  //if length not equal then not same

	if (found3) {

		if (calculator->isRunning == true) return true;

		if (ram->allocate(40) == true) {  //checking for sufficient space
			calculator->isRunning = true;
			return true;
		}
	}


	//for settings
	bool found4 = true;
	int i4 = 0;

	const char* target4 = "Settings";

	while (appName[i4] != '\0' && target4[i4] != '\0') {

		if (appName[i4] != target4[i4]) {
			found4 = false;
			break;
		}
		i4++;
	}

	if (appName[i4] != '\0' || target4[i4] != '\0') found4
		= false;  //if length not equal then not same

	if (found4) {

		if (settings->isRunning == true) return true;

		if (ram->allocate(20) == true) {  //checking for sufficient space
			settings->isRunning = true;
			return true;
		}
	}


	return false;

} //launch app;


bool ApplicationManager::closeApp(const char* appName) {

	// for file explorer
	const char* target1 = "FileExplorer";
	int i1 = 0;
	bool found1 = true;
	while (appName[i1] != '\0' && target1[i1] != '\0') {
		if (appName[i1] != target1[i1]) {
			found1 = false;
			break;
		}
		i1++;
	}
	if (appName[i1] != '\0' || target1[i1] != '\0') found1 = false;

	if (found1) {
		if (!fileExplorer->isRunning) return false;
		fileExplorer->isRunning = false;
		ram->deallocate(50);
		return true;
	}

	// for recycle bin
	const char* target2 = "RecycleBin";
	int i2 = 0;
	bool found2 = true;
	while (appName[i2] != '\0' && target2[i2] != '\0') {
		if (appName[i2] != target2[i2]) {
			found2 = false;
			break;
		}
		i2++;
	}
	if (appName[i2] != '\0' || target2[i2] != '\0') found2 = false;

	if (found2) {
		if (!recycleBin->isRunning) return false;
		recycleBin->isRunning = false;
		ram->deallocate(30);
		return true;
	}

	// for calculator
	const char* target3 = "Calculator";
	int i3 = 0;
	bool found3 = true;
	while (appName[i3] != '\0' && target3[i3] != '\0') {
		if (appName[i3] != target3[i3]) {
			found3 = false;
			break;
		}
		i3++;
	}
	if (appName[i3] != '\0' || target3[i3] != '\0') found3 = false;

	if (found3) {
		if (!calculator->isRunning) return false;
		calculator->isRunning = false;
		ram->deallocate(40);
		return true;
	}

	// for settings
	const char* target4 = "Settings";
	int i4 = 0;
	bool found4 = true;
	while (appName[i4] != '\0' && target4[i4] != '\0') {
		if (appName[i4] != target4[i4]) {
			found4 = false;
			break;
		}
		i4++;
	}
	if (appName[i4] != '\0' || target4[i4] != '\0') found4 = false;

	if (found4) {
		if (!settings->isRunning) return false;
		settings->isRunning = false;
		ram->deallocate(20);
		return true;
	}


	return false;


} //close app


bool ApplicationManager::isRunning(const char* appName) const {

	// for file explorer
	const char* target1 = "FileExplorer";
	int i1 = 0;
	bool found1 = true;
	while (appName[i1] != '\0' && target1[i1] != '\0') {
		if (appName[i1] != target1[i1]) {
			found1 = false;
			break;
		}
		i1++;
	}
	if (appName[i1] != '\0' || target1[i1] != '\0') found1 = false;

	if (found1) {

		if (fileExplorer->isRunning) return true;

		else return false;
	}

	// for recycle bin
	const char* target2 = "RecycleBin";
	int i2 = 0;
	bool found2 = true;
	while (appName[i2] != '\0' && target2[i2] != '\0') {
		if (appName[i2] != target2[i2]) {
			found2 = false;
			break;
		}
		i2++;
	}
	if (appName[i2] != '\0' || target2[i2] != '\0') found2 = false;

	if (found2) {

		if (recycleBin->isRunning) return true;

		else return false;
	}

	// for calculator
	const char* target3 = "Calculator";
	int i3 = 0;
	bool found3 = true;
	while (appName[i3] != '\0' && target3[i3] != '\0') {
		if (appName[i3] != target3[i3]) {
			found3 = false;
			break;
		}
		i3++;
	}
	if (appName[i3] != '\0' || target3[i3] != '\0') found3 = false;

	if (found3) {

		if (calculator->isRunning) return true;

		else return false;
	}

	// for settings
	const char* target4 = "Settings";
	int i4 = 0;
	bool found4 = true;
	while (appName[i4] != '\0' && target4[i4] != '\0') {
		if (appName[i4] != target4[i4]) {
			found4 = false;
			break;
		}
		i4++;
	}
	if (appName[i4] != '\0' || target4[i4] != '\0') found4 = false;

	if (found4) {

		if (settings->isRunning) return true;

		else return false;
	}


	return false;

} //is running



void* ApplicationManager::getApp(const char* appName) const {

	//same as launch app, just returns pointer instead of bool

	//for file explorer
	bool found1 = true;
	int i1 = 0;

	const char* target1 = "FileExplorer";

	while (appName[i1] != '\0' && target1[i1] != '\0') {

		if (appName[i1] != target1[i1]) {
			found1 = false;
			break;
		}
		i1++;
	}
	if (appName[i1] != '\0' || target1[i1] != '\0') found1 = false;  //if length not equal then not same

	if (found1) {
		return (void*)fileExplorer;       //returning void pointer
	}

	//for recycle bin
	bool found2 = true;
	int i2 = 0;

	const char* target2 = "RecycleBin";

	while (appName[i2] != '\0' && target2[i2] != '\0') {

		if (appName[i2] != target2[i2]) {
			found2 = false;
			break;
		}
		i2++;
	}

	if (appName[i2] != '\0' || target2[i2] != '\0') found2 = false;  //if length not equal then not same

	if (found2) {
		return (void*)recycleBin;
	}

	//for calculator
	bool found3 = true;
	int i3 = 0;

	const char* target3 = "Calculator";

	while (appName[i3] != '\0' && target3[i3] != '\0') {

		if (appName[i3] != target3[i3]) {
			found3 = false;
			break;
		}
		i3++;
	}

	if (appName[i3] != '\0' || target3[i3] != '\0') found3 = false;  //if length not equal then not same

	if (found3) {
		return (void*)calculator;
	}


	//for settings
	bool found4 = true;
	int i4 = 0;

	const char* target4 = "Settings";

	while (appName[i4] != '\0' && target4[i4] != '\0') {

		if (appName[i4] != target4[i4]) {
			found4 = false;
			break;
		}
		i4++;
	}

	if (appName[i4] != '\0' || target4[i4] != '\0') found4
		= false;  //if length not equal then not same

	if (found4) {
		return (void*)settings;
	}


	return nullptr;


} //getapp

void ApplicationManager::displayAll() const {

	//file explorer
	cout << "FILE EXPLORER: " << endl;

	if (fileExplorer->isRunning) {
		cout << "Running" << endl;
	}

	else {
		cout << "Not Running" << endl;
	}

	cout << "Storage Size: " << fileExplorer->getFile()->getSize() << " MB" << endl;

	cout << "RAM Requirement: " << 50 << " MB";


	//recycle bin
	cout << "RECYCLE BIN: " << endl;

	if (recycleBin->isRunning) {
		cout << "Running" << endl;
	}

	else {
		cout << "Not Running" << endl;
	}

	cout << "Storage Size: " << recycleBin->getFile()->getSize() << " MB" << endl;

	cout << "RAM Requirement: " << 30 << " MB" << endl;

	cout << endl;


	//calculator
	cout << "CALCULATOR: " << endl;

	if (calculator->isRunning) {
		cout << "Running" << endl;
	}

	else {
		cout << "Not Running" << endl;
	}

	cout << "Storage Size: " << calculator->getFile()->getSize() << " MB" << endl;

	cout << "RAM Requirement: " << 40 << " MB" << endl;;

	cout << endl;

	//settings
	cout << "SETTINGS: " << endl;

	if (settings->isRunning) {
		cout << "Running" << endl;
	}

	else {
		cout << "Not Running" << endl;
	}

	cout << "Storage Size: " << settings->getFile()->getSize() << " MB" << endl;

	cout << "RAM Requirement: " << 20 << " MB" << endl;

} //display


//===========================================destructor==============================================

ApplicationManager::~ApplicationManager() {
	delete[] fileExplorer;
	delete[] recycleBin;
	delete[] calculator;
	delete[] settings;
}



/////////////////////////////////////////CALCULATOR///////////////////////////////////////////////////////

//============================constructor========================


Calculator::Calculator() {
	isRunning = false;
	historyCount = 0;
	maxHistory = 10;  // initial capacity
	history = new char* [maxHistory];
	memoryCount = 0;
	memory = new double[memoryCount];
}

//=========================helper function=======================

char* Calculator::intToChar(int num) const {

	int temp = num;
	int digits = 0;

	if (num == 0) digits = 1;

	else {

		while (temp > 0) {
			temp /= 10;
			digits++;
		}
	}

	char* str = new char[digits + 1]; //allocating memory

	str[digits] = '\0';


	//using reverse loop becuase we want it to right ot left not the otehr wway around
	for (int i = digits - 1; i >= 0; i--) {
		str[i] = (num % 10) + '0';  //so that char are sotred instead of ascii values
		num /= 10;
	}

	return str;

} //int to char



//========================functions==============================

File* Calculator::getFile() const {
	return file;
}


double Calculator::add(double a, double b) {

	if (!isRunning) return 0.0;

	double result = a + b;
	double lastResult = result;


	//converting into int so counting digits is easy
	int inta = (int)a;
	int intb = (int)b;
	int intresult = (int)result;

	char* cha = intToChar(inta);   //calling helper funtion
	char* chb = intToChar(intb);
	char* chresult = intToChar(intresult);

	int la = 0;
	int lb = 0;
	int lresult = 0;

	//findind lengths of all char strings
	while (cha[la] != '\0') {
		la++;
	}

	while (chb[lb] != '\0') {
		lb++;
	}

	while (chresult[lresult] != '\0') {
		lresult++;
	}

	int totalLength = la + 1 + lb + 1 + lresult;  //one for + and one for equal

	char* final = new char[totalLength + 1];

	int k = 0;

	// copying a
	for (int i = 0; i < la; i++) {
		final[k] = cha[i];
		k++;
	}

	final[k] = '+';
	k++;

	// copying b
	for (int i = 0; i < lb; i++) {
		final[k] = chb[i];
		k++;
	}

	final[k] = '=';
	k++;

	// copying result
	for (int i = 0; i < lresult; i++) {
		final[k] = chresult[i];
		k++;
	}


	final[k] = '\0';

	history[historyCount] = final;
	historyCount++;

	delete[] cha;
	delete[] chb;
	delete[] chresult;

	return (double)result;

} //add


double Calculator::subtract(double a, double b) {

	if (!isRunning) return 0.0;

	double result = a - b;
	double lastResult = result;


	//converting into int so counting digits is easy
	int inta = (int)a;
	int intb = (int)b;
	int intresult = (int)result;

	char* cha = intToChar(inta);   //calling helper funtion
	char* chb = intToChar(intb);
	char* chresult = intToChar(intresult);

	int la = 0;
	int lb = 0;
	int lresult = 0;

	//findind lengths of all char strings
	while (cha[la] != '\0') {
		la++;
	}

	while (chb[lb] != '\0') {
		lb++;
	}

	while (chresult[lresult] != '\0') {
		lresult++;
	}

	int totalLength = la + 1 + lb + 1 + lresult;  //one for + and one for equal

	char* final = new char[totalLength + 1];

	int k = 0;

	// copying a
	for (int i = 0; i < la; i++) {
		final[k] = cha[i];
		k++;
	}

	final[k] = '-';
	k++;

	// copying b
	for (int i = 0; i < lb; i++) {
		final[k] = chb[i];
		k++;
	}

	final[k] = '=';
	k++;

	// copying result
	for (int i = 0; i < lresult; i++) {
		final[k] = chresult[i];
		k++;
	}


	final[k] = '\0';

	history[historyCount] = final;
	historyCount++;

	delete[] cha;
	delete[] chb;
	delete[] chresult;

	return (double)result;
} //subtract


double Calculator::multiply(double a, double b) {
	\

		if (!isRunning) return 0.0;

	double result = a * b;
	double lastResult = result;


	//converting into int so counting digits is easy
	int inta = (int)a;
	int intb = (int)b;
	int intresult = (int)result;

	char* cha = intToChar(inta);   //calling helper funtion
	char* chb = intToChar(intb);
	char* chresult = intToChar(intresult);

	int la = 0;
	int lb = 0;
	int lresult = 0;

	//findind lengths of all char strings
	while (cha[la] != '\0') {
		la++;
	}

	while (chb[lb] != '\0') {
		lb++;
	}

	while (chresult[lresult] != '\0') {
		lresult++;
	}

	int totalLength = la + 1 + lb + 1 + lresult;  //one for + and one for equal

	char* final = new char[totalLength + 1];

	int k = 0;

	// copying a
	for (int i = 0; i < la; i++) {
		final[k] = cha[i];
		k++;
	}

	final[k] = '*';
	k++;

	// copying b
	for (int i = 0; i < lb; i++) {
		final[k] = chb[i];
		k++;
	}

	final[k] = '=';
	k++;

	// copying result
	for (int i = 0; i < lresult; i++) {
		final[k] = chresult[i];
		k++;
	}


	final[k] = '\0';

	history[historyCount] = final;
	historyCount++;

	delete[] cha;
	delete[] chb;
	delete[] chresult;

	return (double)result;


} //multiply


double Calculator::divide(double a, double b) {

	if (!isRunning) return 0.0;

	if (b == 0) {
		cout << "Denominator cannot be zero." << endl;
		return 0.0;
	}

	double result = a / b;
	double lastResult = result;


	//converting into int so counting digits is easy
	int inta = (int)a;
	int intb = (int)b;
	int intresult = (int)result;

	char* cha = intToChar(inta);   //calling helper funtion
	char* chb = intToChar(intb);
	char* chresult = intToChar(intresult);

	int la = 0;
	int lb = 0;
	int lresult = 0;

	//findind lengths of all char strings
	while (cha[la] != '\0') {
		la++;
	}

	while (chb[lb] != '\0') {
		lb++;
	}

	while (chresult[lresult] != '\0') {
		lresult++;
	}

	int totalLength = la + 1 + lb + 1 + lresult;  //one for + and one for equal

	char* final = new char[totalLength + 1];

	int k = 0;

	// copying a
	for (int i = 0; i < la; i++) {
		final[k] = cha[i];
		k++;
	}

	final[k] = '/';
	k++;

	// copying b
	for (int i = 0; i < lb; i++) {
		final[k] = chb[i];
		k++;
	}

	final[k] = '=';
	k++;

	// copying result
	for (int i = 0; i < lresult; i++) {
		final[k] = chresult[i];
		k++;
	}


	final[k] = '\0';

	history[historyCount] = final;
	historyCount++;

	delete[] cha;
	delete[] chb;
	delete[] chresult;

	return (double)result;

} //divide


double Calculator::power(double base, double exp) {

	if (!isRunning) return 0.0;

	if (exp < 0) {
		cout << "Exponent cannot be negative." << endl;
		return 0.0;
	}

	if (exp == 0) return 1.0;

	double result = 1;

	int intexp = (int)exp;

	for (int i = 0; i < intexp; i++) {
		result *= base;
	}

	double lastResult = result;

	int intbase = (int)base;
	int intresult = (int)result;

	char* chbase = intToChar(intbase);
	char* chexp = intToChar(intexp);
	char* chresult = intToChar(intresult);

	int lbase = 0;
	int lexp = 0;
	int lresult = 0;

	while (chbase[lbase] != '\0') {
		lbase++;
	}

	while (chexp[lexp] != '\0') {
		lexp++;
	}

	while (chresult[lresult] != '\0') {
		lresult++;
	}

	int totalLength = lbase + 1 + lexp + 1 + lresult;

	char* final = new char[totalLength + 1];

	int k = 0;

	// copying a
	for (int i = 0; i < lbase; i++) {
		final[k] = chbase[i];
		k++;
	}

	final[k] = '^';
	k++;

	// copying b
	for (int i = 0; i < lexp; i++) {
		final[k] = chexp[i];
		k++;
	}

	final[k] = '=';
	k++;

	// copying result
	for (int i = 0; i < lresult; i++) {
		final[k] = chresult[i];
		k++;
	}


	final[k] = '\0';

	history[historyCount] = final;
	historyCount++;

	delete[] chbase;
	delete[] chexp;
	delete[] chresult;

	return (double)result;

} //power

double Calculator::squareRoot(double value) {

	if (!isRunning) return 0.0;

	if (value < 0) {
		cout << "For square root calculation, value cannot be negative." << endl;
		return 0.0;
	}

	if (value == 0) return 0.0;

	if (value == 1) return 1.0;

	double lowRange = 0;     //range will be between 0 and the number itself
	double highRange = value;
	double mid;

	for (int i = 0; i < 40; i++) {     //hardcoded 40 iterations
		mid = (lowRange + highRange) / 2;

		if (mid * mid == value) break;   //mid is the answer

		else if (mid * mid < value) {
			lowRange = mid;      //decreasing the range
		}

		else {
			highRange = mid;    //inreasing the range
		}
	}

	double result = mid;

	int intval = (int)value;
	int intresult = (int)result;

	char* chval = intToChar(intval);
	char* chresult = intToChar(intresult);

	int lval = 0;
	int lresult = 0;

	while (chval[lval] != '\0') {
		lval++;
	}

	while (chresult[lresult] != '\0') {
		lresult++;
	}

	int totalLength = 5 + lval + 1 + lresult;    //sqrt(val)




	char* final = new char[totalLength + 1];

	int k = 0;

	final[k] = 's';
	k++;
	final[k] = 'q';
	k++;
	final[k] = 'r';
	k++;
	final[k] = 't';
	k++;
	final[k] = '(';
	k++;

	for (int i = 0; i < lval; i++) {
		final[k] = chval[i];
		k++;
	}


	final[k] = ')';
	k++;


	final[k] = '=';
	k++;

	// copying result
	for (int i = 0; i < lresult; i++) {
		final[k] = chresult[i];
		k++;
	}


	final[k] = '\0';

	history[historyCount] = final;
	historyCount++;

	delete[] chval;
	delete[] chresult;

	return (double)result;


} //square root


//=================================variable methods====================================


void Calculator::storeVariable(char name, double value) {

	if (!isRunning) return;

	int index = -1;

	if (name >= 'A' && name <= 'Z') index = name - 'A';

	else if (name >= 'a' && name <= 'z') index = name - 'a';

	else return;

	variables[index] = value;

} //store variables


double Calculator::recallVariable(char name) const {

	if (!isRunning) return 0.0;

	int index = -1;


	if (name >= 'A' && name <= 'Z') index = name - 'A';

	else if (name >= 'a' && name <= 'z') index = name - 'a';

	else return 0.0;

	return variables[index];

} //recall variables


//===========================statistical methods=====================================

double Calculator::getMean() const {

	if (!isRunning || memoryCount == 0) return 0.0;

	double sum = 0.0;

	for (int i = 0; i < memoryCount; i++) {
		sum += memory[i];
	}

	double mean = sum / memoryCount;

	return mean;

}  //get mean


double Calculator::getSum() const {
	if (!isRunning || memoryCount == 0) return 0.0;

	double sum = 0.0;

	for (int i = 0; i < memoryCount; i++) {
		sum += memory[i];
	}

	return (double)sum;
} //get sum


double Calculator::getMin() const {

	if (!isRunning || memoryCount == 0) return 0.0;

	double min = memory[0];

	for (int i = 0; i < memoryCount; i++) {

		if (memory[i] < min) {
			min = memory[i];
		}
	}
	return min;
} //get min


double Calculator::getMax() const {

	if (!isRunning || memoryCount == 0) return 0.0;

	double max = memory[0];

	for (int i = 0; i < memoryCount; i++) {

		if (memory[i] > max) {
			max = memory[i];
		}
	}
	return max;
} //get max

//==========================history and export===================================

bool Calculator::exportHistory(const char* filename, Storage* storage) {

	if (!isRunning) return false;

	char content[1000];    //1000 chosen as appropriate length for string
	int index = 0;

	for (int i = 0; i < historyCount; i++) {

		int j = 0;
		while (history[i][j] != '\0') {
			content[index] = history[i][j];
			index++;
			j++;
		}

		content[index] = '\n';
		index++;
	}

	content[index] = '\0';

	File historyFile(filename, content, 1); //making object and 1 is becuase of 1mb

	return storage->saveFile(historyFile);

} //export history


void Calculator::printHistory() const {

	if (!isRunning) return;

	for (int i = 0; i < historyCount; i++) {
		int j = 0;
		while (history[i][j] != '\0') {
			cout << history[i][j];;
			j++;
		}
		cout << endl;

	}
} //print history

int Calculator::getMemoryCount() const {

	if (!isRunning) return 0;

	return memoryCount;
} //get memory count


//==================================required operators=======================================

double Calculator::operator()(double a, char op, double b) {

	if (!isRunning) return 0.0;


	//if (op == '+') { 
	//	double result = add(a, b);

	//	if (memoryCount < maxMemory) {
	//		memory[memoryCount] = result;
	//		memoryCount++;
	//	}
	//	return result;
	//}

	//else if (op == '-') { 
	//	double result=subtract(a, b); 
	//	
	//	if (memoryCount < maxMemory) {
	//		memory[memoryCount] = result;
	//		memoryCount++;
	//	}
	//	return result;
	//}

	//else if (op == '*') {
	//	double result=multiply(a, b); 
	//	
	//	if (memoryCount < maxMemory) {
	//		memory[memoryCount] = result;
	//		memoryCount++;
	//	}
	//	return result;
	//}

	//else if (op == '/') { 
	//	double result=divide(a, b); 
	//	
	//	if (memoryCount < maxMemory) {
	//		memory[memoryCount] = result;
	//		memoryCount++;
	//	}
	//	return result;

	//}

	//else if (op == '^') { 
	//	double result=power(a, b);
	//	
	//	if (memoryCount < maxMemory) {
	//		memory[memoryCount] = result;
	//		memoryCount++;
	//	}
	//	return result;
	//}


	//return 0.0;

	double result = 0.0;

	switch (op) {
	case '+': {
		result = add(a, b); break;
	}

	case '-': {
		result = subtract(a, b); break;
	}

	case '*': {
		result = multiply(a, b); break;
	}

	case '/': {
		result = divide(a, b); break;
	}
	case '^': {
		result = power(a, b); break;
	}

	default: {
		return 0.0;
	}

	} //switch

	if (memoryCount < maxMemory) {
		memory[memoryCount] = result;
		memoryCount++;
	}

	return result;

} //()


double Calculator::operator[](char varName) const {


	if (!isRunning) return 0.0;

	return recallVariable(varName);  //since same as recall variable
} //[]


//========================================destrcutor==========================================

//Calculator::~Calculator() {
//
//	/*if (history != nullptr) {
//		for (int i = 0; i < historyCount; i++) {
//			delete[] history[i];  
//		}
//		delete[] history;       
//		history = nullptr;
//	}*/
//
//	delete[] memory;
//}


////////////////////////////////////////////////////COMPUTER/////////////////////////////////////////////////


//=================constructor===================
Computer::Computer(int storageMB, int ramMB) {

	storage = new Storage(storageMB);
	ram = new RAM(ramMB);

	apps = new ApplicationManager(storage, ram);

}


//========================getters===============================

FileExplorer* Computer::getFileExplorer() const {
	return (FileExplorer*)apps->getApp("FileExplorer");
}

RecycleBin* Computer::getRecycleBin() const {
	return (RecycleBin*)apps->getApp("RecycleBin");
}

Calculator* Computer::getCalculator() const {
	return (Calculator*)apps->getApp("Calculator");
}

Settings* Computer::getSettings() const {
	return (Settings*)apps->getApp("Settings");
}


//=======================functions=======================


//============================application manager============================
bool Computer::launchApp(const char* appName) {
	return apps->launchApp(appName);    //forwarding it to the application manager where these functions are written
} //launch

bool Computer::closeApp(const char* appName) {
	return apps->closeApp(appName);
} //close

void Computer::displaySystemStatus() const {

	cout << "Available Space: " << storage->getAvailableSpace() << " MB" << endl;
	cout << "Available RAM: " << ram->getAvailableMemory() << " MB" << endl;

	apps->displayAll();

} //display


//==========================================file explorer====================================================

bool Computer::createFile(const char* name, const char* content, int size) {

	FileExplorer* fileobj = (FileExplorer*)apps->getApp("FileExplorer");   //creating object first

	if (fileobj == nullptr || !fileobj->isRunning) return false;  //checking for availability

	return fileobj->createFile(name, content, size);
} //create file


bool Computer::deleteFile(const char* name) {

	FileExplorer* fileobj = (FileExplorer*)apps->getApp("FileExplorer");

	RecycleBin* binobj = (RecycleBin*)apps->getApp("RecycleBin");

	if (fileobj == nullptr || !fileobj->isRunning) return false;

	if (binobj != nullptr && binobj->isRunning) {
		return fileobj->deleteFile(name, binobj);
	}

	else {
		return fileobj->deleteFile(name, nullptr); //if rb not present then delete permanently
	}

} //delete file


//===========================================recycle bin=====================================

void Computer::listFiles() const {

	FileExplorer* fileobj = (FileExplorer*)apps->getApp("FileExplorer");

	if (fileobj == nullptr || !fileobj->isRunning) return;

	fileobj->listFiles();

} //listfile


bool Computer::restoreFile(const char* name) {
	RecycleBin* binobj = (RecycleBin*)apps->getApp("RecycleBin");

	if (binobj == nullptr || !binobj->isRunning) return false;

	binobj->restoreFile(name);

	return true;

} //restore file


void Computer::emptyRecycleBin() {

	RecycleBin* binobj = (RecycleBin*)apps->getApp("RecycleBin");

	if (binobj == nullptr || !binobj->isRunning) return;

	binobj->emptyBin();

} //empty


void Computer::listRecycleBin() const {

	RecycleBin* binobj = (RecycleBin*)apps->getApp("RecycleBin");

	if (binobj == nullptr || !binobj->isRunning) return;

	binobj->listBin();

}


//====================================calculator==========================================

double Computer::calculate(double a, char op, double b) {

	Calculator* calc = (Calculator*)apps->getApp("Calculator");

	if (calc == nullptr || !calc->isRunning) return 0.0;



	return (*calc)(a, op, b); //calling the () fun

}  //calculate


bool Computer::exportCalculations(const char* filename) {

	Calculator* calc = (Calculator*)apps->getApp("Calculator");

	if (calc == nullptr || !calc->isRunning) return false;

	return calc->exportHistory(filename, storage);

}  //export calcualtions

//==================================settings========================================

bool Computer::setSetting(const char* key, const char* value) {

	Settings* s = (Settings*)apps->getApp("Settings");

	if (s == nullptr || !s->isRunning) return false;

	return s->setSetting(key, value);
} //sete settings

const char* Computer::getSetting(const char* key) const {

	Settings* s = (Settings*)apps->getApp("Settings");

	if (s == nullptr || !s->isRunning) return nullptr;

	return s->getSetting(key);
} //get settings

//==============================operators========================

bool Computer::operator>(const Computer& other) const {
	int free = ram->getAvailableMemory();
	int otherfree = other.ram->getAvailableMemory();

	return (free > otherfree);

} //>

Computer& Computer::operator+=(const char* appName) {
	launchApp(appName);
	return *this;

} //+=

Computer& Computer::operator-=(const char* appName) {
	closeApp(appName);
	return *this;

} //-=

//=======================destructor====================================
Computer::~Computer() {
	delete apps;
	delete ram;
	delete storage;
}



//////////////////////////////////////////////////////////FILE/////////////////////////////////////////////////////

File::File(const char* name, const char* content, int size) {
	this->size = size;

	int l1 = 0;

	while (name[l1] != '\0') {
		l1++;
	}

	this->name = new char[l1 + 1];

	for (int i = 0; i < l1; i++) {       //deep copy of char string after allocaton of memory
		this->name[i] = name[i];
	}
	this->name[l1] = '\0';


	int l2 = 0;

	while (content[l2] != '\0') {
		l2++;
	}

	this->content = new char[l2 + 1];

	for (int i = 0; i < l2; i++) {       //deep copy of char string after allocaton of memory
		this->content[i] = content[i];
	}
	this->content[l2] = '\0';

} //paramter constructor


File::File(const File& other) {
	this->size = other.size;

	int l1 = 0;

	while (other.name[l1] != '\0') {
		l1++;
	}

	this->name = new char[l1 + 1];

	for (int i = 0; i < l1; i++) {       //deep copy of char string after allocaton of memory
		this->name[i] = other.name[i];
	}
	this->name[l1] = '\0';


	int l2 = 0;

	while (other.content[l2] != '\0') {
		l2++;
	}

	this->content = new char[l2 + 1];

	for (int i = 0; i < l2; i++) {       //deep copy of char string after allocaton of memory
		this->content[i] = other.content[i];
	}
	this->content[l2] = '\0';

} //copy


//===================getters=========================

const char* File::getName() const {
	return name;
}

const char* File::getContent() const {
	return content;
}

int File::getSize() const {
	return size;
}


//========================functions===========================

File File::operator+(const File& other) const {

	int l1 = 0;
	int l2 = 0;

	while (this->name[l1] != '\0') {
		l1++;
	}

	while (other.name[l2] != '\0') {
		l2++;
	}

	char* newName = new char[l1 + 1 + l2 + 1];   //to create the name with _ in it combining the names and one more for '\0'

	for (int i = 0; i < l1; i++) {
		newName[i] = this->name[i];
	}

	newName[l1] = '_';

	for (int i = 0; i < l2; i++) {
		newName[l1 + 1 + i] = other.name[i];
	}

	newName[l1 + l2 + 1] = '\0';

	//for content now
	int l3 = 0;
	int l4 = 0;

	while (this->content[l3] != '\0') {
		l3++;
	}

	while (other.content[l4] != '\0') {
		l4++;
	}

	char* newContent = new char[l3 + l4 + 1];

	for (int i = 0; i < l3; i++) {
		newContent[i] = this->content[i];
	}

	for (int i = 0; i < l4; i++) {
		newContent[l3 + i] = other.content[i];
	}
	newContent[l3 + l4] = '\0';

	//for size
	int newSize = this->size + other.size;

	File final(newName, newContent, newSize);  //creating new object with the new values

	delete[] newName;
	delete[] newContent;

	return final;

} //+op function


bool File::operator<(const File& other) const {

	if (this->size < other.size) return true;

	else return false;
}


//======================destructor======================

File::~File() {
	delete[]name;
	delete[]content;

} //destructor




/////////////////////////////////////////////////FILE EXPLORER///////////////////////////////////////////////////////////////

//========================== = constructor==================== =

FileExplorer::FileExplorer(Storage* storage) {
	this->storage = storage;
	isRunning = false;
}

//==========================fucntions========================================

File* FileExplorer::getFile() const {
	return file;
}


bool FileExplorer::createFile(const char* name, const char* content, int size) {

	if (isRunning == false) return false;

	File newFile(name, content, size); //creating new file object

	return storage->saveFile(newFile);
} //create file


bool FileExplorer::deleteFile(const char* name, RecycleBin* bin) {

	if (!isRunning || bin == nullptr) return false;

	File* deleteFile = storage->getFile(name);

	if (!deleteFile) return false;  //incase file not found

	if (bin->isRunning || bin != nullptr) {  //adding to bin
		bin->addFile(*deleteFile);
	}

	storage->deleteFile(name);   //deleting from storage

	return true;
} //delete file


void FileExplorer::listFiles() const {

	if (isRunning) {

		File** files = storage->getFiles();
		int count = storage->getFileCount();

		for (int i = 0; i < count; i++) {
			cout << files[i]->getName() << endl;
		}

	}
} //list files


File* FileExplorer::viewFile(const char* name) const {
	if (!isRunning) return nullptr;

	return storage->getFile(name);
} //view file


//bool FileExplorer::deleteFile(const char* name, RecycleBin* bin) {
//
//}


/////////////////////////////////////////////////////////////RAM////////////////////////////////////////

//========================contructor=======================

RAM::RAM(int capacityMB) {
	this->capacity = capacityMB;
	this->usedMemory = 0;
}


//=====================functions==========================

bool RAM::allocate(int sizeMB) {

	if (sizeMB <= (capacity - usedMemory)) {
		usedMemory += sizeMB;
		return true;
	}

	else return false;
} //allocate

void RAM::deallocate(int sizeMB) {
	usedMemory -= sizeMB;

	if (usedMemory < 0) {
		usedMemory = 0;
	}

} //deallocate


int RAM::getAvailableMemory() const {
	return capacity - usedMemory;
} //available memory


////////////////////////////////////////////////////////////////////////RECYCLE BIN///////////////////////////////////////////////////////////////

//=============================constructor====================================

RecycleBin::RecycleBin(Storage* storage) {

	this->storage = storage;
	maxFiles = 5;
	fileCount = 0;

	deletedFiles = new File * [maxFiles];

	isRunning = false;



}

//=======================functions==============================

File* RecycleBin::getFile() const {
	return file;
}

void RecycleBin::addFile(const File& file) {
	if (!isRunning) {
		cout << "Recycle bin not running" << endl;
		return;
	}

	if (fileCount > -maxFiles) {

		int newSize = maxFiles * 2;   //doubling capacity if full
		File** arr = new File * [newSize];

		for (int i = 0; i < fileCount; i++) {
			arr[i] = deletedFiles[i];
		}

		delete[] deletedFiles;
		deletedFiles = arr;
		maxFiles = newSize;


	}

	deletedFiles[fileCount] = new File(file);  //adding copy of file as last element

	fileCount++;

} //add file


bool RecycleBin::restoreFile(const char* filename) {

	if (!isRunning) return false;

	//searching for file required
	int index = -1;

	for (int i = 0; i < fileCount; i++) {

		const char* name = deletedFiles[i]->getName();

		int j = 0;
		bool found = true;

		while (name[j] != '\0' && filename[j] != '\0') {
			if (name[j] != filename[j]) {
				found = false;
				break;
			}
			j++;
		}

		if (name[j] != '\0' || filename[j] != '\0') found = false;

		if (found) {
			index = i;
			break;
		}
	}

	if (index == -1) return false;

	File* restore = deletedFiles[index];

	bool save = storage->saveFile(*restore); //saving copy of file to storage

	if (!save) return false;

	delete deletedFiles[index];   //deleting from bin

	for (int i = 0; i < fileCount; i++) {   //shifting array to left so theres no gap
		deletedFiles[i] = deletedFiles[i + 1];
	}

	fileCount--;

	return true;
} //restore file


void RecycleBin::emptyBin() {

	if (!isRunning) return;

	for (int i = 0; i < fileCount; i++) {
		delete deletedFiles[i];
		deletedFiles[i] = nullptr;
	}

	fileCount = 0;

} //empty bin

void RecycleBin::listBin() const {

	if (!isRunning) return;

	if (fileCount == 0) {
		cout << "Recycle bin is empty" << endl;
		return;
	}

	cout << "Files in Recycle bin: " << endl;

	for (int i = 0; i < fileCount; i++) {
		cout << deletedFiles[i]->getName() << endl;
	}

} //list

int RecycleBin::getFileCount() const {
	return fileCount;
}

void RecycleBin::operator-(const char* filename) {

	if (!isRunning) return;

	storage->deleteFile(filename);  //deleting from storage

	for (int i = 0; i < fileCount; i++) {
		const char* name = deletedFiles[i]->getName();
		bool found = true;
		int j = 0;

		while (name[j] != '\0' && filename[j] != '\0') {
			if (name[j] != filename[j]) {
				found = false;
				break;
			}
			j++;
		}
		if (name[j] != '\0' || filename[j] != '\0') found = false; // length check

		if (found) {
			delete deletedFiles[i];

			for (int k = i; k < fileCount - 1; k++) {  //shifting array after deleting
				deletedFiles[k] = deletedFiles[k + 1];
			}

			deletedFiles[fileCount - 1] = nullptr;
			fileCount--;
			return;
		}
	}

} //fn

//==========================destructor=============================

//RecycleBin::~RecycleBin() {
//
//	if (deletedFiles != nullptr) {
//
//		for (int i = 0; i < fileCount; i++) {
//			delete deletedFiles[i];   
//		}
//
//		delete[] deletedFiles;
//	}
//}


/////////////////////////////////////////////SETTINGS//////////////////////////////////////////////////////

//========================================== = constructor========================================

Settings::Settings() {

	maxPairs = 5;
	count = 5;
	name = new char[9];
	diskSize = 5;
	ramRequired = 20;
	isRunning = false;
	file = nullptr;

	const char tempName[9] = { 'S','e','t','t','i','n','g','s','\0' };

	for (int i = 0; i < 9; i++) {
		name[i] = tempName[i];
	}

	keys = new char* [maxPairs];
	values = new char* [maxPairs];


	const char* defaultKeys[5] = { "font_size", "font_family", "theme", "language", "date_format" };
	const char* defaultValues[5] = { "12", "Arial", "light", "English", "DD/MM/YYYY" };

	for (int i = 0; i < maxPairs; i++) {
		int lkey = 0;
		while (defaultKeys[i][lkey] != '\0') lkey++;
		keys[i] = new char[lkey + 1];
		for (int j = 0; j <= lkey; j++) {  // include \0
			keys[i][j] = defaultKeys[i][j];
		}


		int lval = 0;
		while (defaultValues[i][lval] != '\0') lval++;
		values[i] = new char[lval + 1];
		for (int j = 0; j <= lval; j++) {  // include \0
			values[i][j] = defaultValues[i][j];
		}
	}

} //constructor

//=========================================functions============================================

File* Settings::getFile() const {
	return file;
}


bool Settings::setSetting(const char* key, const char* value) {

	if (!isRunning) return false;

	int index = -1;

	for (int i = 0; i < count; i++) {
		bool found = true;
		int j = 0;

		while (keys[i][j] != '\0' && key[j] != '\0') {
			if (keys[i][j] != key[j]) {
				found = false;
				break;
			}
			j++;
		}

		if (keys[i][j] != '\0' || key[j] != '\0') found = false;

		if (found == true) {
			index = i;
			break;
		}
	}

	if (index == -1) return false;   //key not found in array

	delete[] values[index];  //deelting the old value

	int lval = 0;
	while (value[lval] != '\0') {
		lval++;
	}

	values[index] = new char[lval + 1];

	for (int k = 0; k <= lval; k++) {  //= for \0
		values[index][k] = value[k];
	}

	return true;
} //set setting

const char* Settings::getSetting(const char* key) const {

	if (!isRunning) return nullptr;


	for (int i = 0; i < count; i++) {
		bool found = true;
		int j = 0;

		while (keys[i][j] != '\0' && key[j] != '\0') {
			if (keys[i][j] != key[j]) {
				found = false;
				break;
			}
			j++;
		}

		if (keys[i][j] != '\0' || key[j] != '\0') found = false;

		if (found == true) {
			return values[i];
		}
	}

	return nullptr;
} //get setting


void Settings::displaySettings() const {
	if (!isRunning) return;

	for (int i = 0; i < count; i++) {

		int j = 0;
		while (keys[i][j] != '\0') {
			cout << keys[i][j];
			j++;
		}

		cout << endl;

		j = 0;
		while (values[i][j] != '\0') {
			cout << values[i][j];
			j++;
		}

		cout << endl;
	}
} //display settings


bool Settings::resetToDefault() {
	if (!isRunning) return false;

	const char* defaultValues[5] = { "12", "Arial", "light", "English", "DD/MM/YYYY" };

	for (int i = 0; i < count; i++) {

		delete[] values[i];  //deleting the old value

		int length = 0;
		while (defaultValues[i][length] != '\0') length++;

		values[i] = new char[length + 1];

		for (int j = 0; j <= length; j++) {   //equal for \0
			values[i][j] = defaultValues[i][j];
		}
	}

	return true;

} //reset to default



///////////////////////////////////////////////////////////////STORAGE/////////////////////////////////////////////////////////////


//==============constructors===================

Storage::Storage(int capacityMB) {
	this->capacity = capacityMB;
	usedSpace = 0;
	fileCount = 0;
	maxFiles = 10;

	files = new File * [maxFiles];
}

//===================functions======================

bool Storage::saveFile(const File& file) {



	if (file.getSize() > capacity - usedSpace) return false;   //if file size is more than available space

	if (fileCount >= maxFiles) {
		File** arr = new File * [maxFiles * 2];  //doubling array if slots full

		for (int i = 0; i < fileCount; i++) {
			arr[i] = files[i];
		}

		delete[] files; //deleting old array


		files = arr;   //ptr towards new array
		maxFiles *= 2;
	}

	files[fileCount] = new File(file);  //adding the deep copy of file in the array

	usedSpace += file.getSize();
	fileCount++;

	return true;

} //savefile

bool Storage::deleteFile(const char* name) {

	bool found;
	for (int i = 0; i < fileCount; i++) {

		const char* fileName = files[i]->getName();
		found = true;
		int j = 0;

		while (fileName[j] != '\0' || name[j] != '\0') {

			if (fileName[j] != name[j]) {
				found = false;
				break;
			}
			j++;
		}

		if (found == true) {
			usedSpace -= files[i]->getSize();
			delete files[i];

			for (int k = i; k < fileCount - 1; k++) {   //shifting the elements in the array
				files[k] = files[k + 1];
			}

			fileCount--;
			return true;
		}

	}

	return false;



} //delete file

File* Storage::getFile(const char* name) const {

	bool found;
	for (int i = 0; i < fileCount; i++) {

		const char* fileName = files[i]->getName();
		found = true;
		int j = 0;

		while (fileName[j] != '\0' || name[j] != '\0') {

			if (fileName[j] != name[j]) {
				found = false;
				break;
			}
			j++;
		}


		if (found == true) {
			return files[i];                    //returning pointer
		}


	}

	return nullptr;            //returning nullptr of not found

} //getfile


int Storage::getAvailableSpace() const {
	return capacity - usedSpace;
} //available space

bool Storage::isFull() const {

	int space = capacity - usedSpace;

	if (space == 0) return true;

	else return false;

} //isfull


File** Storage::getFiles() const {
	return files;
}

int Storage::getFileCount() const {
	return fileCount;
}