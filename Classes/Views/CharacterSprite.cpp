//
//  CharacterSprite.cpp
//  PixelPoem
//
//  Created by SuiYi on 1/4/16.
//
//

#include "CharacterSprite.hpp"

CharacterSprite::CharacterSprite(CharacterTexture* texture)
{
    _texture = texture;
    _texture->retain();
	
	_rawTexture = NULL;
}

CharacterSprite::CharacterSprite(Texture2D* texture)
{
    _rawTexture = texture;
    _rawTexture->retain();
	
	_texture = NULL;
}

CharacterSprite::~CharacterSprite()
{
	if(_texture != NULL)
		_texture->release();

	if(_rawTexture != NULL)
		_rawTexture->release();

}

void CharacterSprite::setPositionInUnit(Vec2 pos)
{
    _positionInUnit = pos;
}

void CharacterSprite::setScale(int charWidth, int charHeight)
{
    _widthInUnit = charWidth;
    _heightInUnit = charHeight;
}

void CharacterSprite::setRotate(CharacterRotateType rotate)
{
    _rotateStatus = rotate;
}
