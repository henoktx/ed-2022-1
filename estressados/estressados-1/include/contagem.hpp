#pragma once
#include <iostream>
#include <vector>

using namespace std;

float calcular_stress_medio(vector<int> fila) 
{
    float soma, media;
    
    for (int i = 0; i < int(fila.size()); i++) {
        soma += fila[i];
    }

    media = soma / int(fila.size());

    return abs(media);
}

string mais_homens_ou_mulheres(vector<int> fila)
{
    int homens = 0, mulheres = 0;

    for (int i = 0; i < int(fila.size()); i++) {
        if (fila[i] > 0)
            homens++;
        else    
            mulheres++;
    }

    if (homens > mulheres)
        return "homens";
    else if (mulheres > homens)
        return "mulheres";
    else 
        return "empate";
}

string qual_metade_eh_mais_estressada(vector<int> fila)
{
    float primeira_metade = 0, segunda_metade = 0, media_primeira_metade, media_segunda_metade;
    
    for (int i = 0; i < int(fila.size()); i++) {
        if (i < (int(fila.size() / 2))) 
            primeira_metade += abs(fila[i]);
        else
            segunda_metade += abs(fila[i]);
    }

    media_primeira_metade = primeira_metade / int(fila.size() / 2);
    media_segunda_metade = segunda_metade / int(fila.size() / 2);

    if (media_primeira_metade >  media_segunda_metade) 
        return "primeira";
    else if (media_segunda_metade > media_primeira_metade)
        return "segunda";
    else 
        return "empate";
}

bool homens_sao_mais_estressados_que_mulheres(vector<int> fila) 
{
    float soma_homens = 0, soma_mulheres = 0, media_homens, media_mulheres;
    int cont_homens = 0, cont_mulheres = 0;

    for (int i = 0; i < int(fila.size()); i++) {
        if (fila [i] > 0) {
            soma_homens += fila[i];
            cont_homens++;
        } else {  
            soma_mulheres += abs(fila[i]);
            cont_mulheres++;
        }
    }

    media_homens = soma_homens / cont_homens;
    media_mulheres = soma_mulheres / cont_mulheres;

    if (media_homens > media_mulheres)
        return true;
    else if (media_mulheres > media_homens)
        return false;
    else 
        return false;

}