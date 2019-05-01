//
// Created by Jedson on 4/30/2019.
//

#ifndef AEROTRACKER_ALTERARAERONAVE_H
#define AEROTRACKER_ALTERARAERONAVE_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "../../Inserir/inserirAeronaveUI.h"
#include "../../../../../../../Environment.h"
#include "../../../../../../../core/Aeronave/Aeronave.h"

void alterarAeronave(Aeronave *cliente);

char escolhaAlterarAeronave();

void telaAlterarAeronave();

#endif //AEROTRACKER_ALTERARAERONAVE_H
