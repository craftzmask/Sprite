#pragma once
#include "Graphics.h"
#include "Surface.h"
#include "RectI.h"
#include "Vei2.h"

class Font
{
public:
	Font(const std::string& filename, Color chroma);
	void Draw(const std::string& text, const Vei2& pos, Color color, Graphics& gfx) const;

private:
	RectI MapGlyphRect(char c) const;

private:
	Surface sprite;
	int glyphWidth;
	int glyphHeight;
	Color chroma;
	static constexpr char firstChar = ' ';
	static constexpr char lastChar = '~';
	static constexpr int nColumns = 32;
	static constexpr int nRows = 3;
};