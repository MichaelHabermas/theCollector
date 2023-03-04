#include "MainWindow.h"
#include "Game.h"
#include <iostream>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	rng( rd() ),
	xDist( 100, 700 ),
	yDist( 100, 500 ),
	coin( xDist( rng ), yDist( rng ) )
{
	Player player = Player();
	for (int i = 0; i < numOfEnemies; i++)
	{
		enemies[i].Init(xDist(rng), yDist(rng), 6, 6);
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!isGameOver)
	{
		player.Update( wnd.kbd );
		player.Clamp();

		if (coin.Collision( player ))
		{
			coin.Respawn(xDist(rng), yDist(rng));
		}

		for (int i = 0; i < numOfEnemies; i++)
		{
			enemies[i].Update();
			if (enemies[i].Collision( player ))
			{
				isGameOver = true;
			}
		}
	}
}

void Game::ComposeFrame()
{
	gfx.DrawCircle( 300, 350, 100, Colors::Magenta );
	player.Draw( gfx );
	coin.Draw( gfx );

	for (int i = 0; i < numOfEnemies; i++)
	{
		enemies[i].Draw(gfx);
	}
}
