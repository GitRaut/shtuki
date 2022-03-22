#ifndef BOT_ROBOT_H_INCLUDED
#define BOT_ROBOT_H_INCLUDED

class Bot_robot{
public:
    Bot_robot(int x, int y, int width, int height, SDL_Texture* tex, int speed);
    ~Bot_robot(){}

    void move_Bot_robot(SDL_Renderer* renderer);



    void get_size(int &width, int &height);
    void set_size(int width, int height);

    void get_position(int &x, int &y);
    void set_position(int x, int y);

    void set_image(SDL_Surface* img);
    void set_texture(SDL_Texture* tex);

    int get_xpos();
    int get_ypos();

    int get_width();
    int get_height();

    bool live;
    int life_bar_bot=140;
    bool null_com=false;

    int shield_prochnost=5;
    bool shield=false;


private:
    Mix_Chunk* laser = Mix_LoadWAV("Sounds\\laser.wav");
    Mix_Chunk* boom = Mix_LoadWAV("Sounds\\rpg_boom.wav");
    float k;
    int x_smesheniye;
    double x_pos;
    double y_pos;
    double x2_pos;
    double y2_pos;
    int screen_x;
    int screen_y;
    double x2_pos_player_old;
    double y2_pos_player_old;
    float Bot_robot_speed;
    int angle_move=0;
    bool textt=true;

    int timebullet=400;
    int timereaction=-1;
    int timeangry;
    bool firs_react=false;
    bool firs_react_old=false;
    int x_size;
    int y_size;
    bool quit = false;
    double angle;
    double angle2;
    double angle3;

    SDL_Surface* image;
    SDL_Texture* texture;
    SDL_Texture* texture_pokoy;
    SDL_Texture* texture_acctive;
    SDL_Texture* texture_angry;
};

#endif // BOT_ROBOT_H_INCLUDED
