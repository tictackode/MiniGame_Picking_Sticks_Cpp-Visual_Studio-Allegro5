

#include "Glow.h"
#include "MapObject.h"

#include <cstdio>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/display.h>

ALLEGRO_EVENT event;
ALLEGRO_KEYBOARD_STATE state;
bool keyPressed = false;


class GameScreen
{
public:

	unsigned short SCREEN_X;
	unsigned short SCREEN_Y;
	unsigned short NUMBER_OF_BLOCKS;
	unsigned short BLOCK_SIDE_SIZE;
	unsigned long int gameCicles;
	ALLEGRO_BITMAP* bufferBackground=NULL; //*buffer;

	GameScreen()
	{
		this->NUMBER_OF_BLOCKS = 20;
		this->BLOCK_SIDE_SIZE = 40;
		this->SCREEN_X = this->BLOCK_SIDE_SIZE * this->NUMBER_OF_BLOCKS;
		this->SCREEN_Y = this->BLOCK_SIDE_SIZE * this->NUMBER_OF_BLOCKS;
		this->gameCicles = 0;
		this->bufferBackground = NULL;
		

	}
	~GameScreen()
	{

	}

	void drawGrass()
	{
		this->bufferBackground = al_create_bitmap(800, 800);
		al_set_target_bitmap(bufferBackground);

		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				al_draw_bitmap(grass.image, (i * 40.0), (j * 40.0), 0);
				//al_draw_rectangle((i * 40.0), (j * 40.0), (i * 40.0) + 40, (j * 40.0) + 40, al_map_rgb(0, 255, 0),5);
			}
		}

	}

	void drawScreen()
	{

		al_draw_bitmap(bufferBackground, 0, 0, 0);

		al_draw_bitmap(player1.image, (player1.x * this->BLOCK_SIDE_SIZE), (player1.y * this->BLOCK_SIDE_SIZE), 0);
		//al_draw_filled_rectangle(player1.x * this->BLOCK_SIDE_SIZE, player1.y * this->BLOCK_SIDE_SIZE, (player1.x * this->BLOCK_SIDE_SIZE) + 40, (player1.y * this->BLOCK_SIDE_SIZE) + 40, al_map_rgb(0, 0, 255));

		//printing the wodden stick

		al_draw_bitmap(wooden_stick.image, (wooden_stick.x * this->BLOCK_SIDE_SIZE), (wooden_stick.y * this->BLOCK_SIDE_SIZE), 0);
		//al_draw_filled_rectangle(wooden_stick.x * this->BLOCK_SIDE_SIZE, wooden_stick.y * this->BLOCK_SIDE_SIZE, (wooden_stick.x * this->BLOCK_SIDE_SIZE) + 40, (wooden_stick.y * this->BLOCK_SIDE_SIZE) + 40, al_map_rgb(150, 150, 150));


		//al_draw_bitmap(buffer, 0, 0, 0);

		al_flip_display();


	}

	void initStickPosition()
	{
		//set the random location of the wooden stick                   
		wooden_stick.x = rand() % NUMBER_OF_BLOCKS;
		wooden_stick.y = rand() % NUMBER_OF_BLOCKS;
	}

	void controls()
	{

		al_get_keyboard_state(&state);

		if ((al_key_down(&state, ALLEGRO_KEY_A)&&keyPressed==false))
		{
			if (player1.x > 0)
			{
				player1.x--;
			}
			
			keyPressed = true;

		}
		if ((al_key_down(&state, ALLEGRO_KEY_D) && keyPressed == false))
		{
			if (player1.x < 19)
			{
				player1.x++;
			}

			keyPressed = true;
		}

		if ((al_key_down(&state, ALLEGRO_KEY_S) && keyPressed == false))
		{
			if (player1.y < 19)
			{
				player1.y++;
			}

			keyPressed = true;
		}
		if ((al_key_down(&state, ALLEGRO_KEY_W)) && keyPressed == false)
		{
			if (player1.y > 0)
			{
				player1.y--;
			}

			keyPressed = true;
		}
		/*else if (event.type == ALLEGRO_KEY_Z)
		{
			//increase zoom (experimental)
			this->BLOCK_SIDE_SIZE++;
			this->SCREEN_X = this->BLOCK_SIDE_SIZE * this->NUMBER_OF_BLOCKS;
			this->SCREEN_Y = this->BLOCK_SIDE_SIZE * this->NUMBER_OF_BLOCKS;

			//set_gfx_mode(GFX_AUTODETECT_WINDOWED, gameScreen.SCREEN_X, gameScreen.SCREEN_Y, 0, 0);

			this->drawScreen();

		}
		else if (event.type == ALLEGRO_KEY_X)
		{
			//decrease zoom (experimental)
			this->BLOCK_SIDE_SIZE--;
			this->SCREEN_X = this->BLOCK_SIDE_SIZE * this->NUMBER_OF_BLOCKS;
			this->SCREEN_Y = this->BLOCK_SIDE_SIZE * this->NUMBER_OF_BLOCKS;

			// set_gfx_mode(GFX_AUTODETECT_WINDOWED, gameScreen.SCREEN_X, gameScreen.SCREEN_Y, 0, 0);

			this->drawScreen();

		}
		else if (event.type == ALLEGRO_KEY_N)
		{
			//increase map size
			this->NUMBER_OF_BLOCKS++;
			this->SCREEN_X = this->BLOCK_SIDE_SIZE * this->NUMBER_OF_BLOCKS;
			this->SCREEN_Y = this->BLOCK_SIDE_SIZE * this->NUMBER_OF_BLOCKS;

			//set_gfx_mode(GFX_AUTODETECT_WINDOWED, gameScreen.SCREEN_X, gameScreen.SCREEN_Y, 0, 0);

			player1.x = 1;
			player1.y = 1;
			initStickPosition();
			this->drawScreen();


		}
		else if (event.type == ALLEGRO_KEY_M)
		{
			//reduce map size
			this->NUMBER_OF_BLOCKS--;
			this->SCREEN_X = this->BLOCK_SIDE_SIZE * this->NUMBER_OF_BLOCKS;
			this->SCREEN_Y = this->BLOCK_SIDE_SIZE * this->NUMBER_OF_BLOCKS;



			player1.x = 1;
			player1.y = 1;
			initStickPosition();
			this->drawScreen();

		}*/


	}
	
};
