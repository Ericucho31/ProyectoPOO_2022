#pragma once
#include "Entidad.h"
#include "Bullets.h"
#include "Player.h"
class Enemy :
    public Entidad
{
public:
    Enemy(string id, Juego* juegoDondeProviene);
    ~Enemy();

    vector <Bullets> balas;

    void Moverse() override;
    void MostrarHP();
    void Disparar();
    void Procesar() override;
};

