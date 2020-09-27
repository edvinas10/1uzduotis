#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> //Del rand() funkcijos
#include <time.h>  //del "time"
#include <ctime>

using std::cout;
using std::cin;
using std::string;
using std::swap;
struct duomuo {
  string Vard;
  string Pav;
  int paz[10];
  int egz;
  float GP=0;
};

//rikiuoti(Eil.paz);
//rikiuoti(Eil.egz);

void rikiuoti(int masyvas[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      for (j = 0; j < n-i-1; j++)  
        if (masyvas[j] > masyvas[j+1])  
          std::swap(masyvas[j], masyvas[j+1]);  
}
double rastiMediana(int masyvas[], int n) 
{ 
    if (n % 2 != 0) 
        return (double)masyvas[n / 2]; 
    return (double)(masyvas[(n - 1) / 2] + masyvas[n / 2]) / 2.0; 
}
int randomSk(){
  srand((unsigned) time(0)); //susigeneruoju seed'a
  return ((rand() % 10) + 1);
}

int main()
{
  duomuo Eil; duomuo Eil_mas[5];
  std::vector <duomuo> Eil_vect;

  cout << "Pasirinkite: Atsitiktiniai_paz/Ivedami_paz\n";
  string parinktis;
  cin >> parinktis;
  int namDarbSk;
  if (parinktis == "Atsitiktiniai_paz"){
    cout << "Iveskite Eil. duom. (Vardas, Pavarde, kiek paz.):\n";
    cin >> Eil.Vard >> Eil.Pav >> namDarbSk;
    for (int i = 0; i < namDarbSk; i++) { 
      Eil.GP = Eil.GP + randomSk();
    };
  }
  else if (parinktis == "Ivedami_paz"){
    cout << "Iveskite Eil. duom. (Vardas, Pavarde, kiek paz., egz. paz. ir sem. paz.):\n";
    cin >> Eil.Vard >> Eil.Pav >> namDarbSk >> Eil.egz;
    for (int i = 0; i < namDarbSk; i++) { 
      cin >> Eil.paz[i];
      Eil.GP = Eil.GP + (float)Eil.paz[i];
    }
  }
    else {
    cout << "Klaida, turite ivesti tinkamus duomenis\n";
  }

  Eil.GP = Eil.GP / namDarbSk;
  Eil.GP = Eil.GP * 0.4 + 0.6 * Eil.egz;

  cout << "Ivesta:" << Eil.Vard << " " << Eil.Pav << " " << Eil.egz << "\n";
  for (int i = 0; i < namDarbSk; i++){  
    cout << " " << Eil.paz[i];
  };

  cout << "Pasirinkite: Mediana/GP(galutinis)\n";
  cin >> parinktis;
  if (parinktis == "Mediana"){
   Eil.GP = rastiMediana(Eil.paz, namDarbSk); //Isveda tik pazymiu mediana
    //Turbut reiktu dar papildomai kazka padaryti su egzamino balais
    Eil.GP = Eil.GP * 0.4 + 0.6 * Eil.egz;
    cout << Eil.GP << std::endl; 
  }
  else if (parinktis == "GP(galutinis)"){
    cout << " " << Eil.GP << std::endl;
  }
  else {
    cout << "Klaida, turite ivesti tinkamus duomenis\n";
  }
}