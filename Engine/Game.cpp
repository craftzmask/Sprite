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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	s("Images\\link90x90.bmp"),
	c({ 50.0f, 50.0f }, s),
	font("Fonts\\Fixedsys16x28.bmp", Colors::White)
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
	while (!wnd.kbd.KeyIsEmpty())
	{
		const auto e = wnd.kbd.ReadKey();
		if (e.IsPress() && e.GetCode() == VK_SPACE)
		{
			c.ActivateEffect();
			hit.Play();
		}
	}

	Vec2 dir = { 0.0f, 0.0f };
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		dir.x += 1.0f;
	}
	else if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		dir.x -= 1.0f;
	}
	else if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		dir.y -= 1.0f;
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		dir.y += 1.0f;
	}

	c.SetDirection(dir);
	c.Update(ft.Mark());
}

void Game::ComposeFrame()
{
	font.Draw("Hello\nWorld!", wnd.mouse.GetPos(), Colors::White, gfx);
	c.Draw(gfx);
}
