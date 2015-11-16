#ifndef PLAYER_H
#define PLAYER_H
#include<string>
using namespace std;
enum Result { WIN, LOSE, PUSH, BLACKJACK };

class Player
{
    public:
        //constructor, destructor
        //Player(string name, string ip, int sock, int port);
        Player(int sock, int port, string ip, string name);
        virtual ~Player();

        //getter, setter
        int getSocket();
        string getName();
        void setHand(int hand);
        int getHand();
        void setStand(bool stand);
        bool getStand();
        void setPlaying(bool playing);
        bool getPlaying();

    protected:
    private:
        string name, ip;
        int sock, port, hand;
        bool stand, playing;
};
#endif // PLAYER_H
