
void playHit();

class MapObject
{
public:
    unsigned short x;
    unsigned short y;
    unsigned short colided;
    ALLEGRO_BITMAP *image;
    
    

    MapObject()
    {
        this->x = 0;
        this->y = 0;
        this->colided = 0;
        this->image = NULL;
        
        

    }

   /* MapObject(const char path)
    {
        this->x = 0;
        this->y = 0;
        this->colided = 0;
        this->image = ;

    }*/

    ~MapObject()
    {
        al_destroy_bitmap(this->image);
        
   
    }

    void checkCollision(MapObject& wooden_stick)
    {

        if ((this->x == wooden_stick.x) && (this->y == wooden_stick.y))
        {
            wooden_stick.x = rand() % 20;
            wooden_stick.y = rand() % 20;

            this->colided++;

            playHit();
        }

    }
    void loadImage(const char *path)
    {
        this->image = al_create_bitmap(40, 40);
        al_set_target_bitmap(this->image);
        this->image = al_load_bitmap(path);
    }


}wooden_stick,grass,player1;
