#include "stdafx.h"
#include "Level.h"

Level::Level()
{
}

Level::Level(int num):Escena::Escena(SCREEN_WIDTH, SCREEN_HEIGHT)
{
	//Pusheamos todos los objetos
	//Background
	Background = SDL_Rect{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	
	//ITEMS
	Renderer::Instance()->LoadTexture(ITEMS, PATH_IMG + "items.png");
	Renderer::Instance()->LoadTexture(PLAYER1, PATH_IMG + "player1.png");
	Renderer::Instance()->LoadTexture(PLAYER2, PATH_IMG + "player2.png");

	//MAPA SEGUN EL NUMERO QUE RECIBAMOS
	std::string nameFichero;
	if (num == 1)
	{
		nameFichero = "Mapa1.xml";
	}
	else if (num == 2)
	{
		nameFichero = "Mapa2.xml";
	}

	//Creacion del documento para poder leer su contenido
	rapidxml::xml_document<> doc;
	std::ifstream file(nameFichero);
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	//Recogemos valores del mapa (Columnas, filas, vidas y tiempo)
	rapidxml::xml_node<> *pRoot = doc.first_node();
	rapidxml::xml_node<> *Map = doc.first_node("Mapa");

	filas = std::stoi(Map->first_attribute("filas")->value(), nullptr);
	columnas = std::stoi(Map->first_attribute("columnas")->value(), nullptr);

	//ATRIBUTOS PARA LOS JUGADORES
	firstPlayer.vida = std::stoi(Map->first_attribute("vidas")->value(), nullptr);
	firstPlayer.playerX = std::stoi(Map->first_attribute("xPlayer1")->value(), nullptr);
	firstPlayer.playerY = std::stoi(Map->first_attribute("yPlayer1")->value(), nullptr);

	secondPlayer.vida = std::stoi(Map->first_attribute("vidas")->value(), nullptr);
	secondPlayer.playerX = std::stoi(Map->first_attribute("xPlayer2")->value(), nullptr);
	secondPlayer.playerY = std::stoi(Map->first_attribute("yPlayer2")->value(), nullptr);

	//HUD
	tiempo = std::stoi(Map->first_attribute("tiempo")->value(), nullptr);

	firstPlayer = Player(1,firstPlayer.playerX,firstPlayer.playerY,firstPlayer.vida);
	secondPlayer = Player(2,secondPlayer.playerX,secondPlayer.playerY,secondPlayer.vida);
	//Creamos el mapa
	for (int i = 0; i < columnas; i++)
	{
		for (int j = 0; j < filas; j++)
		{
			rapidxml::xml_node<> *casilla = Map
				->first_node(("Columna" + std::to_string(i)).c_str())
				->first_node(("Cd" + std::to_string(j)).c_str());
			std::string s = casilla->value();
			if (s == "no")
			{
				mapaObstaculos[i][j] = new Obstaculos(tipoObj::tipo::NODEST, i, j);
			}
			else if (s == "vacio")
			{
				mapaObstaculos[i][j] = new Obstaculos(tipoObj::tipo::NONE, i, j);
			}
			else if (s == "dest")
			{
				mapaObstaculos[i][j] = new Obstaculos(tipoObj::tipo::DEST, i, j);
			}
		}
	}
	//mapaObstaculos[firstPlayer.sprite.x / columnas][firstPlayer.sprite.y / filas]->type = tipoObj::tipo::PLAYER;
	

}

void Level::draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(MENU_BG, Background);

	//Se han de cargar en el renderer los obstaculos
	for (int i = 0; i < columnas; i++)
	{
		for (int j = 0; j < filas; j++)
		{
			mapaObstaculos[i][j]->draw();
		}
	
	}
	
	//Mandamos printarse a players
	
	firstPlayer.draw();
	secondPlayer.draw();

	Renderer::Instance()->Render();
}

void Level::update()
{
}

void Level::eHandler() 
{
	SDL_Event event;
	int posIzq;
	int posDerech;
	int posAbajo;
	int posArriba;

	// posicionesJug;
	int posPlayI;
	int posPlayJ;
	int esquinaInfIzq;
	int esquinaDer;

	

	Obstaculos prueva(mapaObstaculos[1][1]->type, 1, 1);
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			/* Look for a keypress */
		case SDL_KEYDOWN:

		

			/* Check the SDLKey values and move change the coords */
			switch (event.key.keysym.sym) {
				
			case SDLK_LEFT:
				posPlayI = firstPlayer.sprite.x / SPRITEWIDTH;
				posPlayJ = (firstPlayer.sprite.y - SPRITEZ) / SPRITEHEIGHT;

				esquinaInfIzq = (firstPlayer.sprite.y - SPRITEZ) + 46;

				posIzq = posPlayI - 1;
				
				if ((mapaObstaculos[posIzq][posPlayJ]->type == tipoObj::tipo::NONE) && (esquinaInfIzq / SPRITEHEIGHT == posPlayJ))
				{
					firstPlayer.moveleft();
				}				
				else 
				{
					if (firstPlayer.sprite.x - 6 >= SPRITEWIDTH + ((posIzq*SPRITEWIDTH)))
					{
						firstPlayer.moveleft();
					}
				}
				
				break;
			case SDLK_RIGHT:
				/*posPlayI = (firstPlayer.sprite.x + SPRITEWIDTH) / SPRITEWIDTH;
				posPlayJ = (firstPlayer.sprite.y - SPRITEZ) / SPRITEHEIGHT;
				posDerech= posPlayI + 1;*/

				//CARACTER QUE NO TENGO EN EL TECLADO
				//<>

				posPlayI = (firstPlayer.sprite.x + SPRITEWIDTH) / SPRITEWIDTH;
				posPlayJ = (firstPlayer.sprite.y - SPRITEZ) / SPRITEHEIGHT;

				posDerech = posPlayI + 1;
			
				if ((firstPlayer.sprite.x + SPRITEWIDTH) == 14 * SPRITEWIDTH)
				{
				}
				else if ((mapaObstaculos[posDerech][posPlayJ]->type == tipoObj::tipo::NONE))
				{
					firstPlayer.moveright();
				}
				else
				{
					
					if (firstPlayer.sprite.x +SPRITEWIDTH+6 < SPRITEWIDTH + (((posDerech-1)*SPRITEWIDTH)))
					{
						firstPlayer.moveright();
					}
				else
					{
						firstPlayer.sprite.x = ((posDerech-1) * SPRITEWIDTH);
					}
				}
				break;
			case SDLK_UP:

				posPlayI = firstPlayer.sprite.x / SPRITEWIDTH;
				posPlayJ = (firstPlayer.sprite.y - SPRITEZ) / SPRITEHEIGHT;

				posArriba = posPlayJ - 1;
				esquinaDer = firstPlayer.sprite.x+46;

				if ((mapaObstaculos[posPlayI][posArriba]->type == tipoObj::tipo::NONE) && ((esquinaDer/SPRITEWIDTH)==posPlayI)   )
				{
					firstPlayer.moveup();
				}
				else
				{
					if (firstPlayer.sprite.y - 86 >= (SPRITEHEIGHT) + ((posArriba*(SPRITEHEIGHT))))
					{
						firstPlayer.moveup();
					}
				}
				break;
			case SDLK_DOWN:

				posPlayI = firstPlayer.sprite.x / SPRITEWIDTH;
				posPlayJ = (firstPlayer.sprite.y - SPRITEZ) / SPRITEHEIGHT;

				posAbajo = posPlayJ + 1;

				if ((mapaObstaculos[posPlayI][posAbajo]->type == tipoObj::tipo::NONE))
				{
					firstPlayer.movedown();
				}
				else
				{
					if (firstPlayer.sprite.y - 6 > (SPRITEHEIGHT) + ((posAbajo*(SPRITEHEIGHT))))
					{
						firstPlayer.movedown();
					}
				}



				firstPlayer.movedown();
				break;
		
			}
		}
	}
}

Level::~Level()
{}
