#include <iostream>
#include <cstdio>
#include <sys/stat.h>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <filesystem>
#include <string>
#include <fstream>
#include <mmsystem.h>

#pragma comment( lib, "winmm" )

#define DLUGOSC_GRY 12

using namespace std;



struct pytanie
{
    string p;
    string odp_1;
    string odp_2;
    string odp_3;
    string odp_4;
    string prawidlowa;
};

pytanie pts[100];


    errno_t err;
    ifstream pytania;
    char tmp[200];
    int i = 0;
    string nazwa;
    string s_tmp;
    int ilosc_pytan;
    int ii;
    int wylosowane[200];
    bool k1 = false;
    bool k2 = false;
    bool k3 = false;
 


    void PressAKeyToContinue()
    {
        int c;
        printf("\nWcisnij spacje...\n");
        c = _getch();
        if (c == 0 || c == 224) _getch();
        system("cls");
    }


    char Wybierz_odpowiedz()
    {
        int c;
        char kl;

        printf("\nWybierz odpowiedz \n\n");
        
        Sleep(2000);

        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

        do
        {
            
            c = _getch();
            if (c == 0 || c == 224) _getch();


        } while (c != 97 && c !=98 &&  c != 99 && c != 100 && c != 65 && c != 66 && c != 67 && c != 68 && c != 81 && c != 113 && c != 27 && (c != 49 || k1) && (c != 50 || k2) && (c != 51 || k3));

        if (c == 97 || c == 65)
        {
            kl = 'a';
        }

        if (c == 98 || c == 66)
        {
            kl = 'b';
        }

        if (c == 99 || c == 67)
        {
            kl = 'c';
        }

        if (c == 100 || c == 68)
        {
            kl = 'd';
        }

        if (c == 81 || c == 113 || c == 27)
        {
            kl = 'q';
        }

        if (c == 49)
        {
            kl = '1';
        }
        
        if (c == 50)
        {
            kl = '2';
        }

        if (c == 51)
        {
            kl = '3';
        }

        printf("Twoja odpowiedz to: %c\n", kl);

        

        return kl;
    }






int main(int argc, char* argv[])
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);


    for (i = 0; i < 200; i++)
    {
        wylosowane[i] = 0;
    }


    srand(time(NULL));

    strcpy_s(tmp, 200, argv[0]);

    i = strlen(tmp);


    printf("Witaj w milionerach\n");

#if _DEBUG == FALSE
    PlaySound(TEXT("poczatek.wav"), NULL, SND_FILENAME);
#endif

    printf("Przed Toba 12 pytan\n");

    printf("Jesli odpowiesz na wszystkie wygrasz milion\n");

    printf("\n");

    PressAKeyToContinue();

    do
    {

        i--;


    } while (tmp[i] != '\\');

    tmp[i + 1] = 0;

    nazwa = string(tmp) + string("pytania.txt");


    pytania.open(nazwa.c_str());
    if (pytania.bad())
    {
        printf("Nie udalo sie otworzyc pliku \n");
        return 0;
    }

    i = 0;

    while (!pytania.eof())
    {
        if (getline(pytania, s_tmp))
        {
            pts[i].p = string(s_tmp);
        }

        if (getline(pytania, s_tmp))
        {
            pts[i].odp_1 = string(s_tmp);
        }

        if (getline(pytania, s_tmp))
        {
            pts[i].odp_2 = string(s_tmp);
        }

        if (getline(pytania, s_tmp))
        {
            pts[i].odp_3 = string(s_tmp);
        }

        if (getline(pytania, s_tmp))
        {
            pts[i].odp_4 = string(s_tmp);
        }

        if (getline(pytania, s_tmp))
        {
            pts[i].prawidlowa = string(s_tmp);
        }

        if (getline(pytania, s_tmp))
        {i++;}

        
    }

    ilosc_pytan = i + 1;

    pytania.close();

    /*
    for (i = 0; i < ilosc_pytan; i++)
    {
        printf("Pytanie: %s\n", pts[i].p.c_str());
        printf("Odp 1: %s\n", pts[i].odp_1.c_str());
        printf("Odp 2: %s\n", pts[i].odp_2.c_str());
        printf("Odp 3: %s\n", pts[i].odp_3.c_str());
        printf("Odp 4: %s\n", pts[i].odp_4.c_str());
        printf("Poprawna: %s\n", pts[i].prawidlowa.c_str());

        printf("\n");
    }
    */


    for (i = 0; i < DLUGOSC_GRY; i++)
    {
        bool o1 = true;
        bool o2 = true;
        bool o3 = true;
        bool o4 = true;
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;
        int p4 = 0;
        int p5 = 0;
        int p6 = 0;

        int po1 = 0;
        int po2 = 0;
        int po3 = 0;
        int po4 = 0;


        string kasa;
        char wybrana = ' ';


        switch (i)
        {
        case 0:
            kasa = "500";
            break;
        case 1:
            kasa = "1000";
            break;
        case 2:
            kasa = "2000";
            break;
        case 3:
            kasa = "5000";
            break;
        case 4:
            kasa = "10000";
            break;
        case 5:
            kasa = "20000";
            break;
        case 6:
            kasa = "40000";
            break;
        case 7:
            kasa = "75000";
            break;
        case 8:
            kasa = "125000";
            break;
        case 9:
            kasa = "250000";
            break;
        case 10:
            kasa = "500000";
            break;
        case 11:
            kasa = "1000000";
            break;
        }


        ii = rand() % ilosc_pytan;
       
        while (wylosowane[ii] == 1)
        {
            ii++;
            if (ii == ilosc_pytan)
            {
                ii = 0;
            }
        }

        wylosowane[ii] = 1;

        //Petla z ktorej nie wychodzimy dopoki ktos nie wybierze odpowiedzi-------------------------------------------------------


        do
        {
            

            system("cls");

            printf("Pytanie za %s\n", kasa.c_str());

            if (!k1)
            {
                printf("\t\t\t\t\t\t\t\t\t\t1: Pol na pol\n");
            }
            else
            {
                printf("\t\t\t\t\t\t\t\t\t\t1: -----\n");
            }

            if (!k2)
            {
                printf("\t\t\t\t\t\t\t\t\t\t2: Pytanie do publicznosci\n");
            }
            else
            {
                printf("\t\t\t\t\t\t\t\t\t\t2: -----\n");
            }

            if (!k3)
            {
                printf("\t\t\t\t\t\t\t\t\t\t3: Telefon do przyjaciela\n\n\n");
            }
            else
            {
                printf("\t\t\t\t\t\t\t\t\t\t3: -----\n\n\n");
            }

#if _DEBUG == FALSE
            PlaySound(TEXT("zastanawianie_sie.wav"), NULL, SND_FILENAME | SND_ASYNC);
#endif
            printf("%s\n\n", pts[ii].p.c_str());
           


            //Publicznoœæ --------------------------------------------------------
            if (string(1, wybrana) == string(1, '2'))
            {
                if (rand() % 100 < 30)
                {
                    printf("Pytamy publicznosc... \n");
                    PlaySound(TEXT("publicznosc.wav"), NULL, SND_FILENAME);
                    printf("\n");
                    printf("Sorry, ale z powodu COVID'a nie ma zadnej publicznosci :) \n");
                }
                else
                {
                    printf("Pytamy publicznosc... \n");
                    PlaySound(TEXT("publicznosc.wav"), NULL, SND_FILENAME);


                    if (o1 && o2 && o3 && o4)
                    {

                        p1 = rand() % 20 + 27;
                        p2 = 75 - p1;
                        p3 = rand() % 24 + 1;
                        p4 = 100 - (p1 + p2 + p3);



                    }
                    else
                    {
                        p5 = rand() % 64 + 1;
                        p6 = 100 - p5;


                    }





                }


                if (k1 && k2 && k3)
                {
                    PlaySound(TEXT("kolo.wav"), NULL, SND_FILENAME);
                }
            }
            printf("\n");



            //Pó³ na pó³ -------------------------------------------------------
            if (string(1, wybrana) == string(1, '1'))
            {
                o1 = false;
                o2 = false;
                o3 = false;
                o4 = false;


                bool zamieniono = false;
                int x;


                //Zaznaczanie prawid³owej odpowiedzi do wyswietlenia -------------------------------------------------------
                if (string(1, 'a') == pts[ii].prawidlowa)
                {
                    o1 = true;
                }
                else

                if (string(1, 'b') == pts[ii].prawidlowa)
                {
                    o2 = true;
                }
                else

                if (string(1, 'c') == pts[ii].prawidlowa)
                {
                    o3 = true;
                }
                else

                if (string(1, 'd') == pts[ii].prawidlowa)
                {
                    o4 = true;
                }


                //losowanie drugiej odpowiedzi do wyswietlenia -------------------------------------------------------
            
                do
                {
                    x = rand() % 4 + 1;

                    if(x == 1 && !o1)
                    {
                        o1 = true;
                        zamieniono = true;
                        if(po1 == 0)
                        { 
                            po1 = p5;
                        }
                    }

                    if (x == 2 && !o2)
                    {
                        o2 = true;
                        zamieniono = true;
                        if (po2 == 0)
                        {
                            po2 = p5;
                        }
                    }

                    if (x == 3 && !o3)
                    {
                        o3 = true;
                        zamieniono = true;
                        if (po3 == 0)
                        {
                            po3 = p5;
                        }
                    }

                    if (x == 4 && !o4)
                    {
                        o4 = true;
                        zamieniono = true;
                        if (po4 == 0)
                        {
                            po4 = p5;
                        }
                    }


                } while (!zamieniono);



                //Wyswietlanie odpowiedzi -------------------------------------------------------
                if (o1)
                {
                    printf("%s ", pts[ii].odp_1.c_str());

                    if (po1 != 0)
                    {
                        printf("%d %%", po1);
                    }

                    printf("\n");
                }
                else
                {
                    printf(" \n");
                }

                if (o2)
                {
                    printf("%s ", pts[ii].odp_2.c_str());

                    if (po2 != 0)
                    {
                        printf("%d %%", po2);
                    }

                    printf("\n");
                }
                else
                {
                    printf(" \n");
                }

                if (o3)
                {
                    printf("%s ", pts[ii].odp_3.c_str());

                    if (po3 != 0)
                    {
                        printf("%d %%", po3);
                    }

                    printf("\n");
                }
                else
                {
                    printf(" \n");
                }

                if (o4)
                {
                    printf("%s ", pts[ii].odp_4.c_str());

                    if (po4 != 0)
                    {
                        printf("%d %%", po4);
                    }

                    printf("\n");
                }
                else
                {
                    printf(" \n");
                }

                if (k1 && k2 && k3)
                {
                    PlaySound(TEXT("kolo.wav"), NULL, SND_FILENAME);
                }

            }
            else
            {
                
                if (p6 == 0)
                {

                    if (string(1, 'a') == pts[ii].prawidlowa)
                    {
                        po1 = p1;
                        po2 = p2;
                        po3 = p3;
                        po4 = p4;
                    }


                    if (string(1, 'b') == pts[ii].prawidlowa)
                    {
                        po1 = p2;
                        po2 = p1;
                        po3 = p3;
                        po4 = p4;
                    }


                    if (string(1, 'c') == pts[ii].prawidlowa)
                    {
                        po1 = p4;
                        po2 = p3;
                        po3 = p1;
                        po4 = p2;
                    }

                    if (string(1, 'd') == pts[ii].prawidlowa)
                    {
                        po1 = p2;
                        po2 = p4;
                        po3 = p3;
                        po4 = p1;
                    }
                }
                else
                {

                    po1 = p5;
                    po2 = p5;
                    po3 = p5;
                    po4 = p5;


                    //Zaznaczanie prawid³owej odpowiedzi do wyswietlenia -------------------------------------------------------
                    if (string(1, 'a') == pts[ii].prawidlowa)
                    {                       
                        po1 = p6;
                    }
                    else

                    if (string(1, 'b') == pts[ii].prawidlowa)
                    {                        
                        po2 = p6;
                    }
                    else

                    if (string(1, 'c') == pts[ii].prawidlowa)
                    {                        
                        po3 = p6;
                    }
                    else

                    if (string(1, 'd') == pts[ii].prawidlowa)
                    {
                        po4 = p6;
                    }

                }




                if (o1)
                {
                    printf("%s ", pts[ii].odp_1.c_str());

                    if (po1 != 0)
                    {
                        printf("%d %%", po1);
                    }

                    printf("\n");
                }
                else
                {
                    printf("\n");
                }

                if (o2)
                {
                    printf("%s ", pts[ii].odp_2.c_str());

                    if (po2 != 0)
                    {
                        printf("%d %%", po2);
                    }

                    printf("\n");
                }
                else
                {
                    printf("\n");
                }

                if (o3)
                {
                    printf("%s ", pts[ii].odp_3.c_str());

                    if (po3 != 0)
                    {
                        printf("%d %%", po3);
                    }

                    printf("\n");
                }
                else
                {
                    printf("\n");
                }

                if (o4)
                {
                    printf("%s ", pts[ii].odp_4.c_str());

                    if (po4 != 0)
                    {
                        printf("%d %%", po4);
                    }

                    printf("\n");
                }
                else
                {
                    printf("\n");
                }

            }
            printf("\n");
            

            


            //Telefon do przyjaciela -------------------------------------------------------
            if (string(1, wybrana) == string(1, '3'))
            {
                printf("Dzwonimy do przyjaciela... \n");
                PlaySound(TEXT("telefon_1.wav"), NULL, SND_FILENAME);
                PlaySound(TEXT("sygnal.wav"), NULL, SND_FILENAME);
                PlaySound(TEXT("sygnal.wav"), NULL, SND_FILENAME);
                PlaySound(TEXT("sygnal.wav"), NULL, SND_FILENAME);
                PlaySound(TEXT("sygnal.wav"), NULL, SND_FILENAME);
                PlaySound(TEXT("telefon_2.wav"), NULL, SND_FILENAME);
                printf("\n");
                printf("Niestety przyjaciel nie odebral telefonu :)\n");

                if (k1 && k2 && k3)
                {
                    PlaySound(TEXT("kolo.wav"), NULL, SND_FILENAME);
                }
            }
            printf("\n");



            wybrana = Wybierz_odpowiedz();

            if(string(1, wybrana) == string(1, '1'))
            {
                k1 = true;
            }

            if (string(1, wybrana) == string(1, '2'))
            {
                k2 = true;
            }

            if (string(1, wybrana) == string(1, '3'))
            {
                k3 = true; 
            }
           

        
        } while (string(1, wybrana) == string(1, '1') || string(1, wybrana) == string(1, '2') || string(1, wybrana) == string(1, '3'));
        

        //Odpowiedz zostala wybrana -------------------------------------------------------

        
        PlaySound(NULL, NULL, SND_ASYNC);

        if (string(1, wybrana) == string(1, 'q'))
        {
            printf("Do zobaczenia nastepnym razem!\n");
            return 0;
        }
#if _DEBUG == FALSE
        PlaySound(TEXT("emocje.wav"), NULL, SND_FILENAME);
#endif
        if (string(1,wybrana) == pts[ii].prawidlowa)
        {
            printf("Prawidlowa odpowiedz to: %s\n\n", pts[ii].prawidlowa.c_str());
#if _DEBUG == FALSE
            PlaySound(TEXT("poczatek.wav"), NULL, SND_FILENAME);
#endif
            PressAKeyToContinue();
        }
        else
        {
            PlaySound(TEXT("zla_odp.wav"), NULL, SND_FILENAME);
            printf("Niestety zla odpowiedz\n");
            return 0;
        }

       

    }

    printf("Gratulacje, udalo Ci sie zdobyc glowna nagrode - milion zlotych!! \n\n");
    PlaySound(TEXT("Wygrana.wav"), NULL, SND_FILENAME);
    printf("Aby odebrac nagrode skontaktuj sie z naszym sponsorem :) \n");
    printf("Powodzenia!!!\n\n");

}

