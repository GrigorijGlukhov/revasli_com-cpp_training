#ifndef CAR_H
#define CAR_H

class Car
{
  std::string m_company;
  std::string m_model;
public:
  Car(const std::string &, const std::string &);
  friend bool operator==(const Car &, const Car &);
  friend bool operator!=(const Car &, const Car &);
  friend std::ostream& operator<<(std::ostream &, const Car &);
  friend bool operator<(const Car &, const Car &);
};

bool operator==(const Car &, const Car &);
bool operator!=(const Car &, const Car &);
std::ostream& operator<<(std::ostream &, const Car &);
bool operator<(const Car &, const Car &);

#endif
