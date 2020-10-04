#include <iostream>
#include <fstream>
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
  std::vector<int> paz;
  int egz;
  float GP=0;
};

//rikiuoti(Eil.paz);
//rikiuoti(Eil.egz);

void rikiuoti(std::vector<int> masyvas, int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++){
      int k = i;      
      for (j = i+1; j < n; j++)  
        if (masyvas[i] > masyvas[j])
          k = j;  
      std::swap(masyvas[i], masyvas[k]); 
    } 
}
double rastiMediana(std::vector<int> masyvas, int n) 
{ 
  rikiuoti(masyvas,  n);
    if (n % 2 != 0) {
      return (double)masyvas[n / 2]; 
    }
    else return (double)(masyvas[(n - 1) / 2] + masyvas[n / 2]) / 2.0; 
}
int randomSk(){
  srand((unsigned) time(0)); //susigeneruoju seed'a
  return ((rand() % 10) + 1);
}

int main()
{
  duomuo Eil; duomuo Eil_mas[5];
  std::vector <duomuo> Eil_vect;

  std::ifstream fd;
  std::ofstream fr;

  cout << "Pasirinkite: Atsitiktiniai_paz/Ivedami_paz/Nuskaitomi_paz\n";
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
    };
  }
  else if (parinktis == "Nuskaitomi_paz"){
    cout << "Iveskite failo pavadinima (pavadinimas.txt):\n";
    string pavadinimas;
    cin >> pavadinimas;

    fd.open(pavadinimas);

    int ndSkaicius = 0;
    string vardas, pavarde, temp;

    fd >> vardas >> pavarde;
    do {
        fd >> temp;
        ndSkaicius++;
    } while (temp != "Egz.");
    --ndSkaicius;

    int egzaminas;
    int* Masyvas = new int[ndSkaicius];

    while (true) {
        duomuo laikinas;

      fd >> vardas >> pavarde;
      for (int x = 0; x < ndSkaicius; x++) {
          fd >> Masyvas[x];
          laikinas.paz.push_back(Masyvas[x]);
      }
      fd >> egzaminas;

      laikinas.Vard = vardas;
      laikinas.Pav = pavarde;
      laikinas.egz = egzaminas;

      Eil_vect.push_back(laikinas);
      if(fd.eof()) break;
    }
    cout<< "Vardas        "<<"Pavarde       "<<"Galutinis(GP)       "<<"Galutinis(Mediana)      " << std::endl;
    cout <<"-----------------------------------------------------" << std::endl;

    /*Iövedimas vektoriaus*/
    for (duomuo eile : Eil_vect) {

        cout << eile.Vard <<"        "<<  eile.Pav <<"        ";

        Eil.GP = 0;
        for (int pazymys : eile.paz) {
            Eil.GP = Eil.GP + pazymys;
        }
        Eil.GP = Eil.GP/15;
        Eil.GP = Eil.GP * 0.4 + 0.6 * eile.egz;
        cout << Eil.GP << std::endl;
        Eil.GP = rastiMediana(eile.paz, 15);
        cout << Eil.GP << std::endl; 
    }
    return 0;
  }
  else {
    cout << "Klaida, turite ivesti tinkamus duomenis\n";
    return -1;
  }

  Eil.GP = Eil.GP / namDarbSk;
  Eil.GP = Eil.GP * 0.4 + 0.6 * Eil.egz;

  cout << "Ivesta: " << Eil.Vard << " " << Eil.Pav << " " << Eil.egz << "\n";
  for (int i = 0; i < namDarbSk; i++){  
    cout << Eil.paz[i] << " ";
  };

  cout << "Pasirinkite: Mediana/GP(galutinis)\n";
  cin >> parinktis;
  if (parinktis == "Mediana"){
    Eil.GP = rastiMediana(Eil.paz, namDarbSk); 
    Eil.GP = Eil.GP * 0.4 + 0.6 * Eil.egz;
    cout << Eil.GP << std::endl; 
    //fd.close();
    fr.close();
    return 0;
  }
  else if (parinktis == "GP(galutinis)"){
    cout << " " << Eil.GP << std::endl;
   // fd.close();
    fr.close();
    return 0;
  }
  else {
    cout << "Klaida, turite ivesti tinkamus duomenis\n";
  //  fd.close();
    fr.close();
    return -1;
  }
}