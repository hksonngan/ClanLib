/*
**  ClanLib SDK
**  Copyright (c) 1997-2013 The ClanLib Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Mark Page
*/

#pragma once

class App;
class Panel;
class Component3D;

class GUI
{
public:
	GUI(App *app);
	~GUI();

	bool run();
	void draw();

	clan::GUIManager &get_gui_manager() {return gui;}

private:
	clan::Vec3f transform_point(const clan::Vec3d &src_point, const clan::Mat4d &matrix);
	void wm_input_intercept(clan::InputEvent &input_event);

private:
	// NOTE: The order of these constructors is important
	clan::DisplayWindow window;
	clan::DisplayCache resources_gui;
	clan::GUIWindowManagerTexture wm;
	clan::GUIManager gui;

	clan::Canvas canvas;
	App *app;
};
