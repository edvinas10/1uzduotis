# 1uzduotis
project (stages)
V0.1 versijoje tiek atsitiktinų skaičių generavimas, tiek įvedamų skaičių nuskaitymas vyksta panašiu greičiu.
Galutinio balo arba medianos suskaičiavimas taip pat vyksta panašiu greičiu.
Skaičiuojant medianą buvo panaudotas bubble sort rūšiavimo algoritmas tam, kad sūrušiuotame sąraše būtų galima rasti medianą.
Atsitiktiniai skaičiai buvo generuojami su random funkcija įsivedus randomSk kintamajį ir po to panaudojus jį išvestyje.
Duomenų nuskaitymui naudojamas vektorius, nes pažymių masyvas yra gerokai per mažas.
Išvestyje matoma struktūra atrodo taip: studento vardas, pavardė ir galutinis pažymys bei mediana.
Testavimui naudojame kursiokai.txt failą, kuriame yra duomenys apie studentų pažymius bei egzamino įvertinimą.
V0.3 versijoje atsiranda papildomi: antraštinis header failas struct1.h kuriame iš pagrindinio failo v03.cpp yra įkeltos naudojamos bibliotekos,
duomenų struktūros, duomenų tipai bei funkcijų prototipai. Kitas failas pavadinimu struct1.cpp yra antraštinio header failo cpp failas, kuriame yra
realizuotas pats funkcijų vykdymas. Šioje versijoje yra taip pat panaudotas išimčių valdymas, kuris turėtų leisti mesti tam tikrą, norimą klaidos 
pranešimą kai įvedami duomenys yra netinkami. Šiuo atveju kuomet skaičiuojame galutinį balą ir skaičiuojant namų darbų vidurkį, daliname iš namų darbų 
skaičiaus, namų darbų skaičius yra 0. V0.4 yra V0.1 versijos patobulinimas. Sukuriami 4 nauji failai su studentų įrašais ir atsitiktinai generuojamais pažymiais bei
egzamino pažymiu. Tuomet skaičiuojamas jų galutinis balas bei pagal jį visi studentai surūšiuojami į 2 kategorijas: "Kietiakai" ir "Minkštučiai".  Pirmieji turi
GP>5, likusieji GP<5. Visi surūšiuoti studentai perkeliami į dar 2 naujus failus "Kietiakai.txt" ir "Minkstuciai.txt". Taip pat matuojame programos žingsnių
veikimo spartą. Skaičiuojame kiek užtrunka duomenų nuskaitymas iš kiekvieno failo bei duomenų surūšiavimas bei perkėlimas į du naujus failus ir bendra
failų sukūrimo sparta. Tam naudojame std::chrono biblioteką. pažymime kodo, atliekančio mums reikalingas funkcijas pradžią ir pabaigą (start ir
end) bei vėliau atimame pabaigą iš pradžios (end-start). Spartos analizės testavimo rezultatai yra tokie:

Failu sukurimo veikimo laikas (sec): 243.587;
Duomenu nuskaitymo veikimo laikas (sec) 1 failas: 4.2449e-05;
Duomenu rusiavimo ir perkelimo i naujus failus veikimo laikas (sec) 1 failas: 0.00240191;
Duomenu nuskaitymo veikimo laikas (sec) 2 failas: 0.00250364;
Duomenu rusiavimo ir perkelimo i naujus failus veikimo laikas (sec) 2 failas: 0.0665636;
Duomenu nuskaitymo veikimo laikas (sec) 3 failas: 0.0691822;
Duomenu rusiavimo ir perkelimo i naujus failus veikimo laikas (sec) 3 failas: 0.517277;
Duomenu nuskaitymo veikimo laikas (sec) 4 failas: 0.586527;
Duomenu rusiavimo ir perkelimo i naujus failus veikimo laikas (sec) 4 failas: 5.29317;
 
V0.5 versijoje lyginame programos spartą (failų kūrimas, duomenų nuskaitymas, jų sūrušiavimas bei išvedimas į 2 naujus failus) naudojant vektorių ir listą.
Vektoriaus rezultatai jau yra pateikti čia, todel čia keliame listo rezultatus ir palygine matome, kad vektorius dirba nežymiai greičiau uz listą. Testavimo
sistemos parametrai būtų tokie: Procesorius (HDD) - 2.6GHz, Operatyvinė atmintis (RAM) - 8GB, Kietasis diskas HDD (SSD) - 251GB. Testavimo rezultatai su listu
pateikti nuotraukos faile pavadinimu IMG-0424.JPG .
Galutiniame v1.0 release išbandome skirtingas studentų dalijimo į kietus ir minkštus strategijas. Kadangi prieš tai rūšiuojant studentus pagal galutinį balą
naudojome išvedimą į 2 naujus ir dabar bandėme rūšiuoti išvedant į vieną kietųjų failą tuo pačiu ištrinant kietuosius iš senų failų ir taip senuose failuose
paliekant tik minkštus, palygines matau, kad strategija skaidyti į 2 naujus failus yra geresnė. Programų sparta yra panaši, atminties atžvilgiu, be abejo, ši
strategija nėra efektyvesnė, tačiau labai dažnai trinant kiekvieną kartą gana didelė tikimybė prarasti dalį įrašų. Taip pat šioje galutinėje versijoje yra paruoštas CMakeLists.txt failas t.y. įdiegimo instrukcija vartotojui.
