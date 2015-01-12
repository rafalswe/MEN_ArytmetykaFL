#ifndef fl_hpp
#define fl_hpp
#include <iostream>
#include <string>


class LiczbaDziesietna
class LiczbaFl
{
    private:
        string calosc;
        char znak;
        string cecha;
        string mantysa;
        string zwykla;
        void zamienNaZwykla();
        void zamienNaZnormalizowana();
    public:
    LiczbaFl(LiczbaDziesietna liczbaDziesietna);
    void wyswietl();

};
class LiczbaDziesietna
{
    private:
        string calosc;
        string czescCalkowita;
        string czescUlamkowa;

        double dCalosc;
        double dUlamkowa;
        double dCalkowita;
        char znak;

        void zamienNaDouble(bool czyKropka);

    public:
        LiczbaDziesietna(string par);
        void wyswietl();
        char dajZnak() {return znak;}
};

#endif
