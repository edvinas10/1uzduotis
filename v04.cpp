#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> //Del rand() funkcijos
#include <time.h>  //del "time"
#include <ctime>
#include <fstream>
#include <random>
#include <iomanip> // del setprecision

using namespace std;
using std::cout;
using std::cin;
using std::string;
using std::swap;


struct duomuo {
  string Vard;
  string Pav;
  int paz[15];
  int egz;
  float GP=0;
};

void rikiuoti(int masyvas[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      for (j = i+1; j < n; j++)  
        if (masyvas[i] > masyvas[j])  
          std::swap(masyvas[j], masyvas[i]);  
}
double rastiMediana(int masyvas[], int n) 
{ 
  rikiuoti (masyvas, n);
    if (n % 2 != 0) 
        return (double)masyvas[n / 2]; 
    return (double)(masyvas[(n - 1) / 2] + masyvas[n / 2]) / 2.0; 
}
int randomSk() {
    std::random_device rd;//random seed
    std::mt19937 gen(rd());//random number generator
    std::uniform_int_distribution<> dis(1, 10);//range
    return dis(gen);//put generator in range
    //srand((unsigned)time(0)); //susigeneruoju seed'as
}

int main()
{
  ofstream failas;
  int pagalbinis = 1000;
  for(int i = 1; i <= 4; i++){
    ofstream failas(to_string(i)+"_failas.txt", ios::in);
    failas.open (to_string(i)+"_failas.txt");
    for(int j = 1; j <= pagalbinis; j++){
          failas << "Vardas" + to_string(j) + " Pavarde" + to_string(j) << " " <<
          randomSk() <<  " " << randomSk() <<  " " <<
          randomSk() << " " << randomSk() << "\n";
    }
    failas.close();
    pagalbinis *= 10;
  }
    ofstream failasK;
    ofstream failasM;

    failasK.open("kietiakai.txt");
    failasM.open("minkstuciai.txt");
    //duomenu nuskaitymas
    string vardas, pavarde;
    int paz1, paz2, paz3, egz;
    for(int i = 1; i <= 4; i++){
      ifstream failas(to_string(i)+"_failas.txt", ios::in);
      while( failas >> vardas >> pavarde >> paz1 >> paz2 >> paz3 >> egz )
      {
        double GP = (((double)(paz1 + paz2 + paz3)/3) * 0.4 + (double)egz * 0.6);
        if(GP >= 5){
          failasK << vardas << " " << pavarde << " " << fixed << setprecision(2) << GP << "\n";
        }
        else{
          failasM << vardas << " " << pavarde << " " << fixed << setprecision(2) << GP << "\n";
        }
        //pagal gp rusiuot <5 >5
        //surusiavus idet i kitus du tik vard pav ir gp


        cout << vardas << " " << pavarde << " " << fixed << setprecision(2) << GP << " " << i << endl;
      }
    failas.close();
    failasK.close();
    failasM.close();
  }
//------------------------------------------
  duomuo Eil;
  duomuo Eil_mas[5];
  std::vector <duomuo> Eil_vect;

  cout << "Pasirinkite: Atsitiktiniai_paz/Ivedami_paz\n";
  string parinktis;
  cin >> parinktis;
  int namDarbSk;
  if (parinktis == "1"){
    cout << "Iveskite Eil. duom. (Vardas, Pavarde, kiek paz.):\n";
    cin >> Eil.Vard >> Eil.Pav >> namDarbSk;
    for (int i = 0; i < namDarbSk; i++) { 
      int atsitiktinis = randomSk();
      Eil.GP = Eil.GP + atsitiktinis;
      Eil.paz[i] = atsitiktinis;
    };

  }
  else if (parinktis == "2"){
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

  cout << "\nPasirinkite: Mediana/GP(galutinis)\n";
  cin >> parinktis;
  if (parinktis == "Mediana"){
   Eil.GP = rastiMediana(Eil.paz, namDarbSk); //Isveda tik pazymiu mediana
    cout << Eil.GP << std::endl; 
  }
  else if (parinktis == "GP(galutinis)"){
    cout << " " << Eil.GP << std::endl;
  }
  else {
    cout << "Klaida, turite ivesti tinkamus duomenis\n";
  }
}