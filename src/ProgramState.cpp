//
// Created by nicho on 11/26/2023.
//

#include "ProgramState.h"

ProgramState::BraveryStatus ProgramState::getBraveryStatus() {
    if (state == 0){
        return CHAMP_SELECT;
    } else if (state == 1){
        return ITEM_SELECT;
    } else {
        return PLAYING;
    }
}

void ProgramState::setBraveryStatus(ProgramState::BraveryStatus _status) {
    state = _status;
}

ProgramState::ProgramState() {
    state = CHAMP_SELECT;
}

