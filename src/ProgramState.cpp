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
    traversal = DFS;
}

void ProgramState::setChampion(string champion) {
    this->champion = champion;
}

string ProgramState::getChampion() {
    return champion;
}

void ProgramState::setTraversal(int _traversal) {
    traversal = _traversal;
}

ProgramState::Traversal ProgramState::getTraversal() {
    if (traversal == 0){
        return DFS;
    } else {
        return BFS;
    }
}


