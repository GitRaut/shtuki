#ifndef USER_INTERFACE_H_INCLUDED
#define USER_INTERFACE_H_INCLUDED

class User_Interface{
public:
    User_Interface(int width, int height, SDL_Texture* tex);
    ~User_Interface(){}

    void Update_UI(SDL_Renderer* renderer);


    int pl_life;
    int pl_bullets;
    int pl_gun_type;
    int pl_kool_down_bot;
    int kol_bot;
    bool live;


private:
    int x_size;
    int anim_m_stad=10;
    int y_size;
    bool start=true;
    int smesh;
    int time_krov=100;
    int time_back_krov=-1;
    bool time_krov_vis=false;
    SDL_Surface* image;
    SDL_Texture* texture;

};
#endif // USER_INTERFACE_H_INCLUDED
