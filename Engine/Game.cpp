/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	paddle(Vec2(450.0f, 500.0f), Colors::Gray),
	brick(RecF(Vec2(130.0f,240.0f),60.0f,30.0f),Colors::Cyan),
	ball(Vec2(20.0f, 20.0f)),
	walls(Vec2(0.0f,0.0f), int(gfx.ScreenWidth),int(gfx.ScreenHeight)),
	wnd( wnd ),
	gfx( wnd )
{
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
	float dt = ft.Mark();
	paddle.BallBounced(ball,wnd.kbd);
	ball.update(dt);
	ball.Iscontained(walls);
	brick.BallHitten(ball);
	paddle.update(wnd.kbd);
	
	
}

void Game::ComposeFrame()
{
	brick.draw(gfx);
	ball.Draw(gfx);
	paddle.Draw(gfx);
}
