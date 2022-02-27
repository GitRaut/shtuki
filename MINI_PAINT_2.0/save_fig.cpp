#include "mini_paint.h"

void save_to_file(vector<vector<char>>&coordinats){
    ofstream out("result_operation_file.it", std::ofstream::out | std::ofstream::trunc);// ios::app);
    if (out.is_open())
    {
        for(int y=0;y<coordinats.size();y++)
        {
            string str="";
            for(int x=0;x<coordinats[y].size();x++)
            {
                str=str+coordinats[y][x];
            }
            out << str<< endl;
        }

    }
    out.close();
}
void rectangle_save(int xrec,int yrec,int width, int height, char kontur, int resolution_height,int resolution_width, char fil, bool fil_bool,vector<vector<char>>&coordinats)
{
    for(int y = 0; y < resolution_height; y++)
    {
        //OORD pos_y = {xrec, y};
        //SetConsoleCursorPosition(hConsole, pos_y);
        //coordinats[9][9]=kontur;
        if(y == yrec || y == yrec + height-1)
        {
            for(int x = xrec; x < xrec + width; x++)
            {
                if(x>=0 && x<=resolution_width && y>=0 && y<=resolution_height)
                {
                coordinats[y][x]=kontur;
                //cout << kontur;
                }
            }
            //cout << endl;
        }else if(y > yrec && y < yrec + height){
            for(int x = 0; x < resolution_width; x++)
            {
                if(x == xrec || x == xrec + width-1)
                {
                    //COORD pos_x = {x, y};
                    if(x>=0 && x<=resolution_width && y>=0 && y<=resolution_height)
                    {
                        coordinats[y][x]=kontur;
                //cout << kontur;
                    }
                    //coordinats[y][x]=kontur;
                    //SetConsoleCursorPosition(hConsole, pos_x);
                    //cout << kontur;
                }
                if(fil_bool == true && x > xrec && x < xrec + width-1 )
                {
                    if(x>=0 && x<=resolution_width && y>=0 && y<=resolution_height)
                    {
                        coordinats[y][x]=fil;
                        //cout << kontur;
                     }
                    //coordinats[y][x]='f';
                    //cout << fil;
                }
            }
            //cout << endl;
        }
    }
}
void circle_save(int X1, int Y1, int R, char kontur, char fil,bool fil_bool,int resolution_width,int resolution_height,vector<vector<char>>&coordinats)
{
    int x = 0;
    int y = R;
   int delta = 1 - 2 * R;
   int error = 0;
   while (y >= x)
   {
       if(X1+x<=resolution_width && Y1+y<resolution_height)
       {
       //gotoxy(X1+x,Y1+y);
       //cout<<kontur;
       coordinats[Y1+y][X1+x]=kontur;
       }
       if(X1+x<resolution_width && Y1-y>=0)
       {
       //xpoint.push_back(X1 + x);ypoint.push_back(Y1 + y);
       //gotoxy(X1+x,Y1-y);
       //cout<<kontur;
       coordinats[Y1-y][X1+x]=kontur;
       }
       if(X1-x>=0 && Y1+y<resolution_height)
       {
       //xpoint.push_back(X1 + x);ypoint.push_back(Y1 - y);
       //gotoxy(X1-x,Y1+y);
       //cout<<kontur;
       coordinats[Y1+y][X1-x]=kontur;
       }
       if(X1-x>=0 && Y1-y>=0)
       {
       //xpoint.push_back(X1 - x);ypoint.push_back(Y1 + y);
       //gotoxy(X1-x,Y1-y);
       //cout<<kontur;
       coordinats[Y1-y][X1-x]=kontur;
       }
       if(X1+y<resolution_width && Y1+x<=resolution_height)
       {
       //xpoint.push_back(X1 - x);ypoint.push_back(Y1 - y);
       //gotoxy(X1+y,Y1+x);
       //cout<<kontur;
       coordinats[Y1+x][X1+y]=kontur;
       }
       if(X1+y<resolution_width && Y1-x>=0)
       {
       //xpoint.push_back(X1 + y);ypoint.push_back(Y1 + x);
       //gotoxy(X1+y,Y1-x);
       //cout<<kontur;
       coordinats[Y1-x][X1+y]=kontur;
       }
       if(X1-y>=0 && Y1+x<=resolution_height)
       {
       //xpoint.push_back(X1 + y);ypoint.push_back(Y1 - x);
       //gotoxy(X1-y,Y1+x);
       //cout<<kontur;
       coordinats[Y1+x][X1-y]=kontur;
       }
       if(X1-y>=0 && Y1-x>=0)
       {
       //xpoint.push_back(X1 - y);ypoint.push_back(Y1 + x);
       //gotoxy(X1-y,Y1-x);
       //cout<<kontur;
       coordinats[Y1-x][X1-y]=kontur;
       }
       //xpoint.push_back(X1 - y);ypoint.push_back(Y1 - x);
       if(fil_bool==true)
       {
           line_save(X1+x,Y1-y+1,X1+x,Y1+y-1,fil,resolution_width,resolution_height,coordinats);
           line_save(X1-x,Y1-y+1,X1-x,Y1+y-1,fil,resolution_width,resolution_height,coordinats);
       }

       error = 2 * (delta + y) - 1;
       if ((delta < 0) && (error <= 0))
       {
           delta += 2 * ++x + 1;
           continue;
       }

       if ((delta > 0) && (error > 0))
       {
          delta -= 2 * --y + 1;
           continue;
       }

       delta += 2 * (++x - --y);
   }

}
void line_save(int x1, int y1, int x2, int y2,char kontur,int resolution_width,int resolution_height,vector<vector<char>>&coordinats)
{
    int dx;
    int dy;

    if(x2 - x1 >= 0)dx = 1;
    else dx = -1;
    if(y2 - y1 >= 0)dy = 1;
    else dy = -1;

    int lengthX = abs(x2 - x1);
    int lengthY = abs(y2 - y1);
    int length = max(lengthX, lengthY);

    if (length == 0)
    {
        //gotoxy(x1,y1);
        //cout<<kontur;
        coordinats[y1][x1]=kontur;
        //SDL_RenderDrawPoint(renderer, x1, y1);
    }

    if (lengthY <= lengthX)
    {
    // Начальные значения
        int x = x1;
        int y = y1;
        int d = -lengthX;
        // Основной цикл
        length++;
        while(length--)
        {
            if(x>=0 && x<=resolution_width && y>=0 && y<=resolution_height)
            {
                //gotoxy(x,y);
                //cout<<kontur;
                coordinats[y][x]=kontur;
            }

            //SDL_RenderDrawPoint(renderer, x, y);
            x += dx;
            d += 2 * lengthY;
            if (d > 0) {
                d -= 2 * lengthX;
                y += dy;
            }
        }
      }
      else
      {
        // Начальные значения
        int x = x1;
        int y = y1;
        int d = - lengthY;
        // Основной цикл
        length++;
        while(length--)
        {
            if(x>=0 && x<=resolution_width && y>=0 && y<=resolution_height)
            {
            //gotoxy(x,y);
            //cout<<kontur;
            coordinats[y][x]=kontur;
            }
            //SDL_RenderDrawPoint(renderer, x, y);
            y += dy;
            d += 2 * lengthX;
            if (d > 0) {
                d -= 2 * lengthY;
                x += dx;
            }
        }
      }
}

void fon_save(char fon_fil, int resolution_width,int resolution_height,vector<vector<char>>&coordinats)
{
    gotoxy(0,0);vector<char>a;
    for(int x=0;x<resolution_width;x++)
    {
        a.push_back(fon_fil);
    }

    for(int y=0;y<resolution_height;y++)
    {
        coordinats.push_back(a);
    }
}
