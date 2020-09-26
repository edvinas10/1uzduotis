#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
struct duomuo {
  string Vard;
  string Pav;
  int paz[10];
  int egz;
  float GP=0;
};

int main()
{
  duomuo Eil; duomuo Eil_mas[5];
  std::vector <duomuo> Eil_vect;
  cout << "Iveskite Eil. duom. (Vardas, Pavarde, egz. paz. ir 5 sem. paz.):\n";
  cin >> Eil.Vard >> Eil.Pav >> Eil.egz;
  for (int i = 0; i < 5; i++) { 
    cin >> Eil.paz[i];
    Eil.GP = Eil.GP + (float)Eil.paz[i];
  };
  Eil.GP = Eil.GP / 5.0;
  Eil.GP = Eil.GP * 0.4 + 0.6 * Eil.egz;
  cout << "Ivesta:" << Eil.Vard << " " << Eil.Pav << " " << Eil.egz;
  for (int i = 0; i < 5; i++){  
    cout << " " << Eil.paz[i];
  };
    cout << " " << Eil.GP << std::endl;
}