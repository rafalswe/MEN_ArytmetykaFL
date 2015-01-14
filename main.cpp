#include <iostream>
#include <string>

using namespace std;

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
        double dajDUlamkowa() {return dUlamkowa;}
        double dajDCalkowita() {return dCalkowita;}
};

class LiczbaFl
{
    private:
        string calosc;
        char znak;
        string cecha;
        string mantysa;
       // LiczbaDziesietna liczbaDziesietna;
        void tworzMantyse(LiczbaDziesietna parLiczbaDziesietna);
        void tworzCeche(int iMantysa);
    public:
    LiczbaFl(LiczbaDziesietna parLiczbaDziesietna);
    void wyswietl();

};



LiczbaDziesietna::LiczbaDziesietna(string par)
{
    calosc = par;
    int kropka;
    bool czyKropka = false;

    if(par[0] == '-')
    {
        znak = '-';
        for(unsigned int i = 1; i < par.length(); i++)
        {
            if((par[i] == ',') || (par[i] == '.'))
            {
                kropka = i;
                czyKropka = true;
                break;
            }
        }
        if(czyKropka) czescCalkowita = par.substr(1,kropka-1);
        else czescCalkowita = par.substr(1,par.length());
    }
    else
    {
        znak = '+';
        for(unsigned int i = 0; i < par.length(); i++)
        {
            if((par[i] == ',') || (par[i] == '.'))
            {
                kropka = i;
                czyKropka = true;
                break;
            }
        }
        if(czyKropka) czescCalkowita = par.substr(0,kropka);
        else czescCalkowita = par;
    }
    if(czyKropka) czescUlamkowa = par.substr(kropka + 1, par.length() - kropka);
    else czescUlamkowa = "0";



    zamienNaDouble(czyKropka);
}

void LiczbaDziesietna::zamienNaDouble(bool czyKropka)
{
    //calkowita

    cout<<"String czCalkowita: "<<czescCalkowita<<" czUlamkowa: "<<czescUlamkowa<<endl;
    dCalkowita = 0;
    int mnoznik = 1;
    for(int i=czescCalkowita.length()-1; i>=0; i--)
    {
       dCalkowita = dCalkowita + ((int)czescCalkowita[i] - 48) * mnoznik;
       mnoznik = mnoznik * 10;
       cout<<"for dCalkowita: "<< i <<"  "<<dCalkowita<<endl;
    }
    //ulamek
    if(czyKropka)
    {
        mnoznik = 1;
        for(int i=czescUlamkowa.length()-1; i>=0; i--)
        {
           dUlamkowa = dUlamkowa + ((int)czescUlamkowa[i] - 48) * mnoznik;
           mnoznik = mnoznik * 10;
        }
        dUlamkowa = dUlamkowa / mnoznik;
        cout<<"dcal: "<<dCalkowita<<endl;
        cout<<"dul: "<<dUlamkowa<<endl;
    }
    else
    {
        dUlamkowa = 0;
    }

}


void LiczbaDziesietna::wyswietl()
{
    cout << "Liczba: " << calosc << endl;
    cout << "Czesc calkowita: " << czescCalkowita << endl;
    cout << "Czesc ulamkowa: " << czescUlamkowa << endl;
    cout << "Znak: " << znak << endl;
}



LiczbaFl::LiczbaFl(LiczbaDziesietna parLiczbaDziesietna)
{
    znak = 'x';
    mantysa = "";
    cecha = "";
    for(int i = 1; i<=5; i++)
        cecha = cecha + "-";
    for(int i = 1; i<=10; i++)
        mantysa = mantysa + "-";
    calosc = znak + cecha + mantysa;

    if(parLiczbaDziesietna.dajZnak() == '+')
    {
        this->znak = '0';
    }
    if(parLiczbaDziesietna.dajZnak() == '-')
    {
        this->znak = '1';
    }
    tworzMantyse(parLiczbaDziesietna);



    calosc = znak + cecha + mantysa;
}

void LiczbaFl::tworzMantyse(LiczbaDziesietna parLiczbaDziesietna)
{
    int czCalkowita = (int)parLiczbaDziesietna.dajDCalkowita();
    double czUlamkowa = parLiczbaDziesietna.dajDUlamkowa();
    bool jestCalkowita = false;
    int iMantysa = 0;
    string bufor = "";

    //czesc Calkowita
    if(czCalkowita != 0)
    {
        if(czCalkowita < 0) czCalkowita = czCalkowita*(-1);
        jestCalkowita = true;
        while(czCalkowita != 0)
        {
            if(czCalkowita % 2 == 0) bufor.insert(0,"0");
            else bufor.insert(0,"1");
            czCalkowita=czCalkowita/2;
        }
        //for(int i = 1; ((i<bufor.length()) && (i<mantysa.length() + 2)) ; i++)
        for(unsigned int i = 1; i<bufor.length(); i++)
        {
            mantysa[i-1] = bufor[i];
        }
        iMantysa = bufor.length() - 1;
    }


    //czesc Ulamkowa
    bufor = "";
    double dzielnik = 0.5;
    unsigned int i = 0;

    while(czUlamkowa)
    {
        if(czUlamkowa >= dzielnik)
        {
            czUlamkowa = czUlamkowa - dzielnik;
            bufor = bufor + "1";
        }
        else bufor = bufor + "0";;
        dzielnik = dzielnik / 2;
        i++;
    }

    if(jestCalkowita)
    {
        i = iMantysa;
        while((i < mantysa.length()) && ((i - iMantysa) < bufor.length()))
        {
            mantysa[i] = bufor[i - iMantysa];
            i++;
        }
        if(i != mantysa.length() -1)
        {
            for(unsigned  int j = i; j < mantysa.length(); j++)
                mantysa[j] = '0';
        }
    }
    else
    {
        i = 0;
        int jedynka;
        while(bufor[i] != '1')   //szukanie pierwszej jedynki
        {
            i++;
        }
        iMantysa = (i + 1) *(-1);

        i++;
        jedynka = i;
        i=0;
        while((i < mantysa.length()) && (i + jedynka < bufor.length()))
        {
            mantysa[i] = bufor[i + jedynka];
            i++;
        }
        if(i != mantysa.length() -1)
        {
            for(unsigned  int j = i; j < mantysa.length(); j++)
                mantysa[j] = '0';
        }
    }
    cout<<"iMantysa: "<<iMantysa<<endl;
    tworzCeche(iMantysa);

}

void LiczbaFl::tworzCeche(int iMantysa)    //cecha = 0 -> 0; cecha = 31 -> inf; cecha = 1 - 15 -> liczby > 1
{
    int i=cecha.length()-1;                //cecha = 16 - 30 -> liczby < 0;
    int iCecha;
    if(iMantysa<=15 && iMantysa>=-15)
    {

        if(iMantysa >= 0)
        {
            iCecha = iMantysa + 1;
        }
        else
        {
            iCecha = 15 + (iMantysa *(-1));
        }
    }
    else iCecha = 31;   //nieskonczonosc
    while(i>=0)
    {
        cecha[i] = (char)48+(iCecha % 2);
        iCecha = iCecha/2;
        i--;
    }
}

void LiczbaFl::wyswietl()
{
    cout << "Liczba: " << calosc << endl;
    cout << "Znak: " << znak << endl;
    cout << "Cecha: " << cecha << endl;
    cout << "Mantysa: " << mantysa << endl;
}


int main()
{
    string sliczbaDzies;
    cout << "Podaj liczbe w systemie 10:" << endl;
    cin >> sliczbaDzies;
    LiczbaDziesietna liczbaDz(sliczbaDzies);
    liczbaDz.wyswietl();
    LiczbaFl liczbafl(liczbaDz);
    liczbafl.wyswietl();

    return 0;
}
