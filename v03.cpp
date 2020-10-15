#include "struct1.h"

int main()
{
  try {
    duomuo Eil; duomuo Eil_mas[5];
    std::vector <duomuo> Eil_vect;
    std::ifstream fd;
    std::ofstream fr;
    cout << "Pasirinkite: Atsitiktiniai_paz/Ivedami_paz/Nuskaitomi_paz\n";
    string parinktis;
    cin >> parinktis;
    int namDarbSk;
    if (parinktis == "Atsitiktiniai_paz") {
        cout << "Iveskite Eil. duom. (Vardas, Pavarde, kiek paz.):\n";
        cin >> Eil.Vard >> Eil.Pav >> namDarbSk;
        for (int i = 0; i < namDarbSk; i++) {
            int temp = randomSk();
            Eil.GP = Eil.GP + temp;
            Eil.paz.push_back(temp);
        };
        Eil.egz = randomSk();
    }
    else if (parinktis == "Ivedami_paz") {
        int tempPaz;
        cout << "Iveskite Eil. duom. (Vardas, Pavarde, kiek paz., egz. paz. ir sem. paz.):\n";
        cin >> Eil.Vard >> Eil.Pav >> namDarbSk >> Eil.egz;
        if (0 == namDarbSk)
        throw "dalyba is 0 negalima";
        for (int i = 0; i < namDarbSk; i++) {
            cin >> tempPaz;
            Eil.paz.push_back(tempPaz);
            Eil.GP = Eil.GP + (float)Eil.paz[i];
        };
    }

    else if (parinktis == "Nuskaitomi_paz") {
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
            if (fd.eof()) break;
        }

        cout << "Vardas        " << "Pavarde       " << "Galutinis(GP)       " << "Galutinis(Mediana)      " << std::endl;
        cout << "-----------------------------------------------------" << std::endl;
        /*Iövedimas vektoriaus*/
        for (duomuo eile : Eil_vect) {
            cout << eile.Vard << "        " << eile.Pav << "        ";
            Eil.GP = 0;
            for (int pazymys : eile.paz) {
                Eil.GP = Eil.GP + pazymys;
            }
            Eil.GP = Eil.GP / 15;
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
    if (0 == namDarbSk)
    throw "dalyba is 0 negalima";
    Eil.GP = Eil.GP / namDarbSk;
    Eil.GP = Eil.GP * 0.4 + 0.6 * Eil.egz;
    cout << "Ivesta: " << Eil.Vard << " " << Eil.Pav << " " << Eil.egz << "\n";
    for (int i = 0; i < namDarbSk; i++) {
        cout << Eil.paz[i] << " ";
    };
    cout << std::endl;
    cout << "Pasirinkite: Mediana/GP(galutinis)\n";
    cin >> parinktis;
    if (parinktis == "Mediana") {
        Eil.GP = rastiMediana(Eil.paz, namDarbSk);
        Eil.GP = Eil.GP * 0.4 + 0.6 * Eil.egz;
        cout << Eil.GP << std::endl;
        //fd.close();
        fr.close();
        return 0;
    }
    else if (parinktis == "GP(galutinis)") {
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
  catch(string exception){
    cout << exception;
    }
}
