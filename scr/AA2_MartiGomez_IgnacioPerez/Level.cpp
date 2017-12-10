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
	Renderer::Instance()->LoadTexture(EXPLOSION, PATH_IMG + "explosion.png"); 
	Renderer::Instance()->LoadTexture(TRANSPARENTE, PATH_IMG + "transparente.png");

	//FUENTE
	f.id = LUIGI_40;
	f.path = PATH_FONT + "MarioLuigi2.ttf";
	f.size = 40;
	Renderer::Instance()->LoadFont(f);

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
	//TIEMPO
	tiempo = std::stof(Map->first_attribute("tiempo")->value(), nullptr);
	min = tiempo / 60;
	secs = (int)tiempo % 60;

	//CONVERSION DEL TIEMPO A MINUTOS
	lastTime = clock();

	clock_t lastTime = clock();
	float timeDown = 80;
	float deltaTime = 0;	
	int auxBomb=0;
	int counter=0;
	timerBomba = 0;

	//JUGADORES
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

	//PLAYER 1
	//SCORE
	scorePlayer1.id = SCORE_PLAYER1;
	scorePlayer1.text = "SCORE1: " + std::to_string(firstPlayer.punts);
	scorePlayer1.color = Color{ 0,0,0,0 };
	Renderer::Instance()->LoadTextureText(f.id, scorePlayer1);
	Vector2 scorePlayer1Size = Renderer::Instance()->GetTextureSize(scorePlayer1.id);
	scorePlayer1.w = scorePlayer1Size.x;
	scorePlayer1.h = scorePlayer1Size.y;

	//LIFES
	lifesPlayer1.id = LIFES_PLAYER1;
	lifesPlayer1.text = "LIFES1: " + std::to_string(firstPlayer.vida);
	lifesPlayer1.color = Color{ 0,0,0,0 };
	Renderer::Instance()->LoadTextureText(f.id, lifesPlayer1);
	Vector2 lifesPlayer1Size = Renderer::Instance()->GetTextureSize(lifesPlayer1.id);
	lifesPlayer1.w = lifesPlayer1Size.x;
	lifesPlayer1.h = lifesPlayer1Size.y;

	//PLAYER2
	//SCORE
	scorePlayer2.id = SCORE_PLAYER2;
	scorePlayer2.text = "SCORE2: " + std::to_string(secondPlayer.punts);
	scorePlayer2.color = Color{ 0,0,0,0 };
	Renderer::Instance()->LoadTextureText(f.id, scorePlayer2);
	Vector2 scorePlayer2Size = Renderer::Instance()->GetTextureSize(scorePlayer2.id);
	scorePlayer2.w = scorePlayer2Size.x;
	scorePlayer2.h = scorePlayer2Size.y;

	//LIFES
	lifesPlayer2.id = LIFES_PLAYER2;
	lifesPlayer2.text = "LIFES2: " + std::to_string(secondPlayer.vida);
	lifesPlayer2.color = Color{ 0,0,0,0 };
	Renderer::Instance()->LoadTextureText(f.id, lifesPlayer2);
	Vector2 lifesPlayer2Size = Renderer::Instance()->GetTextureSize(lifesPlayer2.id);
	lifesPlayer2.w = lifesPlayer2Size.x;
	lifesPlayer2.h = lifesPlayer2Size.y;

	//TIME
	time.id = TIME;
	time.text = std::to_string(min) + ":" + std::to_string(secs);
	time.color = Color{ 0,0,0,0 };
	Renderer::Instance()->LoadTextureText(f.id, time);
	Vector2 timeSize = Renderer::Instance()->GetTextureSize(time.id);
	time.w = timeSize.x;
	time.h = timeSize.y;

	//SDL_RECT (HUD)
	//PLAYER 1
	score1 = SDL_Rect{ (((SCREEN_WIDTH / 5) * 1) - CELL_BORDER) - (scorePlayer1.w / 2), ((SPRITEZ / 8) * 2) - (scorePlayer1.h / 2), scorePlayer1.w, scorePlayer1.h };
	vida1 = SDL_Rect{ (((SCREEN_WIDTH / 5) * 1) - CELL_BORDER) - (lifesPlayer1.w / 2), ((SPRITEZ / 8) * 6) - (lifesPlayer1.h / 2), lifesPlayer1.w, lifesPlayer1.h };

	//PLAYER2
	score2 = SDL_Rect{ (((SCREEN_WIDTH / 5) * 4) + CELL_BORDER) - (scorePlayer2.w / 2), ((SPRITEZ / 8) * 2) - (scorePlayer2.h / 2), scorePlayer2.w, scorePlayer2.h };
	vida2 = SDL_Rect{ (((SCREEN_WIDTH / 5) * 4) + CELL_BORDER) - (lifesPlayer2.w / 2), ((SPRITEZ / 8) * 6) - (lifesPlayer2.h / 2), lifesPlayer2.w, lifesPlayer2.h };

	//TIME
	timeRect = SDL_Rect{ (((SCREEN_WIDTH / 2))) - (time.w / 2), ((SPRITEZ / 8) * 4) - (time.h / 2), time.w, time.h };
}

void Level::draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(MENU_BG, Background);

	//HUD
	//PLAYER1
	Renderer::Instance()->PushImage(SCORE_PLAYER1, score1);
	Renderer::Instance()->PushImage(LIFES_PLAYER1, vida1);

	//PLAYER2
	Renderer::Instance()->PushImage(SCORE_PLAYER2, score2);
	Renderer::Instance()->PushImage(LIFES_PLAYER2, vida2);

	//TIME
	Renderer::Instance()->PushImage(TIME, timeRect);

	//Se han de cargar en el renderer los obstaculos
	for (int i = 0; i < columnas; i++)
	{
		for (int j = 0; j < filas; j++)
		{
			mapaObstaculos[i][j]->draw();
		}
	
	}
	
	if (firstPlayer.puedoPlantar == false)
	{
		//firstPlayerBomb.draw();
	}
	//Mandamos printarse a players
	firstPlayer.draw();
	secondPlayer.draw();

	Renderer::Instance()->Render();
}

void Level::update()
{	
	//CALCULO
	deltaTime = (clock() - lastTime);
	lastTime = clock();
	deltaTime /= CLOCKS_PER_SEC;
	tiempo -= deltaTime;
	min = tiempo / 60;
	secs = (int)tiempo % 60;

	//CAMBIO EL TEXTO
	time.id = TIME;
	time.text = std::to_string(min) + ":" + std::to_string(secs);
	time.color = Color{ 0,0,0,0 };
	Renderer::Instance()->LoadTextureText(f.id, time);
	Vector2 timeSize = Renderer::Instance()->GetTextureSize(time.id);
	time.w = timeSize.x;
	time.h = timeSize.y;

	if (tiempo <= 0)
	{
		estadoactual = escenaEscena::Estado::RankingEscena;
	}
	for (int i = 0; i < columnas; i++)
	{
		for (int j = 0; j < filas; j++)
		{
			mapaObstaculos[i][j]->update();
		}

	}
	//comprobamos jugador
	if (mapaObstaculos[firstPlayer.sprite.x / SPRITEWIDTH][firstPlayer.sprite.y / SPRITEHEIGHT]->doDmg == true)
	{
		firstPlayer.reciveDmg();
	}
	if ((timerBomba - tiempo) > 7)
	{
		firstPlayer.puedoPlantar = true;
	}
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

				if (((mapaObstaculos[posIzq][posPlayJ]->type == tipoObj::tipo::NONE) || (mapaObstaculos[posIzq][posPlayJ]->type == tipoObj::tipo::ARRIBA1) || (mapaObstaculos[posIzq][posPlayJ]->type == tipoObj::tipo::ARRIBA2) || (mapaObstaculos[posIzq][posPlayJ]->type == tipoObj::tipo::IZQUIERDA1) || (mapaObstaculos[posIzq][posPlayJ]->type == tipoObj::tipo::IZQUIERDA2) || (mapaObstaculos[posIzq][posPlayJ]->type == tipoObj::tipo::DERECHA1) || (mapaObstaculos[posIzq][posPlayJ]->type == tipoObj::tipo::DERECHA2) || (mapaObstaculos[posIzq][posPlayJ]->type == tipoObj::tipo::ABAJO1) || (mapaObstaculos[posIzq][posPlayJ]->type == tipoObj::tipo::ABAJO2)) && (esquinaInfIzq / SPRITEHEIGHT == posPlayJ))
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

				posPlayI = (firstPlayer.sprite.x + SPRITEWIDTH - 1) / SPRITEWIDTH;
				posPlayJ = (firstPlayer.sprite.y - SPRITEZ) / SPRITEHEIGHT;

				posDerech = posPlayI + 1;

				esquinaDer = (firstPlayer.sprite.y + SPRITEHEIGHT-SPRITEZ-1)/SPRITEHEIGHT;

				if ((firstPlayer.sprite.x + SPRITEWIDTH) == 14 * SPRITEWIDTH)
				{
					firstPlayer.sprite.x = 14 * SPRITEWIDTH;
				}
				else if (((mapaObstaculos[posDerech][posPlayJ]->type == tipoObj::tipo::NONE) || (mapaObstaculos[posDerech][posPlayJ]->type == tipoObj::tipo::ARRIBA1) || (mapaObstaculos[posDerech][posPlayJ]->type == tipoObj::tipo::ARRIBA2) || (mapaObstaculos[posDerech][posPlayJ]->type == tipoObj::tipo::IZQUIERDA1) || (mapaObstaculos[posDerech][posPlayJ]->type == tipoObj::tipo::IZQUIERDA2) || (mapaObstaculos[posDerech][posPlayJ]->type == tipoObj::tipo::DERECHA1) || (mapaObstaculos[posDerech][posPlayJ]->type == tipoObj::tipo::DERECHA2) || (mapaObstaculos[posDerech][posPlayJ]->type == tipoObj::tipo::ABAJO1) || (mapaObstaculos[posDerech][posPlayJ]->type == tipoObj::tipo::ABAJO2)) && (esquinaDer==posPlayJ))
				{
					firstPlayer.moveright();
				}
				else if ((mapaObstaculos[posDerech][posPlayJ]->type != tipoObj::tipo::NONE))
				{
					
					if (((SPRITEWIDTH + (((posDerech - 1)*SPRITEWIDTH))) - (firstPlayer.sprite.x + SPRITEWIDTH + 6)) < 6)
					{
						firstPlayer.sprite.x = (posDerech - 1)*SPRITEWIDTH;
					}
					else if (firstPlayer.sprite.x + SPRITEWIDTH + 6 < SPRITEWIDTH + (((posDerech - 1)*SPRITEWIDTH)))
					{
						prueva.type = mapaObstaculos[posDerech][posPlayJ]->type;
						firstPlayer.moveright();
					}

				}
				break;

			case SDLK_UP:

				posPlayI = firstPlayer.sprite.x / SPRITEWIDTH;
				posPlayJ = (firstPlayer.sprite.y - SPRITEZ) / SPRITEHEIGHT;

				posArriba = posPlayJ - 1;
				esquinaDer = firstPlayer.sprite.x + SPRITEWIDTH-1;

				if (((mapaObstaculos[posPlayI][posArriba]->type == tipoObj::tipo::NONE) || (mapaObstaculos[posPlayI][posArriba]->type == tipoObj::tipo::ARRIBA1) || (mapaObstaculos[posPlayI][posArriba]->type == tipoObj::tipo::ARRIBA2) || (mapaObstaculos[posPlayI][posArriba]->type == tipoObj::tipo::IZQUIERDA1) || (mapaObstaculos[posPlayI][posArriba]->type == tipoObj::tipo::IZQUIERDA2) || (mapaObstaculos[posPlayI][posArriba]->type == tipoObj::tipo::DERECHA1) || (mapaObstaculos[posPlayI][posArriba]->type == tipoObj::tipo::DERECHA2) || (mapaObstaculos[posPlayI][posArriba]->type == tipoObj::tipo::ABAJO1) || (mapaObstaculos[posPlayI][posArriba]->type == tipoObj::tipo::ABAJO2)) && ((esquinaDer / SPRITEWIDTH) == posPlayI))
				{
					firstPlayer.moveup();
				}
				else
				{
					if (firstPlayer.sprite.y - 86 >= (SPRITEHEIGHT)+((posArriba*(SPRITEHEIGHT))))
					{
						firstPlayer.moveup();
					}
				}
				break;

			case SDLK_DOWN:

				posPlayI = (firstPlayer.sprite.x) / SPRITEWIDTH;
				posPlayJ = (firstPlayer.sprite.y - SPRITEZ + SPRITEHEIGHT - 1) / SPRITEHEIGHT;

				posAbajo = posPlayJ + 1;
				esquinaDer = (firstPlayer.sprite.x + SPRITEWIDTH - 1)/SPRITEWIDTH;
				
				if (((mapaObstaculos[posPlayI][posAbajo]->type == tipoObj::tipo::NONE) || (mapaObstaculos[posPlayI][posAbajo]->type == tipoObj::tipo::ARRIBA1) || (mapaObstaculos[posPlayI][posAbajo]->type == tipoObj::tipo::ARRIBA2) || (mapaObstaculos[posPlayI][posAbajo]->type == tipoObj::tipo::IZQUIERDA1) || (mapaObstaculos[posPlayI][posAbajo]->type == tipoObj::tipo::IZQUIERDA2) || (mapaObstaculos[posPlayI][posAbajo]->type == tipoObj::tipo::DERECHA1) || (mapaObstaculos[posPlayI][posAbajo]->type == tipoObj::tipo::DERECHA2) || (mapaObstaculos[posPlayI][posAbajo]->type == tipoObj::tipo::ABAJO1) || (mapaObstaculos[posPlayI][posAbajo]->type == tipoObj::tipo::ABAJO2)) && (esquinaDer == posPlayI))
				{
					firstPlayer.movedown();
				}
				else if ((mapaObstaculos[posPlayI][posAbajo]->type != tipoObj::tipo::NONE) )
				{
					posDerech = ((SPRITEHEIGHT + (((posAbajo - 1)*SPRITEHEIGHT)) + SPRITEZ) - (firstPlayer.sprite.y + SPRITEHEIGHT + 6));

					if (((SPRITEHEIGHT + (((posAbajo - 1)*SPRITEHEIGHT))+SPRITEZ) - (firstPlayer.sprite.y + SPRITEHEIGHT + 6)) < 6)
					{
						firstPlayer.sprite.y = ((posAbajo-1)*SPRITEHEIGHT)+SPRITEZ;
					}
					else if(firstPlayer.sprite.y + 6 + SPRITEHEIGHT < SPRITEZ+SPRITEHEIGHT + (((posAbajo-1)*SPRITEHEIGHT)))
					{
						firstPlayer.movedown();
					}
				}
				else if ((firstPlayer.sprite.y + 6 < (SPRITEHEIGHT)+(((posAbajo)*(SPRITEHEIGHT)))) && ((esquinaDer / SPRITEWIDTH)) == posPlayI)
				{
					{
						firstPlayer.movedown();
					}
				}
				break;


			case SDLK_SPACE:

				posPlayI = (firstPlayer.sprite.x) / SPRITEWIDTH;
				posPlayJ = (firstPlayer.sprite.y - SPRITEZ + SPRITEHEIGHT - 1) / SPRITEHEIGHT;
				if (firstPlayer.puedoPlantar == true) {
					mapaObstaculos[posPlayI][posPlayJ]->type = tipoObj::tipo::BOMB;

					//DERECHA
					if (mapaObstaculos[posPlayI + 1][posPlayJ]->type == tipoObj::tipo::NONE) 
					{
						mapaObstaculos[posPlayI + 1][posPlayJ]->type = tipoObj::tipo::DERECHA1;
					}
					else if (mapaObstaculos[posPlayI + 1][posPlayJ]->type == tipoObj::tipo::DEST)
					{
						mapaObstaculos[posPlayI + 1][posPlayJ]->seDestruira = true;
					}
					if (mapaObstaculos[posPlayI + 1][posPlayJ]->seDestruira != true) {
						if ((posPlayI + 1) < columnas) {
							if ((mapaObstaculos[posPlayI + 2][posPlayJ]->type == tipoObj::tipo::NONE))
							{
								mapaObstaculos[posPlayI + 2][posPlayJ]->type = tipoObj::tipo::DERECHA2;
							}
							else if (mapaObstaculos[posPlayI + 2][posPlayJ]->type == tipoObj::tipo::DEST)
							{
								mapaObstaculos[posPlayI + 2][posPlayJ]->seDestruira = true;
							}
						}
					}
					//IZQUIERDA
					if (mapaObstaculos[posPlayI - 1][posPlayJ]->type==tipoObj::tipo::NONE) 
					{
					mapaObstaculos[posPlayI - 1][posPlayJ]->type = tipoObj::tipo::IZQUIERDA1;
					}
					else if (mapaObstaculos[posPlayI - 1][posPlayJ]->type == tipoObj::tipo::DEST)
					{
						mapaObstaculos[posPlayI - 1][posPlayJ]->seDestruira = true;
					}
					if (mapaObstaculos[posPlayI - 1][posPlayJ]->seDestruira != true) {
						if (((posPlayI - 2) > 0)) {
							if ((mapaObstaculos[posPlayI - 2][posPlayJ]->type == tipoObj::tipo::NONE))
							{
								mapaObstaculos[posPlayI - 2][posPlayJ]->type = tipoObj::tipo::IZQUIERDA2;
							}
							else if (mapaObstaculos[posPlayI - 2][posPlayJ]->type == tipoObj::tipo::DEST)
							{
								mapaObstaculos[posPlayI - 2][posPlayJ]->seDestruira = true;
							}
						}
					}
					//ABAJO
					if (mapaObstaculos[posPlayI][posPlayJ + 1]->type== tipoObj::tipo::NONE) {
						mapaObstaculos[posPlayI][posPlayJ + 1]->type = tipoObj::tipo::ABAJO1;
					}
					else if (mapaObstaculos[posPlayI][posPlayJ + 1]->type == tipoObj::tipo::DEST)
					{
						mapaObstaculos[posPlayI][posPlayJ + 1]->seDestruira = true;
					}
					if (mapaObstaculos[posPlayI][posPlayJ + 1]->seDestruira != true) {
						if ((posPlayJ + 2) < filas)
						{
							if ((mapaObstaculos[posPlayI][posPlayJ + 2]->type == tipoObj::tipo::NONE)) {
								mapaObstaculos[posPlayI][posPlayJ + 2]->type = tipoObj::tipo::ABAJO2;
							}
							else if (mapaObstaculos[posPlayI][posPlayJ + 2]->type == tipoObj::tipo::DEST)
							{
								mapaObstaculos[posPlayI][posPlayJ + 2]->seDestruira = true;
							}
						}
					}
					//ARRIBA
					if (mapaObstaculos[posPlayI][posPlayJ - 1]->type == tipoObj::tipo::NONE)
					{
						mapaObstaculos[posPlayI][posPlayJ - 1]->type = tipoObj::tipo::ARRIBA1;
					}
					else if (mapaObstaculos[posPlayI][posPlayJ - 1]->type == tipoObj::tipo::DEST)
					{
						mapaObstaculos[posPlayI][posPlayJ - 1]->seDestruira = true;
					}
					if (mapaObstaculos[posPlayI][posPlayJ - 1]->seDestruira != true) {
						if ((posPlayJ - 2) > 0)
						{
							if ((mapaObstaculos[posPlayI][posPlayJ - 2]->type != tipoObj::tipo::NONE)) {
								mapaObstaculos[posPlayI][posPlayJ - 2]->type = tipoObj::tipo::ARRIBA2;
							}
							else if (mapaObstaculos[posPlayI][posPlayJ - 2]->type == tipoObj::tipo::DEST)
							{
								mapaObstaculos[posPlayI][posPlayJ - 2]->seDestruira = true;
							}
						}
					}
					firstPlayer.puedoPlantar = false;
					timerBomba = tiempo;					
						
				}

				break;
			}
		}
	}
}

Level::~Level()
{}
