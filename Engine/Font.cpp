#include "Font.h"
#include "SpriteEffect.h"

Font::Font(const std::string& filename, Color chroma)
    :
	sprite(filename),
	glyphWidth(sprite.GetWidth() / nColumns),
	glyphHeight(sprite.GetHeight() / nRows),
	chroma(chroma)
{
}

void Font::Draw(const std::string& text, const Vei2& pos, Color color, Graphics& gfx) const
{
	auto curPos = pos;
	for (const char c : text)
	{
		if (c == '\n')
		{
			curPos.x = pos.x;
			curPos.y += glyphHeight;
			continue;
		}

		if (c >= firstChar + 1 && c <= lastChar)
		{
			gfx.DrawSprite(curPos.x, curPos.y, MapGlyphRect(c), sprite, SpriteEffect::Substitution{ chroma, Colors::White });
		}
		curPos.x += glyphWidth;
	}
}

RectI Font::MapGlyphRect(char c) const
{
	const int index = c - firstChar;
	const int yIndex = index / nColumns;
	const int xIndex = index % nColumns;
    return RectI({ xIndex * glyphWidth, yIndex * glyphHeight }, glyphWidth, glyphHeight);
}
