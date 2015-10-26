#ifndef PLAYER_H
#define PLAYER_H

enum Result { WIN, LOSE, PUSH, BLACKJACK };

class Player
{
    public:
        //constructor, destructor
        Player(string name, string ip, int sock, int port);
        virtual ~Player();

        //getter, setter
        int getSocket();
        string getName();
        void setHand(int hand);
        int getHand();
        void setStand(bool stand);
        bool getStand();
        void setResult(Result r);

    protected:
    private:
        string name, ip;
        int sock, port, hand;
        bool stand;
        Result r;
};
#endif // PLAYER_H
