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
skaičiaus, namų darbų skaičius yra 0. V0.4 yra V0.1 versijos patobulinimas. Sukuriami 4 nauji failai su studentu irasais ir atsitiktinai generuojamais pazymiais bei
egzamino pazymiu. Tuomet skaiciuojamas ju galutinis balas bei pagal ji visi studentai surusiuojami i 2 kategorijas: "Kietiakai" ir "Minkstuciai".  Pirmieji turi 
GP>5, likusieji GP<5. Visi surusiuoti studentai perkeliami i dar 2 naujus failus "Kietiakai.txt" ir "Minkstuciai.txt".  Taip pat matuojame programos žingsnių 
veikimo spartą. Skaičiuojame kiek užtrunka duomenų nuskaitymas iš kiekvieno failo bei duomenų surūšiavimas bei perkėlimas į du naujus failus ir bendra failų 
sukūrimo sparta. Tam naudojame std::chrono biblioteką. pažymime kodo, atliekančio mums reikalingas funkcijas pradžią ir pabaigą (start ir end) bei vėliau atimame 
pabaigą iš pradžios (end-start).
