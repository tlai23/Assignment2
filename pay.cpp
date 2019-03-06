#include "person.cpp"
#include <iostream>
#include <fstream>

int readData(Person employee[], int n);
void writeData(Person employee[], int n);

int main()
{
int N =0;
Person employee[20];
N = readData(employee,20);
writeData(employee, N-1);
}


int readData(Person employee[], int n)
{
  string first, last;
  float payR, hr;
  int i=0;
  ifstream inData ("input.txt");
  if (inData.is_open())
  {
  while (inData)
  {
    inData>> first;
    inData>> last;
    inData>> payR;
    inData>> hr;
    employee[i].setFirstName(first);
    employee[i].setLastName(last);
    employee[i].setPayRate(payR);
    employee[i].setHoursWorked(hr);
    i++;
  }
  inData.close();
}
  return i;
}

void writeData(Person employee[], int n)
{
  ofstream outData;
  outData.open("output.txt");
  for(int i=0; i<=n; i++)
  {
    outData<<employee[i].fullName();
    outData<<employee[i].totalPay()<<endl;
  }
  outData.close();
}
