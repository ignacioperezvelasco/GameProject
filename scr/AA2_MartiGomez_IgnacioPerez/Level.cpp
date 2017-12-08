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
	/*Player::vida = std::stoi(Map->first_attribute("vidas")->value(), nullptr);
	Player::playerX1 = std::stoi(Map->first_attribute("xPlayer1")->value(), nullptr);
	Player::playerY1 = std::stoi(Map->first_attribute("yPlayer1")->value(), nullptr);
	Player::playerX2 = std::stoi(Map->first_attribute("xPlayer2")->value(), nullptr);
	Player::playerY2 = std::stoi(Map->first_attribute("yPlayer2")->value(), nullptr);*/

	//HUD
	tiempo = std::stoi(Map->first_attribute("tiempo")->value(), nullptr);

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
				mapaObstaculos[i][j] = new Obstaculos(tipoObj::tipo::DEST, i, j);
			}
			else if (s == "vacio")
			{
				mapaObstaculos[i][j] = new Obstaculos(tipoObj::tipo::NONE, i, j);
			}
			else if (s == "dest")
			{
				mapaObstaculos[i][j] = new Obstaculos(tipoObj::tipo::NODEST, i, j);
			}
		}
	}


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
		std::cout<<std::endl;
	}
	
	Renderer::Instance()->Render();
}

void Level::update()
{}
void Level::eHandler() 
{}

Level::~Level()
{}
