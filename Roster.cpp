#include "Roster.h"

#include <cstdlib>
#include <fstream>
#include <cassert>

Roster::Roster() {
  // initialize to empty array

  this->numStudents = 0;
  for (int i=0; i<ROSTER_MAX; i++) {
    this->students[i] = NULL;
  }

}

void Roster::resetRoster() {
 // To avoid memory leaks:
  //  Recycle memory for all allocated students on roster
  
  while (this->numStudents > 0) {
    delete this->students[this->numStudents - 1];
    this->numStudents --;
  }

}

void Roster::addStudentsFromFile(std::string filename) {
  std::ifstream ifs; // the stream we will use for the input file
  ifs.open(filename);
  
  if (ifs.fail()) {
    std::cerr << "Could not open input file: "
	      << filename << std::endl;
    exit(2); 
  }

  // ifs is an instance of ifstream
  // ifstream inherits from istream, 
  //   i.e. ifs is-a istream

  this->addStudentsFromStream(ifs);

}

void Roster::addStudentsFromStream(std::istream &is) {

  this->resetRoster();

  std::string thisLine;
  // Try to read past the header line.
  getline(is,thisLine);
  if ( is.eof() || is.fail() ) {
    std::cerr << "Unable to read first line of input stream" << std::endl;
    exit(3);
  }

  getline(is,thisLine);
  while (  !is.eof() && !is.fail() ) {
    // If we get here, it means the most recent attempt to read succeeded!
    // So do something with thisLine
    
    Student *sPtr = new Student(thisLine);
    this->students[this->numStudents] = sPtr;
    this->numStudents++;
    
    // try to read another line
    getline(is,thisLine);
  } // end while

}

int Roster::getNumStudents() const { 
  return numStudents; 
}

Student Roster::getStudentAt(int index) const { 
 // return Student(-999,"Stubbi","Stubsdottir"); 
    return *students[index]; 
}

std::string Roster::toString() const {
  std::string result = "{\n";
  
  result += "STUB!!!!";   // @@@ RESTORE THIS 

  result += "}\n";
  return result;

}

void swap(Student *p1, Student *p2){
    Student temp = *p1;
    *p1 = *p2; 
    *p2 = temp; 
}

void Roster::sortByPerm() {
  // SELECTION SORT
    int min_idx;
    for(int i = 0; i < numStudents; i ++){
	min_idx = i;
	for(int j = i+1; j < numStudents; j++)
	    if(students[j]->getPerm() < students[i]->getPerm())
		min_idx = j;
	swap(students[i], students[min_idx]);
    } 
}

int Roster::indexOfMaxPermAmongFirstKStudents(int k) const {
  int max_idx;
  int max = students[0]->getPerm();
  if(k == 1) return 0; 
  for(int i = 0; i < k; i ++){
      if(students[i]->getPerm() > max){
          max_idx = i;
	  max = students[i]->getPerm();
      }
  }
  return max_idx; 
}

//void Roster::sortByPermHelper(int k) {
  // swaps max perm from [0..k-1] with elem [k-1]


  //int im = indexOfMaxPermAmongFirstKStudents(k);

  // now swap the pointers between index im and index k-1

  // THIS IS STILL A STUB !!!
  
//}
