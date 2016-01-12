//
//  GamePanelLayer.cpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#include "GamePanelLayer.hpp"
#include "PixelPanel.hpp"
#include "../ObjectModels/GameDefinition.hpp"


bool GamePanelLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto sprite = Sprite::create("res/ui/iphone6p/MainGameMask2.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 100);
    
    // Adding PixelPanel
    GameDefinition* def = GameDefinition::createSample();
    _pixelPanel = new PixelPanel(def);
    _pixelPanel->generatePixelCharacters();
    
    _pixelPanel->show(this);
    _pixelPanel->setPosition(Vec2::ZERO);
    
    // Register touch events
    auto touchListener = EventListenerTouchOneByOne::create();
    
    touchListener->onTouchBegan = CC_CALLBACK_2(GamePanelLayer::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(GamePanelLayer::onTouchEnded, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(GamePanelLayer::onTouchMoved, this);
    touchListener->onTouchCancelled = CC_CALLBACK_2(GamePanelLayer::onTouchCancelled, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    
    
    return true;
}

bool GamePanelLayer::onTouchBegan(Touch* touch, Event* event)
{
    Point touchLocation = touch->getLocation();
    Point currentLocation = _pixelPanel->getSprite()->getPosition();
    _touchOffset = Vec2(touchLocation.x - currentLocation.x, touchLocation.y - currentLocation.y);
    
    return true;
}

void GamePanelLayer::onTouchEnded(Touch* touch, Event* event)
{
    cocos2d::log("touch ended");
}

void GamePanelLayer::onTouchMoved(Touch* touch, Event* event)
{
    cocos2d::log("touch moved");
    
    Point touchLocation = touch->getLocation();
    _pixelPanel->getSprite()->setPosition(touchLocation.x - _touchOffset.x, touchLocation.y - _touchOffset.y);
    
}

void GamePanelLayer::onTouchCancelled(Touch* touch, Event* event)
{
    cocos2d::log("touch cancelled");
}