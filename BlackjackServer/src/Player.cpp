#include "Player.h"

Player::Player(int csock, int cport, string cip, string cname)
{
    //ctor
    this->sock = csock;
    this->port = cport;
    this->ip = cip;
    this->name = cname;
    this->stand = false;
    this->playing = false;
}

Player::~Player()
{
    //dtor
}

int Player::getSocket() {
    return this->sock;
}
string Player::getName() {
    return this->name;
}
void Player::setHand(int hand) {
    this->hand = hand;
}
int Player::getHand() {
    return this->hand;
}
void Player::setStand(bool stand) {
    this->stand = stand;
}
bool Player::getStand() {
    return stand;
}
void Player::setPlaying(bool playing) {
    this->playing = playing;
}
bool Player::getPlaying() {
    return playing;
}

