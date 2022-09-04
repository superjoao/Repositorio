#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <clocale>

using namespace std;

//Construção padrão do personagem
typedef struct Npokemon
{
    string nome;
    int tipo;
    int health;
    int hp;
    int atk;
    int def;
    int spAtk;
    int spDef;
    int vel;
}personagem; personagem p[1];

void battle(int i, int j, int turn, int incinerar, int afogamento, int enraizar);
void imprimirPersonagem (int i, int j);
void bag(int i, int j, int incinerar, int afogamento);


// Diz a posição da flecha no menu
void arrow (int position, int arrowPosition){
    (position == arrowPosition) ? cout <<"-> " : cout <<"  ";
}

//barra de vida.
void hpBar(int i){
    setlocale(LC_ALL, "");
    int hpPorcentagem = p[i].health* 10.0;
    cout << "HP: " << p[i].hp << "/" << p[i].health;
}

// Dano tomado no HP do oponente
int hpDamange (int i, int dam){
    return (i == 1) ? p[1].health -= dam : p[0].health -= dam;
}
// Dano do ataque
int atkDamange (personagem p, int atk, int porcent){
    srand(time(0));
    int dano, accurracy = rand()%100;
    if (accurracy <= porcent )
    {
        dano = p.atk + atk;
        return dano;
    }else{
        cout << "Voce errou o ataque." << endl;
        return dano = 0;
    }
    
    return 0;
}

// Dano do ataque especial
int spAtkDamange (personagem p, int spAtk, int porcent){
    srand(time(0));
    int dano, accurracy = rand()%100;
    if (accurracy <= porcent )
    {
        dano = p.spAtk + spAtk;
        return dano;
    }else{
        cout << "Voce errou o ataque." << endl;
        return dano = 0;
    }
    
    return 0;
}

//Menu dos Golpes
void attack (int i, int j, int turn, int incinerar, int afogamento, int enraizar){
    
    #define MENU_ATTACK_MAX 4
    #define MENU_ATTACK_MIN 1
    setlocale(LC_ALL, "Portuguese");
    int position = 1, arrowPress, atk=0, spAtk=0, dam=0;
    if (p[i].tipo == 1)
    {
        do
        {
            system("CLS");
            imprimirPersonagem(i, j);
            cout << "  turno do: "<< p[i].nome << endl;
            cout << "  ----------------------------------" << endl;
            arrow(1,position); cout << "|[atk]   -Arranhao     +1d/100%% |" << endl;
            arrow(2,position); cout << "|[status]-intimidaçao  / -1atk   |" << endl;
            arrow(3,position); cout << "|[status]-incinerar    / +2dCont |" << endl;
            arrow(4,position); cout << "|[spAtk] -bola de fogo +4d/80%%  |" << endl;
            cout << "  ----------------------------------" << endl;
            cout << "  use as setas ↑↓" << endl;
            arrowPress = getch();
            fflush(stdin);
            
            
            if (arrowPress == 80 && position != MENU_ATTACK_MAX)
            {
                position++;
            }else if (arrowPress == 72 && position != MENU_ATTACK_MIN)
            {
                position--;
            }else{
                position = position;
            }
            
            
        } while (arrowPress != 13);

        if(incinerar >0){
            if((turn+2) %2 !=0){
                cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
                cout << " |- 2d devido a incineracao.|" << endl;
                cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
                p[j].health -= 2;
                incinerar--;
            }
            
        }

        switch (position)
        {
        case 1:
            atk = 1;
            dam = atkDamange(p[i], atk, 100);
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << " |" << p[i].nome << " usou Arranhao causando " << dam << " dano.|"  << endl;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=" << endl;
            hpDamange (j, dam);
            cout << " Precione Qualquer tecla para continuar" << endl;
            getch();
            battle(i, j, turn, incinerar, afogamento, enraizar);
            break;
        case 2:
            p[j].atk -=1;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << " |" << p[i].nome << " Intimidou seu adversario diminunido em 1 pt o ataque inimigo.|" << endl;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << " Precione Qualquer tecla para continuar" << endl;
            getch();
            battle(i, j, turn, incinerar, afogamento, enraizar);
            break;
        case 3:
            if (incinerar >0)
            {
                cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=" << endl;
                cout << " |O inimigo ja esta sobre o efeito do ataque, escolha outro golpe.|" << endl;
                cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=" << endl;
                getch();
                return attack(i,j,turn, incinerar, afogamento, enraizar);
            }
            incinerar = 4;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-" << endl;
            cout << " |" << p[i].nome << " Incinerou seu oponente 2d por 5 turnos.|" << endl;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-" << endl;
            p[j].health -= 2;
            cout << " Precione Qualquer tecla para continuar" << endl;
            getch();
            battle(i, j, turn, incinerar, afogamento, enraizar);
            break;
        case 4:
            spAtk = 4;
            dam = spAtkDamange(p[i], spAtk, 80);
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-" << endl;
            cout << " |" << p[i].nome << " usou Bola de fogo causando " << dam << " dano.|" << endl;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-" << endl;
            cout << " Precione Qualquer tecla para continuar" << endl;
            hpDamange(j, dam);
            getch();
            battle(i, j, turn, incinerar, afogamento, enraizar);
            break;
        default:
            break;
        }
    }

    if (p[i].tipo == 2)
    {
        do
        {
            system("CLS");
            imprimirPersonagem(i, j);
            cout << "  turno do: "<< p[i].nome << endl;
            cout << "  ----------------------------------" << endl;
            arrow(1,position); cout << "|[atk]   -rabada        +1d/100%% |" << endl;
            arrow(2,position); cout << "|[status]-cara de bebe  / -1spAt  |" << endl;
            arrow(3,position); cout << "|[status]-afogamento    / +2dCont |" << endl;
            arrow(4,position); cout << "|[spAtk] -Jato de Agua  +4d/80%%  |" << endl;
            cout << "  ----------------------------------" << endl;
            cout << " use as setas ↑↓" << endl;
            arrowPress = getch();
            fflush(stdin);
            if(afogamento >0){
                cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
                cout << " |- 2d devido estar sendo afogado.|" << endl;
                cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
                p[j].health -= 2; 
            } 
            
            if (arrowPress == 80 && position != MENU_ATTACK_MAX)
            {
                position++;
            }else if (arrowPress == 72 && position != MENU_ATTACK_MIN)
            {
                position--;
            }else{
                position = position;
            }
            
            
        } while (arrowPress != 13);

        if(afogamento >0){
            if((turn+2) %2 !=0){
                cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
                cout << " |- 2d devido a incineracao.|" << endl;
                cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
                p[j].health -= 2;
                afogamento--;
            }
            
        }
        switch (position)
        {
        case 1:
            atk = 1;
            dam = atkDamange(p[i], atk, 100);
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-" << endl;
            cout << " |" << p[i].nome << " usou rabada causando " << dam << " dano.|"  << endl;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-" << endl;
            cout << " Precione Qualquer tecla para continuar" << endl;
            hpDamange(j, dam);
            getch();
            battle(i, j, turn, incinerar, afogamento, enraizar);
            break;
        case 2:
            p[j].spAtk -=1; 
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
            cout << " |" << p[i].nome << " encantou seu adversario diminunido em 1 pt de ataque especial do inimigo.|" << endl;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
            cout << " Precione Qualquer tecla para continuar" << endl;
            getch();
            battle(i, j, turn, incinerar, afogamento, enraizar);
            break;
        case 3:
            if (afogamento >0)
            {
                cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=" << endl;
                cout << " |O inimigo ja esta bobre o efeito do ataque, escolha outro golpe.|" << endl;
                cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=" << endl;
                attack(i,j,turn, incinerar, afogamento, enraizar);
            }
            afogamento = 5;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << " |" << p[i].nome << " Esta a afogar seu oponente 2d por 5 turnos.|" << endl;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << " Precione Qualquer tecla para continuar" << endl;
            getch();
            battle(i, j, turn, incinerar, afogamento, enraizar);
            break;
        case 4:
            spAtk = 4;
            dam = spAtkDamange (p[i], spAtk, 80);
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << " |" << p[i].nome << " usou Jato de agua causando " << dam << " dano.|" << endl;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << " Precione Qualquer tecla para continuar" << endl;
            hpDamange(j, dam);
            getch();
            battle(i, j, turn, incinerar, afogamento, enraizar);
            break;
        default:
            break;
        }
    }

    if (p[i].tipo == 3)
    {
        do
        {
            system("CLS");
            imprimirPersonagem(i, j);
            cout << "  turno do: "<< p[i].nome << endl;
            cout << "  ----------------------------------" << endl;
            arrow(1,position); cout << "|[atk]   -cabeçada      +1d/100%% |" << endl;
            arrow(2,position); cout << "|[status]-atordoante   / -1vel    |" << endl;
            arrow(3,position); cout << "|[status]-enraizar     / +2HPCont |" << endl;
            arrow(4,position); cout << "|[spAtk] -galhada       +4d/80%%  |" << endl;
            cout << "  ----------------------------------" << endl;
            cout << " use as setas ↑↓" << endl;
            arrowPress = getch();
            fflush(stdin);
            if(enraizar >0){
                cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
                cout << " |+ 2HP, esta absorvendo energia da terra.|" << endl;
                cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
                p[i].health += 2; 
            } 
            
            if (arrowPress == 80 && position != MENU_ATTACK_MAX)
            {
                position++;
            }else if (arrowPress == 72 && position != MENU_ATTACK_MIN)
            {
                position--;
            }else{
                position = position;
            }
            
            
        } while (arrowPress != 13);

        if(enraizar >0){
            if((turn+1) %2 !=0){
                cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
                cout << " |- 2d devido a incineracao.|" << endl;
                cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
                p[j].health += 2;
                enraizar--;
            }
            
        }
        switch (position)
        {
        case 1:
            atk = 1;
            dam = atkDamange(p[i], atk, 100);
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << " |" << p[i].nome << " usou cabecada causando " << dam << " dano.|"  << endl;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << " Precione Qualquer tecla para continuar" << endl;
            hpDamange(j, dam);
            getch();
            battle(i, j, turn, incinerar, afogamento, enraizar);
            break;
        case 2:
            p[j].vel -=1; 
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << " |" << p[i].nome << " atordoou seu adversario diminunido em 1 pt de velocidade do inimigo.|" << endl;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << " Precione Qualquer tecla para continuar" << endl;
            getch();
            battle(i, j, turn, incinerar, afogamento, enraizar);
            break;
        case 3:
            enraizar = 5;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
            cout << " |" << p[i].nome << " Esta juntando nutrientes da terra, +2hp por 5 turnos.|" << endl;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
            cout << " Precione Qualquer tecla para continuar" << endl;
            getch();
            battle(i, j, turn, incinerar, afogamento, enraizar);
            break;
        case 4:
            spAtk = 4;
            dam = spAtkDamange (p[i], spAtk, 80);
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << " |" << p[i].nome << " usou galhada causando " << dam << " dano.|" << endl;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << " Precione Qualquer tecla para continuar" << endl;
            hpDamange(j, dam);
            getch();
            battle(i, j, turn, incinerar, afogamento, enraizar);
            break;
        default:
            break;
        }
        
    }

    if (p[i].tipo >= 4)
    {
        do
        {
            system("CLS");
            imprimirPersonagem(i, j);
            cout << "  turno do: "<< p[i].nome << endl;
            cout << "  ----------------------------------" << endl;
            arrow(1,position); cout << "|[atk]   -Soco           +2d/100%% |" << endl;
            arrow(2,position); cout << "|[status]-concentracao  / +1atk's  |" << endl;
            arrow(3,position); cout << "|[status]-endurecer     / +1def's  |" << endl;
            arrow(4,position); cout << "|[spAtk] -barrigad        +3d/90%%  |" << endl;
            cout << "  ----------------------------------" << endl;
            cout << " use as setas ↑↓" << endl;
            arrowPress = getch();
            fflush(stdin);
            
            if (arrowPress == 80 && position != MENU_ATTACK_MAX)
            {
                position++;
            }else if (arrowPress == 72 && position != MENU_ATTACK_MIN)
            {
                position--;
            }else{
                position = position;
            }
            
            
        } while (arrowPress != 13);

        switch (position)
        {
        case 1:
            atk = 2;
            dam = atkDamange(p[i], atk, 100);
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
            cout << " |" << p[i].nome << " usou soco causando " << dam << " dano|"  << endl;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
            cout << " Precione Qualquer tecla para continuar" << endl;
            hpDamange(j, dam);
            getch();
            battle(i, j, turn, incinerar, afogamento, enraizar);
            break;
        case 2:
            p[i].atk +=1;
            p[i].spAtk +=1;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl; 
            cout << "| " << p[i].nome << " melhorou sua concentração aumentando em 1 pt seus ataques.|" << endl;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
            cout << " Precione Qualquer tecla para continuar" << endl;
            getch();
            battle(i, j, turn, incinerar, afogamento, enraizar);
            break;
        case 3:
            p[i].def +=1;
            p[i].spDef +=1; 
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
            cout << " |" << p[i].nome << " endureceu melhorando suas defesas em 1pt|" << endl;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
            cout << " Precione Qualquer tecla para continuar" << endl;
            getch();
            battle(i, j, turn, incinerar, afogamento, enraizar);
            break;
        case 4:
            spAtk = 3;
            dam = spAtkDamange (p[i], spAtk, 90);
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << "|" << p[i].nome << " usou barrigada causando " << dam << " dano.|" << endl;
            cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << " Precione Qualquer tecla para continuar" << endl;
            hpDamange(j, dam);
            getch();
            battle(i, j, turn, incinerar, afogamento, enraizar);
            break;
        default:
            break;
        }
    } 
}
//Retorna o atacante da rodada.(*erro: ambiguos)
int battleTurn(int i, int j, int turn){
    
    return (turn %2 != 0)? i : j;
}
// Decide quem começa a atacar primeiro.
int myTurn1 (){
    srand(time(0));
    return (p[0].vel > p[1].vel) ? 0 : (p[1].vel > p[0].vel) ? 1 : rand()%1;
}
// Decide quem ataca depois
int myTurn2 (int i){
    
    return (i ==1)? 0 :1; 
}

//Menu da mochila
void bag(int i, int j, int incinerar, int afogamento){
    #define MENU_BAG_MAX 4
    #define MENU_BAG_MIN 1
    setlocale(LC_ALL, "Portuguese");
    int position = 1, arrowPress;
    do
    {
        system("CLS");
        imprimirPersonagem(i,j);
        cout << "  turno do: "<< p[i].nome << endl;
        cout << "  ---------" << endl;
        arrow(1,position); cout << "|pocao +10hp |" << endl;
        arrow(2,position); cout << "|desincinerar|" << endl;
        arrow(3,position); cout << "|  desafogar |" << endl;
        arrow(4,position); cout << "|    sair    |" << endl;
        cout << "  ---------" << endl;
        cout << " use as setas ↑↓" << endl;
        arrowPress = getch();
        fflush(stdin);
        
        
        if (arrowPress == 80 && position != MENU_BAG_MAX)
        {
            position++;
        }else if (arrowPress == 72 && position != MENU_BAG_MIN)
        {
            position--;
        }else{
            position = position;
        }
            
    } while (arrowPress != 13);

    switch (position){
    case 1:
        if (p[i].hp == p[i].health)
        {
            cout << " =-=-=-=-=-=-=-=-=-" << endl;
            cout << "|HP Ja esta cheio.|" << endl;
            cout << " =-=-=-=-=-=-=-=-=-" << endl;
            bag(i,j, incinerar, afogamento);
        }
        
        p[i].health +=10;
        cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << "|" << p[i].nome <<  "recuperou 10 de HP.|" << endl;
        cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        break;
    case 2:
        incinerar = 0;
        cout << " =-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cout << "|" << p[i].nome <<  " parou de queimar.|" << endl;
        cout << " =-=-=-=-=-=-=-=-=-=-=-=" << endl;
        break;
    case 3:
        afogamento = 0;
        cout << " =-=-=-=-=-=-=-=-=-=-=" << endl;
        cout << "|" << p[i].nome <<  " desafogou.|" << endl;
        cout << " =-=-=-=-=-=-=-=-=-=-=" << endl;
        break;
    default:
        break;
    }
}
//Menu de Batalha
void battle(int i, int j, int turn, int incinerar, int afogamento, int enraizar ){
    
    #define MENU_BATTLE_MAX 4
    #define MENU_BATTLE_MIN 1
    setlocale(LC_ALL, "Portuguese");
    int position = 1, arrowPress, k, w;
    i = myTurn1();
    j = myTurn2(i);
    k = battleTurn(i, j, turn);
    w = (k == 1)?0 :1;
    if (p[i].health <= 0){
        cout << " =-=-=-=-=-=-=-=-=-" << endl;
        cout << " |Vitoria do " << p[j].nome << "|" << endl;
        cout << " =-=-=-=-=-=-=-=-=-" << endl;
        return;
    }else if (p[j].health <= 0)
    {   cout << " =-=-=-=-=-=-=-=-=-" << endl;
        cout << " |Vitoria do " << p[i].nome << "|" << endl;
        cout << " =-=-=-=-=-=-=-=-=-" << endl;
        return;
    }else{
        do
        {
            system("CLS");
            imprimirPersonagem(k,w);
            cout << "  turno do: "<< p[k].nome << endl;
            cout << "  ---------" << endl;
            arrow(1,position); cout << "|atacar |" << endl;
            arrow(2,position); cout << "|mochila|" << endl;
            arrow(3,position); cout << "|trocar |" << endl;
            arrow(4,position); cout << "| fugir |" << endl;
            cout << "  ---------" << endl;
            cout << " use as setas ↑↓" << endl;
            arrowPress = getch();
            fflush(stdin);
            
            
            if (arrowPress == 80 && position != MENU_BATTLE_MAX)
            {
                position++;
            }else if (arrowPress == 72 && position != MENU_BATTLE_MIN)
            {
                position--;
            }else{
                position = position;
            }
            
        } while (arrowPress != 13);

        switch (position)
        {
        case 1:
            turn++;
            attack(k, w, turn, incinerar, afogamento, enraizar);
            break;
        case 4:
            cout << " =-=-=-=-=-=-=-=-=-" << endl;
            cout << " |desistiu " << p[k].nome << "|" << endl;
            cout << " =-=-=-=-=-=-=-=-=-" << endl;
            break;
        default:
            break;
        }

    }

}

//imprime os dados do personagem
void imprimirPersonagem (int i, int j){
    
    setlocale(LC_ALL, "Portuguese");
    hpBar(i);cout <<"              ";hpBar(j);
    cout <<                                                               endl;  
    cout << "|    ficha do P1    |" << "  " << "|    ficha do P2    |" << endl;
    cout << "|___________________|" << "  " << "|___________________|" << endl;
    cout << "|                   |" << "  " << "|                   |" << endl;
    cout << "|Nome:  "<< p[i].nome <<"        |" << "  " <<  "|Nome:  "<< p[j].nome <<"         |" << endl;
    
    switch (p[i].tipo)
    {
    case 1:
        cout << "|tipo:  Fogo        |";
        break;
    case 2:
        cout << "|tipo:  Agua        |";
        break;
    case 3:
        cout << "|tipo:  Planta      |";
        break;
    default:
        cout << "|tipo:  Normal      |";
        break;
    }
    switch (p[j].tipo)
    {
    case 1:
        cout << "  " << "|tipo:  Fogo        |";
        break;
    case 2:
        cout << "  " << "|tipo:  Agua        |";
        break;
    case 3:
        cout << "  " << "|tipo:  Planta      |";
        break;
    default:
        cout << "  " << "|tipo:  Normal      |";
        break;
    }
    cout << endl;
    cout << "|HP:    "<< p[i].hp  <<"          |" << "  "  << "|HP:    "<< p[j].hp  <<"          |" << endl;
    cout << "|atk:   "<< p[i].atk <<"           |" << "  " << "|atk:   "<< p[j].atk <<"           |" << endl;
    cout << "|def:   "<< p[i].def <<"           |" << "  " << "|def:   "<< p[j].def <<"           |" << endl;
    cout << "|spAtk: "<<p[i].spAtk<<"           |" << "  " << "|spAtk: "<<p[j].spAtk<<"           |" << endl;
    cout << "|spDef: "<<p[i].spDef<<"           |" << "  " << "|spDef: "<<p[j].spDef<<"           |" << endl;
    cout << "|vel:   "<< p[i].vel <<"           |" << "  " << "|vel:   " << p[j].vel <<"           |" << endl;
    cout << "---------------------"              <<  "-----------------------"               << endl;
}

//criar NPC
personagem criarNpc (int i){
    
    // Gerar numeros aleatorios conforme o tempo
    srand(time(0));
    
    //criar personagem
    p[i].nome  =  "NPC";
    p[i].tipo  = (rand()%3) +1;
    p[i].atk   = (rand()%5) +1;
    p[i].def   = (rand()%5) +1;
    p[i].spAtk = (rand()%5) +1;
    p[i].spDef = (rand()%5) +1;
    p[i].vel   = (rand()%5) +1;
    p[i].hp    = (p[i].def + p[i].spDef +5)*3;
    p[i].health= p[i].hp;

    return p[i];
}

//Cria o personagem
personagem criarPersonagem (int i){
    
    setlocale(LC_ALL, "Portuguese");
    // Gerar numeros aleatorios conforme o tempo
    srand(time(0));

    //criar personagem
    cout << "Criacao do Personagem:" << endl;
    cout << "______________________" << endl;
    cout << "seu nome?  " << endl;
    getline (cin, p[i].nome);
    cout << "Elemento:  " << endl;
    cout << "-----------" << endl;
    cout << "Fogo  [1]"   << endl;
    cout << "Agua  [2]"   << endl;
    cout << "Planta[3]"   << endl;
    cout << "Normal[n/c]" << endl;
    cout <<                  endl;
    cin  >> p[i].tipo;
    p[i].atk   = (rand()%5) +1;
    p[i].def   = (rand()%5) +1;
    p[i].spAtk = (rand()%5) +1;
    p[i].spDef = (rand()%5) +1;
    p[i].vel   = (rand()%5) +1;
    p[i].hp    = (p[i].def + p[i].spDef +5)*3;
    p[i].health= p[i].hp;
    return p[i];
}
/*
void init (int i){
    p[i].nome = "\0";
    p[i].tipo = NULL;
    p[i].hp = NULL;
    p[i].atk = NULL;
    p[i].def = NULL;
    p[i].spAtk = NULL;
    p[i].spDef = NULL;
    p[i].vel = NULL;
}
*/
int main(int argc, char const *argv[])
{

    #define MENU_MAX 4
    #define MENU_MIN 1
    setlocale(LC_ALL, "Portuguese");
    int opc = 1, position = 1, arrowPress;
    
    //Menu
    do
    {
        
        cout << "  _________________" << endl;
        cout << "  |escolha a opc: |" << endl;
        cout << "  |---------------|" << endl;
        arrow(1,position); cout << "|   1 Jogador   |" << endl;
        arrow(2,position); cout << "|   2 Jogador   |" << endl;
        arrow(3,position); cout << "|    Creditos   |" << endl;
        arrow(4,position); cout << "|      Sair     |" << endl;
        cout << "  |_______________|" << endl;
        cout << " opc: ";
        
        cout << "use as setas cima baixo" << endl;
        arrowPress = getch();
        system("CLS");
        fflush(stdin);
        
        
        if (arrowPress == 80 && position != MENU_MAX)
        {
            position++;
        }else if (arrowPress == 72 && position != MENU_MIN)
        {
            position--;
        }else{
            position = position;
        }
        
        
    } while (arrowPress != 13);

        
    switch (position)
    {
    case 1:
        criarPersonagem(0);
        criarNpc(1);
        system("CLS");
        imprimirPersonagem(0, 1);
        cout << "Precione Qualquer tecla para continuar" << endl;
        getch();
        battle(0,1,0, 0, 0, 0);
        break;
    
    default:
        break;
    }
    return 0;
}