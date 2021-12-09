#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

class Doctor;

class Patient
{
  std::string m_name;
  std::vector<Doctor *> m_doctors;
  void addDoctor(Doctor * doc); // adds Doctor to m_doctors list. Each patient can holds many docs.
public:
  Patient(std::string name): m_name(name) {}
  friend std::ostream& operator<< (std::ostream &, const Patient &);
  std::string getName() const { return m_name; }
  friend class Doctor;
};

void Patient::addDoctor(Doctor * doc)
{
  m_doctors.push_back(doc);
}

class Doctor
{
  std::string m_name;
  std::vector<Patient *> m_patients; 
public:
  Doctor(std::string name): m_name(name) {}
  void addPatient(Patient * pat);
  friend std::ostream& operator<< (std::ostream &, const Doctor &);
  std::string getName() const { return m_name; }
};

void Doctor::addPatient(Patient * pat)
{
  m_patients.push_back(pat);
  // adds doctor to current patient
  pat->addDoctor(this);
}

std::ostream& operator<< (std::ostream & out, const Doctor & doc)
{
  uint8_t length = doc.m_patients.size();
  if( length == 0 )
  {
    out << doc.getName() << " hasn't any patients.\n";
    return out;
  }
  out << doc.m_name << " is seeing patients: ";
  for( uint8_t cnt = 0; cnt < length; ++cnt )
    out << doc.m_patients[cnt]->getName() << ' ';
  return out;
}

// definition of this function here because forward declaration of claas isn't enought
// error: invalid use of incomplete class
std::ostream& operator<< (std::ostream & out, const Patient & pat)
{
  uint8_t length = pat.m_doctors.size();
  if( length == 0 )
  {
    out << pat.getName() << " hasn't any doctors.\n";
    return out;
  }
  out << pat.m_name << " is seeing doctors: ";
  for( uint8_t cnt = 0; cnt < length; ++cnt )
    out << pat.m_doctors[cnt]->getName() << ' ';
  return out;
}


int main()
{
  Patient * p1 = new Patient("Alex");
  Patient * p2 = new Patient("Bob");
  Patient * p3 = new Patient("Clive");

  Doctor * d1 = new Doctor("Smith");
  Doctor * d2 = new Doctor("Doug");

  d1->addPatient(p1);

  d2->addPatient(p1);
  d2->addPatient(p3);


  std::cout << *d1 << '\n';
  std::cout << *d2 << '\n';

  std::cout << *p1 << '\n';
  std::cout << *p2 << '\n';
  std::cout << *p3 << '\n';

  delete p1;
  delete p2;
  delete p3;

  delete d1;
  delete d2;

  return 0;
}
