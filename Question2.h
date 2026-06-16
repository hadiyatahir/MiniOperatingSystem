#pragma once
#ifndef QUESTION2_H
#define QUESTION2_H

class ApplicationManager;
class Calculator;
class Computer;
class File;
class FileExplorer;
class RAM;
class RecycleBin;
class Settings;
class Storage;




class ApplicationManager {

private:
	FileExplorer* fileExplorer;
	RecycleBin* recycleBin;
	Calculator* calculator;
	Settings* settings;
	Storage* storage;
	RAM* ram;

public:

	ApplicationManager(Storage* storage, RAM* ram);

	bool launchApp(const char* appName);
	bool closeApp(const char* appName);
	bool isRunning(const char* appName) const;
	void* getApp(const char* appName) const;
	void displayAll() const;

	~ApplicationManager();

};   //applicationmanager


class Calculator {

private:
	File* file;

	char** history; // dynamic array of calculation strings
	int historyCount;
	int maxHistory;
	double variables[26];  // A maps to index 0, Z to index 25
	double* memory;  // dynamic array of stored results
	int memoryCount;
	int maxMemory;
	char* name; // = "Calculator"
	int diskSize; // = 15
	int ramRequired; // = 40

public:

	File* getFile() const;
	bool isRunning;

	Calculator(); //constructor

	char* intToChar(int num) const; //helper fucntion

	double add(double a, double b);
	double subtract(double a, double b);
	double multiply(double a, double b);
	double divide(double a, double b);
	double power(double base, double exp);
	double squareRoot(double value);


	//variable methods
	void storeVariable(char name, double value);
	double recallVariable(char name) const;

	//statistical methods
	double getMean() const;
	double getSum() const;
	double getMin() const;
	double getMax() const;

	//history and export
	bool exportHistory(const char* filename, Storage* storage);
	void printHistory() const;
	int getMemoryCount() const;

	//required operators
	double operator()(double a, char op, double b);
	double operator[](char varName) const;

	//~Calculator();  //destructor

};  //calcualator


class Computer {

private:
	Storage* storage;
	RAM* ram;
	ApplicationManager* apps;

public:
	Computer(int storageMB, int ramMB);

	//getters
	FileExplorer* getFileExplorer() const;
	RecycleBin* getRecycleBin() const;
	Calculator* getCalculator() const;
	Settings* getSettings() const;

	//application manager
	bool launchApp(const char* appName);
	bool closeApp(const char* appName);
	void displaySystemStatus() const;

	//file explorer
	bool createFile(const char* name, const char* content, int size);
	bool deleteFile(const char* name);    //(recycle bin)
	void listFiles() const;

	//recycle bin
	bool restoreFile(const char* name);
	void emptyRecycleBin();
	void listRecycleBin() const;

	//calculator
	double calculate(double a, char op, double b);
	bool exportCalculations(const char* filename);

	//settings
	bool setSetting(const char* key, const char* value);
	const char* getSetting(const char* key) const;

	//operators
	bool operator>(const Computer& other) const;
	Computer& operator+=(const char* appName);
	Computer& operator-=(const char* appName);

	~Computer(); //destructor


};  //computer


class File {

private:
	char* name;
	char* content;
	int size;

public:
	File(const char* name, const char* content, int size);
	File(const File& other);

	const char* getName() const;
	const char* getContent() const;
	int getSize() const;

	File operator+(const File& other) const;
	bool operator<(const File& other) const;

	~File();

}; //file


class FileExplorer {

private:
	File* file;
	Storage* storage;
	char* name;      // = "FileExplorer"
	int diskSize;          // = 20
	int ramRequired;        // = 50

public:

	bool isRunning;  //this is public because test cases access it directly

	FileExplorer(Storage* storage);  //constructor

	File* getFile() const;

	bool createFile(const char* name, const char* content, int size);
	bool deleteFile(const char* name, RecycleBin* bin);
	void listFiles() const;
	File* viewFile(const char* name) const;

};  //file explorer


class RAM {

private:
	int capacity;  //total ram in mb
	int usedMemory;  //mb currently located

public:
	RAM(int capacityMB);

	bool allocate(int sizeMB);
	void deallocate(int sizeMB);
	int getAvailableMemory() const;

};  //ram


class RecycleBin {

private:
	File* file;  //for display fucntion in application manager
	File** deletedFiles; // dynamic array, starts at capacity 5
	int fileCount;
	int maxFiles;
	Storage* storage;
	char* name; // = "RecycleBin"
	int diskSize; // = 10
	int ramRequired; // = 30

public:
	bool isRunning;

	RecycleBin(Storage* storage); //constructor

	File* getFile() const;

	void addFile(const File& file);
	bool restoreFile(const char* filename);
	void emptyBin();
	void listBin() const;
	int getFileCount() const;

	void operator-(const char* filename);

	//~RecycleBin();

}; //recyclebin


class Settings {

private:
	File* file;

	char** keys; // dynamic array of setting keys
	char** values; // parallel array of setting values
	int count;
	int maxPairs;
	char* name; // = "Settings"
	int diskSize; // = 5
	int ramRequired; // = 20


public:

	bool isRunning;
	File* getFile() const;

	Settings();  //constructor

	bool setSetting(const char* key, const char* value);
	const char* getSetting(const char* key) const;
	void displaySettings() const;
	bool resetToDefault();


};  //settings


class Storage {

private:
	File** files;  //dynamic array of File pointers, initial capacity 10
	int capacity;  // total storage in MB
	int usedSpace;  // MB currently occupied
	int fileCount;  // number of files currently stored
	int maxFiles;   // current size of the files array

public:
	Storage(int capacityMB);

	bool saveFile(const File& file);
	bool deleteFile(const char* name);
	File* getFile(const char* name) const;
	int getAvailableSpace() const;
	bool isFull() const;

	File** getFiles() const;   //these getters for filexplorer list files function
	int getFileCount() const;


};  //storage





#endif // !Q2SUBMISSION_H
