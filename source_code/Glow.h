/*
    Developed by Regson Jaques
    https://www.youtube.com/user/tictacKode/playlists
    https://github.com/tictackode
    https://www.facebook.com/groups/ProgDesafios/
*/

#include <allegro5/allegro.h>

class Glow
{
    public:
    int fontaux;
    bool desceCor;
    
    Glow()
    {
        this->desceCor=false;
        this->fontaux=0;

    }
    void reset()
    {
        this->fontaux=0;
        this->desceCor=false;
    }
    
    void glowingColor()
    {
         if((this->fontaux<255)&&(this->desceCor==false))
         { 
             this->fontaux++;
         }
         if(this->fontaux==0)
         {
             this->desceCor=false;
         }
         if(this->fontaux==255)
         {
             this->desceCor=true;
         }
         if((this->fontaux>0)&&(this->desceCor==true))
         {
             this->fontaux--;                     
         }
    }


}glow;
